#include "obsqt.h"
#include <filesystem>
#ifndef __OBS__STUDIO__
#include <Psapi.h>
#include <ShlObj.h>
#define QT_WA(unicode, ansi) unicode
typedef bool(*LOADPLUGINPROC)();
typedef bool(*LOADPLUGINEXPROC)(UINT);
OBSMODULE* f_obs_current_module()
{
	namespace fs = std::tr2::sys;
	OBSMODULE* m = new OBSMODULE;
	m->hModule = GetModuleHandle(nullptr);
	TCHAR tName[MAX_PATH] = { 0 };
	GetModuleFileName(nullptr, tName, MAX_PATH);
	m->strBinary_path = QString::fromWCharArray(tName);
	fs::wpath p(tName);
	m->strFileNmae = QString::fromStdWString(p.basename());
	m->strData_path = QString::fromStdWString(p.replace_extension(L""));
	m->strData_path += '\\';
	return m;
}
const char* f_obs_get_module_name(OBSMODULE* m)
{
	return m->strFileNmae.toStdString().c_str();
}
void f_obs_enum_modules(obs_enum_module_callback_t callback, void *param)
{
	namespace fs = std::tr2::sys;
	HMODULE hMods[1024];
	DWORD count;
	if (EnumProcessModulesEx(GetCurrentProcess(), hMods, sizeof(hMods), &count, LIST_MODULES_ALL))
	{
		for (UINT i = 0; i<(count / sizeof(HMODULE)); i++)
		{
			TCHAR szFileName[MAX_PATH];

			if (GetModuleFileNameEx(GetCurrentProcess(), hMods[i], szFileName, _countof(szFileName) - 1))
			{
				OBSMODULE* m = new OBSMODULE;
				m->strBinary_path = QString::fromWCharArray(szFileName);
				fs::wpath p(szFileName);
				m->strFileNmae = QString::fromStdWString(p.basename());
				m->strData_path = QString::fromStdWString(p.replace_extension(L""));
				m->strData_path += '\\';
				callback(param, m);
				delete m;
			}
		}
	}

}
const char* f_obs_module_config_path(const char *file)
{
	TCHAR lpAppDataPath[MAX_PATH] = { 0 };
	SHGetFolderPath(NULL, CSIDL_APPDATA, NULL, SHGFP_TYPE_CURRENT, lpAppDataPath);
	QString strCfgPath = QString::fromWCharArray(lpAppDataPath);
	strCfgPath += "\\OBS\\pluginData\\";

	return strCfgPath.toStdString().c_str();
}
int f_obs_open_module(OBSMODULE **module, const char *path,
	const char *data_path)
{
	namespace fs = std::tr2::sys;
	QString strModulePath = QString::fromUtf8(path);
	std::wstring strWModulePath = strModulePath.toStdWString();
	fs::wpath p(strWModulePath);
	HMODULE h = GetModuleHandle(p.basename().c_str());
	if (!h)
	{
		h = LoadLibrary(strWModulePath.c_str());
	}
	if (h)
	{
		*module = new OBSMODULE;
		(*module)->hModule = h;
		(*module)->strBinary_path = strModulePath;
		(*module)->strData_path = QString::fromStdWString(p.replace_extension(L""));
		(*module)->strData_path += '\\';
		(*module)->strFileNmae = QString::fromStdWString(p.basename());
		return 0;
	}
	return -1;
}
bool f_obs_init_module(OBSMODULE *module)
{
	bool bLoaded = false;
	if (module)
	{
		if (module->hModule)
		{
			LOADPLUGINEXPROC loadPluginEx = (LOADPLUGINEXPROC)GetProcAddress(module->hModule, "LoadPluginEx");
			if (loadPluginEx) {
				bLoaded = loadPluginEx(0x0103);
			}
			else {
				LOADPLUGINPROC loadPlugin = (LOADPLUGINPROC)GetProcAddress(module->hModule, "LoadPlugin");
				bLoaded = loadPlugin && loadPlugin();
			}
		}
	}
	return bLoaded;
}
const char* f_obs_get_module_binary_path(OBSMODULE *module)
{
	return module->strBinary_path.toStdString().c_str();
}
const char* f_obs_get_module_data_path(OBSMODULE *module)
{
	return module->strData_path.toStdString().c_str();
}
bool LoadPlugin()
{
	return true;
}

void UnloadPlugin()
{
	return;
}

const TCHAR   * GetPluginName()
{
	return L"Sources.GameCaptureSource.PluginName";
}

const TCHAR   * GetPluginDescription()
{
	return L"Sources.GameCaptureSource.PluginName";
}
static int g_modalLoopCount = 0;
HHOOK g_hhook;
Qt::HANDLE g_plugin;
bool    bCreate = false;
void ExitQtApplication()
{
	if (qApp)
		delete qApp;
}

LRESULT CALLBACK QtFilterProcEx(int nCode, WPARAM wParam, LPARAM lParam)
{
	if (qApp) {

		if (g_modalLoopCount)
			qApp->sendPostedEvents();
		else
			qApp->sendPostedEvents(0, -1);
		tagMSG* msg;
		msg = (tagMSG*)lParam;
		if (msg->message == WM_QUIT)
		{
			ExitQtApplication();
		}
		if (msg->message == WM_LBUTTONUP)
		{
			char name[MAX_PATH] = { 0 };
			::GetClassNameA(msg->hwnd, name, MAX_PATH);
			UINT uid = ::GetDlgCtrlID(msg->hwnd);
			if (_tcscmp("Button", name) == 0)
			{
				if (uid == 5017)
				{
					++g_modalLoopCount;
					QWinWidget win(::GetParent(msg->hwnd));
					win.showCentered();
					PluginStore* d = new PluginStore(&win);
					d->exec();
					--g_modalLoopCount;

				}
			}


		}

	}
	else
	{
		if (!bCreate)
		{
			int argc = 0;
			(void)new QApplication(argc, 0);
			if (g_plugin) {
				char filename[256];
				if (GetModuleFileNameA((HINSTANCE)g_plugin, filename, 255))
					LoadLibraryA(filename);
			}
		}


	}
	return CallNextHookEx(g_hhook, nCode, wParam, lParam);
}
bool InitQtApplication(HINSTANCE hInstance)
{
	if (qApp)
		return false;
	g_plugin = hInstance;
	QT_WA({
		g_hhook = SetWindowsHookExW(WH_GETMESSAGE, QtFilterProcEx, 0, GetCurrentThreadId());
	}, {
		g_hhook = SetWindowsHookExA(WH_GETMESSAGE, QtFilterProcEx, 0, GetCurrentThreadId());
	});
	return g_hhook ? true : false;
}
BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID /*lpvReserved*/)
{
	static bool ownApplication = false;

	if (dwReason == DLL_PROCESS_ATTACH)
	{
		QCoreApplication::addLibraryPath(".");
		QCoreApplication::setAttribute(Qt::AA_ShareOpenGLContexts);
		ownApplication = InitQtApplication(hInstance);
	}
	if (dwReason == DLL_PROCESS_DETACH&& ownApplication)
	{

		if (g_hhook) {
			UnhookWindowsHookEx(g_hhook);
			g_hhook = 0;
		}


	}
	return TRUE;
}
#endif
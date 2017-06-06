#pragma once
#ifndef __OBS__STUDIO__
#include <QMfcApp>
#include <qmfcapp>
#include <qwinwidget>
#include<Windows.h>
#include<tchar.h>
#include <iostream>
#include <memory>
#include "pluginstore.h"
struct OBSMODULE
{
	QString strFileNmae;
	QString	strBinary_path;
	QString	strData_path;
	HMODULE	hModule;
};
OBSMODULE* f_obs_current_module();
const char* f_obs_get_module_name(OBSMODULE* m);
typedef void(*obs_enum_module_callback_t)(void *param, OBSMODULE *module);
void f_obs_enum_modules(obs_enum_module_callback_t callback, void *param);
const char* f_obs_module_config_path(const char *file);
int f_obs_open_module(OBSMODULE **module, const char *path,
	const char *data_path);
bool f_obs_init_module(OBSMODULE *module);
const char* f_obs_get_module_binary_path(OBSMODULE *module);
const char* f_obs_get_module_data_path(OBSMODULE *module);
#define AutoFreeMemory(f,d) std::shared_ptr<f>(d)
#define obs_module_t OBSMODULE
#define obs_current_module()								f_obs_current_module()
#define obs_get_module_name(f)								f_obs_get_module_name(f)
#define obs_enum_modules(c,p)								f_obs_enum_modules(c,p)							
#define obs_module_config_path(f)							f_obs_module_config_path(f)
#define obs_open_module(m,p,d)								f_obs_open_module(m,p,d)
#define obs_init_module(m)									f_obs_init_module(m)
#define obs_get_module_binary_path(m)						f_obs_get_module_binary_path(m)
#define obs_get_module_data_path(m)							f_obs_get_module_data_path(m)
#define MODULE_SUCCESS 0
#define obs_get_locale() QString("")
extern "C" __declspec(dllexport) bool LoadPlugin();
extern "C" __declspec(dllexport) void UnloadPlugin();
extern "C" __declspec(dllexport) const TCHAR    * GetPluginName();
extern "C" __declspec(dllexport) const TCHAR   *GetPluginDescription();

#else
#define AutoFreeMemory
#endif

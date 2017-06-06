#include "pluginDB.h"

PluginDB::PluginDB()
{

}


PluginDB::~PluginDB()
{
}

bool PluginDB::InitPluginDB()
{
    bool bRet = false;
    QString qstrFilePath;
    if (QSqlDatabase::isDriverAvailable(__DEF_SQL_DRIVER_TYPE__))
    {
        qstrFilePath = __DEF_SQL_DATABASE_NAME__;
        m_database = QSqlDatabase::addDatabase(__DEF_SQL_DRIVER_TYPE__);

        if (!QFile::exists(qstrFilePath))
        {
            QFile dbFile(qstrFilePath);
            bRet = dbFile.open(QIODevice::WriteOnly) ? true : false;
            dbFile.close();
        }
        else
            bRet = true;

        if (bRet)
        {
            m_database.setDatabaseName(qstrFilePath);
            bRet = OpenDB();
        }

        if (bRet)
        {
            if (!IsExistTable("PluginInfo"))
            {
                bRet = CreatePluginTable();
            }
            else
                bRet = true;

            if (!IsExistTable("Config"))
            {
                bRet = CreateConfigTable();
            }
            else
                bRet = true;
        }
    }    
    return bRet;
}


bool PluginDB::OpenDB()
{
    bool bRet = false;
    if (m_database.isOpen())
    {
        CloseDB();
    }

    bRet = m_database.open();
    if (!bRet)
    {
        qDebug() << m_database.lastError();
    }

    return bRet;
}

void PluginDB::CloseDB()
{
    m_database.close();
}

bool PluginDB::CreatePluginTable()
{
    bool bRet = false;
    QString qstrSQL("CREATE TABLE PluginInfo(plug_id INTEGER,file_name TEXT,local_path TEXT,plugin_state INTEGER,down_size INTEGER,file_size INTEGER,json_data TEXT);");
    if (!qstrSQL.isEmpty())
    {
        QSqlQuery query(m_database);
        bRet = query.exec(qstrSQL);
        if (!bRet)
        {
            qDebug() << query.lastError();
        }
    }
    return bRet;
}

bool PluginDB::CreateConfigTable()
{
    bool bRet = false;
    QString qstrSQL("CREATE TABLE Config(name TEXT,value TEXT);");
    if (!qstrSQL.isEmpty())
    {
        QSqlQuery query(m_database);
        bRet = query.exec(qstrSQL);
        if (!bRet)
        {
            qDebug() << query.lastError();
        }
    }
    return bRet;
}

bool PluginDB::SetConfigValue(QString qstrName, QString qstrValue)
{
    bool bRet = false;
    QSqlQuery query(m_database);
    QString qstrSQL;
    if (GetConfigValue(qstrName).isEmpty())
    {
        qstrSQL = QString("INSERT INTO Config (name,value) VALUES(:name,:value);");
    }
    else
    {
        qstrSQL = QString("UPDATE Config SET value=:value WHERE name=:name;");
    }
    
    query.prepare(qstrSQL);
    query.bindValue(":name", qstrName);
    query.bindValue(":value", qstrValue);
    qDebug() << query.executedQuery();
    bRet = query.exec();
    if (!bRet)
    {
        qDebug() << query.lastError();
    }

    return bRet;
}

QString PluginDB::GetConfigValue(QString qstrName)
{
    QString qstrValue = "";
    QSqlQuery query(m_database);
    QString qstrSQL = QString("SELECT value FROM Config WHERE name='%1'").arg(qstrName);
    query.exec(qstrSQL);
    while (query.next())
    {
        qstrValue = query.value("value").toString();
    }
    return qstrValue;
}

bool PluginDB::IsExistTable(QString qstrTabName)
{
    bool bRet = false;
    QSqlQuery query(m_database);
    QString qstrSQL = QString("SELECT name FROM sqlite_master where type = 'table' and  name = '%1'").arg(qstrTabName);
    query.exec(qstrSQL);
    if (query.next())
    {
        QString qResult = query.value("name").toString();
        qDebug() << qResult << "---------" << qstrTabName;
        if (qResult.compare(qstrTabName) == 0)
        {
            bRet = true;
        }
    }
    return bRet;
}

bool PluginDB::InsertPluginData(PluginInfo obj)
{
    bool bRet = false;
    QSqlQuery query(m_database);
    QString qstrSQL = QString("INSERT INTO PluginInfo (plug_id,file_name,local_path,down_size,file_size,plugin_state,json_data)"\
                              " VALUES(:plug_id,:file_name,:local_path,:down_size,:file_size,:plugin_state,:json_data);");

    query.prepare(qstrSQL);
    query.bindValue(":plug_id", obj.plugin_id);
    query.bindValue(":file_name", obj.file_name);
    query.bindValue(":local_path", obj.local_path);
    query.bindValue(":down_size", obj.down_size);
    query.bindValue(":file_size", obj.file_size);
    query.bindValue(":json_data", obj.json_data);
    query.bindValue(":plugin_state", obj.state);
    qDebug() << query.executedQuery();
    bRet = query.exec();
    if (!bRet)
    {
        qDebug() << query.lastError();
    }

    return bRet;
}

bool PluginDB::DeletePluginData(qint64 qiPluginId)
{
    bool bRet = false;
    QSqlQuery query(m_database);
    QString qstrSQL = QString("DELETE FROM PluginInfo where PluginInfo.plug_id ='%1'").arg(qiPluginId);
    bRet = query.exec(qstrSQL);
    if (!bRet)
    {
        qDebug() << query.lastError();
    }
    return bRet;
}

bool PluginDB::UpdatePluginData(qint64 qiPluginId, PluginInfo obj)
{
    bool bRet = false;
    QSqlQuery query(m_database);
    QString qstrSQL = QString("UPDATE PluginInfo SET down_size = :down_size,"\
                                                    "file_size = :file_size,"\
                                                    "file_name = :file_name,"\
                                                    "local_path = :local_path,"\
                                                    "json_data = :json_data,"\
                                                    "plugin_state = :plugin_state"\
                              " WHERE plug_id = :plug_id");

    query.prepare(qstrSQL);
    query.bindValue(":local_path", obj.local_path);
    query.bindValue(":file_name", obj.file_name);
    query.bindValue(":down_size", obj.down_size);
    query.bindValue(":file_size", obj.file_size);
    query.bindValue(":json_data", obj.json_data);
    query.bindValue(":plugin_state", obj.state);
    query.bindValue(":plug_id", qiPluginId);

    bRet = query.exec();
    if (!bRet)
    {
        qDebug() << query.lastError();
    }
    return bRet;
}

int PluginDB::GetPluginDataCount(qint64 qiPluginId)
{
    return QueryPluginData(qiPluginId).count();
}

QList<PluginDB::PluginInfo> PluginDB::QueryPluginData(qint64 qiPluginId)
{
    QList<PluginInfo> list;
    QSqlQuery query(m_database);
    QString qstrSQL = QString("SELECT * FROM PluginInfo");
    if (qiPluginId != -1)
    {
        qstrSQL.append(QString(" WHERE plug_id = '%1'").arg(qiPluginId));
    }
    qDebug() << qstrSQL;
    query.exec(qstrSQL);
    while (query.next())
    {
        PluginInfo item;
        item.plugin_id = query.value("plug_id").toInt();
        item.file_name = query.value("file_name").toString();
        item.local_path = query.value("local_path").toString();
        item.down_size = query.value("down_size").toInt();
        item.file_size = query.value("file_size").toInt();
        item.json_data = query.value("json_data").toString();
        item.state = (PluginState)query.value("plugin_state").toInt();

        list.append(item);
    }

    return list;
}

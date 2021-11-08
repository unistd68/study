#!/usr/bin/python3
#coding=utf-8
import sys
import configparser
import pymysql

config_path = "./config.ini"

#map_key
db_alias_IP = "IP"
db_alias_Port = "Port"
db_alias_User = "User"
db_alias_Password = "Password"
db_alias_CharsetName = "CharsetName"

db_info = {}

def close_db_conn(db_cursor,db_obj):
    db_cursor.close()
    db_obj.close()

def get_config_info(file_path,db_alias):
    cf = configparser.ConfigParser()
    cf.read(file_path)
    db_info[db_alias_IP] = cf.get(db_alias, db_alias_IP)
    db_info[db_alias_Port] = cf.get(db_alias, db_alias_Port)
    db_info[db_alias_User] = cf.get(db_alias, db_alias_User)
    db_info[db_alias_Password] = cf.get(db_alias, db_alias_Password)
    db_info[db_alias_CharsetName] = cf.get(db_alias, db_alias_CharsetName)
    print("########################################################")
    print("配置文件数据")
    print("db_alias:%s"%(db_alias))
    print("db_info[db_alias_IP]:%s"%(db_info[db_alias_IP]))
    print("db_info[db_alias_Port]:%s"%(db_info[db_alias_Port]))
    print("db_info[db_alias_User]:%s"%(db_info[db_alias_User]))
    print("db_info[db_alias_Password]:%s"%(db_info[db_alias_Password]))
    print("db_info[db_alias_CharsetName]:%s"%(db_info[db_alias_CharsetName]))
    print("########################################################")

if __name__ == '__main__':
    reload(sys)
    sys.setdefaultencoding('utf8') # 设置默认编码格式为'utf-8'
    get_config_info(config_path,"mysql")
    db_pos = pymysql.connect(host = db_info[db_alias_IP], port = int(db_info[db_alias_Port]), user = db_info[db_alias_User], passwd = db_info[db_alias_Password], use_unicode = True, charset = db_info[db_alias_CharsetName])
    db_cursor = db_pos.cursor()
    close_db_conn(db_cursor,db_pos)

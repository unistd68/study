package db_mysql

import (
	"fmt"
    "database/sql"
    // "github.com/go-sql-driver/mysql"
	model "https_gin/app/model"
)

func connect(dbinfo model.DBAuthInfo)  {
	var url =fmt.Sprintf("%s:%s@(%s:%s)/%s",dbinfo.DBUser,dbinfo.DBPwd,dbinfo.DBHost,dbinfo.DBPort,dbinfo.DBName)
	fmt.Println(url)

	db,_:=sql.Open("mysql",url) // 设置连接数据库的参数
    defer db.Close()    //关闭数据库
    err:=db.Ping()      //连接数据库
    if err!=nil{
        fmt.Println("数据库连接失败")
        return
    }
	fmt.Println("数据库连接成功")
}

func query(){}

func add(){}

func del(){}

func modify(){}
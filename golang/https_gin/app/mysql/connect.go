package db_mysql

import (
	"fmt"
    "database/sql"
	// "github.com/jmoiron/sqlx"
    _ "github.com/go-sql-driver/mysql"
	model "https_gin/app/model"
)

func Connect(dbinfo model.DBAuthInfo)  {
	var url =fmt.Sprintf("%s:%s@tcp(%s:%s)/%s",dbinfo.DBUser,dbinfo.DBPwd,dbinfo.DBHost,dbinfo.DBPort,dbinfo.DBName)
	fmt.Println(url)

	db, _:= sql.Open("mysql", "gch:GCHgch_123456@tcp(127.0.0.1:3306)/test?charset=utf8")
    db.SetMaxOpenConns(2000)
    db.SetMaxIdleConns(1000)
    // db.Ping()
	// db,_:=sql.Open("mysql",string(url)) // 设置连接数据库的参数
	// db,_:=sqlx.Open("mysql","gch:GCHgch_123456@tcp(127.0.0.1:3306)/test")
    //defer db.Close()    //关闭数据库
    err:=db.Ping()      //连接数据库
    if err!=nil{
        fmt.Println("数据库连接失败")
        return
    }
	fmt.Println("数据库连接成功")
	// db.Close()
}

func query(){}

func add(){}

func del(){}

func modify(){}
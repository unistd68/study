package db_mysql

import (
	"fmt"
    "database/sql"
    _ "github.com/go-sql-driver/mysql"
    "encoding/json"

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

func QueryDB(sqlStr string) (string, error){
    // var url =fmt.Sprintf("%s:%s@tcp(%s:%s)/%s",dbinfo.DBUser,dbinfo.DBPwd,dbinfo.DBHost,dbinfo.DBPort,dbinfo.DBName)
	// fmt.Println(url)
    fmt.Println("begin QueryDB")
	db, _:= sql.Open("mysql", "gch:GCHgch_123456@tcp(127.0.0.1:3306)/test?charset=utf8")
    db.SetMaxOpenConns(2000)
    db.SetMaxIdleConns(1000)
    // db.Ping()
	// db,_:=sql.Open("mysql",string(url)) // 设置连接数据库的参数
	// db,_:=sqlx.Open("mysql","gch:GCHgch_123456@tcp(127.0.0.1:3306)/test")
    defer db.Close()    //关闭数据库
    err:=db.Ping()      //连接数据库
    if err!=nil{
        fmt.Println("数据库连接失败")
        return "", err 
    }
	fmt.Println("数据库连接成功")

    stmt, err := db.Prepare(sqlStr)
	if err != nil {
        fmt.Println("Prepare err")
		return "", err
	}
	defer stmt.Close()
    fmt.Println("stmt.Close")
	rows, err := stmt.Query()
	if err != nil {
        fmt.Println("stmt.Close err")
		return "", err
	}
	defer rows.Close()
    fmt.Println("rows.Close")
    columns, err := rows.Columns()
	if err != nil {
      fmt.Println("Columns error")
	  return "", err
	}
    fmt.Println("rows.Columns")
    count := len(columns)
	tableData := make([]map[string]interface{}, 0)
	values := make([]interface{}, count)
	valuePtrs := make([]interface{}, count)
	for rows.Next() {
      fmt.Println("rows.Next..")
	  for i := 0; i < count; i++ {
		  valuePtrs[i] = &values[i]
	  }
	  rows.Scan(valuePtrs...)
	  entry := make(map[string]interface{})
      fmt.Println("range columns")
	  for i, col := range columns {
		  var v interface{}
		  val := values[i]
		  b, ok := val.([]byte)
		  if ok {
			  v = string(b)
		  } else {
			  v = val
		  }
		  entry[col] = v
	  }
      fmt.Println("append")
	  tableData = append(tableData, entry)
	}
    fmt.Println("Marshal")
	jsonData, err := json.Marshal(tableData)
	if err != nil {
      fmt.Println("Marshal error")
	  return "", err
	}
    fmt.Println("ok")
	fmt.Println(string(jsonData))
	return string(jsonData), nil 
}

func add(){}

func del(){}

func modify(){}
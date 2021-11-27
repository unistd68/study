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

func query(sqlStr string) (string, error){
    // var url =fmt.Sprintf("%s:%s@tcp(%s:%s)/%s",dbinfo.DBUser,dbinfo.DBPwd,dbinfo.DBHost,dbinfo.DBPort,dbinfo.DBName)
	// fmt.Println(url)

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

    rows, _ := db.Query(sqlStr)

	defer rows.Close()//defer关闭查询连接

    //获取列相关信息
	// strings, _ := rows.Columns()
    
	// for i:=0;i< len(strings);i++{
	// 	fmt.Print(" ",strings[i])
	// }
	
    // fmt.Println()

    // var obj model.VideoMsg
    // var videos model.Video
    

    // for rows.Next(){
    //     rows.Scan(&obj.No,&obj.Title,&obj.Type,&obj.Url)//将一行数据放入参数中
    //     videos.
    // }

    // buf, err := json.Marshal(model.AccountLogin{Name: "root",Passwd:"123456"})
    // if err != nil {
    //     panic(err)
    // }
    // println(string(buf))
	// fmt.Println(string(buf))
	// c.String(http.StatusOK, string(buf))

    columns, err := rows.Columns()
	if err != nil {
	  return "", err
	}
    count := len(columns)
	tableData := make([]map[string]interface{}, 0)
	values := make([]interface{}, count)
	valuePtrs := make([]interface{}, count)
	for rows.Next() {
	  for i := 0; i < count; i++ {
		  valuePtrs[i] = &values[i]
	  }
	  rows.Scan(valuePtrs...)
	  entry := make(map[string]interface{})
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
	  tableData = append(tableData, entry)
	}
	jsonData, err := json.Marshal(tableData)
	if err != nil {
	  return "", err
	}
	fmt.Println(string(jsonData))
	return string(jsonData), nil 
}

func add(){}

func del(){}

func modify(){}
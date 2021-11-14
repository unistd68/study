/*
 * @Author: your name
 * @Date: 2021-11-08 10:39:41
 * @LastEditTime: 2021-11-14 17:40:10
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \dubbo-goe:\other\vshare\test\golang\gin\app\shop\handler.go
 */

 package user

 import (
	"fmt"
	"github.com/gin-gonic/gin"
	"encoding/json"
	"net/http"

	model "https_gin/app/model"
	dbmysql "https_gin/app/mysql"
 )

func user_login(c *gin.Context) {
	json := model.User{}
	c.BindJSON(&json)
	fmt.Println("%v",&json)
	c.JSON(http.StatusOK, gin.H{
		"status": 0,
		"desc": "login success",
		"name": json.Name,
		"password": json.Passwd,
		"autoLogin": json.AutoLogin,
		"type": json.Type
	})
}

func testdb(c *gin.Context) {
	var dbinfo = model.DBAuthInfo{"test","127.0.0.1","3306","gch","GCHgch_123456"};
	dbmysql.Connect(dbinfo);
	c.String(http.StatusOK, "testdb success\n")

}

func testjson(c *gin.Context) {
    buf, err := json.Marshal(model.User{Name: "root",Passwd:"123456"})
    if err != nil {
        panic(err)
    }
    println(string(buf))
	fmt.Println(string(buf))
	c.String(http.StatusOK, string(buf))
}
/*
 * @Author: your name
 * @Date: 2021-11-08 10:39:41
 * @LastEditTime: 2021-11-14 17:40:10
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \dubbo-goe:\other\vshare\test\golang\gin\app\shop\handler.go
 */

 package video

 import (
	"fmt"
	"github.com/gin-gonic/gin"
	"encoding/json"
	"net/http"
	"os"
	"io/ioutil"
	"path/filepath"

	model "https_gin/app/model"
	dbmysql "https_gin/app/mysql"
 )

func getAllFiles(path string)([]string,error){
	files,err := filepath.Glob(filepath.Join(path,"*"))
	if err != nil {
		panic(err)
	}
 
	for file := range files {
		fmt.Println(file[i]) //打印path
	}

	return files,nil
}

func testPath(c *gin.Context){
	var path = "/data/video/天下足球/"
	buf,err := getAllFiles(path);
	if err != nil {
        panic(err)
    }

	c.JSON(http.StatusOK,"ok")
}

func getVideoMsg(c *gin.Context) {
	sqlStr := "select * from tb_address_info"
	buf,err := dbmysql.QueryDB(sqlStr);
	if err != nil {
        panic(err)
    }

	var respBuff = "{\"data\":" + string(buf) + "}"
	str:=[]byte(string(respBuff))
	var videos model.Video
	err = json.Unmarshal(str,&videos)
	if err!=nil{
        fmt.Println(err)
    }
	
	// fmt.Println("%v",&videos)
	c.JSON(http.StatusOK,videos)
}

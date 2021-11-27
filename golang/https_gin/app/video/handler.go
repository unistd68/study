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
	// "fmt"
	"github.com/gin-gonic/gin"
	// "encoding/json"
	"net/http"

	// model "https_gin/app/model"
	dbmysql "https_gin/app/mysql"
 )

func getVideoMsg(c *gin.Context) {
	sqlStr := "select * from tb_address_info"
	buf,err := dbmysql.QueryDB(sqlStr);
	if err != nil {
        panic(err)
    }
    println(string(buf))
	// c.String(http.StatusOK, string(buf))

	str:=[]byte(buf)
	var videos model.Video
	err:=json.Unmarshal(str,&videos)
	if err!=nil{
        fmt.Println(err)
    }
	fmt.Println("%v",&videos)
	c.JSON(http.StatusOK,videos)
}

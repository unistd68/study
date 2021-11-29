/*
 * @Author: your name
 * @Date: 2021-11-08 10:39:41
 * @LastEditTime: 2021-11-14 17:40:10
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \dubbo-goe:\other\vshare\test\golang\gin\app\shop\handler.go
 */

 package audio

 import (
	"fmt"
	"github.com/gin-gonic/gin"
	"encoding/json"
	"net/http"
	"path"
	"io/ioutil"
	// "path/filepath"
	"strings"

	model "https_gin/app/model"
	dbmysql "https_gin/app/mysql"
 )

 func UpdateUrls(c *gin.Context){
	var filepath = "/data/video/天下足球/"

	files,err := ioutil.ReadDir(filepath)
	if err != nil {
		panic(err)
		return
	}

	fmt.Println(len(files))

	for i := range files {
		fmt.Println(files[i].Name())  //打印当前文件或目录下的文件或目录名
		fileext := path.Ext(files[i].Name())
		filetype := strings.Trim(fileext, ".")
		filename := strings.TrimSuffix(files[i].Name(), fileext)
		sqlStr := "insert into tb_audio_addr(no,title,type,url) values('01','"+ filename +"','"+ filetype +"','"+files[i].Name()+"');"
		fmt.Println(sqlStr)
		dbmysql.ExecSql(sqlStr)
	}
	c.JSON(http.StatusOK,"ok")
}


func getAudioMsg(c *gin.Context) {
	sqlStr := "SELECT taa.NAME AS NAME, tai1.NAME AS artist, taa.net_link AS url, taa.lrc_link AS lrc, tai2.pic_net_link AS cover FROM tb_audio_addr taa LEFT JOIN tb_album_info tai2 ON taa.album_no = tai2.NO LEFT JOIN tb_artist_info tai1 ON tai2.artist_no = tai1.NO;"
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

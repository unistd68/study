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
	"path"
	"io/ioutil"
	"path/filepath"
	"strings"

	model "https_gin/app/model"
	dbmysql "https_gin/app/mysql"
 )

func getAllFilesPath(path string)([]string,error){
	files,err := filepath.Glob(filepath.Join(path,"*"))
	if err != nil {
		panic(err)
	}
 
	for i := range files {
		fmt.Println(files[i]) //打印path
	}

	return files,nil
}

// func getAllFilesName(path string)([]string,error){
// 	files,err := ioutil.ReadDir(path)
// 	if err != nil {
// 		panic(err)
// 	}
// 	fmt.Println(len(files))
// 	for i := range files {
// 		fmt.Println(files[i].Name())  //打印当前文件或目录下的文件或目录名
// 	}

// 	return files,nil
// }

func UpdateUrls(c *gin.Context){
	var filepath = "/data/video/天下足球/"
	// files,err := getAllFilesName(path);
	// if err != nil {
    //     panic(err)
    // }
	
	files,err := ioutil.ReadDir(filepath)
	if err != nil {
		panic(err)
		return
	}
	fmt.Println(len(files))
	// for i := range files {
	// 	fmt.Println(files[i].Name())  //打印当前文件或目录下的文件或目录名
	// }

	for i := range files {
		fmt.Println(files[i].Name())  //打印当前文件或目录下的文件或目录名
		fileext := path.Ext(files[i].Name())
		filetype := strings.Trim(fileext, ".")
		filename := strings.TrimSuffix(files[i].Name(), fileext)
		sqlStr := "insert into tb_video_addr(no,title,type,url) values('01','"+ filename +"','"+ filetype +"','"+files[i].Name()+"');"
		fmt.Println(sqlStr)
		dbmysql.ExecSql(sqlStr)
	}
	c.JSON(http.StatusOK,"ok")
}

func getVideoMsg(c *gin.Context) {
	sqlStr := "select no,name as title,type,net_link as url  from tb_video_addr"
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


func getVideoMsg2(c *gin.Context) {
	sqlStr := "select tva.title as title,tsi.ip_addr as ip, tva.bucket as bucket,  tva.video_path as filepath from tb_video_addr tva inner join tb_server_intance tsi on tva.server_no = tsi.no;"
	buf,err := dbmysql.QueryDB(sqlStr);
	if err != nil {
        panic(err)
    }

	var buff = "{\"data\":" + string(buf) + "}"
	str:=[]byte(string(buff))
	var records model.AudioRecords
	err = json.Unmarshal(str,&records)
	if err!=nil{
        fmt.Println(err)
    }

	var respBuff model.VideoResp

	vlen := len(records.DBAudios)
	for i:=0;i<vlen;i++{
		var url = strings.TrimSpace(records.DBAudios[i].Ip) + strings.TrimSpace(records.DBAudios[i].Bucket) + "/" + strings.TrimSpace(records.DBAudios[i].Filepath);
		respBuff.Addrs = append(respBuff.Addrs,model.VideoAddr{Title:records.DBAudios[i].Title,Url:url})
	}

	// fmt.Println("%v",&videos)
	c.JSON(http.StatusOK,respBuff)
}
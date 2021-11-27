/*
 * @Author: your name
 * @Date: 2021-11-08 09:56:58
 * @LastEditTime: 2021-11-08 16:07:51
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \dubbo-goe:\other\vshare\test\golang\gin\main.go
 */
package main

import (
"fmt"
user "https_gin/app/user"
routers "https_gin/routers"
video "https_gin/app/video"

)

func main() {
	// 加载多个APP的路由配置
	routers.Include( user.Routers video.Routers)
	// 初始化路由
	r := routers.Init()
	if err := r.Run(":8888"); err != nil {
		fmt.Println(" startup service failed, err:%v\n", err)
	}
	fmt.Println(" service exit\n")
}


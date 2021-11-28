###
 # @Author: your name
 # @Date: 2021-11-08 09:56:31
 # @LastEditTime: 2021-11-14 17:25:48
 # @LastEditors: Please set LastEditors
 # @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 # @FilePath: \dubbo-goe:\other\vshare\test\golang\gin\run.sh
### 
#!/bin/bash
ls go.mod
if [ $? -ne 0 ]; then
    go mod init main
fi
ls go.sum
if [ $? -ne 0 ]; then
    go mod tidy
fi
git pull origin develop
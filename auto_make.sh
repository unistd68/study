###
 # @Author: your name
 # @Date: 2021-10-03 16:16:54
 # @LastEditTime: 2021-10-05 10:54:10
 # @LastEditors: Please set LastEditors
 # @Description: In User Settings Edit
 # @FilePath: \dubbo-goe:\code\study\auto_build.sh
### 
#!/bin/bash
echo "### begin build      ###"
echo "### current position ###"
pwd
echo "* files *"
ls -l
make clean 
make
valgrind --leak-check=full --show-reachable=yes --trace-children=yes --log-file=test.log --time-stamp=yes ./my_service 
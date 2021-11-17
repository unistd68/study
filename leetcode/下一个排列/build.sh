###
 # @Author: your name
 # @Date: 2021-11-17 12:00:25
 # @LastEditTime: 2021-11-17 12:33:53
 # @LastEditors: Please set LastEditors
 # @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 # @FilePath: \dubbo-goe:\other\vshare\test\leetcode\下一个排列\build.sh
### 

#!/bin/bash
shared_dir_test=/media/sf_vshare/test
# rm -f test 
make clean
git pull origin develop
make
./test
# g++ main.cpp  tools.cpp  tools.h includes.h -o test -g
# ./test
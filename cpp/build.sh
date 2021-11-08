###
 # @Author: your name
 # @Date: 2021-11-01 10:11:40
 # @LastEditTime: 2021-11-01 12:38:35
 # @LastEditors: Please set LastEditors
 # @Description: In User Settings Edit
 # @FilePath: \dubbo-goe:\other\vshare\test\auto_test.sh
### 
#!/bin/bash
shared_dir_test=/media/sf_vshare/test
rm -f test 
g++ main.cpp dp.h dp.cpp string_test.cpp string_test.h  md5.cpp  md5.h  sm3.cpp  sm3.h  sm4.cpp  sm4.h  tools.cpp  tools.h includes.h -o test -luuid  -fpermissive -g
./test

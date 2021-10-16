###
 # @Author: xtcgch
 # @Date: 2021-10-03 16:16:54
 # @LastEditTime: 2021-10-05 10:54:10
 # @LastEditors: xtcgch
 # @Description: In User Settings Edit
 # @FilePath: \dubbo-goe:\code\study\sm4\TestSM4\Makefile
### 
#!/bin/bash
echo " ################################################################ "
echo " ################ BUILD BEGIN       "
echo " ################ CURRENT POSITION  "
pwd
echo " ################ SOURCE FILES  "
ls -l
make clean 
make
ls test_sm4
if [ #? -ne 0 ];then
    echo " ################ ERROR      "
    echo " ################ MAKE FAIL  "
    exit 1
fi
echo " ################ BUILD SUCCESS    "
echo " ################ BUILD TARGET     "
ls -l test_sm4
echo " ################ BUILD END       "
echo " ################################################################ "
valgrind --leak-check=full --show-reachable=yes --trace-children=yes --log-file=log_test_sm4.log --time-stamp=yes ./test_sm4 
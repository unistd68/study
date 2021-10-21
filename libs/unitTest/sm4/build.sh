###
# @Author: xtcgch
# @Date: 2021-10-03 16:16:54
 # @LastEditTime: 2021-10-21 21:23:02
 # @LastEditors: Please set LastEditors
# @Description: In User Settings Edit
# @FilePath: \dubbo-goe:\code\study\sm4\TestSM4\Makefile
###
#!/bin/bash
# echo " ################################################################ "
# echo " ################ BUILD BEGIN       "
# echo " ################ CURRENT POSITION  "
# pwd
# echo " ################ SOURCE FILES  "
# ls -l
# make clean
# make
# ls test_sm4
# # if [ #? -ne 0 ]
# # then
# #     echo " ################ ERROR      "
# #     echo " ################ MAKE FAIL  "
# #     exit 1
# # fi
# echo " ################ BUILD SUCCESS    "
# echo " ################ BUILD TARGET     "
# ls -l test_sm4
# echo " ################ BUILD END       "
# echo " ################################################################ "
# valgrind --leak-check=full --show-reachable=yes --trace-children=yes --log-file=log_test_sm4.log --time-stamp=yes ./test_sm4

build_sm4_test() {
    rm test_sm4
    g++ -I../../../includes/ -I../../include -I/usr/local/include/readerwriterqueue -I/home/xtcgch/Env/redis/redis-6.2.5/deps -L/home/xtcgch/Env/redis/redis-6.2.5/deps/hiredis/build_dir -lhiredis -std=c++11 -fpermissive -lstdc++ -W -Wall ../../src/sm4.cpp ../../include/sm4.h test_sm4.cpp -o test_sm4
    valgrind --leak-check=full --show-reachable=yes --trace-children=yes --log-file=log_test_sm4.log --time-stamp=yes ./test_sm4

}

build_sm3_test() {
    rm test_sm3
    g++ -I../../../includes/ -I../../include -I/usr/local/include/readerwriterqueue -I/home/xtcgch/Env/redis/redis-6.2.5/deps -L/home/xtcgch/Env/redis/redis-6.2.5/deps/hiredis/build_dir -lhiredis -std=c++11 -fpermissive -lstdc++ -W -Wall ../../src/sm3.cpp ../../include/sm3.h test_sm3.cpp -o test_sm3
    valgrind --leak-check=full --show-reachable=yes --trace-children=yes --log-file=log_test_sm3.log --time-stamp=yes ./test_sm3

}

show_help() {
    echo " ################################################# "
    echo " ##################  Usage  ###################### "
    echo " #########[1]./build.sh 1 : sm3 test sample ###### "
    echo " #########[2]./build.sh 2 : sm4 test sample ###### "
    echo " ################################################# "
}

if [ "$#" != "1" ]; then
    show_help
    exit 1
fi

if [ "$1" == "1" ]; then
    build_sm3_test
elif [ "$1" == "2" ]; then
    build_sm4_test
else
    show_help
fi

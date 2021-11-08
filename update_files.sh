###
 # @Author: your name
 # @Date: 2021-11-01 11:43:11
 # @LastEditTime: 2021-11-01 11:47:47
 # @LastEditors: Please set LastEditors
 # @Description: In User Settings Edit
 # @FilePath: \dubbo-goe:\other\vshare\test\update_files.sh
### 
#!/bin/bash
work_place=/media/sf_vshare/test
exec_place=`pwd`
echo "execplace: "$exec_place
echo "workplace: "$work_place
# rm -f *.c 
rm -f *cpp 
rm -f *.h
rm -f build.sh
rm -f Makefile
# cp -f $work_place/*.c .
cp -f $work_place/*.cpp .
cp -f $work_place/*.h .
cp -f $work_place/build.sh .
cp -f $work_place/Makefile .
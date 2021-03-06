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
sid=$(pidof my_http)
echo  $sid
if [ $sid  ]
then
  sudo kill -9 $sid
fi
sudo /bin/rm -f my_http
sudo /bin/rm -f /home/xtcgch/MyService/my_http
echo "* begin make *"
make
echo "* files *"
sudo /bin/cp -f my_http /home/xtcgch/MyService/my_http
(nohup /home/xtcgch/MyService/my_http &)
echo "### build finished ! ###"
ps -ef | grep my_http
valgrind --leak-check=full --show-reachable=yes --trace-children=yes --log-file=test.log --time-stamp=yes ./my_service 
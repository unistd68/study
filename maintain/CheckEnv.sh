#!/bin/bash
# 界面输出区
optimize() {
	echo "
----系统优化选择项目----
	1.网络信息获取
	2.CPU信息获取
	3.内存信息获取
	4.系统基本信息
	5.网络测试
	0.退出监测
	"
}
 
# 函数命令区-order
ip_get(){
	echo "--网卡列表--"
	cat /proc/net/dev | sed -n '3,$p' | awk -F ':' {'print $1'} |sed s/[[:space:]]//g|grep -v lo
	echo "------------"
	read -ep "请选择您想要获取IP的网卡名称:" wangka
	zw=`ifconfig |grep -n1 $wangka |grep inet|awk '{print $5}'`
	ip=`ifconfig |grep -n1 $wangka |grep inet|awk '{print $3}'`
	wg=`ifconfig |grep -n1 $wangka |grep inet|awk '{print $7}'`
	echo "网卡 $wangka IP为: $ip "
	echo "网卡 $wangka 网关为: $wg "
	echo "网卡 $wangka 子网掩码为: $zw "
		
}
# cpu信息获取
cpu_get(){
	echo "
	----cpu查询内容----
	1.cpu的数量
	2.cpu的空闲值
	3.cpu的核心数
	4.cpu的型号
	0.返回上一层
	e.直接退出监测
	"
	while :
	do
		read -ep "输入您的选择项:" cp
		case $cp in
		1)
			cpu_shu=`cat /proc/stat | grep cpu[0-9]|wc -l`
			echo "CPU的数量为:$cpu_shu 个"
		;;
		2)
			cpu_kong=`vmstat |tail -n1|awk '{print $15}'`
			echo "CPU空闲率为:$cpu_kong %"
		;;
		3)
			cpu_he=`cat /proc/cpuinfo |grep "cores"|head -n1|awk -F ': ' '{print $2}'`
			echo "CPU核心数:$cpu_he 个"
		;;
		4)
			cpu_xing=`grep "model name" /proc/cpuinfo|sort|uniq|awk -F: '{print $2}'|sed s/[[:space:]]//g`
			echo "CPU的型号:$cpu_xing"
		;;
		0)
			break
		;;
		e)
			exit
		;;
		*)
			echo "选项输出有误,从新输入"
		esac
	done
}
# 内存信息获取
mem_get(){
	echo "
	--- 内存信息选项---
	1.系统总物理内存
	2.系统总交换内存
	3.系统以使用内存
	4.系统剩余内存
	0.返回上一级
	e.直接退出监测
	"
	while :
	do
		read -ep "输入您的选择项:" cp
		case $cp in
		1)
			free_wu=`free -h|grep Mem|awk {'print $2'}`
			echo "系统总物理内存:$free_wu"
		;;
		2)
			free_jiao=`free -h|grep Swap|awk {'print $2'}`
			echo "系统总交换内存:$free_jiao"
		;;
		3)
			free_yong=`free -m|grep Mem|awk {'print $3'}`
			echo "系统以使用内存:$free_yong M"
		;;
		4)
			free_yu=`free -m|grep Mem|awk {'print $4'}`
			echo "系统剩余内存:$free_yu M"
		;;
		0)
			break
		;;
		e)
			exit
		;;
		*)
			echo "选项输出有误,从新输入"
		esac
	done
}
#系统基本信息
centos_get(){
	echo "
		---系统信息选项---
		1.系统类型
		2.系统版本
		3.系统内核
		4.本机名称
		5.当前时间
		6.运行时长
		7.启动时间
		0.返回上一级
		e.直接退出监测
		"
		while :
	do
		read -ep "输入您的选择项:" cp
		case $cp in
		1)
			os_lei=`uname`
			echo "系统类型:$os_lei"
		;;
		2)
			os_ban=`cat /etc/redhat-release`
			echo "系统版本:$os_ban"
		;;
		3)
			os_he=`uname -a|awk '{print $3}'`
			echo "系统内核:$os_he"
		;;
		4)
			host=`hostname`
			echo "本机名称:$host"
		;;
		5)
			date_dang=`date +%F_%T`
			echo "系统当前时间:$date_dang"
		;;
		6)
			date_yun=`uptime |awk '{print $3}'|awk -F, '{print $1}'`
			echo "系统运行时长:$date_yun"
		;;
		7)
			date_xi=`who -b|awk '{print $2,$3}'`
			 echo "系统启动时间:$date_xi"
		;;
		8)
			who_i=`who |wc -l`
			echo "系统登陆用户数:$who_i 个 "
		;;
		0)
			break
		;;
		e)
			exit
		;;
		*)
			echo "选项输出有误,从新输入"
		esac
	done
}
#网络
wang_get(){
	curl -I http://www.baidu.com &>/dev/null # 测试
	if [ $? -eq 0 ];then 
		echo "    访问外网：成功"
	else 
		echo "    访问外网：失败"
	fi
}
 
# 函数执行区-execute
 
while :
do
	optimize
	read -ep "输入需要监控查看的选项:" kong
	case $kong in
	1)
	#IP获取
		ip_get
	;;
	2)
		#CPU信息获取
		cpu_get
	;;
	3)
		#内存信息获取
		mem_get
	;;	
	4)
		#系统基本信息
		centos_get
	;;
	5)
		#网络测试
		wang_get
	;;
	0)
		exit 0
	;;
	*)
		echo "选项输出有误,从新输入"
	esac
	
done
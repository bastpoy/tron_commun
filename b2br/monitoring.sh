#!/bin/bash

#echo "Broadcast message from $(whoami)@$(hostname)" | wall

echo "	#Architecure: $(uname -a)"
echo "	#CPU physical : $(lscpu | awk 'NR==15'| awk -F ' ' '{print $2}')"
echo "	#vCPU : $(cat /proc/cpuinfo | grep processor | awk -F ' ' '{print $3}')"
echo "	#Memory Usage: $(free | grep Mem | awk '{print $3}' | cut -c1-2)/$(free | grep Mem | awk '{print $2}' | cut -c1-3)MB ($(free | grep Mem | awk '{print $3/$2 * 100}' | cut -c1-4)%)"
echo "	#Disk Usage: $(df | awk 'NR==4' | awk '{print $3}' | cut -c1-4)/$(df -h | awk 'NR==4' | awk '{print $2}') ($(df | awk 'NR==4' | awk '{print $5}'))"
echo ""

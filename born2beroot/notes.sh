# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    notes.sh                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inoteboo <inoteboo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 09:11:27 by inoteboo          #+#    #+#              #
#    Updated: 2023/02/08 08:45:03 by inoteboo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


---------------------------------------SSH--------------------------------------
# add ssh user
	sudo nano /etc/ssh/sshd_config
	# add line
	AllowUsers	[username]

# status ssh
	sudo service ssh status

# restart ssh
	sudo service ssh restart

--------------------------------------UFW---------------------------------------
# firewall status
	sudo ufw status

# add rule
	sudo ufw allow [port number/tcp||udp]

# delete rule
	sudo ufw delete allow [port number/tcp||udp]

---------------------------------------HOSTNAME----------------------------------
# modify hostname
	sudo hostnamectl set-hostname [hostname]
	# modify hosts file
	sudo nano /etc/hosts
	# reboot
	sudo reboot

-----------------------------------------USERS & GROUPS--------------------------
# list users
	cut -d: -f1 /etc/passwd

# list all groups
	getent group

# list groups a user is a member of
	groups [username]

# create user
	sudo adduser [username]

# delete user
	sudo deluser [username]

# create group
	sudo groupadd [groupname]

# delete group
	sudo groupdel [groupname]

# add user to a group
	usermod -a -G [groupname] [username]

# remove user from a group
	sudo deluser [username] [groupname]

----------------------------------------SUDO--------------------------------------
# edit sudo config file
	sudo visudo /etc/sudoers

# print sudo log file
	sudo cat /var/log/sudo/sudo.log

--------------------------------------SECURITY------------------------------------
# edit password policy config file
	sudo nano /etc/pam.d/common-password

# install cracklib (common password library)
	sudo apt install libpam-cracklib

# edit login config file
	sudo nano /etc/login.defs

# check expiration policy
	sudo chage -l [username]

-------------------------------------MONITORING----------------------------------
# architecture
	echo -e "#architecture:\t\t" `uname -v` `uname -m`
# kernel version
	uname -v
# cpu count
	echo -e "#CPU physical:\t\t" `grep "physical id" /proc/cpuinfo | sort | uniq | wc -l`
# vcpu count
	echo -e "#vCPU:\t\t `grep "^processor" /proc/cpuinfo | wc -l`
# memory usage
	echo -e "#memory usage:\t\t" `free | awk '/Mem/{printf("%d/%dMB (%.2f%%)"),$3, $2, $3/$2*100}'`
# disk usage
	echo -e "#Disk Usage:\t\t" `df --total --human-readable | awk '/total/{printf("%s/%s (%s)"), $3, $2, $5}'`
# cpu load
	echo -e "#CPU load:\t\t"`cat /proc/stat | awk '/cpu/{printf("%.2f%%\n"), ($2+$4)*100/($2+$4+$5)}' | awk '{print $0}' | head -1`
# last boot
	echo -e "#Last boot:\t\t" `who -b | awk '{printf("%s %s"), $3, $4}'`
# LVM use
	if mount | grep -q /dev/mapper/
	then
	echo -e "#LVM use:\t\tyes"
	elseee
	echo -e "#LVM use:\t\tno"
	fi
#network connections
	echo -e "#Connections TCP:\t\t" `netstat -ant | grep ESTABLISHED | wc -l` "ESTABLISHED"
#number of users
	echo -e "#Users logged in:\t\t" `w -h | wc -l`
#network info
	echo -e "#Network:\t\t" `ifconfig | head -n5 | grep 'inet' | cut -d: -f2 | awk '{print $2}'` "("`ifconfig | head -n5 | grep 'ether' | cut -f2 | awk '{print $2}'`")"
#sudo logfile count
	echo -e "#SUDO log count:\t\t" `cat /var/log/sudo/sudo.log | wc -l | awk '{printf("%s\n"), $1/2}'`

--------------------------------------SCRIPT--------------------------------------
# colors

	# Reset
	Color_Off='\033[\0m'       # Text Reset
	
	# Regular Colors
	Black='\033[0;30m'        # Black
	Red='\033[0;31m'          # Red
	Green='\033[0;32m'        # Green
	Yellow='\033[0;33m'       # Yellow
	Blue='\033[0;34m'         # Blue
	Purple='\033[0;35m'       # Purple
	Cyan='\033[0;36m'         # Cyan
	White='\033[0;37m'        # White
	
	# Bold
	BBlack='\033[1;30m'       # Black
	BRed='\033[1;31m'         # Red
	BGreen='\033[1;32m'       # Green
	BYellow='\033[1;33m'      # Yellow
	BBlue='\033[1;34m'        # Blue
	BPurple='\033[1;35m'      # Purple
	BCyan='\033[1;36m'        # Cyan
	BWhite='\033[1;37m'       # White
	
	# Underline
	UBlack='\033[4;30m'       # Black
	URed='\033[4;31m'         # Red
	UGreen='\033[4;32m'       # Green
	UYellow='\033[4;33m'      # Yellow
	UBlue='\033[4;34m'        # Blue
	UPurple='\033[4;35m'      # Purple
	UCyan='\033[4;36m'        # Cyan
	UWhite='\033[4;37m'       # White
	
	# Background
	On_Black='\033[40m'       # Black
	On_Red='\033[41m'         # Red
	On_Green='\033[42m'       # Green
	On_Yellow='\033[43m'      # Yellow
	On_Blue='\033[44m'        # Blue
	On_Purple='\033[45m'      # Purple
	On_Cyan='\033[46m'        # Cyan
	On_White='\033[47m'       # White
	
	# High Intensity
	IBlack='\033[0;90m'       # Black
	IRed='\033[0;91m'         # Red
	IGreen='\033[0;92m'       # Green
	IYellow='\033[0;93m'      # Yellow
	IBlue='\033[0;94m'        # Blue
	IPurple='\033[0;95m'      # Purple
	ICyan='\033[0;96m'        # Cyan
	IWhite='\033[0;97m'       # White
	
	# Bold High Intensity
	BIBlack='\033[1;90m'      # Black
	BIRed='\033[1;91m'        # Red
	BIGreen='\033[1;92m'      # Green
	BIYellow='\033[1;93m'     # Yellow
	BIBlue='\033[1;94m'       # Blue
	BIPurple='\033[1;95m'     # Purple
	BICyan='\033[1;96m'       # Cyan
	BIWhite='\033[1;97m'      # White
	
	# High Intensity backgrounds
	On_IBlack='\033[0;100m'   # Black
	On_IRed='\033[0;101m'     # Red
	On_IGreen='\033[0;102m'   # Green
	On_IYellow='\033[0;103m'  # Yellow
	On_IBlue='\033[0;104m'    # Blue
	On_IPurple='\033[0;105m'  # Purple
	On_ICyan='\033[0;106m'    # Cyan
	On_IWhite='\033[0;107m'  


echo ""
echo "\033[32m ---------------------------------------------------------------------------\033[\0m"
echo "\033[32m| \033[\0m#Architecture:\t"`uname -v` `uname -m`"\033[32m\t    |\033[\0m"
echo "\033[32m| \033[\0m#CPU Physical:\t"`grep "physical id" /proc/cpuinfo | sort | uniq | wc -l`"\033[32m\t\t\t\t\t\t    |\033[\0m"
echo "\033[32m| \033[\0m#vCPU:\t\t"`grep "^processor" /proc/cpuinfo | wc -l`"\033[34m\t\t\t        :::      ::::::::\033[\0m\033[32m   |\033[\0m"
echo "\033[32m| \033[\0m#Memory Usage:\t"`free | awk '/Mem/{printf("%d/%dMB (%.2f%%)"), $3, $2, $3/$2*100}'`"\033[34m\t      :+:      :+:    :+:\033[\0m\033[32m   |\033[\0m"
echo "\033[32m| \033[\0m#Disk Usage:\t\t"`df --total --human-readable | awk '/total/{printf("%s/%s (%s)"), $3, $2, $5}'`"\033[34m\t\t    +:+ +:+         :+:\033[\0m\033[32m\t    |\033[\0m"
echo "\033[32m| \033[\0m#CPU Load:\t\t"`top -b -n1 | grep "%Cpu" | awk '{printf("%.1f%%"), $2 + $4}'`"\033[34m\t\t\t  +#+  +:+       +#+\033[\0m\033[32m\t    |\033[\0m"
echo "\033[32m| \033[\0m#Last boot:\t\t"`who -b | awk '{printf("%s %s"), $3, $4}'`"\033[34m\t+#+#+#+#+#+   +#+\033[\0m\033[32m\t    |\033[\0m"
if mount | grep -q /dev/mapper/
then
echo "\033[32m| \033[\0m#LVM use:\t\tyes\033[34m\t\t\t     #+#    #+#\033[\0m\033[32m\t\t    |\033[\0m"
else
echo "\033[32m| \033[\0m#LVM use:\t\tno\033[34m\t\t\t     #+#    #+#\033[\0m\033[32m\t\t    |\033[\0m"
fi
echo "\033[32m| \033[\0m#Connections TCP:\t"`netstat -ant | grep ESTABLISHED | wc -l`"\033[34m\t\t\t    ###   ###########\033[\0m\033[32m\t    |\033[\0m"
echo "\033[32m| \033[\0m#Users logged in:\t"`w -h | wc -l`"\033[32m\t\t\t\t\t\t    |\033[\0m"
echo "\033[32m| \033[\0m#Network:\t\tIP "`sudo ifconfig | head -n5 | grep 'inet' | cut -d: -f2 | awk '{print $2}'` "("`sudo ifconfig | head -n5 | grep 'ether' | cut -f2 | awk '{print $2}'`>
echo "\033[32m| \033[\0m#SUDO log count:\t"`cat /var/log/sudo/sudo.log | wc -l | awk '{printf("%s\n"), $1/2}'`"\033[32m\t\t\t\t\t\t    |\033[\0m"
echo "\033[32m ---------------------------------------------------------------------------\033[\0m"
echo ""


chage for root
what is tty
sort in script nodig?

#!/bin/bash


# before starting any of the program it checks of the user is root, 
# and if not it exits out
if [ "$(id -u)" != "0" ]; then
	echo "This sript must be run as root" 1>&2
	exit 1
fi

# for each line in the emails.txt list of emails
for line in $(cat emails.txt)
do
	# exracts a username from the beginning part of the email
	uname=${line%@*}
	passw=$(openssl rand -base64 12)
	# if the username is Not already taken, create a new user
	# and password
	if (groups $uname | grep -q '\bCSI230\b') >/dev/null 2>&1; then
		usermod --password $(openssl passwd -crypt $passw) $uname
	else
		useradd -g 'CSI230' -m -p $(openssl passwd -crypt $passw) $uname
	fi
	# regardless of if the user name is taken, propmt the user
	# for a new password at next login

	echo $uname $passw

	chage --lastday 0 $uname >/dev/null 2>&1
	chage -l $uname >/dev/null 2>&1

	# email the user with their username and password

done

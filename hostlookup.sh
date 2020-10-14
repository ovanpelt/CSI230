#!/bin/bash

# file hostlookup.sh
# brief Using While loops to read through an input file, about host ip
# author olivia.vanpelt
# Lab 6.2
# date 10/13/2020

# brief displays the intended for of the file
usage()
{
        echo "$0 usage: [-f input file]"
        exit 1
}

while getopts ":f:" options;
do
        case "${options}" in
        f)
          f=${OPTARG}
          if [ -f "$f" ]; then
		echo "reading from $f"
	  else
		echo "file $f not found"
		usage
	  fi
          ;;
        *)
        usage
        ;;
        esac
done


while read line
do
       out=$(host -W1 -t A $line)
        if [ $? -eq 0 ];then
                ip=$(echo $out | cut -d " " -f 4)
                echo ${line},$ip
        else
                echo "${line},not found"
        fi

done < $f

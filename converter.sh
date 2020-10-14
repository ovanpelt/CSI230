#!/bin/bash

# file converter.sh
# brief Using while loops to read an input file and change its case
# author olivia.vanpelt
# Lab 6.2
# date 10/13/2020


# brief a function to display the intended format of script call
usage()
{
	echo "$0 usage: [-f input filed] [-c U(pper) or L(ower)"
	exit 1
}

while getopts ":f:c:" options;
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
	c)
	  c=${OPTARG}
	  if [[ ${c} == "U" || ${c} == "L" ]]; then
		echo "${f} -${c}"
	  else
		usage
	  fi
	  ;;
	*)
	usage
	;;
	esac
done
#conversion
while read line
do
	if [ ${c} == "U" ]; then
		echo $line | tr [:lower:] [:upper:]
	else
		echo $line | tr [:upper:] [:lower:]
	fi
done < $f

exit 0

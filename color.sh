#!/bin/bash

red='\033[0;31m'
green='\033[0;32m'
yellow='\033[0;33m'
blue='\033[0;34m'
magenta='\033[0;35m'
default='\033[0m'

read -p "whats is your favorite color (red, green, yellow, blue, or magenta)" color
color=${color^^}

case "${color}" in
        "RED")
          selected_color=$red
          ;;
        "GREEN")
	  selected_color=$green
          ;;
	"YELLOW")
	  selected_color=$yellow
	  ;;
	"BLUE")
	  selected_color=$blue
	  ;;
	"MAGENTA")
	  selected_color=$magenta
	  ;;
        *)
          echo "you did not enter a valid color"
          exit 1
          ;;
        esac
echo -e "${selected_color}Your selected color is ${color}${default}"


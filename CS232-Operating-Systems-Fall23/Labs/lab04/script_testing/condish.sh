#!/usr/bin/bash

echo "Please enter a number: "
read num

if [ $num -lt 0 ]; then
	echo "Your number is negative"
elif [ $num -lt 10 -a $num -gt 0 ]; then
	echo "Your number is between 0 and 10"
else
	echo "Your number is very positive"
fi

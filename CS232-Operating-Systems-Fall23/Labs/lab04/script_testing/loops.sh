#!/usr/bin/bash

echo "---------WHILE LOOP-----------"

i=1

while [ $i -le 10 ]; do
	echo $i
	(( i += 1 ))
done

echo "---------FOR LOOP-----------"

for i in {1..10}
do
	echo $i
done

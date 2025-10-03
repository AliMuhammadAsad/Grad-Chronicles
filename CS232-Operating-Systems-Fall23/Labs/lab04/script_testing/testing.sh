#!/usr/bin/bash

echo "Always start with #!/bin/bash or whatever your bash thingy is which u can see using 'which bash' command in the terminal"

echo "'echo' is used to echo or print something out"
echo "you can use variables as well (just don't put a space between var name, equals to, and the data - I struggled kaafi der with this"
echo "You can use the '$' sign to output a specific variable or smthng as well"
echo "'read' command to take input from the user"

echo "Today is " `date`

echo -e "\nEnter the directory you want to list the files of"
read the_path
echo -e "\nYour path has the following files and folders"
ls $the_path

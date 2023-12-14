#!/usr/bin/bash

# Check if the user did not provide directory and days (number of args)
if [ $# -ne 2 ]; then
    echo "Usage: $0 <Directory> <Days>"
    exit 1
fi

dir="$1"
days="$2"

# If directory does not exist then print error message and exit.
if [ ! -d "$dir" ]; then
    echo "Directory $dir does not exist."
    exit 2
fi

# Use find to search for files and directories within the specified location. the option -type f searches for files only. -mtime +$days searches for files that were modified more than $days ago. -exec rm -f {} \; executes the rm command on the files found. 
find "$dir" -type f -mtime +"$days" -exec rm -f {} \;

echo "Success"
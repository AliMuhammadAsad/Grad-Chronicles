#!/usr/bin/bash

# If user enters incorrect number of arguments, print usage message and exit.
if [ $# -ne 1 ]; then
    echo "Usage: $0 <CSV File>"
    exit 1
fi

# Log file input
log="$1"

# If log file does not exist then print error message and exit.
if [ ! -f "$log" ]; then
    echo "File $log does not exist."
    exit 2
fi

# Setting error message to search for, and the count of errors
e="ERROR"
e1="error"
e2="Error"
count=0

# Loop through each line of the log file and increment count if error message is found
while IFS= read -r line; do
    if [["$line" == "$e" || "$line" == "$e1" || "$line" == "$e2" ]]; then
        ((count++))
    fi
done < "$log"

# Print summary report
echo "Log Analysis Summary Report:"
echo "Log File: $log"
echo "Error Count: $count"

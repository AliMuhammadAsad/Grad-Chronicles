#!/usr/bin/bash

# If user enters incorrect number of arguments, print usage message and exit.
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <CSV File> <word to search for>"
    exit 1
fi

# CSV File input is first argument
csv_file="$1" 

# If csv file does not exist then print error message and exit.
if [ ! -f "$csv_file" ]; then
    echo "File $csv_file does not exist."
    exit 2
fi

# Word to search for is second argument
word="$2"
# wc=$(grep -o -w "$word" "$csv_file" | wc -l)
# wc=$(tr ',' '\n' < "$csv_file" | grep -o -w "$word" | wc -l)+

# The below command, We use -F for field seperator which is ',' for CSV file. -v is used to set variable word to shell variable world. Then a loop iterates over each field and checks if the field is equal to the word. If it is, then count is incremented. Finally, the count is printed.
wc=$(awk -F, -v word="$word" '{for(i=1;i<=NF;i++) if($i==word) count++} END{print count}' "$csv_file")

echo "There are $wc occurrences of the word $word in the file $csv_file."
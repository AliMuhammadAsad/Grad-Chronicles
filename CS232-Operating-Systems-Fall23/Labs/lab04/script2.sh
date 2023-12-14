#!/usr/bin/bash

cpu=$(top -bn1 | grep "Cpu(s)" | awk '{print $2 + $4}') #Top provides sys processes info in real time, -bn1 runs top in batch mode (b), and specifies that top should only run for 1 iteration. It then pipes to grep that searches for the string "Cpu(s)" and pipes to awk that prints the second and fourth column of the output.

# lscpu provides detailed info about the CPU and its features. That is piped onto grep which searches for the Model name and pipes to awk which prints the second column of the output. The output is then piped to sed which removes leading whitespace - readable format.
processor_model=$(lscpu | grep "Model name" | awk -F':' '{print $2}' | sed 's/^[ \t]*//')

# lsb_release prints certain LSB (Linux Standard Base) and Distribution information. The -d flag prints the description of the distribution. The -s flag prints only the description.
os_description=$(lsb_release -d -s)

# free displays the amount of free and used memory in the system. The -h flag prints the output in human readable format. The output is then piped to awk which searches for the line that starts with Mem: and prints the second column of the output. 
mem_RAM=$(free -h | awk '/^Mem:/ {print $2}')

# df displays the amount of disk space available on the file system containing each file name argument. The -h flag prints the output in human readable format. The output is then piped to awk which searches for the line that starts with total and prints the second column of the output.
total_disk_space=$(df -h --total | awk '/total/ {print $2}')

# df displays the amount of disk space available on the file system containing each file name argument. The -h flag prints the output in human readable format. The output is then piped to awk which searches for the line that starts with / and prints the second, third, fourth, and fifth column of the output.
disk_usage=$(df -h / | awk 'NR==2 {printf("Total: %s, Used: %s, Available: %s, Usage: %s", $2, $3, $4, $5)}')

echo "-------------System Information-------------"
echo "CPU Usage: $cpu"
echo "Processor Model: $processor_model"
echo "Operating System: $os_description"
echo "RAM Installed: $mem_RAM"
echo "Total Memory/Disk Space: $total_disk_space"
echo "Disk Usage: $disk_usage"
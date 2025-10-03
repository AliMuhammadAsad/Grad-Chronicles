#!/usr/bin/bash

if [ $# -ne 2 ]; then
    echo "Usage: $0 <Source Directory> <Destination Directory>"
    exit 1
fi

s_dir="$1"
d_dir="$2"

# Check if Source Exists
if [ ! -d "$s_dir" ]; then
    echo "Source directory '$s_dir' does not exist."
    exit 2
fi

# Create the destination directory if it doesn't exist
if [ ! -d "$d_dir" ]; then
    mkdir -p "$d_dir"
fi

# Use 'rsync' to copy all files from the source directory to the destination directory
rsync -av "$s_dir/" "$d_dir/"

archive_file="backup.tar.gz"

# Use the 'tar' command to create a compressed archive of the source directory
tar -czvf "$d_dir/$archive_file" -C "$s_dir" .

echo "Backup completed: $archive_file is created in '$d_dir'."
#!/usr/bin/bash

password() {
    local len="$1"
    local num_len="$2"
    local special_len="$3"
    local pass=""

    upper="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    lower="abcdefghijklmnopqrstuvwxyz"
    numbers="0123456789"
    special_chars="!@#$%^&*()_+"

    # Initialize char set with just letters
    char_set="$upper$lower"

    if [ "$num_len" -gt 0 ]; then
        char_set="$char_set$numbers"
    fi

    if [ "$special_len" -gt 0 ]; then
        char_set="$char_set$special_chars"
    fi

    for ((i = 0; i < len; i++)); do
        random_char=${char_set:$((RANDOM % ${#char_set})):1}
        pass="$pass$random_char"
    done

    echo "$pass"
}

if [ $# -ne 3 ]; then
    echo "Usage: $0 <Password Length> <Number Length> <Special Character Length>"
    exit 1
fi

length="$1"
num_len="$2"
special_len="$3"

if [[ "$length" -lt 1 || "$num_len" -lt 0 || "$special_len" -lt 0 ]]; then
    echo "Password length can not be less than 1. Number length and special character length must be non-negative integers."
    exit 1
fi

pass=$(password "$length" "$num_len" "$special_len")

echo "Generated Password: $pass"

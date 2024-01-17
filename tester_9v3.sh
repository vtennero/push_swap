#!/bin/bash

# Log file path
LOG_FILE="push_swap_output.log"

# Function to execute push_swap and handle output
execute_and_log() {
    # Execute push_swap and capture the last line
    last_line=$(./push_swap "$@" | tail -n 1)

    # Check if the last line is different from "123456789"
    if [[ $last_line != "123456789" ]]; then
        # Save to log file
        echo "$last_line" >> "$LOG_FILE"

        # Display the command and its output
        echo "./push_swap $* -> $last_line"
    fi
}

# Clear log file at the beginning of the script
> "$LOG_FILE"

# Execute with different number sets
execute_and_log 6 2 8 9 4 5 7 3 1
execute_and_log 4 9 7 8 1 2 5 6 3
execute_and_log 1 4 6 3 5 9 8 7 2
execute_and_log 4 2 6 3 9 1 8 7 5
execute_and_log 2 6 1 3 9 7 4 5 8

#!/bin/bash

# Log file path
LOG_FILE="push_swap_output.log"

# Counters for success and total tests
success_count=0
total_count=0

# Function to execute push_swap and handle output
execute_and_log() {
    # Increment total test counter
    ((total_count++))

    # Execute push_swap and capture the last line
    last_line=$(./push_swap "$@" | tail -n 1)

    # Check if the last line is "123456789" for a success
    if [[ $last_line == "123456789" ]]; then
        # Increment success counter
        ((success_count++))
    else
        # Save to log file and display output for non-success cases
        echo "$last_line" >> "$LOG_FILE"
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
execute_and_log 2 4 3 9 6 7 1 5 8
execute_and_log 7 2 8 4 9 3 1 5 6
execute_and_log 9 5 4 8 3 6 2 7 1
execute_and_log 5 6 1 2 4 8 9 7 3
execute_and_log 3 6 9 5 1 4 2 7 8
execute_and_log 7 6 4 5 1 8 3 2 9
execute_and_log 9 5 7 4 3 2 1 8 6
execute_and_log 3 1 7 2 6 9 4 5 8
execute_and_log 4 7 3 1 9 8 5 6 2
execute_and_log 9 6 5 7 2 8 1 4 3
execute_and_log 6 4 7 5 2 9 3 8 1
execute_and_log 1 6 4 3 5 9 8 2 7
execute_and_log 8 3 6 2 9 1 4 5 7
execute_and_log 8 4 6 7 2 1 9 5 3
execute_and_log 9 8 5 1 4 7 2 6 3
execute_and_log 8 3 4 7 5 6 1 9 2
execute_and_log 7 2 9 3 8 6 1 4 5
execute_and_log 9 1 8 4 6 3 2 7 5
execute_and_log 6 7 4 1 3 9 2 8 5
execute_and_log 3 8 9 1 4 2 7 5 6
execute_and_log 5 4 3 8 1 7 2 6 9
execute_and_log 9 1 2 8 3 7 5 6 4
execute_and_log 1 3 7 8 6 5 2 4 9
execute_and_log 7 8 2 3 1 4 6 9 5
execute_and_log 4 1 6 9 5 8 3 2 7

# Display the success rate at the end
echo "$success_count/$total_count tests passed"
rm "$LOG_FILE"


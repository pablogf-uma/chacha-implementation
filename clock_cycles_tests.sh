#!/bin/bash

# Number of runs per test
runs=100

csv_file="benchmarking_chacha20.csv"

echo "Initializing CSV file: $csv_file"

for test in {1..5}
do
    for ((i=1; i<=runs; i++))
    do
        echo -e "\nTest $test, Run $i:"
        
        # Clean and compile
        make clean > /dev/null 2>&1
        make > /dev/null 2>&1
        
        # Run the program
        output=$(./chacha20 --clock-ct $test 2>/dev/null)
        
        # Extract clock cycles
        clock_cycles=$(echo "$output" | grep "Clock cycles per byte" | awk '{print $5}')
        echo "Extracted Clock Cycles: $clock_cycles"
        
        # Write to CSV
        echo "$test,$i,$clock_cycles" >> $csv_file
    done
done

#!/bin/bash

d_out="./output_directory"
d_in="./input_directory"
f_in=($d_in/*)
f_out=()
execute_file=./Le_Nguyen_QuickSort


# generate list of output files base on input files
for file in "${f_in[@]}"; do
    f_out+=("$d_out/output_$(basename "$file")")
done

# check if d_out exist, if not create
if [ ! -d "$d_out" ]; then
  mkdir -p "$d_out"
fi

# run multiple time
for ((i=0; i<${#f_in[@]}; i++)); do
  #echo "Input: ${f_in[$i]}, Output: ${f_out[$i]}"
  ./Le_Nguyen_QuickSort ${f_in[$i]} ${f_out[$i]}
  pid=$! # capture the pid id of background process
  wait $pid # wait for previous command done
  sleep 1 # delay
done

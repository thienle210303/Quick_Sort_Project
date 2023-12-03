# Program to simulating Quick Sort perform as well as calculating execute time and average execute time

## How to run QuickSort following commands
# Simple commands
g++ -std=c++17 -Wall Le_Nguyen_QuickSort.cpp -o Le_Nguyen_QuickSort
./Le_Nguyen_QuickSort <input_file_name> <output_file_name>
make average
# run simple testing case
make test0
# run all advange testing case
make test1

## Command (Makefile)
# Default make to perform every work include generating and calculating average
make
# to init QuickSort executable file
make init
# to run simple test case with 1 input file and 1 output file
make test0
# to run test with generating file
make test1
# to generate input files
make generate
# to calculating average of output
make average
# to clean all redundant file
make clean
# or clean output only
make clean_output
# or clean execuable file only
make clean_exe

## File Structure
- Le_Nguyen_QuicSort_cpp        : main program to perform quick sort and calculating executing time
- InputFileGenerator.cpp        : program to random generating 25 input files with value range(-100, 100)
- Average_time.cpp              : program to take "Le_Nguyen_averageTime.txt" to calculating average base on size
- script.sh                     : bash script to perform multiple execute QuickSort from generating

- *plotAverageExecutionTime.jpg : plot of avarage execute time

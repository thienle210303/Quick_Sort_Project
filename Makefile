TARGET = Le_Nguyen_QuickSort
SOURCE = ${TARGET}.cpp

.PHONY: run
all: run

run: clean init generate script average clean_exe
	@echo "Done";

# Test 0: simle run test case with input and output file
_test0: clean init
	./$(TARGET) example_input.txt example_output.txt
test0: _test0 average clean_exe

# Test 1: generating files and test
test1: clean init generate script clean_exe
	@echo "Done";

script:
	@chmod +x script.sh
	@./script.sh

init:
	@g++ -std=c++17 -Wall $(SOURCE) -o $(TARGET)

generate:
	@echo "Generating Input Files"
	@g++ -std=c++17 InputFileGenerator.cpp -o inputGenerate
	@./inputGenerate

average:
	@g++ -std=c++17 Average_time.cpp -o average
	@./average

clean_output:
	rm -rf *_directory Le_Nguyen_*.txt example_output.txt
clean_exe:
	rm -rf Le_Nguyen_QuickSort average inputGenerate
clean: clean_output clean_exe

.PHONY: clean

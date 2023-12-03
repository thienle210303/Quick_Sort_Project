#include <iostream>
#include <fstream>
#include <unordered_map>
#include <iomanip>

int main() {
    const std::string inputFileName = "Le_Nguyen_executionTime.txt";
    const std::string outputFileName = "Le_Nguyen_averageExecutionTime.txt";

    std::ifstream inputFile(inputFileName);
    if (!inputFile.is_open()) {
        std::cerr << "ERROR ----- Unable to open input file: " << inputFileName << std::endl;
        return 1;
    }

    std::unordered_map<int, double> sums;
    std::unordered_map<int, int> counts;
    int size;
    double time;

    while (inputFile >> size >> time) {
        sums[size] += time;
        counts[size]++;
    }
    inputFile.close();

    std::ofstream outputFile(outputFileName);
    if (!outputFile.is_open()) {
        std::cerr << "ERROR ----- Unable to open output file: " << outputFileName << std::endl;
        return 1;
    }
    
    for (const auto& entry : sums) {
        int size = entry.first;
        double average = entry.second / counts[size];
        outputFile << std::noshowpos << size << "    " << std::scientific << std::setprecision(2) << average << std::endl;
    }
    outputFile.close();

    return 0;
}

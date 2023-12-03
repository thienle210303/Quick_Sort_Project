#include <fstream>
#include <random>
#include <set>
#include <filesystem>  // Include the filesystem library for directory creation

int main() {
    std::random_device rd;  // Random number device
    std::mt19937 generator(rd()); // Mersenne twister generator
    std::uniform_real_distribution<> distribution(-100.0, 100.0); // Uniform distribution

    // Create a folder for all files
    std::filesystem::create_directory("input_directory");

    for (int size = 10; size <= 1000; size *= 10) {
        for (int i = 0; i < 25; ++i) {
            // Use the common folder for file placement
            std::ofstream file("input_directory/input" + std::to_string(size) + "_" + std::to_string(i) + ".txt");
            std::set<float> numbers;
            while (numbers.size() < size) {
                numbers.insert(distribution(generator));
            }
            for (const auto& num : numbers) {
                file << num << " ";
            }
        }
    }

    return 0;
}
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <chrono>
#include <iomanip>
#include <filesystem>

using std::cout;
using std::endl;
using std::cerr;

using std::ifstream;
using std::ofstream;

using std::string;
using std::vector;
using std::swap;

float median(float a, float b, float c) {
  // Find median by using math
  if((a-b) * (c-a) >= 0)
    return a;
  else if((b-a) * (c-b) >= 0)
    return b;
  else
    return c;
}

int partition(vector<float>& arr, int left, int right) {
  float pivot = median(arr[left], arr[right], arr[(left + right)/2]);
  int i = left - 1, j = right + 1;
  while (true) {
    // find the value i on left hand of pivot
    do {
      i++;
    } while(arr[i] < pivot);

    // find the value j on right hand of pivot
    do {
      j--;
    } while (arr[j] > pivot);
  
    if (i >= j) return j;

    swap(arr[i], arr[j]);
  }
}

void QuickSort(vector<float>& arr, int left, int right) {
  if (left < right) {
    int s = partition(arr, left, right); // split
    QuickSort(arr, left, s - 1);
    QuickSort(arr, s + 1, right);
  }
}

int main(int argc, char* argv[]) {
  if (argc != 3) {
    cerr << "ERROR ----- Command Order: " << argv[0] << "<input_file_name> <output_file_name>" << endl;
  }

  // Input
  ifstream inputFile(argv[1]);
  if(!inputFile.is_open()) {
    cerr << "ERROR ----- unable to open file" << endl;
    cout << argv[1] << endl;
    return 1;
  }

  vector<float> arr;
  float num;
  while (inputFile >> num) {
    arr.push_back(num);
  }
  inputFile.close();

  // Start time
  auto start = std::chrono::high_resolution_clock::now();

  // Sort
  QuickSort(arr, 0, arr.size()-1);

  // Record end time
  auto end = std::chrono::high_resolution_clock::now();

  // Output
  ofstream outputFile(argv[2]);
  for(float n : arr) {
    outputFile << n << " ";
  }
  outputFile << "\n";
  outputFile.close();
  
  auto executionTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
  double doneTime = (double)(executionTime);
  
  // Output ExecuteTime
  ofstream exeFile("Le_Nguyen_executionTime.txt", std::ios_base::app);
  exeFile << std::noshowpos << arr.size() << "    " << std::scientific << std::setprecision(2) << doneTime << "\n";
  exeFile.close();

  //std::cout << "Time: " << std::setprecision(2) << std::scientific << doneTime << " ms" << std::endl;

  return 0;
}
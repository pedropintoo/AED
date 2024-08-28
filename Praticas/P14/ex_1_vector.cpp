//
// Algoritmos e Estruturas de Dados --- 2023/2024
//
// STL Containers - Performance
//

#include <iomanip>
#include <chrono>
#include <iostream>
#include <vector>

using namespace std;
using namespace std::chrono;

int main(void) {
  const size_t MIN = 1000;
  const size_t MAX = 1000000;

  // Header
    std::cout << std::setw(30) << "BEGIN" << std::setw(32) << "END" << std::endl;
    std::cout << "N" << std::setw(20) << "INSERT" << " | " << "AVERAGE" << " | " <<  "ERASE"
              << std::setw(15) << "INSERT" << " | " << "AVERAGE" << " | " << "ERASE" << std::endl;

  for (size_t size = MIN; size <= MAX; size *= 10) {

    std::cout << std::setw(10) << std::left << size;

    // 1st vector container --- appending at the end

    vector<double> v1;

    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    for (size_t i = 0; i < size; i++) {
      v1.push_back(i);
    }

    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(t2 - t1).count();

    std::cout << std::right << std::setw(11) << duration;

    t1 = high_resolution_clock::now();

    double sum = 0.0;
    for (size_t i = 0; i < size; i++) {
      sum += v1[i];
    }

    t2 = high_resolution_clock::now();
    duration = duration_cast<microseconds>(t2 - t1).count();

    std::cout << std::right << std::setw(10) << duration;

    t1 = high_resolution_clock::now();

    for (size_t i = 0; i < size; i++) {
      v1.pop_back();
    }

    t2 = high_resolution_clock::now();
    duration = duration_cast<microseconds>(t2 - t1).count();

    std::cout << std::right << std::setw(8) << duration;

    // 2nd vector container --- inserting at the beginning

    vector<double> v2;

    t1 = high_resolution_clock::now();

    for (size_t i = 0; i < size; i++) {
      v2.insert(v2.begin(), i); // slower because he needs to shift all values
    }

    t2 = high_resolution_clock::now();
    duration = duration_cast<microseconds>(t2 - t1).count();

    std::cout << std::right << std::setw(15) << duration;

    t1 = high_resolution_clock::now();

    sum = 0.0;
    for (int i = size - 1; i >= 0; i--) {
      sum += v2[i];
    }

    t2 = high_resolution_clock::now();
    duration = duration_cast<microseconds>(t2 - t1).count();

    std::cout << std::right << std::setw(10) << duration;

    t1 = high_resolution_clock::now();

    for (size_t i = 0; i < size; i++) {
      v2.erase(v2.begin());
    }

    t2 = high_resolution_clock::now();
    duration = duration_cast<microseconds>(t2 - t1).count();

    cout << std::right << std::setw(8) << duration;

    cout << std::endl;

  }

  return 0;
}
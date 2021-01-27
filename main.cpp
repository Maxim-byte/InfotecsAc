#include <chrono>
#include <iostream>
#include "globalVar.hpp"
#include "quickSort.hpp"

int main()
{
  randomFill(gromov::array, gromov::SIZE);
  //std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now(); тестирование производительности
  quickSort(gromov::array, 0, gromov::SIZE);
  //std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();  тестирование производительности
  //auto duration = duration_cast<std::chrono::seconds>( t2 - t1 ).count(); тестирование производительности
  //std::cout << duration; тестирование производительности
  return 0;
}

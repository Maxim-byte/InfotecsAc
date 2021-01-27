#ifndef ALGO_QUICKSORT_HPP
#define ALGO_QUICKSORT_HPP

#include <utility>
#include <ostream>
#include <functional>
#include <random>

int pivot(int i, int j)
{
  return ((i + j) / 2);
}

template <class T>
void quickSort(T *values, int low, int high)
{
  int start;
  int end;
  T k;
  int p;


  if (low < high)
  {
    p = pivot(low, high);
    std::swap(values[low], values[p]);
    k = values[low];
    start = (low + 1);
    end = high;

    while (start <= end)
    {
      while ((start <= high) && (values[start] <= k))
      {
        start++;
      }
      while ((end >= low) && (values[end] > k))
      {
        end--;
      }
      if (start < end)
      {
        std::swap(values[start], values[end]);
      }
    }
    std::swap(values[low], values[end]);
    quickSort(values, low, (end - 1));
    quickSort(values, (end + 1), high);
  }
}

template <class T>
void printArray(T * array, long long size, std::ostream & out)
{
  for (auto i = 0; i < size; ++i)
  {
    out << std::fixed << array[i] << '\n';
  }
}

template <class T>
void randomFill(T * array, const long long size)
{
  std::random_device device;
  std::mt19937 generator;
  generator.seed(device());
  std::uniform_real_distribution<T> distribution(LONG_MIN, LONG_MAX);
  for(auto i = 0; i < size; ++i)
  {
    array[i] = distribution(generator);
  }

}

#endif

/*
Given a list of numbers. Determine how many elements in this list are greater
than their two neighbors. Output the number of such elements.

Input: A list of numbers is entered. All numbers in the list are on one line.

Output: Print a count
*/
#include "iostream"
#include <vector>

int main() {
  int num;
  std::vector<int> arr;
  while (std::cin >> num) {
    arr.push_back(num);
  }
  int count = 0;
  for (int i = 1; i < arr.size() - 1; ++i) {
    if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
      count++;
    }
  }
  std::cout << count;
  return 0;
}

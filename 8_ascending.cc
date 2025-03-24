/*
Given a list, determine whether it is monotonically increasing (i.e., is it
true that each element of this list is strictly greater than the previous one).

Print YES if the array is monotonically increasing and NO otherwise.
*/
#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec;
  int num;
  while (std::cin >> num) {
    vec.push_back(num);
  }
  int temp = vec[0];
  int flag = 0;
  for (int i = 1; i < vec.size(); ++i) {
    if (vec[i] > temp) {
      temp = vec[i];
    } else {
      flag = 1;
      break;
    }
  }
  if (flag == 0) {
    std::cout << "YES";
  } else {
    std::cout << "NO";
  }
  return 0;
}

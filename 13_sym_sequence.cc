#include <iostream>
#include <vector>

void print(const std::vector<int> &vec) {
  for (int i = 0; i < vec.size(); ++i) {
    if (i == vec.size() - 1) {
      std::cout << vec[i];
    } else {
      std::cout << vec[i] << " ";
    }
  }
}

int main() {
  int num;
  std::vector<int> vec;
  std::vector<int> temp_vec;
  std::cin >> num;
  for (int i = 0; i < num; ++i) {
    int value;
    std::cin >> value;
    vec.push_back(value);
  }

  // - - - - - - - - - - - - -
  bool is_sym = true;
  for (int i = 0; i < num; ++i) {
    if (i == num - i - 1) {
      break;
    }
    if (vec[i] != vec[num - i - 1]) {
      is_sym = false;
      break;
    }
  }
  // - - - - - - - - - - - - -

  if (is_sym) {
    std::cout << "0" << std::endl;
    return 0;
  }

  int full_num;
  if (vec[num - 1] == vec[num - 2]) {
    full_num = num + num - 2;
  } else {
    full_num = num + num - 1;
  }
  for (int i = vec.size(); i < full_num; ++i) {
    temp_vec.push_back(vec[full_num - i - 1]);
  }
  std::cout << full_num - num << std::endl;
  print(temp_vec);
  return 0;
}

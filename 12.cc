#include <cmath>
#include <iostream>
#include <vector>

int main() {
  int num;
  std::cin >> num;

  std::vector<int> vec(num);
  for (int i = 0; i < vec.size(); ++i) {
    std::cin >> num;
    vec[i] = num;
  }
  int x;
  std::cin >> x;
  x = fabs(x);
  int diff = fabs(x - vec[0]);
  int res = vec[0];
  for (int i = 1; i < vec.size(); ++i) {
    if (fabs(x - vec[i]) < diff) {
      diff = fabs(x - vec[i]);
      res = vec[i];
    }
  }
  std::cout << res;
  return 0;
}

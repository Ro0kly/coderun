/*
 *Three natural numbers are given. Is it possible to construct a triangle with
 *such sides? If it is possible, output the string YES, otherwise output the
 *string NO.

 Input: Three natural numbers.

 Output: "YES" / "NO"
 */
#include "iostream"

int main() {
  int a, b, c;
  std::cin >> a >> b >> c;
  if (a + b > c && a + c > b && b + c > a) {
    std::cout << "YES";
  } else {
    std::cout << "NO";
  }
  return 0;
}

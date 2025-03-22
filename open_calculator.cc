/*
 The new OpenCalculator program has a new feature - you can configure which
buttons are displayed and which are not. If a button is not displayed on the
screen, then you cannot enter the corresponding number from the keyboard or copy
it from another program. Petya has configured the calculator so that it displays
only buttons with the numbers x, y, z. Write a program that determines whether
Petya can enter the number N, and if not, what is the minimum number of buttons
that must be additionally displayed on the screen for its entry.

Input: First, three different numbers from 0 to 9 are entered: x, y and z (the
numbers are separated by spaces). Next, an integer non-negative number N is
entered that Petya wants to enter into the calculator. The number N does not
exceed 10000.

Output: Print the minimum number of buttons that must be added to be able to
enter the number N (if the number can be entered using the existing buttons,
print 0)
*/
#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec;
  int v;
  while (std::cin >> v) {
    if (vec.size() == 3) {
      break;
    }
    vec.push_back(v);
  }
  int count = 0;
  while (v != 0) {
    int num = v % 10;
    for (int i = 0; i < vec.size(); ++i) {
      if (vec[i] == num) {
        break;
      }
      if (i == vec.size() - 1) {
        vec.push_back(num);
        count++;
      }
    }
    v /= 10;
  }
  std::cout << count;
  return 0;
}

/*
Lena really likes number theory. Last time she asked the season participants to
guess the Euler function. Unfortunately, for some users this task was too
difficult, so Lena came up with an easier one.

You are given 2 natural numbers aa and bb. You need to calculate GCD(a, b) and
LCM(a, b).

Input: The only input line contains two numbers − a,b(1≤a,b≤10^9).
Output: 2 integers − GCD(a,b) and LCM(a,b).

Example Input:
20 8
Example Output:
4 40

Example Input:
5 15
Example Output:
5 15
*/
#include <iostream>

int main() {
  long long a, b;
  std::cin >> a >> b;
  long long a_ = a, b_ = b;
  while (a_) {
    std::swap(a_, b_);
    a_ %= b_;
  }
  std::cout << b_ << " " << (a / b_) * b;
  return 0;
}

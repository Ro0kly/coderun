/*You are given a quadratic equation of the form: ax^2+bx+c=0,
where a, b, and c are integers such that a≠0.

Write a program that solves this equation.

Input: The only line of input contains three integers a, b, c
(−10^3≤a,b,c≤10^3−10^3≤a,b,c≤10^3, a≠0).

Output: In the first line, output the number of real roots of the equation.

In the second line, output the roots themselves. If the equation has two roots,
print them separated by a space in ascending order. If there is only one root,
print it. If there are no roots, do not output anything. Your answer will be
accepted if the entered numbers differ from the correct answers by no more than
10^−6.
*/
#include "iostream"

#include <cmath>
#include <iomanip>

double find_x(double a, double b, double c, double discr, bool positive) {
  double res = 0;
  if (positive) {
    return res = (-b + std::sqrt(discr)) / (2 * a);
  } else {
    return res = (-b - std::sqrt(discr)) / (2 * a);
  }
}

int main() {
  double a, b, c;
  std::cin >> a >> b >> c;
  double discr = pow(b, 2) - 4 * a * c;
  double res1 = 0;
  double res2 = 0;
  int count = 0;
  if (discr > 0) {
    res1 = find_x(a, b, c, discr, true);
    res2 = find_x(a, b, c, discr, false);
    count = 2;
    std::cout << count << std::endl;
    std::cout << std::fixed << std::setprecision(6) << res2 << " " << res1;
  } else if (discr == 0) {
    res1 = -b / (2 * a);
    count = 1;
    std::cout << count << std::endl;
    std::cout << res1;
  } else {
    count = 0;
    std::cout << count;
  }
  return 0;
}

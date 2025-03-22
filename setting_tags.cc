/*
 Most problems in the CodeRun season have tags that help users choose the
appropriate algorithm to solve them. It is known that for the first and second
tasks of each track, the number of tags is 1 (t[1]=t[2]=1t[1]=t[2]=1). For all
subsequent tasks, the number of tags is calculated using the following rule:

t[i]=t[i−1]+t[i−2];

Where t[i]t[i] is the number of tags for the task with number ii.

It has been determined that it takes one second to assign one tag. Calculate the
total time required to assign all the tags.

Input: n as integer, 1 <= n <= 35;

Output: one integer - sum of t[i];
*/
#include "iostream"

int fibo(int num) {
  if (num == 0) {
    return 0;
  }
  if (num == 1) {
    return 1;
  }

  int prev2 = 0;
  int prev1 = 1;
  int cur = 0;
  int sum = 1;
  for (int i = 2; i <= num; ++i) {
    cur = prev1 + prev2;
    prev2 = prev1;
    prev1 = cur;
    sum += cur;
  }
  return sum;
}
// 0 1 2 3 4 5 6 7
// 0 1 1 2 3 5 8 13
int main() {
  int n;
  std::cin >> n;
  int f = fibo(n);
  std::cout << f;
  return 0;
}

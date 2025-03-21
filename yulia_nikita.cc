#include "iostream"
/*
 Preparing tasks for the season is a long and painstaking process. Yulia knows
 that A tasks are already ready. Nikita found out that B more tasks are almost
 ready and will be added to the season soon. Help Yulia and Nikita find out how
 many tasks are planned for the season.

Input: The first line contains two numbers A and B (0≤A,B≤2*10^18),
separated by a space.

Output: one number − A+B − the total number of tasks in the season.
*/
int main() {
  long long a, b;
  std::cin >> a >> b;
  std::cout << a + b;
  return 0;
}

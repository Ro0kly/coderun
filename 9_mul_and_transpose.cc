/*
 Children from the SOSC (School Olympiad Solvers Club) association are preparing
to participate in the ML track. They decided to start their preparation by
studying linear algebra. It turned out that there are two interesting operations
on matrices - multiplication and transposition. They have compiled many examples
and are solving them on a piece of paper, but they need help checking the
results. Write a program that, given matrices A and B, calculates: (A×B)^T,
where A is a matrix of size n×m, and B is a matrix of size m×k.

Input:
n m k
matrix 1
matrix 2

Input Example:
2 1 3
0
2
1 2 8

Output Example:
0 2
0 4
0 16
*/

#include <iostream>
#include <vector>
void print(const std::vector<std::vector<int>> &mat) {
  for (int i = 0; i < mat.size(); ++i) {
    for (int j = 0; j < mat[i].size(); ++j) {
      if (j == mat[i].size() - 1) {
        std::cout << mat[i][j];
      } else {
        std::cout << mat[i][j] << " ";
      }
    }
    if (i != mat.size() - 1) {
      std::cout << std::endl;
    }
  }
}
int main() {
  int n, m, k;
  std::cin >> n;
  std::cin >> m;
  std::cin >> k;
  std::vector<std::vector<int>> mat1(n, std::vector<int>(m));
  std::vector<std::vector<int>> mat2(m, std::vector<int>(k));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      std::cin >> mat1[i][j];
    }
  }
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < k; ++j) {
      std::cin >> mat2[i][j];
    }
  }

  std::vector<std::vector<int>> mat_mul(n, std::vector<int>(k));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < k; ++j) {
      for (int col = 0; col < m; ++col) {
        mat_mul[i][j] += mat1[i][col] * mat2[col][j];
      }
    }
  }

  std::vector<std::vector<int>> mat_res(k, std::vector<int>(n));
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < n; ++j) {
      mat_res[i][j] = mat_mul[j][i];
    }
  }

  print(mat_res);
  return 0;
}

/*
The input file contains text. A word is a sequence of non-space characters in a
row, words are separated by one or more spaces or end-of-line characters.
Determine how many different words are contained in this text.

Input: Text is entered.

Output: Output the answer to the problem.
*/

#include <fstream>
#include <iostream>
#include <set>
#include <string>

int main() {
  std::ifstream inputFile("7_input.txt");
  if (!inputFile.is_open()) {
    std::cerr << "Can not open file" << std::endl;
    return 1;
  }
  std::string str;
  std::set<std::string> set;
  while (inputFile >> str) {
    set.insert(str);
  }
  std::cout << set.size();
  return 0;
}

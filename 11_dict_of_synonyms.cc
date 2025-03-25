/*
You are given a dictionary consisting of pairs of words. Each word is a synonym
for its paired word. All words in the dictionary are different. For one given
word, determine its synonym. Input: The program receives as input the number of
pairs of synonyms N. Then follow NN lines, each line contains exactly two
words-synonyms. After that follows one word. Output: The program must output a
synonym for the given word.

Example Input:
3
Hello Hi
Bye Goodbye
List Array
Goodbye

Example Output:
Bye

---
Example Input:
2
Ololo Ololo
Numbers 1234567890
Numbers

Example Output:
1234567890
*/
#include <iostream>
#include <map>
#include <string>

using namespace std;
int main() {
  int num;
  cin >> num;
  map<string, string> m;
  for (int i = 0; i < num; ++i) {
    string key;
    string value;
    cin >> key >> value;
    m.insert({key, value});
  }
  string target;
  cin >> target;
  int flag = 0;
  for (const auto &pair : m) {
    if (pair.second == target) {
      cout << pair.first;
      flag = 1;
      break;
    }
  }
  if (flag == 0) {
    auto iter = m.find(target);
    if (iter != m.end()) {
      cout << iter->second;
    }
  }
  return 0;
}

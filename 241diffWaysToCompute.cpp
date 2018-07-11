#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;
class Solution {
public:
  vector<int> diffWaysToCompute(string input) {
    vector<int> res;
    for (int i = 0; i < input.length(); i++) {
      char ch = input[i];
      if (ch == '+' || ch == '-' || ch == '*') {
        vector<int> left = diffWaysToCompute(input.substr(0, i));
        vector<int> right = diffWaysToCompute(input.substr(i + 1));
        for (int l : left) {
          for (int r : right) {
            switch (ch) {
            case '+':
              res.push_back(l + r);
              break;
            case '-':
              res.push_back(l - r);
              break;
            case '*':
              res.push_back(l * r);
              break;
            }
          }
        }
      }
    }
    if(res.empty()) res.push_back(atoi(input.c_str()));
    return res;
  }
};
int main() {
  vector<int> ress = Solution().diffWaysToCompute("2-1-1");
  for (int r : ress)
    cout << r << endl;
}

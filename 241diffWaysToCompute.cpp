
// 给定一个含有数字和运算符的字符串，为表达式添加括号，改变其运算优先级以求出不同的结果。
//你需要给出所有可能的组合的结果。有效的运算符号包含 +, - 以及 * 。

// 示例 1:

// 输入: "2-1-1"
// 输出: [0, 2]
// 解释: 
// ((2-1)-1) = 0 
// (2-(1-1)) = 2
// 示例 2:

// 输入: "2*3-4*5"
// 输出: [-34, -14, -10, -10, 10]
// 解释: 
// (2*(3-(4*5))) = -34 
// ((2*3)-(4*5)) = -14 
// ((2*(3-4))*5) = -10 
// (2*((3-4)*5)) = -10 
// (((2*3)-4)*5) = 10

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

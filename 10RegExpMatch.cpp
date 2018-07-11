#include <iostream>
#include <string>
using namespace std;
static const auto _____ = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();
class Solution {
public:
  bool match_sub(string &s, string &p, unsigned long i, unsigned long j) {
    for (; j < p.length() && p[j + 1] != '*'; ++i, ++j) {
      if (i >= s.length() || (s[i] != p[j] && p[j] != '.'))
        return false;
    }
    if (j >= p.length())
      return i >= s.length();
    if (i < s.length() && (s[i] == p[j] || p[j] == '.')) {
      return match_sub(s, p, i + 1, j) || match_sub(s, p, i, j + 2);
    } else
      return match_sub(s, p, i, j + 2);
  }
  bool isMatch(string s, string p) {
    if (p.empty())
      return s.empty();
    unsigned long i = 0, j = 0;
    return match_sub(s, p, i, j);
  }
};
int main() {
  string s = "aaa";
  string p = "ab*a*c*a";
  cout << Solution().isMatch(s, p) << endl;
}

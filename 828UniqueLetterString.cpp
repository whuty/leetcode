#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
  int UniqueLetterString(string s) {
    std::map<char, vector<long>> map;
    for (long i = 0; i < s.length(); i++) {
      char c = s[i];
      map[c].push_back(i);
    }
    unsigned long ans = 0;
    for (pair<char, vector<long>> p : map) {
      vector<long> v = p.second;
      for (long i = 0; i < v.size(); i++) {
        long prev = i > 0 ? v[i - 1] : -1;
        long next = i < v.size() - 1 ? v[i + 1] : s.length();
        ans += (v[i] - prev) * (next - v[i]);
      }
    }
    return (int)ans % 1000000007;
  }
};
int main() {
  string s = "ABC";
  cout << Solution().UniqueLetterString(s) << endl;
}

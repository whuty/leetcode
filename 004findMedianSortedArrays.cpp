
// 给定两个大小为 m 和 n 的有序数组 nums1 和 nums2 。

// 请找出这两个有序数组的中位数。要求算法的时间复杂度为 O(log (m+n)) 。

// 示例 1:

// nums1 = [1, 3]
// nums2 = [2]

// 中位数是 2.0
// 示例 2:

// nums1 = [1, 2]
// nums2 = [3, 4]

// 中位数是 (2 + 3)/2 = 2.5

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;
static const auto _____ = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();
class Solution {

public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int n = nums1.size();
    int m = nums2.size();
    if (n > m)
      return findMedianSortedArrays(nums2, nums1);
    int L1, L2, R1, R2, c1, c2, lo = 0, hi = 2 * n;
    while (lo <= hi) {
      c1 = (lo & hi) + ((lo ^ hi) >> 1); // c1=(lo+hi)/2;
      c2 = m + n - c1;
      L1 = (c1 == 0) ? INT_MIN : nums1[(c1 - 1) / 2];
      R1 = (c1 == 2 * n) ? INT_MAX : nums1[c1 / 2];
      L2 = (c2 == 0) ? INT_MIN : nums2[(c2 - 1) / 2];
      R2 = (c2 == 2 * m) ? INT_MAX : nums2[c2 / 2];

      if (L1 > R2)
        hi = c1 - 1;
      else if (L2 > R1)
        lo = c1 + 1;
      else
        break;
    }
    return (max(L1, L2) + min(R1, R2)) / 2.0;
  }
};
int main() {
  vector<int> nums1 = {1, 3};
  vector<int> nums2 = {2, 4, 5, 7};
  cout << Solution().findMedianSortedArrays(nums1, nums2) << endl;
}

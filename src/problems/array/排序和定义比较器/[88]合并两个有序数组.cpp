/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

//给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1
//成为一个有序数组。
//
// 初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。你可以假设 nums1
// 的空间大小等于 m + n，这样它就有足够的空间保存来自 nu
// ms2 的元素。
//
//
//
// 示例 1：
//
//
//输入：nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
//输出：[1,2,2,3,5,6]
//
//
// 示例 2：
//
//
//输入：nums1 = [1], m = 1, nums2 = [], n = 0
//输出：[1]
//
//
//
//
// 提示：
//
//
// nums1.length == m + n
// nums2.length == n
// 0 <= m, n <= 200
// 1 <= m + n <= 200
// -109 <= nums1[i], nums2[i] <= 109
//
// Related Topics 数组 双指针
// 👍 970 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include <vector>
using std::vector;

/// 排序 merge
// 为了不开辟空间，从右至左进行 merge
class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    // nums1
    int i = m - 1;
    // nums2
    int j = n - 1;
    // 轮次
    int target = i + j + 1;
    while (target >= 0) {
      if (i < 0 && j >= 0) {
        nums1[target--] = nums2[j--];
      } else if (j < 0 && i >= 0) {
        break;
      } else if (nums1[i] <= nums2[j]) {
        nums1[target--] = nums2[j--];
      } else {
        nums1[target--] = nums1[i--];
      }
    }
  }
};
// leetcode submit region end(Prohibit modification and deletion)

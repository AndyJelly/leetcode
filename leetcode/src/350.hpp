#pragma once
/*
350. 两个数组的交集 II
给定两个数组，编写一个函数来计算它们的交集。

示例 1：
输入：nums1 = [1,2,2,1], nums2 = [2,2]
输出：[2,2]

示例 2:
输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出：[4,9]

说明：

输出结果中每个元素出现的次数，应与元素在两个数组中出现次数的最小值一致。
我们可以不考虑输出结果的顺序。
*/

#include <vector>
#include <unordered_map>

class Solution_350
{
public:
	std::vector<int> intersect(
		std::vector<int>& nums1, 
		std::vector<int>& nums2)
	{
		std::unordered_map<int,int> map_record;
		for (std::vector<int>::size_type i = 0; i < nums1.size(); ++i)
		{
			// 记录每个元素出现的次数
			map_record[nums1[i]] ++;
		}

		std::vector<int> vec_result;
		for (std::vector<int>::size_type i = 0; i < nums2.size(); ++i)
		{
			if (map_record[nums2[i]] > 0)
			{
				// 找到相同的元素，并将出现频率
				vec_result.push_back(nums2[i]);
				map_record[nums2[i]] --;
			}
		}

		return vec_result;
	}
};

/*
方法二：排序 + 双指针
如果两个数组是有序的，则可以使用双指针的方法得到两个数组的交集。

首先对两个数组进行排序，然后使用两个指针遍历两个数组。

初始时，两个指针分别指向两个数组的头部。每次比较两个指针指向的两个数组中的数字，如果两个数字不相等，则将指向较小数字的指针右移一位，如果两个数字相等，将该数字添加到答案，并将两个指针都右移一位。当至少有一个指针超出数组范围时，遍历结束。

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/intersection-of-two-arrays-ii/solution/liang-ge-shu-zu-de-jiao-ji-ii-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

#include<algorithm>
class Solution {
public:
	std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
		std::sort(nums1.begin(), nums1.end());
		std::sort(nums2.begin(), nums2.end());
		int length1 = nums1.size(), length2 = nums2.size();
		std::vector<int> intersection;
		int index1 = 0, index2 = 0;
		while (index1 < length1 && index2 < length2) {
			if (nums1[index1] < nums2[index2]) {
				index1++;
			}
			else if (nums1[index1] > nums2[index2]) {
				index2++;
			}
			else {
				intersection.push_back(nums1[index1]);
				index1++;
				index2++;
			}
		}
		return intersection;
	}
};
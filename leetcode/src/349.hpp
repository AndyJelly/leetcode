#pragma once
//349. 两个数组的交集

/*
给定两个数组，编写一个函数来计算它们的交集。
示例 1：
输入：nums1 = [1,2,2,1], nums2 = [2,2]
输出：[2]
示例 2：
输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出：[9,4]
 
说明：
输出结果中的每个元素一定是唯一的。
我们可以不考虑输出结果的顺序。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/intersection-of-two-arrays
*/

#include <vector>
#include <set>
#include <unordered_set>

class Solution_349
{
public:
	std::vector<int> intersection(
		std::vector<int>& nums1, 
		std::vector<int>& nums2)
	{
		std::unordered_set<int> record(nums1.begin(), nums1.end());

		std::unordered_set<int> result;
		for (auto& it : nums2)
		{
			if (record.end() != record.find(it))
			{
				result.insert(it);
			}
		}

		std::vector<int> vec_result(result.begin(), result.end());

		return std::move(vec_result);
	}
};

// 解法二
// 1、对两个数组进行排序
// 2、两个指针分别指向，两个数组的头，另一个指针，指向上一个相同的值
// 3、两个指向头的指针，分别向后走，判断两个值是否相等，并且不等于上一个相同的值
// 4、指向小数的指针，向后移一位
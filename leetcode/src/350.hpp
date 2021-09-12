#pragma once
/*
350. ��������Ľ��� II
�����������飬��дһ���������������ǵĽ�����

ʾ�� 1��
���룺nums1 = [1,2,2,1], nums2 = [2,2]
�����[2,2]

ʾ�� 2:
���룺nums1 = [4,9,5], nums2 = [9,4,9,8,4]
�����[4,9]

˵����

��������ÿ��Ԫ�س��ֵĴ�����Ӧ��Ԫ�������������г��ִ�������Сֵһ�¡�
���ǿ��Բ�������������˳��
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
			// ��¼ÿ��Ԫ�س��ֵĴ���
			map_record[nums1[i]] ++;
		}

		std::vector<int> vec_result;
		for (std::vector<int>::size_type i = 0; i < nums2.size(); ++i)
		{
			if (map_record[nums2[i]] > 0)
			{
				// �ҵ���ͬ��Ԫ�أ���������Ƶ��
				vec_result.push_back(nums2[i]);
				map_record[nums2[i]] --;
			}
		}

		return vec_result;
	}
};

/*
������������ + ˫ָ��
�����������������ģ������ʹ��˫ָ��ķ����õ���������Ľ�����

���ȶ����������������Ȼ��ʹ������ָ������������顣

��ʼʱ������ָ��ֱ�ָ�����������ͷ����ÿ�αȽ�����ָ��ָ������������е����֣�����������ֲ���ȣ���ָ���С���ֵ�ָ������һλ���������������ȣ�����������ӵ��𰸣���������ָ�붼����һλ����������һ��ָ�볬�����鷶Χʱ������������

���ߣ�LeetCode-Solution
���ӣ�https://leetcode-cn.com/problems/intersection-of-two-arrays-ii/solution/liang-ge-shu-zu-de-jiao-ji-ii-by-leetcode-solution/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
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
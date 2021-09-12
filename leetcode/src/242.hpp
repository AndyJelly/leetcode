/*
242. ��Ч����ĸ��λ��
���������ַ��� s �� t ����дһ���������ж� t �Ƿ��� s ����ĸ��λ�ʡ�

ʾ�� 1:
����: s = "anagram", t = "nagaram"
���: true

ʾ�� 2:
����: s = "rat", t = "car"
���: false
˵��:
����Լ����ַ���ֻ����Сд��ĸ��

����:
��������ַ������� unicode �ַ���ô�죿���ܷ������Ľⷨ��Ӧ�����������
*/

#include<string>
#include <unordered_map>


class Solution {
public:
	bool isAnagram(std::string s, std::string t) 
	{
		if (s.size() != t.size())
		{
			return false;
		}

		std::unordered_map<char,int> set_char;
		for (size_t index = 0 ; index < s.size(); ++index)
		{
			auto ifind = set_char.find(s[index]);
			if (set_char.end() == ifind)
			{
				set_char.insert(std::make_pair(s[index],1));
			}
			else
			{
				ifind->second++;
			}
		}

		for (size_t index = 0; index < t.size(); ++index)
		{
			auto ifind = set_char.find(t[index]);
			if (set_char.end() == ifind)
			{
				return false;
			}

			if (ifind->second == 0)
			{
				return false;
			}

			ifind->second--;
		}

		return true;
	}
};

/*
����һ������
tt �� ss ����λ�ʵȼ��ڡ������ַ����������ȡ���������ǿ��Զ��ַ��� ss �� tt �ֱ����򣬿��������ַ����Ƿ���ȼ����жϡ����⣬��� ss �� tt �ĳ��Ȳ�ͬ��tt ��Ȼ���� ss ����λ��

���ߣ�LeetCode-Solution
���ӣ�https://leetcode-cn.com/problems/valid-anagram/solution/you-xiao-de-zi-mu-yi-wei-ci-by-leetcode-solution/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/

#include <algorithm>

class Solution {
public:
	bool isAnagram(std::string s, std::string t)
	{
// 		std::sort(s.begin(), s.end());
// 		std::sort(t.begin(), t.end());
// 
// 		return s == t;

		if (s.size() != t.size())
		{
			return false;
		}

		/* ����һ�����飬��¼�ַ�����ÿ���ַ����ֵĴ��� */
		char hash[26] = { 0 };
		for (int i = 0; s[i] != '\0'; ++i) {
			/* �����±�Ϊ 0 ʱ����Ӧ���ַ����е��ַ� a���������� */
			hash[s[i] - 'a']++;
			hash[t[i] - 'a']--;
		}

		for (int i = 0; i < 26; ++i) {
			if (hash[i] != 0) {
				return false;
			}
		}
	}
};
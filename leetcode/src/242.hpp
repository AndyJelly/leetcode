/*
242. 有效的字母异位词
给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

示例 1:
输入: s = "anagram", t = "nagaram"
输出: true

示例 2:
输入: s = "rat", t = "car"
输出: false
说明:
你可以假设字符串只包含小写字母。

进阶:
如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？
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
方法一：排序
tt 是 ss 的异位词等价于「两个字符串排序后相等」。因此我们可以对字符串 ss 和 tt 分别排序，看排序后的字符串是否相等即可判断。此外，如果 ss 和 tt 的长度不同，tt 必然不是 ss 的异位词

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/valid-anagram/solution/you-xiao-de-zi-mu-yi-wei-ci-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
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

		/* 构建一个数组，记录字符串中每个字符出现的次数 */
		char hash[26] = { 0 };
		for (int i = 0; s[i] != '\0'; ++i) {
			/* 数组下标为 0 时，对应该字符串中的字符 a，依次类推 */
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
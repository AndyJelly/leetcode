#pragma once
#include <string>

std::string LCS(std::string str1, std::string str2) 
{
	// write code here
	if (str1.empty() || str2.empty())
	{
		return "-1";
	}

	int len1 = str1.size();
	int len2 = str2.size();

	int* dp = new int[len2 + 1]();
	memset(dp, 0, sizeof(dp));

	int max_len = 0, start = 0;
	for (int i = 1; i <= len1; ++i)
	{
		int last = 0; //每次都要重新设置数组的初始值
		for (int j = 1; j <= len2; ++j)
		{
			int tmp = dp[j];
			if (str1[i - 1] == str2[j - 1])
			{
				dp[j] = last + 1;
			}
			else
			{
				dp[j] = 0;
			}
			last = tmp;

			if (dp[j] > max_len)
			{
				max_len = dp[j];
				start = i;
			}
		}
	}

	delete[len2 + 1] dp;

	if (max_len == 0)
	{
		return "-1";
	}

	return str1.substr(start - max_len, max_len);
}
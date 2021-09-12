/*
202. 快乐数
编写一个算法来判断一个数 n 是不是快乐数。

「快乐数」定义为：

对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
如果 可以变为  1，那么这个数就是快乐数。
如果 n 是快乐数就返回 true ；不是，则返回 false 。
*/

#include <vector>
#include <unordered_set>
class Solution {
public:
	bool isHappy(int n) {
		// 123
		// 1^2 + 2^2 + 3^2 = 1 + 4 + 9 = 13
		std::unordered_set<int> set_int;
		while (n != 1 && set_int.end() == set_int.find(n))
		{
			set_int.insert(n);
			n = GetNext(n);

		}
		return n == 1;
	}


	int GetNext(int n)
	{
		int sum = 0;
		while (n > 0)
		{
			int bit = n % 10;
			sum += bit * bit;
			n = n / 10;
		}
		return sum;
	}

};


/*
方法二：快慢指针法
通过反复调用 getNext(n) 得到的链是一个隐式的链表。隐式意味着我们没有实际的链表节点和指针，但数据仍然形成链表结构。起始数字是链表的头 “节点”，链中的所有其他数字都是节点。next 指针是通过调用 getNext(n) 函数获得。

意识到我们实际有个链表，那么这个问题就可以转换为检测一个链表是否有环。因此我们在这里可以使用弗洛伊德循环查找算法。这个算法是两个奔跑选手，一个跑的快，一个跑得慢。在龟兔赛跑的寓言中，跑的快的称为 “乌龟”，跑得快的称为 “兔子”。

不管乌龟和兔子在循环中从哪里开始，它们最终都会相遇。这是因为兔子每走一步就向乌龟靠近一个节点（在它们的移动方向上）。

*/
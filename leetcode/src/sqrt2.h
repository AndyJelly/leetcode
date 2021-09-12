#pragma once
#include <iostream>

const double EPSILON = 0.000000000000001;

double sqrt2() 
{
	double low = 1.4, high = 1.5;
	double mid = (low + high) / 2;

	int i_loop = 0;
	while (high - low > EPSILON) 
	{
		if (mid * mid > 2) 
		{
			high = mid;
		}
		else 
		{
			low = mid;
		}
		mid = (high + low) / 2;
		++i_loop;
	}

	std::cout << "Loop :" << i_loop << "\n";
	return mid;
}


template <class T>
T String2T(const std::string& str)
{
	if (str.empty())
	{
		T v = T();
		return v;
	}

	T v;
	std::stringstream ss(str);
	ss >> v;
	return v;
}

template <typename T>
void String2Arrary(
	std::vector<T>& vec,
	const std::string& str,
	char c_split = ',')
{
	vec.clear();
	size_t u_pre_index = 0;
	size_t u_index = 0;
	size_t u_len = 0;

	while ((u_index = str.find_first_of(c_split, u_pre_index)) != std::string::npos)
	{
		size_t u_copy_len = u_index - u_pre_index;
		if (u_copy_len != 0)
		{
			vec.push_back(String2T<T>(str.substr(u_pre_index, u_copy_len)));
		}
		u_pre_index = u_index + 1;
	}

	if (u_pre_index < str.size())
	{
		vec.push_back(String2T<T>(str.substr(u_pre_index)));
	}

}


bool KthNum(int& ret, std::vector<int>& vec1, std::vector<int>& vec2, const int K)
{
	// 参数校验

	size_t size_1 = vec1.size();
	size_t size_2 = vec2.size();

	if (K > size_1 + size_2)
	{
		return false;
	}

	std::vector<int> vec_ret;
	vec_ret.reserve(K);

	int i_index = 0;
	int j_index = 0;

	for (int i = i_index; i < size_1; ++i)
	{
		i_index = i;
		if (vec_ret.size() >= K)
		{
			break;
		}
		int j = j_index;
		for (; j < size_2; ++j)
		{
			if (vec1[i] < vec2[j])
			{
				vec_ret.push_back(vec1[i]);
				break;
			}
			else
			{
				vec_ret.push_back(vec1[j]);
				continue;
			}
		}

		j_index = j;

	}
	ret = vec_ret[K - 1];
	return true;

}

// nowcoder.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <algorithm>
#include <list>
#include <numeric>   
#include <iterator>
#include <vector>
#include <sstream>

using namespace std;

template <typename T>
class GetInputs
{
public:
	GetInputs()
		:iit_(std::cin)
	{
	}

	std::list<T> GetValues()
	{
		// 		while (eos_ != iit_)
		// 		{
		// 			list_Ts_.push_back(*iit_);
		// 			++iit_;
		// 		}
		std::copy(iit_, eos_, std::inserter(list_Ts_, list_Ts_.begin()));

		return std::move(list_Ts_);
	}

private:
	std::istream_iterator<T> eos_;
	std::istream_iterator<T> iit_;
	std::list<T> list_Ts_;
};



template <class T>
T String2T(const std::string& str)
{
	if (str.empty())
	{
		T v = T();
		return v;
	}

	T v;
	std::stringstream ss(str);
	ss >> v;
	return v;
}

template <typename T>
void String2Arrary(
	std::vector<T>& vec,
	const std::string& str,
	char c_split = ',')
{
	vec.clear();
	size_t u_pre_index = 0;
	size_t u_index = 0;
	size_t u_len = 0;

	while ((u_index = str.find_first_of(c_split, u_pre_index)) != std::string::npos)
	{
		size_t u_copy_len = u_index - u_pre_index;
		if (u_copy_len != 0)
		{
			vec.push_back(String2T<T>(str.substr(u_pre_index, u_copy_len)));
		}
		u_pre_index = u_index + 1;
	}

	if (u_pre_index < str.size())
	{
		vec.push_back(String2T<T>(str.substr(u_pre_index)));
	}

}

struct ListNode
{
	ListNode()
		:m_nKey(0)
		, m_pNext(nullptr)
	{
	}

	int       m_nKey;
	ListNode* m_pNext;
};


ListNode* GetKthNode(const std::vector<string>& list_inputs)
{
	if (list_inputs.size() != 3)
	{
		return nullptr;
	}
	int total_elem = String2T<int>(list_inputs.front());
	int k_th = String2T<int>(list_inputs.back());
	if (k_th > total_elem
		|| k_th <= 0
		|| total_elem <= 0)
	{
		return nullptr;
	}

	std::vector<int> list_nodes;
	String2Arrary(list_nodes, list_inputs[1], ' ');

	if (list_inputs.empty())
	{
		return nullptr;
	}

	// 头插法插入元素
	ListNode* p_head = new ListNode();
	p_head->m_nKey = list_nodes.front();
	ListNode* p_tail = p_head;
	for (int i = 0; i < list_nodes.size() - 1; ++i)
	{
		ListNode* new_node = new ListNode();
		p_tail->m_pNext = new_node;
		new_node->m_nKey = list_nodes[i + 1];
		p_tail = new_node;
	}
	p_tail->m_pNext = nullptr;

	ListNode* p_node = p_head;
	// 	while (p_node != nullptr)
	// 	{
	// 		std::cout << p_node->m_nKey << " ";
	// 
	// 		p_node = p_node->m_pNext;
	// 	}

	for (int i = 0; i < k_th; ++i)
	{
		p_node = p_node->m_pNext;
	}

	ListNode* q_node = p_head;
	while (p_node != nullptr)
	{
		q_node = q_node->m_pNext;
		p_node = p_node->m_pNext;
	}
	q_node = q_node->m_pNext;

	//std::cout << q_node->m_nKey;

	return q_node;

}


#if 1
int main()
{
	// 	std::istream_iterator<int> eos;
	// 	std::istream_iterator<int> iit;
	// 	std::vector<int> list_inputs;
	// 	std::copy(iit, eos, std::inserter(list_inputs, list_inputs.begin()));


	std::vector<string> vec_inputs;
	int i = 0;
	while (i < 3)
	{
		std::string inputs;
		std::getline(std::cin, inputs);
		vec_inputs.push_back(inputs);
		++i;
	}


	ListNode* q_node = GetKthNode(vec_inputs);
	std::cout << q_node->m_nKey << std::endl;

	// 
// 	int n;
// 	while (cin >> n)
// 	{
// 		ListNode* head = new ListNode;//头结点
// 		ListNode* p = head;
// 		for (int i = 0; i < n; i++)
// 		{
// 			int val = 0;
// 			ListNode* q = new ListNode;
// 			cin >> val;
// 			q->m_nKey = val;
// 			p->m_pNext = q;
// 			p = q;
// 		}
// 		//!!!!重要，最后一个next一定置为null
// 		p->m_pNext = NULL;
// 		int k = 0;
// 		cin >> k;
// 		p = head;
// 		ListNode* pp = head;
// 		if (k > 0)
// 		{
// 			while (k--)
// 			{
// 				p = p->m_pNext;
// 			}
// 			while (p->m_pNext != NULL) {
// 				p = p->m_pNext;
// 				pp = pp->m_pNext;
// 			}
// 			//这里由于从head开始，所以实际上是k+1个
// 			pp = pp->m_pNext;
// 			cout << pp->m_nKey << endl;
// 		}
// 		else if (k == 0)
// 		{
// 			cout << "0" << endl;
// 		}
// 
// 	}

	//getchar();

	return 0;

}
#endif


#if 0

#include<iostream>
using namespace std;
struct Node {
	int data;
	Node* next;
};
int main() {
	int n;
	while (cin >> n)
	{
		Node* head = new Node;//头结点
		Node* p = head;
		for (int i = 0; i < n; i++)
		{
			int val = 0;
			Node* q = new Node;
			cin >> val;
			q->data = val;
			p->next = q;
			p = q;
		}
		//!!!!重要，最后一个next一定置为null
		p->next = NULL;
		int k = 0;
		cin >> k;
		p = head;
		Node* pp = head;
		if (k > 0)
		{
			while (k--)
			{
				p = p->next;
			}
			while (p->next != NULL) {
				p = p->next;
				pp = pp->next;
			}
			//这里由于从head开始，所以实际上是k+1个
			pp = pp->next;
			cout << pp->data << endl;
		}
		else if (k == 0)
		{
			cout << "0" << endl;
		}

	}
	return 0;
}
#endif


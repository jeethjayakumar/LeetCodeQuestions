#include<iostream>
using namespace std;

template <class T>
class ListNode
{
	T val;
	ListNode *nxt;
public:
	ListNode(T val)
	{
		this->val = val;
		nxt = NULL;
	}

	~ListNode(){ }
};

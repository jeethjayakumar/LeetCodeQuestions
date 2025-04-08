#include "ListNode.h"
#include<climits>

class NewListNode : public ListNode
{
	public:
		NewListNode* random;
		int randomIdx;
		NewListNode(int num) : ListNode(num), random(nullptr), randomIdx(INT_MAX) {}
		NewListNode(int num, NewListNode* randptr) : ListNode(num), random(randptr), randomIdx(INT_MAX) {} 
		NewListNode(int num, NewListNode* randptr, NewListNode* next) : ListNode(num, next), random(randptr), randomIdx(INT_MAX) {}
		NewListNode(int num, int randIdx, NewListNode* next) : ListNode(num, next), random(nullptr), randomIdx(randIdx) {} 
};

#include "Testing.h"

vector<ListNode*> CreateLinkedList(vector<vector<int> >& inp)
{
	vector<ListNode*> outList(inp.size());
	for(int i = 0; i < inp.size(); i++)
	{
		ListNode* head = nullptr;
		ListNode* tmp = nullptr;
		for(auto n : inp[i])
		{
			ListNode* newNode = new ListNode(n);
			if (tmp == nullptr)
			{
				tmp = newNode;
				head = tmp;
			}
			else
			{
				tmp->next = newNode;
				tmp = tmp->next;
			}
		}
		outList[i] = head;
	}

	return outList;
}

void TestingMergeKSortedList(Solution& op)
{
	vector<vector<int> > inp1 = {{1,4,5},{1,3,4},{2,6}};
	vector<ListNode*> inp1List = CreateLinkedList(inp1);

	cout<<"Input Lists of linked list: "<<endl;
	for(int i = 0; i < inp1List.size(); i++)
	{
		cout<<"List "<<i<<" : ";
		op.DisplayList(inp1List[i]);
		cout<<endl;
	}

	ListNode* res = op.mergeKLists(inp1List);
	cout<<"Resultant List: ";
	op.DisplayList(res);
	cout<<endl;
}

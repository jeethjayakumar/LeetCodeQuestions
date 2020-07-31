/*
Leet Code 217:
	Given an array of integers, find if the array contains any duplicates.
	Your function should return true if any value appears at least twice in the array, 
	and it should return false if every element is distinct.
 */

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

// Approach Explanation : Sort the vector and then traverse through vector. If adjacent elements are same return true. If complete
// vector is traversed and no duplicate found, return false
bool findDup_approach1(vector<int> &A)
{
	sort(A.begin(), A.end());
	for(int i = 1; i < A.size(); i++)
	{
		if (A[i-1] == A[i]) return true;
	}

	return false;
}

// Approach Explanation: Traverse through the vector and put it in different datastructure. If we don't find the element in new datastructure, then add the element in new data structure. If the element is present in datastructure, return true. If complete vector has been traversed and then no duplicate element found, return false 

bool findDup_approach2(vector<int> &A)
{
	set<int> s;
	
	for (int i = 0; i < A.size(); i++)
	{
		if (s.find(A[i]) == s.end())
			s.insert(A[i]);
		else
			return true;
	}
	s.clear();
	
	return false;
}

int main()
{
	vector<int> A;
	
	A.push_back(1);
	A.push_back(2);
	A.push_back(3);
	A.push_back(4);
	A.push_back(1);

	cout<<"Duplicate Present in list: "<<findDup_approach2(A)<<endl;
	return 0;
}

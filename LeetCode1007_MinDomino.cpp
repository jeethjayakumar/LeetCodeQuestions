/* 
    LeetCode 1007: In a row of dominoes, A[i] and B[i] represent the top and bottom halves of the i-th domino.  
                   (A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)
		   We may rotate the i-th domino, so that A[i] and B[i] swap values.
		   Return the minimum number of rotations so that all the values in A are the same, or all the values in B are 
		   the same.
		   If it cannot be done, return -1.
 */ 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Approach Explanation: Go through the A and B sets and record the number of occurances in each count and also identify the number occurs in the same row. The count counter will give us the number needed for minimum Domino rotations needed.
int minSwap_approach1(vector<int> &A, vector<int> &B)
{
	int countA[7], countB[7], same[7], i, sum;
	
	for (i = 0; i < 7; i++)
		countA[i]=countB[i]=same[i]=0;

	for (i = 0; i < A.size(); i++)
	{
		countA[A[i]]++;
		countB[B[i]]++;
		if (A[i] == B[i]) same[A[i]]++;
	}

	for (i = 1; i < 7; i++)
	{
		sum = countA[i] + countB[i] - same[i];
		if (sum == A.size())
			return (A.size() - max(countA[i],countB[i]));
	}

	return -1;
}

// Approach Explanation: Take the first value in both A and B and identify the number of swaps needed in each sets. Minimum swaps in each turns will give us the minimum Domino swaps needed. 
int numSwap(int &num,vector<int> &A, vector<int> &B)
{
	int numSwap, i;
	numSwap = 0;
	for(i = 0; i < A.size(); i++)
	{
		if (A[i]!=num && B[i]!=num)
			return INT_MAX;
		if (A[i]!=num) numSwap++;
	}

	return numSwap;
}

int minSwap_approach2(vector<int> &A, vector<int> &B)
{
	int minSwap = min(numSwap(A[0], A, B), numSwap(B[0],A,B));
	minSwap = min(minSwap, numSwap(A[0],B,A));
	minSwap = min(minSwap, numSwap(B[0],B,A));
	return (minSwap == INT_MAX?-1:minSwap);
}

int main()
{
	vector<int> A, B;

	// Populating A set of dices
	A.push_back(2);
	A.push_back(1);
	A.push_back(2);
	A.push_back(4);
	A.push_back(2);
	A.push_back(2);

	// Populating B set of dices
	B.push_back(5);
	B.push_back(2);
	B.push_back(6);
	B.push_back(2);
	B.push_back(3);
	B.push_back(2);

	int dominoSwap = minSwap_approach2(A,B);

	cout<<"Minimum Domino Rotations Possible = "<<dominoSwap<<endl;

	return -1;
}

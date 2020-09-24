/*
	LeetCode - 1055 : Given two string source and targets, return the min number of subsequence of sources such that
			  their concatenation equal targets. If the task is impossible, return -1.
			  Example: i/p: source="abc", target="abcbc"
				   o/p: 2

				   i/p: source="abc", target="acdbc"
				   o/p: -1

				   i/p: source="xyz", target="xzyxz"
				   o/p: 3 
 */

#include <string>
#include <iostream>
using namespace std;

// Approach: First check if all chars in target is present in source. Find the longest subsequence in source to form target.

int shortestWay(string src, string target)
{
	int numSubSeq = 0, i, j;
	string remaining = target;

	while (remaining.length() > 0)
	{
		string subSeq;
		i = 0; j = 0;
		while (i < src.length()&& j < remaining.length())
		{
			if (src[i++] == remaining[j])
			{
				subSeq.append(1, remaining[j++]);
			}
		}
		
		if (subSeq.length() == 0) return -1;
		numSubSeq ++;

		remaining = remaining.substr(subSeq.length());
	}

	return numSubSeq;
}

int main()
{
	string source, target;

	source = "xyz";
	target = "xzyxz";
	cout<<"Source: "<<source<<", Target: "<<target<<endl;
	cout<<"Min Number of SubSequence to form a target string from source: "<<shortestWay(source, target)<<endl;
	return 0;
}

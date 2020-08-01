/*
 Leet Code 443:
 	Given an array of characters, compress it in-place.
 	The length after compression must always be smaller than or equal to the original array.
 	Every element of the array should be a character (not int) of length 1.
 	After you are done modifying the input array in-place, return the new length of the array.

 Follow up:
 	Could you solve it using only O(1) extra space?
 */

#include <iostream>
#include <vector>
using namespace std;

// Approach Explanation: I'm passing vector as reference. That way I'm updating the output in same input space, 
// therby not utilizing additional space. In the input vector, we traverse through vector with first character and find the 
// consecutive number of occurences. Once you identify next character, index counter gets updated after adding number of
// occurences and then i comes to j and the traversal continues for next character.
// Time Complexity = O(n) 

int compress(vector<char>& chars)
{
	int index = 0, i = 0, j = 0, k = 0;
	string tmp;
	while (i < chars.size())
	{
		j = i;
		while (j < chars.size() && chars[i]==chars[j])
			j++;
		chars[index++] = chars[i];
		if (j - i > 1)
		{
			tmp = to_string(j - i);
		        k = 0;	
			while(k < tmp.length())
			{
				chars[index++] = tmp[k++];
			}	
		}

		i  = j;
	}
	chars.erase(chars.begin()+index, chars.end());

	return index;
}

void display(vector<char> &chars)
{
	for (int i = 0; i < chars.size(); i++)
		cout<<chars[i];
	cout<<endl;
}

int main()
{
	vector<char> chars;
	int i;
	for (i = 0; i < 12; i++)
		chars.push_back('a');
	for(i = 0; i < 11; i++)
		chars.push_back('b');
	
	cout<<"Input: "; display(chars);

	cout<<"After String Compression, Size = "<<compress(chars)<<endl;

	cout<<"Output: "; display(chars);

	return 0;
}

#include "Testing.h"

void TestingPrefixSearch(Solution& op)
{
	vector<string> words = {"apple", "book", "banana", "bathroom", "batman", "cat", "batman"};
	string prefix = "bat";
	auto res = op.FindStringsForPrefix(words, prefix);

	cout << "Input list of words: ";
	for (auto s : words)
		cout << s << " ";
	cout << endl;
	cout << "List of words starts with prefix - " << prefix << " : ";
	for (auto s : res)
		cout << s << " ";
	cout << endl;
	
	prefix = "b";
	res = op.FindStringsForPrefix(words, prefix);
	cout << "List of words starts with prefix - " << prefix << " : ";
	for (auto s : res)
		cout << s << " ";
	cout << endl;
}

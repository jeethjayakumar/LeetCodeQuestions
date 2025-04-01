#include "Testing.h"

void PrintWordList(vector<string> wlist)
{
	for(auto item : wlist)
		cout<<item<<" - ";
}
void TestingWordLadder(Solution& op)
{
	string beginWord = "hit", endWord = "cog";
	vector<string> wordList1 = {"hot", "dot", "dog", "lot", "log", "cog"};
	cout<<"Begining Word: "<<beginWord<<", Ending Word: "<<endWord<<", Word List: ";
	PrintWordList(wordList1);
	cout<<endl;
	auto res = op.ladderLength(beginWord, endWord, wordList1);
	cout<<"Number of words in the shortest transformation sequence from "<<beginWord<<" to "<<endWord<<" based on wordList1 = "<<res<<endl;

	vector<string> wordList2 = {"hot", "dot", "dog", "lot", "log"};
	cout<<"Begining Word: "<<beginWord<<", Ending Word: "<<endWord<<", Word List: ";
	PrintWordList(wordList2);
	cout<<endl;
	res = op.ladderLength(beginWord, endWord, wordList2);
	cout<<"Number of words in the shortest transformation sequence from "<<beginWord<<" to "<<endWord<<" based on wordList2 = "<<res<<endl;
}

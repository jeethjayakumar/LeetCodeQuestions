#include "Solution.h"

class Testing
{
	private:
		Solution op;
	public:
		void ExecuteOperation(int& choice);

};

template<class T> void PrintInputMatrix(vector<vector<T> >& inp);
void TestingWordLadder(Solution& op);
void TestingSurroundedRegion(Solution& op);

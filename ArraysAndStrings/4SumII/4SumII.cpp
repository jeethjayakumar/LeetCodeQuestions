/*
 * Given four integer arrays nums1, nums2, nums3, and nums4 all of length n, return the number of tuples (i, j, k, l) such that:
 * a) 0 <= i, j, k, l < n
 * b) nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
 * 
 * Example 1:
 * Input: nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
 * Output: 2
 * Explanation:
 * The two tuples are:
 * 1. (0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) + (-1) + 2 = 0
 * 2. (1, 1, 0, 0) -> nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) + (-1) + 0 = 0
 *
 * Example 2:
 * Input: nums1 = [0], nums2 = [0], nums3 = [0], nums4 = [0]
 * Output: 1
 *
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
	public:
		int fourSumCount(vector<int>& nums1 , vector<int>& nums2, vector<int>& nums3, vector<int>& nums4)
		{
			if (nums1.size()!= nums2.size() ||
			    nums1.size()!= nums3.size() ||
			    nums1.size()!= nums4.size())
				return 0;

			int count = 0;
			unordered_map<int, int> sumCount;

			for(auto num1 : nums1)
			{
				for(auto num2 : nums2)
				{
					sumCount[num1 + num2]++;
				}
			}

			for (auto num3: nums3)
			{
				for(auto num4: nums4)
				{
					auto it = sumCount.find(-(num3 + num4));
					if (it != sumCount.end())
					{
						count += it->second;
					}
				}
			}

/*			int count = 0;
			int i, j, k, l;
			int num1Size = nums1.size();
			int num2Size = nums2.size();
			int num3Size = nums3.size();
			int num4Size = nums4.size();

			for (i = 0; i < num1Size; i++)
			{
				for (j = 0; j < num2Size; j++)
				{
					for (k = 0; k < num3Size; k++)
					{
						for (l = 0; l < num4Size; l++)
						{
							if (nums1[i]+nums2[j]+nums3[k]+nums4[l] == 0)
								count++;
						}
					}
				}
			}



			vector<vector<int> > inpMatrix(4*nums1.size());

			inpMatrix.push_back(nums1);
			inpMatrix.push_back(nums2);
			inpMatrix.push_back(nums3);
			inpMatrix.push_back(nums4);

			for (int i = 0; i < 4; i++)
			{
				int sum = inpMatrix[i][0];
				for (int 
			}

*/
			return count;
		}
};

int main()
{
/*	vector<int> nums1 = {1, 2};
	vector<int> nums2 = {-2, -1};
	vector<int> nums3 = {-1, 2};
	vector<int> nums4 = {0, 2};
*/

	vector<int> nums1 = {-268435395,-268434951,-268434508,-268435111,-268434533,-268435396,-268435016,-268435450,-268434826,-268435366,-268434495,-268434908,-268435448,-268435166,-268435287,-268434641,-268435255,-268434603,-268434690,-268435275,-268434907,-268434695,-268435122,-268435204,-268435113,-268435127,-268434820,-268435204,-268434912,-268435236,-268435107,-268434480,-268434729,-268434650,-268434669,-268434811,-268435132,-268435168,-268434831,-268435421,-268435210,-268434517,-268434941,-268435359,-268435407,-268435221,-268434920,-268435133,-268434573,-268435207,-268435190,-268434989,-268434815,-268434581,-268435206,-268434541,-268435185,-268435393,-268435435,-268434969,-268434962,-268434461,-268435041,-268435150,-268435294,-268434508,-268435381,-268435327,-268434874,-268434571,-268435046,-268434768,-268435287,-268434663,-268434626,-268434533,-268434921,-268435100,-268434519,-268434494,-268434712,-268434671,-268434823,-268435422,-268435006,-268434471,-268434667,-268435168,-268435089,-268434910,-268435173,-268435388,-268434956,-268435127,-268435026,-268434780,-268434572,-268435343,-268435180,-268434596};
vector<int> nums2 = {-268434819,-268434987,-268435256,-268434981,-268434460,-268435123,-268435195,-268435278,-268435355,-268435190,-268435064,-268435364,-268435136,-268434666,-268435266,-268434498,-268435350,-268434600,-268435172,-268434993,-268434656,-268434530,-268434942,-268434749,-268435349,-268435201,-268434840,-268434751,-268434749,-268435013,-268435304,-268435382,-268435145,-268434914,-268435393,-268434480,-268435421,-268434512,-268434988,-268435287,-268434641,-268435305,-268434590,-268434603,-268435269,-268435031,-268435052,-268434613,-268434892,-268434800,-268434800,-268434576,-268435138,-268435414,-268434829,-268434655,-268434823,-268435019,-268435261,-268435106,-268435343,-268435274,-268434709,-268434611,-268435153,-268434730,-268435153,-268435217,-268434913,-268435386,-268434507,-268434785,-268434855,-268435441,-268434712,-268435175,-268435372,-268434886,-268434711,-268435168,-268435021,-268435217,-268435234,-268434746,-268434828,-268434986,-268435153,-268435189,-268435295,-268434698,-268435376,-268434938,-268435132,-268434579,-268435164,-268435190,-268434640,-268435330,-268435306,-268434667};
vector<int> nums3 = {268435273,268434555,268434528,268434599,268435008,268434615,268435042,268434470,268434617,268434705,268434570,268434663,268434791,268435221,268435436,268434760,268434763,268434465,268434865,268435390,268434998,268435132,268435155,268435249,268435129,268434978,268434829,268435183,268435021,268434874,268435187,268434468,268435382,268434525,268434835,268434783,268435389,268434521,268435062,268435053,268434504,268435192,268435295,268435387,268435172,268435087,268434640,268435137,268434985,268434886,268434470,268434908,268434985,268435187,268434754,268434963,268435324,268435435,268434887,268435356,268434576,268435255,268434759,268434723,268434563,268434642,268434464,268434637,268434976,268434605,268435266,268435364,268434464,268434569,268435020,268434623,268435401,268435448,268434947,268434588,268434869,268435074,268434508,268435264,268435411,268434497,268434995,268435111,268434552,268435366,268434673,268435031,268435117,268434885,268434649,268434546,268435128,268435303,268435166,268434749};
vector<int> nums4 = {268435159,268435155,268435311,268434873,268435429,268434491,268434502,268434727,268435046,268434676,268434642,268435293,268435232,268434582,268434854,268435346,268435238,268434511,268434834,268435017,268434615,268435173,268435275,268435082,268435435,268434997,268434905,268434829,268434992,268435175,268435326,268435233,268435257,268435371,268435399,268435447,268435017,268434483,268434630,268435430,268435297,268435332,268434678,268435319,268434586,268434663,268434653,268435362,268434704,268435290,268435057,268434860,268434884,268434641,268435110,268434788,268434776,268434948,268435086,268434755,268435323,268435062,268434804,268435033,268434521,268435318,268435052,268435141,268435398,268435152,268435346,268435016,268435237,268435336,268435220,268434509,268434908,268435200,268435220,268435436,268435426,268434916,268435310,268434823,268434749,268434765,268435123,268435093,268435335,268434644,268434594,268434915,268434639,268434497,268435051,268434889,268434951,268434736,268434570,268435303};

	Solution op;

	auto res = op.fourSumCount(nums1, nums2, nums3, nums4);

	cout<<"Number of sums satisfying the condition = "<<res<<"\n";
	return 0;
}

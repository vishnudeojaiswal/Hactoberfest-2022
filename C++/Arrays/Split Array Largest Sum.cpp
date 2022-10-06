#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[51][1001];
    int helper(vector<int> &nums,int m,int i)
    {
        if(m == 1)
        {
            int t = 0;
            for(int j = i;j<nums.size();j++)
            t += nums[j];

            return t;
        }
        if(i == nums.size())
        return INT_MAX;

        if(dp[m][i] != -1)
        return dp[m][i];
        int sum = 0;
        int ans = INT_MAX;
        for(int j = i;j<nums.size();j++)
        {
            sum += nums[j];
            ans = min(ans,max(sum,helper(nums,m-1,j+1)));
        }
        return dp[m][i] = ans;
    }
    int splitArray(vector<int>& nums, int m) {
        memset(dp,-1,sizeof dp);
        return helper(nums,m,0);
    }
};

int main()
{
  vector<int> nums{7,2,5,10,8};
  int m = 2;
  Solution test;
  cout<<test.splitArray(nums,m)<<endl;
  return 0;
}

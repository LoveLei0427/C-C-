/*198、在一列数组中取出一个或多个不相邻数，使其和最大*/
class Solution {
public:
    int *result;
    int solve(vector<int> &nums)
    {
        if(nums.size() <= 1)
            return nums.empty() ? 0 : num[0];
        vector<int> res;
        res.push_back(num[0]);
        res.push_back(max(num[0],num[1]));
        for(int i = 2; i < nums.size(); ++i)
        {
            res.push_back(max(num[i]+res[i-2],res[i-1]));
        }
        return res.back();
    }

};
或者
/*result[0] = nums[0];
  result[1]= max(nums[0],nums[1]);
  for(int i=2;i<nums.size();i++)
    result[i]= max(nums[i]+result[i-2],result[i-1]);*/

/////////////////////////////////////////////////////////
/*在一环状数组中取出一个或多个不相邻数，使其和最大
即第一个元素和最后一个元素不能同时取到*/
class Solution{
public:
	int rob(vector<int>& nums)
	{
		int n = nums.size();
		if(n==0)
			return 0;
		if(n==1)
			return nums[0];
		if(n==2)
			return max(nums[0],nums[1]);
		return max(func(nums,0,n-2),func(nums,1,n-1));
	}
	int func(vector<int>& nums,int begin, int end)
	{
		int n = end - begin + 1;
		vector<int> dp(n);
		dp[0] = nums[begin];
		dp[1] = max(nums[begin],nums[begin+1]);
		for(int i = 2; i < n; ++i)
		{
			int temp = nums[begin + i]+dp[i-2];
			dp[i] = max(temp,dp[i-1]);
		}
		return dp[n-1];
	}
};


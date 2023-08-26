class Solution {
public:

    bool partition_subset(vector<int> &nums, int i, int sum,vector<vector<int>> &memo)
    {
        if(sum==0)
            return true;

        if(sum<0 || i>=nums.size())
            return false;

        if(memo[i][sum]!=-1)
            return memo[i][sum];

        bool pick= partition_subset(nums,i+1,sum-nums[i],memo);
        bool not_pick= partition_subset(nums,i+1,sum,memo);

        bool ans = pick || not_pick;

        if(ans)
            memo[i][sum]=1;
        else
            memo[i][sum]=0;

        return ans;
    }

    bool canPartition(vector<int>& nums) {
        
        int sum=0;

       vector<vector<int>> memo(nums.size()+1,vector<int>(20001,-1));

        for(int i: nums)
            sum+=i;

        if(sum%2)
            return false;

        return partition_subset(nums,0,sum/2,memo);
    }
};
class Solution {
    int chk=-1000000;
public:

    int lis(vector<int> &nums,int i, int prev, vector<vector<int>> &memo)
    {
        if(i>=nums.size())
            return 0;
        
        if(memo[i][prev]!=-1)
            return memo[i][prev];

        int ans,pick=0;
        if(nums[i]>nums[prev])
            pick= 1+lis(nums,i+1,i,memo);
        
        int not_pick= lis(nums,i+1,prev,memo);

        ans= max(pick,not_pick);
        memo[i][prev]=ans;
        return ans;
    }

    int lengthOfLIS(vector<int>& nums) {
        
        nums.insert(nums.begin(),chk);
        vector<vector<int>> memo(nums.size()+1,vector<int>(nums.size()+1,-1));
        return lis(nums,1,0,memo);
    }
};
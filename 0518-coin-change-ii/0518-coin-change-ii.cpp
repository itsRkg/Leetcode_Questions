class Solution {
public:

    int count_change(int amount, vector<int> &coins, int i,vector<vector<int>> &dp)
    {
        if(amount==0)
            return 1;
        if(amount<0 || i>=coins.size())
            return 0;

        if(dp[i][amount]!=-1)
            return dp[i][amount];

        int ans=0;
        int pick= count_change(amount-coins[i],coins,i,dp);
        int not_pick= count_change(amount,coins,i+1,dp);

        ans=pick+not_pick;
        dp[i][amount]=ans;
        return ans;
    }

    int change(int amount, vector<int>& coins) {
        
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        return count_change(amount,coins,0,dp);
    }
};
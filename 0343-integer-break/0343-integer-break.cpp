class Solution {
public:

    int find_prod(int n, int i, int sum,vector<vector<int>> &memo)
    {
        if(sum==0 )
            return 1;
        
        if(i>=n || sum<0)
            return 0;
        
        if(memo[i][sum]!=-1)
            return memo[i][sum];

        int pick = i* find_prod(n,i,sum-i,memo);
        int not_pick= find_prod(n,i+1,sum,memo);

        int ans= max(pick,not_pick);
        memo[i][sum]=ans;
        return ans;        
    }

    int integerBreak(int n) {
        
        vector<vector<int>> memo(n+1,vector<int>(n+1,-1));

        return find_prod(n,1,n,memo);
    }
};
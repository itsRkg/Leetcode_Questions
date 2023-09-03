class Solution {
public:

    int find_path(int m, int n,vector<vector<int>> &memo)
    {
        if(m==0 && n==0)
            return 1;
        if(m<0 || n<0)
            return 0;

        if(memo[m][n]!=-1)
            return memo[m][n];

        int ans= find_path(m-1,n,memo)+find_path(m,n-1,memo);
        
        memo[m][n]=ans;
        return ans;
    }

    int uniquePaths(int m, int n) {
        
        vector<vector<int>> memo(m,vector<int> (n,-1));
        return find_path(m-1,n-1,memo);
    }
};
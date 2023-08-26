class Solution {
public:

    int find_subset( vector<pair<int,int>> &str, int i, int m, int n,vector<vector<vector<int>>> &memo)
    {
        if(i>=str.size())
            return 0;

        if(memo[i][m][n]!=-1)
            return memo[i][m][n];

        int pick=0;
        if(m>=str[i].second && n>=str[i].first)
            pick= 1+find_subset(str,i+1, m-str[i].second, n-str[i].first,memo);

        int not_pick= find_subset(str,i+1,m,n,memo);

        int ans= max(pick,not_pick);

        memo[i][m][n]=ans;
        return ans;        
    }


    int findMaxForm(vector<string>& strs, int m, int n) {
        
        vector<pair<int,int>> freq;

        vector<vector<vector<int>>> memo(strs.size(),vector<vector<int>>(m+1,vector<int>(n+1,-1)));

        for(int i=0;i<strs.size();i++)
        {
            int ones=0,zeros=0;
            for(int j=0;j<strs[i].size();j++)
            {
                if(strs[i][j]=='0')
                    zeros++;
                else
                    ones++;
            }

            freq.push_back({ones,zeros});
        }


        return find_subset(freq,0,m,n,memo);
    }
};
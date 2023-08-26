class Solution {
public:

    static bool comparator(const vector<int> &p1, const vector<int> &p2)
    {
        return p1[0]<p2[0];
    }

    int make_chain(vector<vector<int>> &pairs, int i, int prev, vector<vector<int>> &memo)
    {
        if(i>=pairs.size())
            return 0;

        if(memo[i][prev+1]!=-1)
            return memo[i][prev+1];

        int pick=0;

        if(prev==-1 || pairs[prev][1]<pairs[i][0])
            pick=1+make_chain(pairs,i+1,i,memo);

        int not_pick= make_chain(pairs,i+1,prev,memo);

        int ans= max(pick,not_pick);
        memo[i][prev+1]=ans;
        return ans;
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        
        sort(pairs.begin(),pairs.end(),comparator);
        vector<vector<int>> memo(pairs.size(),vector<int>(pairs.size()+1,-1));
        
        return make_chain(pairs,0,-1,memo);
    }
};
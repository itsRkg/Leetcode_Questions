class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> ans;

        ans.push_back({1});
        
        for(int i=1;i<numRows;i++)
        {
            ans.push_back({});
            for(int j=0;j<=ans[i-1].size();j++)
            {
                if(j==0 || j==ans[i-1].size())
                    ans[i].push_back(1);
                else 
                    ans[i].push_back(ans[i-1][j]+ans[i-1][j-1]);
            }
        }

        return ans;
    }
};
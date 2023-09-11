class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        
        unordered_map<int,vector<int>> h_map;

        for(int i=0;i<groupSizes.size();i++)
        {
            auto ptr = h_map.find(groupSizes[i]);
            if(ptr==h_map.end())
            {
                h_map.insert({groupSizes[i],{i}});
            }
            else
            {
                ptr->second.push_back(i);
            }
        }
        vector<vector<int>> ans;
        for(auto it : h_map)
        {
            int grp_no= it.first;
            vector<int> tmp=it.second;

            int size=0;
            for(int i=0;i<tmp.size();i+=grp_no)
            {
                vector<int> st;
                for(int j=0;j<grp_no;j++)
                    st.push_back(tmp[i+j]);

                ans.push_back(st);
            }
        }
        return ans;
     }
};
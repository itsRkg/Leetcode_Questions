class Solution {
public:

    bool jump(vector<int>& stones, int i, int k,unordered_map<int,int> &h_map, map<pair<int,int>, bool> &memo)
    {
        if(i>=stones.size())
            return false;
        
        if(i==stones.size()-1)
            return true;

        auto it= memo.find({i,k});
        if(it!=memo.end())
            return it->second;

        bool ans1=false, ans2=false, ans3=false;

        auto ptr = h_map.find(stones[i]+k-1);
        if(ptr!=h_map.end() && ptr->second!=i && i!=0)
            ans1= jump(stones,ptr->second,k-1,h_map,memo);

        ptr = h_map.find(stones[i]+k);
        if(ptr!=h_map.end() && ptr->second!=i)
            ans2= jump(stones,ptr->second,k,h_map,memo);
        
        ptr = h_map.find(stones[i]+k+1);
        if(ptr!=h_map.end() && ptr->second!=i && i!=0)
            ans3= jump(stones,ptr->second,k+1,h_map,memo);

        bool ans= ans1 || ans2 || ans3;
        
        memo[{i,k}]=ans;
        return ans ;
    }

    bool canCross(vector<int>& stones) {
        
        unordered_map<int,int> h_map;

        map<pair<int,int>, bool> memo;
        for(int i=0;i<stones.size();i++)
            h_map.insert({stones[i],i});

        return jump(stones,0,1,h_map,memo);
    }
};
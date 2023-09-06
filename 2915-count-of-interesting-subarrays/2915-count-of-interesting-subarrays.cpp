class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        
        vector<int> prefix(nums.size()+1,0);
        unordered_map<int,int> h_map;
        h_map[0]=1;

        long long ans=0;
        for(int i=0;i<nums.size();i++)
            prefix[i+1]=prefix[i]+((nums[i]%modulo==k)?1:0);
        
        /*
        for(int i=0;i<nums.size();i++)
        {
            for(int j=1;j<=nums.size()-i;j++)
            {
                int cnt= prefix[i+j]-prefix[i];
                if(cnt%modulo==k)
                    ans++;
            }
        }
        */

        for(int i=1;i<=nums.size();i++)
        {
            ans+=h_map[(prefix[i]-k+modulo)%modulo];
            h_map[prefix[i]%modulo]++;
        }
        return ans;
    }
};
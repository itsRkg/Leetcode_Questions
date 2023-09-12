class Solution {
public:
    int minDeletions(string s) {
        
        vector<int> freq(26,0);

        for(int i=0;i<s.size();i++)
        {
            freq[s[i]-'a']++;
        }

        unordered_map<int,int> seen;
        int ans=0;
        for(int i=0; i<26;i++)
        {
            if(freq[i]==0)
                continue;

            auto ptr= seen.find(freq[i]);
            if(ptr==seen.end())
            {
                seen.insert({freq[i],1});
                continue;
            }

            int count=freq[i];
            while(ptr!=seen.end() && count>0)
            {
                count--;
                ptr= seen.find(count);
                ans++;
            }

            seen.insert({count,1});
        }

        return ans;
    }
};
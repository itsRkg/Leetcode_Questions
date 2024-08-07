class Solution {
public:

    int count_freq(int k)
    {
        if(k==1)
            return 10;
        
        int j=9;
        int freq=9;
        for(int i=1; i<k;i++) 
        {
            freq*=j;
            j--;
        }

        return freq;

    }

    int countNumbersWithUniqueDigits(int n) {
        
        if(n==0)
            return 1;

        int ans=0;
        for(int i=1;i<=n;i++)
            ans+=count_freq(i);

        return ans;
    }
};

// _9 _9 _ 
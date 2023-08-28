class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        int sum=0;
        //window initialize
        for(int i=0;i<k;i++)
            sum+=nums[i];
        double ans=(double)sum/(double)k;
        int j=0;
        for(int i=k;i<nums.size();i++)
        {
            sum-=nums[j++];
            sum+=nums[i];
            double tmp=(double)sum/(double)k;
            ans= max(ans,tmp);
        }
        return ans;

    }
};
class Solution {
public:
    
    int bestClosingTime(string customers) {
        
        int total_y=0;
        
        for(int i=0; i<customers.size(); i++)
        {
            if(customers[i]=='Y')
                total_y++;
        }


        int curr_y=0;
        int min_penalty=INT_MAX;
        int ans=0;
        int penalty=0;

        for(int i=0;i<=customers.size();i++)
        {
            if(i<customers.size() && customers[i]=='Y')
            {
                curr_y++;
            }
            else
            {
                int curr=penalty;
                if(total_y>curr_y)
                    curr+= total_y- curr_y;

               if(min_penalty>curr)
               {
                   min_penalty=curr;
                   ans=i;
               }
                penalty++;
            }
        }

        return ans;
    }
};
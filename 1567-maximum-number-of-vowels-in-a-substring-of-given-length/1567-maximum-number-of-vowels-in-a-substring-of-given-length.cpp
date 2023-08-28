class Solution {
public:

    bool isVowel(char c)
    {
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
            return true;

        return false;
    }
    //int count = 0;
    int maxVowels(string s, int k) {
    
      int vowel_count=0;
      for(int i=0; i<k; i++){
          if(isVowel(s[i]) )
          {
              vowel_count++;
          }
      }  
        int ans=vowel_count;
        int j=0;
        for(int i=k; i<s.size(); i++)
        {
            if(isVowel(s[j++]) )
                vowel_count--;

            if(isVowel(s[i]))
                vowel_count++;

            ans= max(ans,vowel_count);
        }
        return ans;
    }
};
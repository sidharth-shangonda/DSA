class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if (s1.size() > s2.size()) return false;

        vector<int> freq(26,0);

        for(char c:s1)
            freq[c-'a']++;

        int left = 0;
        int need = s1.size();
        //just check you are decreasing correctly 
        for(int right=0; right<s2.size(); right++) {
  
            if(freq[s2[right]-'a']-- > 0)
                need--;

            if(right-left+1 > s1.size()) {

                if(++freq[s2[left]-'a'] > 0)
                    need++;

                left++;
            }

            if(need==0)
                return true;
        }

        return false;
    }
};
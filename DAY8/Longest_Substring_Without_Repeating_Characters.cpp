class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0,ans=0; 
        int n=s.size(); 
        //unordered map of the char and it's frequency 
        unordered_map<char,int>mp; 
        while(j<n){ 
            //stroing the frequency of the character
            mp[s[j]]++; 
            //when map size > j-i+1, j++
            if(mp.size()>j-i+1){
              j++;
            }
            //when map size < j-i+1
            if(mp.size()<j-i+1){ 
                //while(jab tak) map size < j-i+1, decrease the frequency of the characters
                while(mp.size()<j-i+1){ 
                    mp[s[i]]--; 
                    //when frequency of the character == 0 ,remove the char from the map
                    if(mp[s[i]]==0) 
                        mp.erase(s[i]); 
                    // move the first pointer to decrease / remove char from the first
                    i++; 
                } 
                //move second poiner always
                j++; 
            } 
            //when map size == j-i+1, store the subarray size
            //and calculate the max subarray size and move second pointer always
            if(mp.size()==j-i+1){ 
                ans=max(ans,j-i+1); 
                j++; 

            } 
        } 
        return ans; 
    }
};

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        int i=0,j=0; 
        int mx = -1; 
        //unordered map of the char and it's frequency 
        unordered_map<char,int> memo; 
        while(j<s.length()){ 
            //stroing the frequency of the character
            memo[s[j]]++; 
            //map size matters here, 
            //if map size<k , move the second pointer to equal the k size
            if(memo.size()<k){ 
                j++; 
            } 
            //when map size >k
            else if(memo.size()>k){ 
                //while(jab tak) map size > k , decrease the frequency of the characters
                while(memo.size()>k){ 
                    memo[s[i]]--; 
                    //when frequency of the character == 0 ,remove the char from the map
                    if(memo[s[i]]==0){ 
                       memo.erase(s[i]); 
                    } 
                    // move the first pointer to decrease / remove char from the first
                    i++; 
                } 
                //move second poiner always
                j++; 
            } 
            //when map size == k, store the subarray size
            //and calculate the max subarray size and move second pointer always
            else if(memo.size()==k){ 
                mx = max(mx,j-i+1); 
                j++; 
    
            }
        } 
        return mx; 
    }
};

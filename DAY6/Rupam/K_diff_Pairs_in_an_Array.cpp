//#Approach 1 :  without sorting 98% faster 47% space
// T.C = O(n) & S.C = O(n)
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k<0){return 0;}
        unordered_map<int,int> mp;      
        for(int i = 0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
       int count = 0;
       for(auto x : mp){
           int diff = x.first - k;
           if(mp.find(diff)!=mp.end()){
               if(diff==x.first and x.second>1){
                   count++;
               }else if(diff!=x.first and x.second>=1){
                   count++;
               }
           }
       }
        return count;
       
    }
};

//#Approach 2 : with sorting + map
// T.C = O(nlogn) & S.C = O(n) + o(n)
class Solution {
public:
     int findPairs(vector<int>& nums, int k) {
		      set<pair<int,int>> unq;
          unordered_map<int,int> m;
        
          sort(nums.begin(),nums.end());
        
          for(int i=0;i<nums.size();i++)
           {
            int temp=nums[i]-k;
            if(m.find(temp)!=m.end())
            {
                unq.insert(make_pair(nums[i],temp));
                
            }
            m[nums[i]]=0; // so we can use temp=nums[i]-k again but from next time nums[i] shouldn't be same so we decreament its count  or make it equal to 0 
        }
        
        return unq.size();
     }
};

// two pointers
// T.C = O(nlogn) & S.C = O(1)
class Solution {
public:
     int findPairs(vector<int>& nums, int k) {
          sort(nums.begin(),nums.end());
         int n =  nums.size();
         int count = 0;
         int i = 0; int j = 1;
         while(i<n and j<n){
             if(nums[j] - nums[i] == k){
                 i++;
                 j++;
                 count++;
                 // to handle duplicates
                 while(j<n and nums[j]==nums[j-1]){
                     j++;
                 }
             }else if(nums[j]-nums[i] > k){
                 i++;
                 if(j-i==0){
                     j++;
                 }
             }else{
                 j++;
             }
             
         }
        return count;
          
     }
};

// T.C ==> O(n) & S.C ==> O(n) --> For unordered_map
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
      
        // storing the element and its count
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
          mp[nums[i]]++;
        }
        for(auto it:mp){
          
          // if any elements's count is > n/2
          if(it.second>n/2){
            // return the element
            return it.first;
          }
        }
        return 0;
    }
};

// T.C ==> O(n) & S.C ==> O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
      
        // take count = 1, because the element is 1 time already present in the array
        int n =  nums.size() , count = 1;
      
        // assume the first element as major
        int majority_element = nums[0];
        for(int i=1;i<n;i++){
        
          // when count become 0 , update the major
          if(count==0){
            count = 1;
            majority_element = nums[i];
          }
          
          // if nums[i]==major , then increment the count
          else if(nums[i]==majority_element){
            count++;
            
          }
          
          // else decrement the count
          else if(nums[i]!=majority_element){
            count --;
          }
          
        }
        return majority_element;
      
    }
};

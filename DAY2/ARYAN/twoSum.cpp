Brute Force:- 

Just Run two loops from 0 to 1 and then i+1 to n.
Then check if nums[I] + nums[j] == target , return i,j.
T.C ==> O(n^2)
S.C ==> O(1)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i=0;i<n;i++){
          for(int j=i+1;j<n;j++){
            if(nums[i]+nums[j]==target){
              return {i,j};
            }
          }
        }
        return {};
    }
};

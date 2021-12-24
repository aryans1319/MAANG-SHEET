// T.C ==> O(n^3) & S.C ==> O(1)
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0, ans = 0 , diff = INT_MAX;
        for(int i=0;i<n-2;i++){
          for(int j=i+1;j<n-1;j++){
            for(int k=j+1;k<n;k++){
                // sum of three numbers
                sum = nums[i]+nums[j]+nums[k];
              
                // if sum == target , return atrget
                if(sum==target){
                  return target;
                }
              
                //Checking if the difference between target and the sum is the smallest
                else if(abs(target - sum) <= diff){
                  
                  // update the difference with smaller once
                  diff = abs(target - sum);
                  // update the ans with the current sum
                  ans = sum;
                }
            }
          }
        }
        return ans;
    }
};


// T.C ==> O(n^2) & S.C ==> O(1)
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int sum = 0, ans = 0 , diff = INT_MAX;
        for(int i=0;i<n-2;i++){
          
            int start = i+1;
            int end = n-1;
            while(start<end){
              sum = nums[i]+nums[start]+nums[end];
              
              if(sum==target){
                return target;
              }
              // same code like 3 sum
              // 3 lines are different , which is explained in the brute force
              else if(abs(target-sum)<=diff){
                diff = abs(target - sum);
                ans = sum;
              }
              
              // normal two pointer
              if(sum>target)  end--;
              else            start++;
            }
        }
        return ans;
    }
};

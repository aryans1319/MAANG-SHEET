// brute force

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size(), mx=0;
        for(int i=0;i<n;i++){
          // if nums[i] == 1,it can start a consecutive answer, else it can't start
          if(nums[i]==1){
              // take a j variable, and start from i to find the size of consecutive ones
              int j=i;
              // when nums[i]==0, stop
              while(j<n && nums[j]==1){
                j++;
              }
              // j-i is the length, calculate the max length
              mx = max(mx,j-i);
            } 
        }
        return mx;
    }
};

// optimal

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ones = 0, mx = 0;
        for (auto num : nums){
          
            // when we get 0
            if (num == 0) {
                // calculate the max
                mx = max(mx, ones);
                // make the count of 1 as 0
                ones = 0;
            }
            // if nums[i]!=0, that's means it's 1, increament the count
            else ones++;
        }
        // at the end return the max of mx and ones
        // 1 0 1 1 1 0 0 1 1 1 1  ==> mx = 3 ones = 4
        // 1 0 1 1 1 1 0 0 1 1 1  ==> mx = 4 ones = 3
        return max(mx, ones);
    }
};

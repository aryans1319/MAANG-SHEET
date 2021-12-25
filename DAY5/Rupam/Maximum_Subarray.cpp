// Brute Force

//Run three loops, get all possible subarrays in two loops and their sum in another loop, then return the maximum of them.
// T.C == O(n^3) && S.C == O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = INT_MIN;
        
        for(int i=0; i<nums.size(); i++){
            for(int j=i; j<nums.size(); j++){
              int curr_sum = 0;
                for(int k=i;k<=j;k++){
                  curr_sum += nums[k];
                  max_sum = max(max_sum, curr_sum);
                }
            }
        }
    return max_sum;
    }
};

// optimal

// If we optimise the above approach, we can get sum of all possible subarrays in two loops only, then return the maximum so far.
// T.C == O(n^2) && S.C == O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = INT_MIN;
      
        for(int i=0; i<nums.size(); i++){
            int curr_sum = 0;
            for(int j=i; j<nums.size(); j++){
                curr_sum += nums[j];
                max_sum = max(max_sum, curr_sum);
            }
        }
    return max_sum;
    }
};

// efficient solution

// Kadane Algorithm
// T.C == O(n) && S.C == O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = INT_MIN;
        int curr_sum = 0;
        for(int i = 0; i < nums.size(); i++) {
          
            curr_sum += nums[i];
            max_sum = max(curr_sum, max_sum);
            // if current sum is < 0, make current sum = 0, that's the algorithm
            if(curr_sum < 0) curr_sum = 0;
        }
        return max_sum;
    }
};

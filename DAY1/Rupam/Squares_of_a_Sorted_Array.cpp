// Efficient Solutions

//Take two pointers at either ends of array, Check abs value of both the elements and   fill the array backwards bcoz largest value will be at last

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int start = 0, end = n-1;
        vector<int> ans(n);
        for(int k=n-1;k>=0;k--){
          if(abs(nums[start])<abs(nums[end])){
            ans[k]=nums[end]*nums[end];
            end--;
          }
          else if(abs(nums[start])>=abs(nums[end])){
            ans[k]=nums[start]*nums[start];
            start++;
          }
        }
        
        return ans;
    }
};

// Brute Force

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
          nums[i]*=nums[i];
        }
        sort(nums.begin(),nums.end());
        return nums;
    }
};

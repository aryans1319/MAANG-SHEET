//Brute Force

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> copyArray(n);
        for(int i=0;i<n;i++){
            copyArray[(i+k)%n] = nums[i];
        }
        nums = copyArray;
    }
};

//Optimal

class Solution {
public:
    void reverse(vector<int> &nums, int start , int end){
        while(start<=end){
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }
    
    void rotate(vector<int>& nums, int k) {
        k = k%nums.size();
        if(k<0){
            k = k + nums.size();
        }
        reverse(nums, 0,nums.size()-1);
        reverse(nums,0,k-1);
        reverse(nums,k,nums.size()-1);
    }
};

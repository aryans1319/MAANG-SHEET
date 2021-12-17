//Efficient Approach using two pointers

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        int sizeofNums = nums.size();
        vector<int> ans(sizeofNums);
        while(left<=right){
            for(int i=sizeofNums-1 ; i>=0;i--){
                if(abs(nums[right]) > abs(nums[left])){
                    ans[i] = nums[right] * nums[right];
                    right--;
                }
                else{
                    ans[i] = nums[left] * nums[left];
                    left++;
                }
            }
        }
        return ans;
    }
};


//Brute Force Approach
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        
        for(int i=0;i<nums.size();i++){
            ans.push_back(nums[i]*nums[i]);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        while(k--){
            int temp = nums[nums.size()-1];
            for(int i = nums.size()-2; i>= 0 ;i--){
                nums[i+1] = nums[i];
            }
            nums[0] = temp;
        }   
    }
};

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int sz = nums.size();
        vector<int> result(sz,0);
        for(int i=0;i<sz;i++){
            result[(i + k)%sz] = nums[i];
        }
        nums = result;
    }
};


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};

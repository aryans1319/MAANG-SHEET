// optimal solution

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0,j=0;
        int sum=0;
        int res = INT_MAX;
        while(j<nums.size()){
            
            //it is a varibale window size question
            // we are calculating the sum everytime at the first place
            sum+=nums[j];
            // if sum<target , move the second pointer to create the window
            if(sum<target){
                j++;
            }
            // when sum of subarray sum>= target
            else if(sum>=target){
                // while (jab tak) subarray sum >= target
                while(sum>=target){
                    //storing the subarray size and calculating the min size
                    res=min(res,j-i+1);
                    //excluding from the first
                    sum=sum-nums[i];
                    // move the first pointer
                    i++;
                }
                // move the second pointer to get the sum also
                j++;
            }
        }
        //if result is still == INT_MAX, that's means there is no subarray ,return 0 else result 
        return (res == INT_MAX) ? 0 : res;
    }
};

// brute force

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int res=INT_MAX;
        vector<int> out;
        for(int i=0;i<n;i++){
            sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                if(sum>=target){
                    int temp=j-i+1;
                    res=min(res,temp);
                    break;
                }
            }
        }
        if(res==INT_MAX)
            return 0;
        return res;
    }
};

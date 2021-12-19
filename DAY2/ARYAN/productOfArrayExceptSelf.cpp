//BRUTE FORCE APPROACH

    vector<int> productExceptSelf(vector<int>& nums) {
       int n = nums.size();
        vector<int>ans(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j)continue;
                ans[i] = ans[i] * nums[j];
            }
        }
        return ans;
    }

Time Complexity: O(n^2)
Space Complexity: O(n)

  
//  APPROACH- 2

Maintain a left product array and right product array
Left Product Array stores product of the elements on the left side of array
Right Product Array stores product of the elements on the right side of array

Multiply both array to get the desired resultant array

CODE

// // TC :: O(n) and SC :: O(n)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> ans(n);
        vector<int> leftProductArray(n);
        vector<int> rightProductArray(n);
        
        leftProductArray[0] = 1;
        rightProductArray[n-1] = 1;
        
        for(int i = 1 ;i<n;i++){
            leftProductArray[i] =  leftProductArray[i-1] * nums[i-1];
        }
        
        for(int j=n-2;j>=0;j--){
            rightProductArray[j] = rightProductArray[j+1] * nums[j+1];
        }
        
        for(int k = 0; k<n;k++){
            ans[k] = leftProductArray[k] * rightProductArray[k];
        }
        
        return ans;
    }
};

//Approach 3:- 

// TC :: O(n) and SC :: O(1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> ans(n); // ans array used as right product array
        
        ans[n - 1] = 1; 
        
        for(int i = n - 2; i >= 0; i--){
            ans[i] = nums[i + 1] * ans[i + 1];
        }
        
		// left array as a variable
        int leftProd = 1;
        for(int i = 0; i < n; i++){
            ans[i] = leftProd * ans[i]; // update the answer array using left
            leftProd = leftProd * nums[i]; // updating the left array
        }
        
        return ans;
    }
};

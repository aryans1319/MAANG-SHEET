// here i use divide method , according the question I can't use that
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int product = 1 , count_zero = 0;
        for(int i=0;i<n;i++){
          if(nums[i]==0){
            count_zero++;
            continue;
          }
          else  product *= nums[i];
        }
        if(count_zero == n){
          return nums;
        }
        if(count_zero==0){
          for(int i=0;i<n;i++){
             nums[i]=product/nums[i];
          }
        }
        else if(count_zero==1){
          for(int i=0;i<n;i++){
            if(nums[i]==0){
              nums[i]=product;
             }
            else{
              nums[i]=0;
            }
          }  
        }
        else if(count_zero>1){
          for(int i=0;i<n;i++){
              nums[i]=0;
            }
        }  
        return nums;
    }
};


// Maintain a left product array and right product array , Left Product Array stores product of the elements on the left side of array , Right Product Array stores product of  the elements on the right side of array 

 

Multiply both array to get the desired resultant array
// TC :: O(n) and SC :: O(n)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> left_Product(n);
        vector<int> right_Product(n);
        
        left_Product[0] = 1;
        for(int i = 1; i < nums.size(); i++){
            left_Product[i] = left_Product[i - 1] * nums[i - 1];
        }
        
        right_Product[n - 1] = 1;
        for (int j = n - 2; j >= 0; j--) {
            right_Product[j] = right_Product[j + 1] * nums[j + 1];
        }
        
        for (int k = 0; k < n; k++) {
            ans[k]= left_Product[k] * right_Product[k];
        }
        
        return ans;
    }
};

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
            leftProd = leftProd * nums[i]; // updating the elft array
        }
        
        return ans;
    }
};

// Brute Force ==> Two Traversal
// T.C == O(n) && S.C == O(n)(ans vector) Auxillary Space == O(1)

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
          if(nums[i]%2==0){
            ans.push_back(nums[i]);
          }
        }
        for(int i=0;i<nums.size();i++){
          if(nums[i]%2!=0){
            ans.push_back(nums[i]);
          }
        }
        return ans;
    }
};

// Efficient == Two Pointer
// T.C == O(n) && S.C == O(n)(ans vector) Auxillary Space == O(1) 

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int j=0; // take a pointer at first
        for(int i=0;i<A.size();i++){
            if(A[i]%2==0){ // if nums[i] is even
                swap(A[i],A[j]); // swap with the first index (even should be first )
                j++; // move pointer from first index 
        }
      }
        return A;
    }
};

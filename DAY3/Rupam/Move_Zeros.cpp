// Efficient Solution

// T.C ==> O(n) S.C ==> O(1)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        
        // take a pointer at the start 
        int a=0;
        
        for(int i=0; i<size; i++) {
            // if the nums[i]!=0, swap with the start element
            if(nums[i]!=0) {
                swap(nums[i], nums[a]);
                // increment the start poiner after swapping every time
                a++;
            }
        }
    }
};

// Brute Force solution

/* take an answer vector, with all 0, then store the elements (!=0) from nums to answer. Then restore the elements from answer to nums1 again 

T.C ==> O(n) S.C ==> O(n) --> for creating the answer array */

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        int i=0,j=0;
        while(i<n && j<n){
          if(nums[i]==0){
            i++;
          }
          else{
            ans[j]=nums[i];
            i++;
            j++;
          }
        }
        for(int i=0;i<nums.size();i++){
          nums[i]=ans[i];
        }
    }
};

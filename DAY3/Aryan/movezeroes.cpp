Brute Force:-

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

  
  
/*SNOWBALL TECHNIQUE TO SOLVE

The idea is that we go through the array and gather all zeros on our road.

Let's take our example:
the first step - we meet 0.
Okay, just remember that now the size of our snowball is 1. Go further.

Next step - we encounter 1. Swap the most left 0 of our snowball with element 1.

Next step - we encounter 0 again!

Our ball gets bigger, now its size = 2.

Next step - 3. Swap again with the most left zero.

Looks like our zeros roll all the time

Next step - 12. Swap again:*/

//CODE FOR SNOWBALL


void moveZeroes(vector<int>& nums) {
        int snowBall = 0;
        for(int i=0; i<nums.size();i++){
            if(nums[i]==0)
                snowBall++;
            else if(snowBall>0){
               
		swap(nums[i], nums[i - snowball]);

            }
        }
    }

TIME : O(N)
SPACE: O(1)
  
//Another Optimal
  
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

  
  








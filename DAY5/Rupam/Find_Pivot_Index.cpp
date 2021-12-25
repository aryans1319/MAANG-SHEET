class Solution {
public:
    int pivotIndex(vector<int>& nums) {
    // Brute Force Solution Time O(N^2) & Auxiliary Space O(1)
    // Calculate the sum of elements to the left & right
    // of each index of nums vector and compare them to check equivalence
    int len=nums.size();
    if(len==1)
        return nums[0];
    for(int i=0;i<len;i++){
           // accumulate() takes O(N) time and for loop runs for n iterations.
           // So time taken by for loop is O(n*n)=O(N^2)
          int left=accumulate(nums.begin(),nums.begin()+i,0); 
          int right=accumulate(nums.begin()+i+1,nums.end(),0);
          if(left==right)
              return i;
    }
      return -1;
    }
};

/*
        sum = 28;
        arr[] =  [ 1 , 7 , 3 , 6 , 5 , 6 ]
        
        (1) lsum = 0 , rsum = 27(subtracted index 0 value) 
            now they are not equal from starting index 0  => now at next iteration lsum increases
        (2) lsum=1 , rsum = 20(subtracted index 1 value)
        (3) lsum=8 , rsum = 17(subtracted index 2 value)
        (4) lsum=11 , rsum = 11(subtracted index 3 value)
    
        the 4th statement is actually
            lsum = 1+7+3 == rsum = 5+6
            
            and index value is now 3
*/

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int prefix_sum  =0;
        for(int i= 0; i < nums.size(); i++){
            prefix_sum += nums[i];
        }
        int left_sum =0; 
        int right_sum = prefix_sum ;
        for(int i= 0; i < nums.size(); i++){
            right_sum -= nums[i];
            if(left_sum == right_sum)
                return i;
            
            left_sum += nums[i];
        }
        return -1;
    }
};

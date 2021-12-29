class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // Brute Force Solution Time O(N^3) & Auxiliary Space O(1)
        // Time Limit Exceed(TLE) 61/89 test cases passed
        int len=nums.size(),count=0;
        // Consider all possible subarrays
        for(int i=0;i<len;i++){ 
            for(int j=i;j<len;j++){ // Consider subarray from nums[i] to nums[j]
               int sum=0;
               for(int s=i;s<=j;s++){//Calculate sum of elements from nums[i] to nums[j]
                   sum+=nums[s]; 
                }
                if(sum%k==0) // Check if sum is divided by k
                    count++;
           }
        }
        return count;
    }
};

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // Better Solution Time O(N^2) & Auxiliary Space O(N)
        // Time Limit Exceed(TLE) 84/89 test cases passed
        int len=nums.size(), count=0;
        vector<int> ls; // prefix sum array or left sum array
                        // ls[i] will be sum of elemensts from nums[0] to nums[i]
        ls.push_back(0);
        for(int i=0;i<len;i++)
            ls.push_back(ls.back()+nums[i]); // inserting elements in ls
        for(int i=0;i<ls.size();i++){ 
            for(int j=i+1;j<ls.size();j++){ 
                   // For example: nums[]={2,8,5,-3,1,8}, k=10
                   // ls[]={2,10,15,12,13,21}, k=10
                   // nums[1]+nums[2]+nums[3]=8+5+(-3)=10. 
                   // j runs from 1 to 3. For j=i+1 & j=1, we get i=0.
                   // Therefore i=0 & j=3.
                   // ls[j=3]-ls[i=0]=12-2=10 which is equal to k.
                   if((ls[j]-ls[i]) %k==0) 
                       count++;
            }
        }
        return count;

    }
};

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int result =0, sum =0, remainder =0;
        unordered_map<int, int>mp; // map to store  the frequency of remainders of sum 
        mp[0] =1;
        for(int i =0; i< nums.size(); i++){
            //add nums[i] to sum
            sum += nums[i];
            remainder = (sum% k);
            //if remainder of sum and k comes to be negative than add the remainder to k  and make remainder a positive value
            if( 0 > remainder){
                remainder += k;
            }
            //check if remiander is present in map or not:
            if(mp.find(remainder) != mp.end()){
                //add it to the result
                //this means we have frequency of remainder greater than one 
                result += mp[remainder];
            }
         mp[remainder]++;
           
            
        }
        return result;
    }
};

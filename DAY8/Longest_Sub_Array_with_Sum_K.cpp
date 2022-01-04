class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        int i=0,j=0;
        int sum=0;
        // maxi variable to store the maximum subarray/window size of sum k
        int maxi = 0;
        while(j<N){
            
            //it is a varibale window size question
            // we are calculating the sum everytime at the first place
            sum+=A[j];
            // if sum<k , move the second pointer to create the window
            if(sum<K){
                j++;
            }
            // when sum == k, time to store the window/subarray size 
            // and check the maximum window size of sum k
            else if(sum==K){
                //j-i+1 is the subarray/window size,+1 for 0 based indexing
                maxi=max(maxi,j-i+1);
                // we have to increase the second pointer always to get all the subarray size
                j++;
            }
            // when sum of subarray sum> k
            else if(sum>K){
                // while (jab tak) subarray sum > k, excluding from the first
                while(sum>K){
                    sum=sum-A[i];
                    // move the first pointer
                    i++;
                    }
                }
                // move the second pointer to get the sum also
                j++;
            }
        }
        return maxi;
    } 

};
// If any number is negetive , add or delete the negetive numbers from the first

class Solution{   
public:
    int maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here 
        int sum = 0; 
        int mx = INT_MIN; 
				// starting window's first and last index from 0 
        int start=0,end=0; 
        while(j< Arr.size()){ 
            // adding element and
            sum+=Arr[end];
            // creating the window
            if(end-start+1<K){ // end - start + 1 because of 0 based indexing
                end++; 
            } 
						// window is created
            else if(end-start+1==K){ 
                mx= max(mx,sum);
                // deleting the first index's element 
                sum-=Arr[start];
                // maintaing the window
                start++; // excluding the first
                end++; // including the last's next
            } 
        } 
        return mx; 
    }
};

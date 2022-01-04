// Brute Force

class Solution {
	    // Brute Force Solution Time O(N!*N) & Auxiliary Space O(N^2)
		// Recursion & Backtracking
	    // TLE 64/265 test cases passed
public:
    void permute(int p,vector<int>& arr, vector<vector<int>>& res) {
        int n=arr.size();
        if(p==n) res.push_back(arr);
        for(int i=p;i<n;i++) {
            swap(arr[i],arr[p]);
            permute(p+1,arr,res);
            swap(arr[i],arr[p]);
        }
    }
    void nextPermutation(vector<int>& nums) {
        vector<vector<int>> res; 
        vector<int> arr=nums; 
        permute(0,arr,res); 
        set<vector<int>> s;
        for(int i=0;i<res.size();i++){
            s.insert(res[i]);
        }
        auto it=s.find(nums);
        if(it==(--s.end())){
            it=s.begin();
            nums=*it;
        }
        else{
            it++;
            nums=*it;
        }
    }
};

// Optimal Solution :- 

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
	    // Optimal Solution Time O(N) & Auxiliary Space O(1)
	    // Narayana Panditha's Algorithm
        int len=nums.size(), k=0, l=0;
        for(k=len-2;k>=0;k--){
            if(nums[k]<nums[k+1])
                break;
        }
        if(k<0){
            reverse(nums.begin(),nums.end());
        }
        else{
            for(l=len-1;l>k;l--){
                if(nums[l]>nums[k])
                    break;
        }
            swap(nums[k],nums[l]);
            reverse(nums.begin()+k+1,nums.end());
        }
    }
};

// STL

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
	    // Optimal Solution Time O(N) & Auxiliary Space O(1)
	    // Inbuilt Function
        next_permutation(nums.begin(),nums.end());
    }
};

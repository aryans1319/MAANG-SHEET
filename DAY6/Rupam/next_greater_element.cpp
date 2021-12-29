//optimal

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2){
        //since there are no duplicates, we can store them in a map;
        
        vector<int> res(nums1.size(), -1); //to be returned, initialize it with -1.
        stack<int> st;
        unordered_map<int, int> umap;
        
        for(int i=0; i<nums2.size(); i++){
            int element = nums2[i];
            while(!st.empty() && element > st.top()){
                //NGE of st.top() is element
                umap[st.top()] = element;
                st.pop();
            }
            st.push(element);
        }
        for(int i=0; i<nums1.size(); i++){
            int ele = nums1[i];
            if(umap.find(ele) != umap.end()){
                int nge = umap[ele];
                res[i] = nge; //push NGE of desired element
            }
                
        }
        
        return res;
    }
};

// brute force

class Solution { 
public: 
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) { 
     vector<int>lo; 
          for(auto elem : nums1){
            for (int i = 0; i < nums2.size(); i++){
             if(elem == nums2[i]){ 
                   bool f = false; 
                   int h=i;  
                   for (int k = h ; k <nums2.size(); k++){
                         if(nums2[h]<nums2[k]){
                           f=true; 
                             lo.push_back(nums2[k]); 
                             break; 
                         } 
                  } 
               if(f==false){ 
                   lo.push_back(-1); 
               } 
              } 
            }
          }
        return lo; 

    } 

}; 

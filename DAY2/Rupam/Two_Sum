// Just Run two loops from 0 to 1 and then i+1 to n. 
// Then check if nums[I] + nums[j] == target , return i,j. 
// T.C ==> O(n^2) 
// S.C ==> O(1)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i=0;i<n;i++){
          for(int j=i+1;j<n;j++){
            if(nums[i]+nums[j]==target){
              return {i,j};
            }
          }
        }
        return {};
    }
};


/*Take an answer array and a temp array to store the nums and then sort the nums array. 
Use normal Two pointer approach and store two values into two extra Variables. 
Now iterate through the temp arrays and then check if temp[i] == any value, 
Store the index into the answer vector. Answer vector's size can be maximum 2.*/

// T.C ==> O(nlogn) for sorting 
// S.C ==> O(n) for temp array

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> temp, ans;
        int low = 0, high = nums.size() - 1, value1, value2;
        temp = nums;
        sort(nums.begin(), nums.end());
        while(low < high){
          if(nums[low] + nums[high] > target) high--;
          else if(nums[low] + nums[high] < target) low++;
          else{
            value1 = nums[low], value2 = nums[high];
            break;
          }
        }
        for(int i = 0 ; i < temp.size() ; i++){
          if(temp[i] == value1 || temp[i] == value2){
            ans.push_back(i);
          }
          if(ans.size() == 2) break;
        }
        return ans;
    }
};

// take an unordered map of the element and its index
// iterate through the array and check if (target - nums[i]) is present in the map or not
// if present then push mp[target - nums[i]] and i into the answer 
// else take the element into the map

// dry run--> [2,7,11,15] , i=0):-  9 - 2 == 7 is not presnt in the map so take it into the map
//                          i=1):- 9 - 7 == 2 is aready present in the map , so push 2's index first then 7's index

// T.C ==> O(n)
// S.C ==> O(n) for unordered map

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        // key == element && value == index
        unordered_map<int,int> mp; 
        vector<int> ans;
        for(int i=0;i<n;i++){
          if(mp.find(target - nums[i])!=mp.end()){
            ans.push_back(mp[target - nums[i]]);
            ans.push_back(i);
          }
          
          // taking it into the map
          mp[nums[i]]=i;
        }
        return ans;
    }
};

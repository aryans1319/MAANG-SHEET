class Solution {
public:
  
    int atMost(vector<int>& A, int S) {
        int i=0,j=0,count=0,sum=0;
        int size=A.size();
        if (S < 0)return 0;

        while(j<size){
            sum+=A[j];
            while(sum>S ){
                sum-=A[i];
                i++;
            }
            count+=j-i+1;
            j++;
        }
        return count;
    }

    int numSubarraysWithSum(vector<int>& A, int S) {
        return atMost(A, S) - atMost(A, S - 1);
  
    }
};


class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int ans = 0;
        vector<int> pre(A.size(),A[0]);
        unordered_map<int,int> hash;
        for(int i=1;i<A.size();++i) pre[i] = pre[i-1] + A[i];
        for(int i=0;i<pre.size();++i){
            if(pre[i] == S) ans++;
            ans += hash[pre[i]-S];
            hash[pre[i]]++;
        }
        return ans;
    }
};

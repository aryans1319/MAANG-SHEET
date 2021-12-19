// using set
APPROACH USING SET


class RandomizedSet {
public:
    set<int>s;
    RandomizedSet() {
        s.clear();
    }
    
    bool insert(int val) {
        if(s.find(val)!=s.end()){
        }
        s.insert(val);
            return false;
        return true;
    }
    
    bool remove(int val) {
        if(s.find(val)==s.end()){
            return false;
        }
        
            s.erase(val);
            return true;
    }
    
    int getRandom() {
        return *next(s.begin(),rand()%s.size());
          }
};

Here getRandom function takes O(n) time to generate random numbers as it is dependent on the size of the set 

the " rand()%n " generate the random numbers between [0,n), and *next( S.begin() , k) return the value at index k of set S.

  
                                                      
//APPROACH USING MAP AND VECTOR 

Here getRandom function takes O(1) time

class RandomizedSet {
public:
    unordered_map<int,int> memo;
    vector<int> v;    
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(memo.find(val)!=memo.end()){
            return false;
        }
        v.push_back(val);
        memo[val] = v.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(memo.find(val)==memo.end()){
            return false;
        }
        int last = v.back();
        memo[last] = memo[val];
        v[memo[val]] = last;
        v.pop_back();
        memo.erase(val);
        return true;
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

					
							
Explanation 

Usually the first thing that comes to find when we hear "lookup" , "insert" in constant time is "hashmaps".
That's the reason we use an unordered_map here which stores the element as " key " and its position in vector as the "value ".. The average time complexity of search , insert and remove elements from a hashmap is O(1).
However , here we need to support "Random()" access in O(1) as well. so we are using a vector here to achieve that.
Now the code is fairly simple to understand if you read it, but there is a trick to remove the element in O(1) time from a vector.
Here is the trick to remove in constant time.
Assume that the order of elements does not matter.
This is what you need to pay attention to.
Suppose you have a vector (not indices, but actual values in those positions)
0 1 2 3 4 5 6
and you want to remove the value 3. You can turn this into
0 1 2 6 4 5
in O(1) without any issues. (Again assuming that we are not concerned about maintaining any ordering, we are just looking to delete the value 3 in constant time)
Here is the pseudo-code
	1. If the element you are trying to remove is the last element in the vector, remove it, done, ELSE,
	2. Read the last element of the vector and write it over the element-to-be-removed. (swap is O(1))
	3. Now remove the last element of the vector. (C++ pop_back() in a vector is O(1))
That is exactly the trick we are using here, only that we need to update our hashmap as well.

                                                  

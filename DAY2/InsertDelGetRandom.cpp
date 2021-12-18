// Unordered Map and Vector Approach
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

// Set Approach getRandom here takes O(n) time
class RandomizedSet {
public:
    unordered_set<int>s;
    RandomizedSet() {
        s.clear();
    }
    
    bool insert(int val) {
        if(s.find(val)!=s.end()){
            return false;
        }
        s.insert(val);
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
        //the " rand()%n " generate the random numbers between [0,n), and *next( S.begin() , k) return the value at index k of set S
    }
};



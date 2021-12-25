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

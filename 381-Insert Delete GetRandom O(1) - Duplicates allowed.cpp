class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {}
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {        
        m[val].push_back(vals.size());
        vals.emplace_back(val, m[val].size() - 1);
        return m[val].size() == 1u;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (!m.count(val)) return false;
        int index_to_evict = m[val].back();
        const auto& last_entry = vals.back();
        
        // Update index
        m[last_entry.first][last_entry.second] = index_to_evict;
        
        // Swap vals
        swap(vals.back(), vals[index_to_evict]);
        
        // Clenup
        vals.pop_back();        
        m[val].pop_back();
        if (m[val].empty()) m.erase(val);
        
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return vals[rand() % vals.size()].first;
    }
private:
    // val -> indices array: indices in vals_
    unordered_map<int, vector<int>> m;
    // {val, index in the indices array}
    vector<pair<int,int>> vals;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
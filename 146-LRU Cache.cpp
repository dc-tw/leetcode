class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity, cur = 0;
    }
    
    int get(int key) {
        vector<int>::iterator it = find(v.begin(), v.end(), key);
        if(it == v.end()) return -1; 
        v.erase(it); 
        v.emplace_back(key);
        return m[key];
    }
    
    void put(int key, int value) {
        if(m[key])
        {
            m[key] = value;
            vector<int>::iterator it = find(v.begin(), v.end(), key);
            v.erase(it);
            v.emplace_back(key);
            return;
        }
                
        if(cur == cap)
        {
            int p = v.front();
            m[p] = 0;
            v.erase(v.begin());
            m[key] = value;
            v.emplace_back(key);
        }
        else
        {
            cur++;
            v.emplace_back(key);
            m[key] = value;
        }
    }
    int cap, cur;
    vector<int> v;
    map<int, int> m;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
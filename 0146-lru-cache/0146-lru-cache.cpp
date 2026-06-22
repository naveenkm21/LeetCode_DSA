class LRUCache {
  public:
    
    
    int cap;
    list<pair<int,int>> dll;
    unordered_map<int,list<pair<int,int>>::iterator> mp;
    
    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        
        if(mp.find(key) == mp.end())
           return -1;
           
        
        auto node = mp[key];
        int value = node->second;
        
        dll.erase(node);
        dll.push_front({key, value});
        
        mp[key] = dll.begin();
        
        return value;
        
    }

        
    void put(int key, int value) {
        
        if(mp.find(key) != mp.end()) {
            dll.erase(mp[key]);
        }
        else if(dll.size() == cap){
            auto last = dll.back();
            mp.erase(last.first);
            dll.pop_back();
        }
        
        dll.push_front({key,value});
        
        mp[key] = dll.begin();
        
    }
};
class LRUCache {
private:
    int cap;
    list<pair<int, int>> lru; 
    unordered_map<int, list<pair<int, int>>::iterator> cache; 

public:
    LRUCache(int capacity) : cap(capacity) {}

    int get(int key) {
        if (cache.find(key) == cache.end())
            return -1;

        lru.splice(lru.begin(), lru, cache[key]);
        return cache[key]->second;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            cache[key]->second = value;
            lru.splice(lru.begin(), lru, cache[key]);
        } else {
            if (lru.size() == cap) {
                int lru_key = lru.back().first;
                lru.pop_back();
                cache.erase(lru_key);
            }
            lru.emplace_front(key, value);
            cache[key] = lru.begin();
        }
    }
};

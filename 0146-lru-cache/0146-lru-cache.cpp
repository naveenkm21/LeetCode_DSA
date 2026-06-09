#include <unordered_map>
#include <list>

class LRUCache {
private:
    int capacity;
    std::list<std::pair<int, int>> dll; 
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cache;

public:
    LRUCache(int capacity) : capacity(capacity) {}
    
    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        
        dll.splice(dll.begin(), dll, cache[key]);
        return cache[key]->second;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            cache[key]->second = value;
            dll.splice(dll.begin(), dll, cache[key]);
            return;
        }
        
        if (cache.size() == capacity) {
            cache.erase(dll.back().first);
            dll.pop_back();
        }
        
        dll.emplace_front(key, value);
        cache[key] = dll.begin();
    }
};
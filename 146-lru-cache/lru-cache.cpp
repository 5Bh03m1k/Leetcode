class LRUCache {
private:
    unordered_map<int,_List_iterator<std::pair<int, int>>> table;
    list<pair<int,int>> ll;
    pair<int,int> p;
    int size;

    
public:
    LRUCache(int c) {
        size = c;
    }
    
    int get(int key) {
        if(table.find(key) == table.end())  return -1;
        
        p = *table[key];

        ll.erase(table[key]);
        ll.push_front(p);
        table[key] = ll.begin();
        return p.second;
    }
    
    void put(int key, int value) {
        if(table.find(key) != table.end())
        {
            table[key]->second = value;
            p=*table[key];
            ll.erase(table[key]);
            ll.push_front(p);
            table[key] = ll.begin();
            return;
        }
        ll.push_front({key,value});
        table[key] = ll.begin();

        if(size < ll.size())
        {
            table.erase(ll.back().first);
            ll.pop_back();
        }   
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
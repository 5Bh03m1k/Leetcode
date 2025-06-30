class LRUCache {
private:
    unordered_map<int,_List_iterator<std::pair<int, int>>> table;
    list<pair<int,int>> ll;
    int size;

    void swap_front(_List_iterator<std::pair<int, int>> it)
    {
        ll.push_front({it->first,it->second});
        table[it->first] = ll.begin();
        ll.erase(it);
    }
public:
    LRUCache(int c) {
        size = c;
    }
    
    int get(int key) {
        if(table.find(key) == table.end())  return -1;
    
        swap_front(table[key]);

        return table[key]->second;
    }
    
    void put(int key, int value) {
        if(table.find(key) != table.end())
        {
            table[key]->second = value;

            swap_front(table[key]);
           
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
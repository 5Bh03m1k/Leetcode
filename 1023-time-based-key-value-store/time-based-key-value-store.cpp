class TimeMap {
private:
    unordered_map< string , map<int,string> > table;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int time) {
       table[key][time] = value;

    }
    
    string get(string key, int time) {
        if(table.find(key) == table.end()) return "";
        if(time < table[key].begin()->first)   return "";

        auto it = table[key].lower_bound(time);
        
        if(it->first > time )    it--;

        if(it == table[key].end()) return table[key].rbegin()->second;
        return it->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
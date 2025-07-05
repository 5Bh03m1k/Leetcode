class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> table;
        int x = -1;

        for(auto i:arr)
            table[i]++;

        for(auto it:table)
            x = it.first == it.second ? (x > it.first ? x : it.first):x;

        return x;
        
    }
};
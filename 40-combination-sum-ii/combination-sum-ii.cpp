class Solution {
public:
    vector<vector<int>> res; 
    vector<pair<int,int>> table;
    int t;
    void fn( int sum = 0 , int itr = 0 , vector<int> a={})
    {
        if(sum == t)    {res.push_back(a);return;}
        if(sum > t)     return;
        if(itr >= table.size())     return;
        for(int i=0 ; i<table[itr].second ; i++)
            a.push_back(table[itr].first),sum+=table[itr].first;
            
        for(int i=0 ; i<=table[itr].second ; i++)
        {
            fn( sum , itr+1 , a);
            sum-=table[itr].first;
            a.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& can, int tar) {
        t = tar;
        unordered_map < int , int > hTable;
        for(int i=0 ; i<can.size() ; i++)
            hTable[can[i]]++;
        for(auto it=hTable.begin() ; it != hTable.end() ; it++)
            table.push_back({it->first,it->second});
        fn();
        return res;
    }
};
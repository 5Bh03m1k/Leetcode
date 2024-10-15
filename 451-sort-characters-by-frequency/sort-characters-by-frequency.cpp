class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char , int> hash;
        for(auto i:s)
            hash[i]+=1;
        priority_queue<pair<int,char>> pq;
        for(auto it = hash.begin() ; it != hash.end() ; it++)
            pq.push({it->second , it->first});
            s.clear();
        while(!pq.empty())
        {
            for(int i=0 ; i<pq.top().first ; i++)
                s+=pq.top().second;
            pq.pop();
        }
        return s;
    }
};
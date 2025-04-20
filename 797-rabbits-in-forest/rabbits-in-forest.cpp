class Solution {
public:
    int numRabbits(vector<int>& arr) {
        unordered_map<int,int> f;
        int sum = 0;

        for(auto i:arr)  f[++i]++;

        for(auto i:f)   sum += i.first*((i.second/i.first) + ((i.second % i.first) == 0? 0 : 1));

        return sum;
    }
};
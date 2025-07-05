class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int>table(501,0);
        int x = -1;

        for(auto i:arr)
            table[i]++;

        for(auto it:arr)
            x = table[it] == it && it > x? it : x;

        return x;
        
    }
};
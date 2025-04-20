class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> f;

        for(auto i:answers)
            f[i]++;

        int sum = 0;

        for(auto it = f.begin() ; it != f.end() ; it++)
            sum += ((it->second/(it -> first+1))  + (it->second%(it->first+1)>0 ? 1 : 0)) * (it -> first + 1);
            
        return sum;
    }
};
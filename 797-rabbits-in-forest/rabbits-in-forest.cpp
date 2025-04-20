class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> f;
        int sum = 0;

        for(auto i:answers)
            f[i]++;

        for(auto it :f )
            sum += ((it.second/(it.first+1))  + (it.second%(it.first+1)>0 ? 1 : 0)) * (it.first + 1);

        return sum;
    }
};
class Solution {
public:
    bool checkPerfectNumber(int num) {
        unordered_set<int> hash;
        hash.insert(6);
        hash.insert(28);
        hash.insert(496);
        hash.insert(8128);
        hash.insert(33550336);

        if(hash.find(num) != hash.end())    return true;
        return false;
    }
};
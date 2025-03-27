class Solution {
public:
    bool checkPerfectNumber(int num) {
        /*unordered_set<int> hash;
        hash.insert(6);
        hash.insert(28);
        hash.insert(496);
        hash.insert(8128);
        hash.insert(33550336);*/

        switch(num)
        {
            case 6:return true;
            case 28:return true;
            case 496:return true;
            case 8128:return true;
            case 33550336:return true;
            default :return false;
        }
    }
};
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int , int> hash;

        for(int i=0 ; i<arr.size() ; i++)
            hash[arr[i]]++;
        
        for(auto it = hash.begin() ; it != hash.end() ; it++){
            if(hash.find(it->first * 2) != hash.end()) 
            {
                if((it->first != 0 ) || (it->first == 0 && it->second > 1))
                return true;
            }
        }
        
        return false;
    }
};
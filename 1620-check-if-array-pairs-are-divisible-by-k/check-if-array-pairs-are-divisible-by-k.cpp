class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> table(k,{0});
        for(int i=0 ; i<arr.size() ; i++){if(arr[i]<0)  arr[i] = k+( arr[i]%k);table[arr[i]%k]++;}
        if(table[0]%2 != 0 ) return false;
        for(int i=1 ; i<=k/2 ; i++)
            if(table[i] != table[k-i]) return false;
        return true;
    }
};
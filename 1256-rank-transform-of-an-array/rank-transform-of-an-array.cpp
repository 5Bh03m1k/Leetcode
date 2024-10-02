class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> a,b;
        a = arr;
        sort(a.begin(),a.end());
        int tmp = 1;
        b.push_back(1);
        for(int i=1 ; i<a.size() ; i++)
        {
            if(a[i] != a[i-1])  tmp++;
            b.push_back(tmp);
        }
        unordered_map<int,int> table;
         for(int i=0 ; i<a.size() ; i++)
        {
            table[a[i]] = b[i];
        }
        b.clear();
        for(int i=0 ; i<a.size() ; i++)
        {
           b.push_back( table[arr[i]]) ;
        }
        return b;

    }
};
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int,string>> arr;
        int n = names.size();
        for(int i=0 ; i<n ; i++)
            arr.push_back({heights[i] , names[i]});
        sort(arr.begin() , arr.end());
        for(int i=n-1 ; i>=0 ; i--)
            names[n-1-i] = arr[i].second;
        return names;
    }
};
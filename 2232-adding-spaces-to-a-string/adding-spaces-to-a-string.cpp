class Solution {
public:
    string addSpaces(string s, vector<int>& arr) {
        string ans = "" , space = " ";
        int j = 0;

        for(int i=0 ; i<s.size() ; i++)
        {
            if(j < arr.size() && i == arr[j] ) ans.append(space), j++;
            ans += s[i];
        }

        return ans;
    }
};
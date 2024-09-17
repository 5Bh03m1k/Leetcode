class Solution {
public:
    vector<vector<int>> arr;
    int fn(int itr )
    {
        if(itr == 0)    return arr[0][0];
        for(int i=0 ; i<arr[itr-1].size() ; i++)
        {
            arr[itr-1][i]+=min(arr[itr][i],arr[itr][i+1]);
        }
        return fn(itr-1);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        arr = triangle;
        return fn(triangle.size()-1);
    }
};
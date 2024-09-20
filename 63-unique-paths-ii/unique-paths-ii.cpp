class Solution {
public:
    
    int fx(int x , int y,vector<vector<int>>& arr,vector<vector<int>>& table)
    {
        int c;
        if(arr[x][y] == 1)  return 0;
        if(table[x][y] != INT_MAX)  return table[x][y];
        if(x==0 && y==0)    c = 1;
        else if(x == 0)  c = fx( x , y-1 , arr , table);
        else if(y == 0)  c = fx( x-1 , y , arr , table);
        else c = fx( x-1 , y , arr ,table) + fx( x , y-1 , arr , table);
        table[x][y] = c;
        return c;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& id) {
        vector<vector<int>> arr(id.size(),(vector<int> (id[0].size(),INT_MAX)));
        return fx(id.size()-1 , id[0].size()-1 , id , arr);
    }
};
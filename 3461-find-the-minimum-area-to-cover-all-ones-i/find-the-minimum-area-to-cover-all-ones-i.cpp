class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int lo[2] = {INT_MAX , INT_MAX} , hi[2] = {INT_MIN , INT_MIN};

        for(int i = 0 ; i < grid.size() ; i++)
        {
            for(int j = 0 ; j < grid[0].size() ; j++)
            {
                if(grid[i][j]){
                lo[0] = min(lo[0],i);
                lo[1] = min(lo[1],j);
                hi[0] = max(hi[0],i+1);
                hi[1] = max(hi[1],j+1);
                }
            }
        }
        cout<<hi[0]<<lo[0]<<hi[1]<<lo[1];
        return (hi[0]-lo[0])*(hi[1]-lo[1]);
    }
};
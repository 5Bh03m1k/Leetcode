class Solution {
public:
    // vector<vector<int>>mem
    int fx(int x , int y , vector<vector<int>>& grid ,  vector<vector<int>>&mem)
    {
        int n=grid[x][y];
        if(x==0 && y==0)    
            return n;
        else if(mem[x][y] != INT_MAX) return mem[x][y];
        else if(x==0)
            n += fx(x,y-1,grid,mem);
        else if(y==0)
            n += fx(x-1,y,grid,mem);
        else
            n += min(fx(x-1,y,grid,mem),fx(x,y-1,grid,mem));
        return mem[x][y]=n;
        
    }
    int minPathSum(vector<vector<int>>& grid) {
         vector<vector<int>>mem(grid.size() , vector<int>(grid[0].size(),INT_MAX));
       return fx(grid.size()-1,grid[0].size()-1,grid,mem);
    }
};
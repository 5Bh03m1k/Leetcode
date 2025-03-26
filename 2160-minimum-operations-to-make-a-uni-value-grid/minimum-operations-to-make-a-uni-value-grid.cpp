class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;
        for(int i=0 ; i<grid.size() ; i++)
        {
            for(int j=0 ; j<grid[0].size() ; j++)
                arr.push_back(grid[i][j]);
        }

        sort(arr.begin(),arr.end());

        int sum = 0,l=arr.size();
        for(int i=0 ; i<l ; i++)
        {
            if(abs(arr[i] - arr[l/2])%x != 0)   return -1;
            sum+=abs(arr[i] - arr[l/2])/x;
        }
        return sum;
    }
};
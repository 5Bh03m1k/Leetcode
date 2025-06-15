class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& lst, int sr, int sc, int c) {
        
        queue<pair<int,int>> q;

        int oc = lst[sr][sc];

        if(c == oc) return lst;

        q.push({sr,sc});
        lst[sr][sc] = c;

        while(!q.empty())
        {
           int x = q.front().first , y = q.front().second;

           if(x-1 >= 0 && lst[x-1][y] == oc) lst[x-1][y] = c , q.push({x-1,y});
           if(x+1 < lst.size() && lst[x+1][y] == oc) lst[x+1][y] = c , q.push({x+1,y});
           if(y-1 >= 0 && lst[x][y-1] == oc) lst[x][y-1] = c , q.push({x,y-1});
           if(y+1 < lst[0].size()  && lst[x][y+1] == oc) lst[x][y+1] = c , q.push({x,y+1});

           q.pop();
        }

        return lst;
    }
};
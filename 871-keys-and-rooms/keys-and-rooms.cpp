class Solution {
public:
    void dfs(vector<vector<int>>&al , vector<bool>&v , int n)
    {
        v[n] = false;

        for(auto i:al[n])
        {
            if(v[i])
            {
                v[i] = false;
                dfs(al,v,i);
                //cout<<i<<" ";
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> v(rooms.size(),true);

        dfs(rooms,v,0);

        for(auto i:v)
        {
           if(i)    return false;
        }

        return true;
    }
};
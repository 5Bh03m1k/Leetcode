class Solution {
public:
    void dfs(vector<vector<int>>&al , bool *v , int n)
    {
        v[n] = true;

        for(auto i:al[n])
        {
            if(v[i] == false)
            {
                v[i] = true;
                dfs(al,v,i);
                //cout<<i<<" ";
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        bool* v = (bool*)calloc(rooms.size(),sizeof(bool));

        for(int i = 0 ; i < rooms.size() ; i++)
            cout<<(v[i]?"true":"false")<<" ";

        dfs(rooms,v,0);

        for(int i = 0 ; i < rooms.size() ; i++)
         {
            if(v[i] == false)    return false;
         }

        return true;
    }
};
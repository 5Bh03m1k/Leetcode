class p{
        vector<bitset<101>> hash;
    public:
        p(int n)
        {
            vector<bitset<101>> Hmap(n);
            hash = Hmap;
        }

        void dfs(vector<vector<int>>&al,vector<bool>&vis , int n)
        {
            if(vis[n])  return;

            vis[n] = true;

            for(auto& i:al[n])
            {
                hash[n].set(i);
                dfs(al,vis,i);

                for(int it = 0 ; it < hash[i].size() ; it++)
                {
                    if(hash[i].test(it))
                        hash[n].set(it);
                }
                
            }

            return;
        }

        void graph(int n , vector<vector<int>>&arr)
        {
            vector<vector<int>> al(n);
            vector<int> in(n,0);
            vector<bool> vis(n,false);

            for(auto& i:arr)
            {
                al[i[0]].push_back(i[1]);
                in[i[1]]++;
            }

            int c = 0;

            for(auto& i:in)
            {
                if( i == 0 ) dfs(al,vis,c);
                c++;
            }


        }

        bool query(int a , int b)
        {
            return hash[a][b];
        }

    };
class Solution {  
public:
    vector<bool> checkIfPrerequisite(int nu, vector<vector<int>>& ps, vector<vector<int>>& queries) {

        p it(nu);
        it.graph(nu,ps);

        vector<bool> arr;

        for(auto& i:queries)
            arr.push_back(it.query(i[0],i[1]));
        

        return arr;
    }
};
class Solution {
private:
    bool bfs(vector<vector<int>>&al, int n , vector<int> &c)
    {
            queue<int> q;
                q.push(n);
                c[n] = 0;
                bool tmp = false;


                while(!(q.empty()))
                {
                    tmp = !tmp;
                    int s = q.size();

                    for(int it = 0 ; it < s ; it++)
                    {
                        int n = q.front();

                        for(auto j:al[n])
                        {
                            if(c[j] == -1)  q.push(j),c[j] = tmp ? 1:0;
                            if( (c[j] ==0 && tmp) || ( c[j] == 1 && tmp == false) )return false;

                            
                        }

                        q.pop();
                    }
                }

                return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> c(n,-1);
        
        for(int i = 0 ; i < n  ; i++)
        {
            if(c[i] == -1)
            {
                if(bfs(graph,i,c) == false) return false;
            }
        }

        return true;
    }
};
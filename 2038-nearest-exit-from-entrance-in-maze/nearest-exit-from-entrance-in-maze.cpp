class Solution {
public:
    int nearestExit(vector<vector<char>>& arr, vector<int>& e) {
        int a = arr.size(),b = arr[0].size();
        queue<pair<int,int>> q;
        bool flag = false;
        int c = 1 , n , x , y;

        q.push({e[0],e[1]});
        //arr[e[0]][e[1]] = '+';
        
        

        while(!q.empty())
        {
            n = q.size();
            
            for(int i = 0 ; i < n ; i++)
            {
                x = q.front().first , y = q.front().second;
                //cout<<x<<" "<<y<<endl;
                arr[x][y] = '+';

                if(x-1 >= 0 && arr[x-1][y] == '.')
                {
                    
                    if( x-1 == 0 || y == 0 || y == arr[0].size()-1)  return c;
                    arr[x-1][y] = '+';
                    q.push({x-1,y});
                }
                    
                if(x+1 < arr.size()  && arr[x+1][y] == '.'){
                    if( x+1 == arr.size()-1 || y == 0 || y == arr[0].size()-1)  return c;
                    arr[x+1][y] = '+';
                    q.push({x+1,y});
                }
                if(y +1  < arr[0].size() && arr[x][y+1] == '.'){
                    if( y+1 == arr[0].size()-1 || x == 0 || x == arr.size()-1)  return c;
                    arr[x][y+1] = '+';
                    q.push({x,y+1});
                }
                if(y-1 >= 0 &&  arr[x][y-1] == '.'){
                    if( y-1 == 0 || x == 0 || x == arr.size()-1)  return c;
                    arr[x][y-1] = '+';
                    q.push({x,y-1});
                }
                q.pop();
            }

            c++;
        }

        return -1;
    }
};
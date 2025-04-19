class Solution {
public:
    bool isvalid(vector<vector<char>>&arr , int i , int j , char n)
    {
        for(int x = 0 ; x<9 ; x++)
        {
            if(arr[i][x] == n
            ||arr[x][j] == n
            ||arr[(i/3)*3 + x/3][(j/3)*3 + x%3] == n)  return false;
        }
        return true;
    }
    bool s(vector<vector<char>>&arr)
    {
       
        for(int i=0 ; i<9 ; i++)
        {
            for(int j=0 ; j<9 ; j++)
            {
                if(arr[i][j] == '.')
                { 
                    for(char k='1' ; k<='9' ; k++)
                    {
                        
                        if(isvalid(arr , i , j , k))
                        {
                            arr[i][j] = k;
                            if(s(arr)) goto l;
                           arr[i][j] = '.';
                        }
                        
                         
                    }
                   if(arr[i][j] == '.') return false;
                    
                }
            }
        }
        l:
        return true;
    }
    void solveSudoku(vector<vector<char>>& arr) {
        s(arr);
        
    }
};
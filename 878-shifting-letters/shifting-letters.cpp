class Solution {
private:
    char shift(char ch , int n)
    {
        n %= 26;

        int k = (((int) (ch - 'a')) + n)%26;

        return (char) (k + (int)'a');
    }
public:
    string shiftingLetters(string s, vector<int>& arr) {

        long long int n = 0;

        for(int i = arr.size() - 1 ; i >= 0 ; i--)
        {
            n += (arr[i])%26;
            n%=26;
             s[i] = shift(s[i] , n);
            
        }
        
        return s;
    }
};
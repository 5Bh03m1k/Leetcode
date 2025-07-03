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

        int n = 0;

        for(int i = 0 ; i < arr.size() ; i++)
            arr[i] %= 26;

        for(int i = arr.size() - 1 ; i >= 0 ; i--)
        {
            // arr[i]%=26
            n += arr[i];

            arr[i] = n;
        }
        
        for(int i = 0 ; i < s.size() ; i++)
        {
            s[i] = shift(s[i] , arr[i]);
        }


        return s;
    }
};
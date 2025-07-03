class Solution {
public:
    char kthCharacter(int k) {
        string  a = "a";
        string b = "";

        for(int i = 0 ; a.size() < k ; i++)
        {
            for(auto ch:a)
            {
                if(ch == 'z')   b = b +'a';

                else b = b + (char)((int)ch + 1);
            }

            a = a + b;
            b = "";
        }

        return a[k-1];
        
    }
};
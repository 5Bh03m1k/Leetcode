class Solution {
public:
    bool isValid(string word) {
        if(word.size() < 3) return false;
        bool v = true , c = true ;

        for(int i = 0 ; i < word.size() ; i++)
        {
            if(!isalnum(word[i]))    return false;
            switch(word[i])
            {
                case 'a' :v = false;break;case 'A': v = false;break;
                case 'e' :v = false;break;case 'E': v = false;break;
                case 'i' :v = false;break;case 'I':v = false;break;
                case 'o' :v = false;break;case 'O':v = false;break;
                case 'u' :v = false;break;case 'U':v = false;break;
                default: if(!isdigit(word[i]))    c = false;
            }

        }

        cout<<v<<c;

        return !(v || c);
    }
};
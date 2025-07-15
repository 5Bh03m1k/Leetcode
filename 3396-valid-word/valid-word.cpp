class Solution {
public:
    bool isValid(string word) {
        if(word.size() < 3) return false;
        bool v = true , c = true ;

        for(auto& i:word)
        {
            if(isalnum(i) == false)    return false;
            switch(i)
            {
                case 'a': v = false;break;
                case 'e': v = false;break;
                case 'i':v = false;break;
                case 'o':v = false;break;
                case 'u':v = false;break;
                case 'A': v = false;break;
                case 'E': v = false;break;
                case 'I':v = false;break;
                case 'O':v = false;break;
                case 'U':v = false;break;
                default: if(isdigit(i) == false)    c = false;
            }

        }

        if(v || c)  return false;
        return true;
    }
};
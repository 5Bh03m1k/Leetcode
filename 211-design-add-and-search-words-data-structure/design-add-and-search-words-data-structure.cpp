class t_ll{
public:
    t_ll* arr[26] = {nullptr};  
    bool flag = false;
};


class WordDictionary {
private:
    t_ll* head;

bool sh(string word , int i, t_ll* tmp) 
 {
        if(word.size() == i)    return tmp->flag;

        if(word[i] == '.')
        {
            //bool flag = false;

            for(int it = 0 ; it < 26 ; it++)
            {
                if(tmp->arr[it] != nullptr)
                {
                    if(sh(word,i+1,tmp->arr[it])) return true;
                }
            }

            return false;
        }

        if(tmp->arr[word[i] - 'a'] == nullptr)   return false;

        return sh(word,i+1,tmp->arr[word[i] - 'a']);
        
}

public:
    WordDictionary() {
        t_ll* tmp = new t_ll();
        head = tmp;
    }
    
    void addWord(string word) {
        t_ll* tmp = head;

        for(auto& i:word)
        {
            if(tmp->arr[i-'a'] == nullptr) 
            {
                t_ll* next = new t_ll;
                tmp->arr[i-'a'] = next;
                tmp = next; 
            }

            else
            {
                tmp = tmp->arr[i-'a'];
            }
        }

        tmp->flag = true;
    }
    
    bool search(string word)
    {
        return sh(word,0,head);
    }
};
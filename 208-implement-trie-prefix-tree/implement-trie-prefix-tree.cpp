class t_ll{
public:
    t_ll* arr[26] = {nullptr};  
    bool flag = false;
};


class Trie {
private:
    t_ll* head;
public:

    Trie() {
        t_ll* tmp = new t_ll;
        head = tmp;
        //delete(tmp);
    }
    
    void insert(string word) {
        t_ll* tmp = head;
        
        for(auto& ch:word)
        {
            if(tmp->arr[ch-'a'] == nullptr)
            {
                t_ll* next = new t_ll;
                tmp->arr[ch-'a'] = next;
                tmp = next;
                //delete(next);
            }
            else
            {
                tmp = tmp ->arr[ch-'a'];
            }
        }

        tmp->flag = true;

        return;
    }
    
    bool search(string word) {
        t_ll* tmp = head;

        for(auto& ch:word)
        {
            if(tmp->arr[ch-'a'] == nullptr) return false;

            tmp = tmp->arr[ch-'a'];
        }

        return tmp->flag;
        
    }
    
    bool startsWith(string word) {
        t_ll* tmp = head;

        for(auto& ch:word)
        {
            if(tmp->arr[ch-'a'] == nullptr) return false;

            tmp = tmp->arr[ch-'a'];
        }
        
        return true;
    }
};

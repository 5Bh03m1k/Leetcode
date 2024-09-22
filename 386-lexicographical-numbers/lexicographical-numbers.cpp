class Solution {
public:
    int num;
    void fn(int x , vector<int>&a)
    {
        if(num < x) return;
        a.push_back(x);
        x*=10;
        if(num < x) return;
        for(int i=0 ; i<10 ; i++)
            fn(x+i,a);

    }
    vector<int> lexicalOrder(int n) {
        num = n;
        vector<int> sol;
        for(int i=1 ; i < 10 ; i++)
            fn(i,sol);
        return sol;
        }
};
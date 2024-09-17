class Solution {
public:
    vector<int> curr;
    unordered_map<int,int> table;
    int fn(int r)
    {
        if(table.find(r)!=table.end())  return table[r];
        if(r==0)    return 0;
        if(r<0)     return -1;
        int sum=0,min=INT_MAX,itr;
        for(int i=0 ; i<curr.size() ; i++)
            sum=(fn(r-curr[i])),min = sum>=0?(min>sum?sum:min):min;
        if(min == INT_MAX)  
            itr =-1;
        else
            itr= min+1;
        table[r] = itr;
        return itr;
    }
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        curr=coins;
        int r=fn(amount);
        // if(r==0)    return -1;
        return r;
    }
};
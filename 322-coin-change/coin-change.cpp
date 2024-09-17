class Solution {
public:
    vector<int> curr;
    int table[10002]={0};
    int fn(int r)
    {
        if(r==0)    return 0;
        if(r<0)     return -1;
        if(table[r]!= 0)  return table[r];
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
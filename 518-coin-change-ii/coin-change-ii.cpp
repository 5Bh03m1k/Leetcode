class Solution {
public:
    vector<int> curr;
    unordered_map<long long,int >table;
    int fn(int r,int itr=0)
    {
        if(r==0)    return 1;
        if(r<0)     return 0;
        if(itr == curr.size())  return 0;
        if(table.find(r*curr.size()+itr)!=table.end() )   return table[r*curr.size()+itr];
        int sum=0;
        for(int i=0 ; i<=r ; i+=curr[itr])
            sum+=fn(r-i,itr+1);
         table[r*curr.size()+itr]=sum;
         return sum;
    }
    int change(int amount, vector<int>& coins) {
        curr = coins;
      return  fn(amount);
    }
};
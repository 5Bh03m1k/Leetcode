class Solution {
public:
    // vector<int> mem;

    int fn(int itr,vector<int>&table,vector<int>&meme)
    {
         if(meme[itr]!=0)    return meme[itr];
        vector<int> x;
        for(int i=itr ; i<table.size() ; i++)
        {
            if(table[itr]<table[i])
                x.push_back(i);
        }
        int max=0;
        for(int i=0 ; i<x.size() ; i++)
        {
            int r=fn(x[i],table,meme);
            max = max<r ? r:max;
        }
        return meme[itr] = max+1;
    }

    int lengthOfLIS(vector<int>& nums) {
        int max=0 , n=nums.size();
        vector<int>meme(n,0);
        for(int i=0 ; i<nums.size() ; i++){
            int r=fn(i,nums,meme);
            max = max > r ? max : r;
        }
        return max;
        
    }
};
class Solution {
public:
    int fn(int itr,vector<int>&table,vector<int>&meme)
    {
         if(meme[itr]!=0)    return meme[itr];
        vector<int> x;
        int min_itr = INT_MAX,max=0;
        for(int i=itr ; i<table.size() ; i++)
        {
            if(table[itr]<table[i])
            {
                if(min_itr > table[i]){
                    int r=fn(i,table,meme);
                    max = max<r ? r:max;
                    min_itr = table[i];
                }
            }
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
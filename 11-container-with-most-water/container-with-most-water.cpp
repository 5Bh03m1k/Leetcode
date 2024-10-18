class Solution {
public:
    int fn(int i , int j , int maxi , vector<int>&h)
    {
        if(i == j)  return maxi;
        maxi = max(maxi , min(h[i],h[j])*(j-i));
        if(h[i] > h[j]) return fn(i,j-1,maxi,h);
        else return fn(i+1 , j , maxi , h);
    }
    int maxArea(vector<int>& h) {
         int maxi = INT_MIN , i=0 , j = h.size()-1;
         return fn(i,j,maxi,h);
    }
    private:
        unordered_map<int,unordered_map<int,int>> memo;
};
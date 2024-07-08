class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int > a;
        for(int i=0 ; i<n ; i++)
            a.push_back(i+1);
        int i = 0,ans;
            k--;
        while(true)
        {
            if(a.size()==1){
                ans=a[0];
                break;
            }
            i+=k;
            i%=a.size();
            a.erase(a.begin()+i);
        }
        return ans;
    }
};
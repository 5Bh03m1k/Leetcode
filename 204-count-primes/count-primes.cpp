class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2)   return 0;
        vector<bool> arr(n , true);       
        n--;

        arr[0] =true;
        for(int i=2 ; i*i <= n ; i++)
        {
            if(arr[i]){
                for(int j=2*i ; j<= n ; j+=i)
                {
                    if(arr[j])arr[j]=false;
                }
            }
            
        }
        int count=0;
        for(auto i:arr){
            if(i) count++;
        }
        return count-2;

    }
};
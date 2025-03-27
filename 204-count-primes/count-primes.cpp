vector<int> arr;
class Solution {
public:
    int countPrimes(int n) {
        if(n == 0)  return 0;
        ////////////////////////////
        n--;
        if(n == 1 || n==0) return 0;
        if(arr.size() == 0)
            arr.push_back(2);

        if(n == 2) {
            return 1;
        }
        int tmp = 1;
        for(int j=3 ; j<=n ; j+=2){
            if(arr.size()>tmp){
                if(arr[tmp] == j)   tmp++;
                goto stop;
            }
            else{
                    int s = sqrt(j);
                for(int i=0; arr[i] <=s ; i++)
                {
                    if(j%arr[i] == 0)   goto stop;
                }
                arr.push_back(j);
                tmp++;
            }
            stop:;
        }
        return tmp;
    }
};
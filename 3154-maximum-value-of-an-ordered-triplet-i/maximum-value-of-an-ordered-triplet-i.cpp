class Solution {
private:
    long long val(int i , int j ,int k , vector<int>& num , long long m ){
        long long n = (long long)(num[i] - num[j])*(long long)num[k];
        return n > m ? n : m;
    }
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long soln = 0;
        for(int i=0 ; i<nums.size() ; i++){
            for(int j = i+1 ; j<nums.size() ; j++){
                for(int k = j+1 ; k<nums.size() ; k++){
                    soln = val( i , j , k , nums , soln);
                } 
            }
        }
        return soln;
    }
};
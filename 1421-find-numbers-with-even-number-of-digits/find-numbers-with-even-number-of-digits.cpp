class Solution {
public:
    bool is_digit_even(int n)
    {
        bool flag = false;
        n /= 10;
        while(n)
        {
            flag  = !flag;
            n/=10; 
        }

        return flag;
    }
    int findNumbers(vector<int>& nums) {
        int sum = 0;

        for(auto i:nums)
        {
            if(is_digit_even(i))    sum++;
        }
        
        return sum;
    }
};
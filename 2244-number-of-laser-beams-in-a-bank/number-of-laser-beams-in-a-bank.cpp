class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int>arr;
        int cnt;

        for(auto& i:bank)
        {
            cnt = 0;
            for(auto& j:i)
            {
                cnt += j == '1' ? 1 : 0;
            }
            if(cnt)
                arr.push_back(cnt);
        }

        if(arr.size() == 0 || arr.size() == 1)  return 0;

        cnt = 0;

        for(int i = 0 ; i < arr.size() - 1 ; i++)
        {
            cnt += arr[i]*arr[i+1];
        }

        return cnt;

    }
};
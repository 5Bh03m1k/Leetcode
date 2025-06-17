class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        queue<int> qp;
        queue<int> qn;

        for(auto i:nums)
            i > 0 ? qp.push(i) : qn.push(i);
        
        nums.clear();

        while(!qp.empty())
        {
            nums.push_back(qp.front());
            nums.push_back(qn.front());
            qp.pop();
            qn.pop();
        }

        return nums;
    }
};
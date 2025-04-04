class MedianFinder {
public:
    priority_queue<int> d;
    priority_queue<int , vector<int> , greater<int>> u;
    vector<int> a;
    MedianFinder() {
    }
    
    void addNum(int num) {
        if( d.size() == 0 && u.size() == 0 && (a.size() == 0 || a.size() == 1))
        {  
             switch(a.size())
            {
                case 0:{a.push_back(num);  return;}
                default : {
                                d.push(min(a[0],num));
                                u.push(max(a[0],num));
                                a.clear();
                                return;
                            }
            }
        }

        int n;
        if(num > u.top())
            u.push(num),n=u.top(),u.pop();
        else if(num < d.top())
            d.push(num),n=d.top(),d.pop();
        else    n = num;

        switch(a.size())
        {
            case 0:{a.push_back(n);  return;}
            default : {
                            d.push(min(a[0],n));
                            u.push(max(a[0],n));
                            a.clear();
                            return;
                        }
        }

    }
    
    double findMedian() {
        // double n;
        switch(a.size())
        {
            case 0: return (double)((d.top()+u.top()))/2 ;
            case 1: return a[0];
            default : return 0;
        }
        return 0;
    }
};

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    MedianFinder a;
    for(auto i:nums1)   a.addNum(i);
    for(auto i:nums2)   a.addNum(i);
    return a.findMedian();
    }
};
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
            a.push_back(num);
            if(a.size() == 2)
            {
                d.push(min(a[0],a[1]));
                u.push(max(a[0],a[1]));
                a.clear();
            }
            return;
        }

        int n;
        if(num > u.top())
            u.push(num),n=u.top(),u.pop();
        else if(num < d.top())
            d.push(num),n=d.top(),d.pop();
        else    n = num;


        if(a.size() == 0) {  a.push_back(n);  return;}
        if(a.size() == 1)
        {
            d.push(min(a[0],n));
            u.push(max(a[0],n));
            a.clear();
            return;
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

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
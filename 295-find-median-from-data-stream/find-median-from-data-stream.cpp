class MedianFinder {
private:
    priority_queue<int> maxh;
    priority_queue<int , vector<int> , greater<int>> minh;
    int a,b;
public:
    MedianFinder() {

        
        
    }
    
    void addNum(int nums) {

        if(maxh.size() > 0 && nums > maxh.top()) minh.push(nums);
        else maxh.push(nums);

         a = maxh.size() , b = minh.size();

        if(abs(a-b) > 1 )
        {
            if(a > b){
                minh.push(maxh.top());
                maxh.pop();
            }

            else{
                maxh.push(minh.top());
                minh.pop();
            }
        }
        
    }
    
    double findMedian() {

        if(maxh.size() == minh.size())  return ((double)(maxh.top()+minh.top()))/2;
        return maxh.size() > minh.size() ? maxh.top() : minh.top();
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
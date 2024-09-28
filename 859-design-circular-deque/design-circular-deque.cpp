class MyCircularDeque {
public:
    MyCircularDeque(int k) {
        max=k;
    }
    
    bool insertFront(int value) {
        if(q.size() == max) return false;
        q.push_front(value);
        return true;
    }
    
    bool insertLast(int value) {
        
        if(q.size() == max) return false;
        q.push_back(value);
        return true;
    }
    
    bool deleteFront() {
        if(q.size() == 0) return false;
        q.pop_front();
        return true;
    }
    
    bool deleteLast() {
        
        if(q.size() == 0) return false;
        q.pop_back();
        return true;
    }
    
    int getFront() {
        if(q.size() == 0)   return -1;
        return q.front();
    }
    
    int getRear() {
        if(q.size() == 0)   return -1;
        return q.back();
    }
    
    bool isEmpty() {
        if(q.size() == 0)   return true;
        return false;
    }
    
    bool isFull() {
        if(q.size() ==  max)    return true;
        return false;
        
    }
private:
    deque<int> q;
    int max;
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
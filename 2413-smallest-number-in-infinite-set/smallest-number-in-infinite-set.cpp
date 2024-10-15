class SmallestInfiniteSet {
public:
    priority_queue<int , vector<int> , greater<int>> q;
    unordered_set<int> os;
    int main=1;
    SmallestInfiniteSet() {
    }
    
    int popSmallest() {
        if(q.size()==0){
            main++;
            return main-1;
        }
        int t = q.top();
        q.pop();
        os.erase(t);
        return t;
    }
    
    void addBack(int num) {
        if(num >= main) return;
        if(os.find(num) == os.end())
            q.push(num),os.insert(num);
        
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
class ProductOfNumbers {
public:
    vector<int> a;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        a.push_back(num);
    }
    
    int getProduct(int k) {
        int m=1;
        for(int i = 0; i<k ; i++)
        {
            if(i == a.size()) return m;
            m*=a[a.size()-1-i];
        }
        return m;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
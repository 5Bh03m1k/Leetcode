class Solution {
public:
    int fn(vector<int>& n, int t,int l,int r)
    {
        if(n[l] == t)
            return l;
        if(n[r] == t)
            return r;
        int mid = (l + r) / 2;
        if(l == mid || r == mid)
            return -1;
        if(n[mid] > t)
            r = mid;
        else
            l = mid;
        return fn(n,t,l,r);
    }
    int search(vector<int>& n, int t) {
        return fn(n,t,0,n.size()-1);
    }
};
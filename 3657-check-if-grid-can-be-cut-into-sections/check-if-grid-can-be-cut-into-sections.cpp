class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& arr) {
        vector<int> sv;
        vector<int> sh;
        vector<vector<int>> x,y;
        vector<int>tmp;

        for(int i=0  ; i<arr.size() ; i++)
        {
            tmp.push_back(arr[i][0]),tmp.push_back(arr[i][2]);
            x.push_back(tmp);
            tmp.clear();
            tmp.push_back(arr[i][1]),tmp.push_back(arr[i][3]);
            y.push_back(tmp);
            tmp.clear();

        }

        sort(x.begin(),x.end());
        sort(y.begin() , y.end());

        for(int i = 0 ; i < x.size() ; i++ )
        {
            ////////////////////x///////////////
            if(sv.size()==0 || sv.back()<=x[i][0])
            {
                sv.push_back(x[i][0]);
                sv.push_back(x[i][1]);
            }

            else{
                if(sv.back()<x[i][1])
                {
                    sv.pop_back();
                    sv.push_back(x[i][1]);
                }
            }
            ////////////////////////////

            /////////////////y/////////////
            if(sh.size()==0 || sh.back()<=y[i][0])
            {
                sh.push_back(y[i][0]);
                sh.push_back(y[i][1]);
            }

            else{
                if(sh.back()<y[i][1])
                {
                    sh.pop_back();
                    sh.push_back(y[i][1]);
                }
            }
            ///////////////////////////////
        }
        cout<<sv.size()<<" "<<sh.size();
        if(sv.size() >= 6 || sh.size() >= 6)    return true;

        return false;
    }
};
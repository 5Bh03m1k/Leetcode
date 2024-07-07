/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 static const int __ = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Codec {//using DFS//
public:

    // Encodes a tree to a single string.
    void fn(TreeNode* root , string &a)
    {
        if(root==nullptr)
        {
            a.append("1010 ");
            return;
        }
        a.append(to_string(root->val)+' ');
        fn(root->left,a);
        fn(root->right,a);
    }//performs DFS;
    string serialize(TreeNode* root) {
        string a;
        if(root == nullptr)
            return a;
        fn(root,a);
        cout<<a;
        return a;
        
    }

    // Decodes your encoded data to tree.
    //////////////////get string//////////////
    int index=0;
    string s;
    int stl()
    {
        if(index >= s.size())
            return INT_MIN;
        string a="";
        while(s[index]!= ' ')
                a=a+s[index],index++;
        index++;
            return(stoi(a));
    }
    ////////////////////////////////////////////
    //////////////////////create node//////////////////
    TreeNode* create(int n)
    {
        TreeNode* itr = new TreeNode;
        itr->val=n;
        itr->left=nullptr;
        itr->right=nullptr;
        return itr;
    }
    //////////////////////////////////////////////////
    void func(TreeNode* root)
    {
        int a=stl();
        if(a == INT_MIN)
            return ;
        if(a != 1010){
            root->left=create(a);
            func(root->left);
        }
            a=stl();
            if(a == INT_MIN)
                 return ;
            if(a != 1010){
            root->right=create(a);
            func(root->right);
            }
                return;
    }
    /////////////////////////////////////////////////
    TreeNode* deserialize(string data) {
        if(data.size() == 0)
            return nullptr;
        s=data;
        TreeNode* root = create(stl());
        func(root);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
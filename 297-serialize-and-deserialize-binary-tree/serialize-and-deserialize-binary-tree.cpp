/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
////////////////////////////////////////////coding////////////////////////////////////////////
// Encodes a tree to a single string.
    string a="";
    queue<TreeNode*> q;
    void fn(int n)
    {
        if(n==0)
            return;
        TreeNode* root;
        for(int i=0 ; i<n ; i++)
        {
            root=q.front();
            q.pop();
            if(root == nullptr)
            {
                a.append("1010 ");
            }
            else
            {
                a.append(to_string(root->val)+' ');
                q.push(root->left);
                q.push(root->right);
            }
        }
        fn(q.size());
    }
    string serialize(TreeNode* root) {
        if(root == nullptr)
            return a;
        q.push(root);
        fn(1);
        return a;
    }
////////////////////////////////////////////////////////////////////////////////////////////////
///////using level order search to encode and decode !!! should try others//////////////////////
/////////////////////////////////////////////////decoding///////////////////////////////////////
    // Decodes your encoded data to tree.
    int index=0;
    string s;
    int stl()
    {
        string a="";
        while(s[index]!= ' ')
                a=a+s[index],index++;
        index++;
            return(stoi(a));
    }//string to array of integer
        /////////////////////////create to treeNode/////////////////////
    TreeNode* create(int n)
    {
        TreeNode* itr = new TreeNode;
        itr->val=n;
        itr->left=nullptr;
        itr->right=nullptr;
        return itr;
    }
        ///////////////////////queue to tree/////////////
    void crt(int n)
    {
        if(n==0)
            return;
        for(int itr=0 ; itr<n ; itr++)
        {
            TreeNode* root=q.front();
            q.pop();
            int a=stl();
            if(a != 1010)                ///flag INT_MIN
            {
                TreeNode* le=create(a);
                root->left = le;
                q.push(root->left);
            }
            a=stl();
            if(a!= 1010)                     ////flagINT_MIN
            {
                TreeNode* le=create(a);
                root->right = le;
                q.push(root->right);
            }
        }
        return crt(q.size());
    }
    TreeNode* deserialize(string data) {
        if(data.size()==0)
            return nullptr;
            s=data;
        TreeNode* root=create(stl());
        q.push(root);
        crt(1);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
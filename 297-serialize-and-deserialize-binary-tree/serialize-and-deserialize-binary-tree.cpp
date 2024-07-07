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
/*string x = "12 65 98 A";
stringstream s;
s << x;
int temp;
while(s>>temp){
    ...
}
////////////////////////////////////////////////////////////////////////////////
// Encodes a tree to a single string.
   /* string a="";
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
                string l="N ";
                a=a+l;
            }
            else
            {
                q.push(root->left);
                q.push(root->right);
                string l=to_string(root->val);
                a=a+l+' ';
            }
        }
        fn(q.size());
    }*/
    //string
    string serialize(TreeNode* root) {
        string a;
        if(root == nullptr)
            return a;
        queue<TreeNode*> q;
        q.push(root);
        int s;
        int i;
        while(!q.empty())
        {
            s = q.size();
            for(i = 0; i<s; i++)
            {
                TreeNode *root = q.front();
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
        }
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
            index++;     ////using intmin as indicator of null should be corrected
            return(stoi(a));
    }
   //string to array of integer
        /////////////////////////create to treeNode/////////////////////
        ///////////////////////queue to tree/////////////
    /*    queue<TreeNode*> q;
    void crt(int n)
    {
        if(n==0)
            return;
        for(int itr=0 ; itr<n ; itr++)
        {
            TreeNode* root=q.front();
            q.pop();
            int a=stl();
            if(a != INT_MIN)                ///flag INT_MIN
            {
                TreeNode* left =new TreeNode;
                left->left=nullptr;
                left->right=nullptr;
                left->val=a;
                root->left = left;
                q.push(root->left);
            }
            a=stl();
            if(a!= INT_MIN)                     ////flagINT_MIN
            {
                TreeNode* left =new TreeNode ;
                left->left=nullptr;
                left->right=nullptr;
                left->val=a;
                root->right = left;
                q.push(root->right);
            }
        }
        return crt(q.size());
    }*/
    TreeNode* deserialize(string data) {
        if(data.size()==0)
            return nullptr;
       s=data;
        TreeNode* root=new TreeNode ;
        TreeNode* tmp=root;
        root->val=stl();
        queue<TreeNode*> q;
        q.push(root);
        int si;
        int i,a;
         while(!q.empty())
        {
            si = q.size();
            for(i = 0; i<si; i++)
            {
                root=q.front();
                q.pop();
                a=stl();
                if(a != 1010)                ///flag INT_MIN
                {
                    root-> left =new TreeNode;
                    root->left->val = a;
                    q.push(root->left);
                }
                a=stl();
                if(a!= 1010)                     ////flagINT_MIN
                {
                    root->right =new TreeNode ;
                    root->right->val = a;
                    q.push(root->right);
                }
            }
        }
        return tmp;
        return nullptr;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
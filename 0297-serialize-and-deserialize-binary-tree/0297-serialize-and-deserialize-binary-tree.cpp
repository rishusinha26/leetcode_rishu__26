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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==nullptr) return "";
        queue<TreeNode*>q;
        q.push(root);
        string ans="";
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();

            if(node){
                ans+=to_string(node->val)+',';
                q.push(node->left);
                q.push(node->right);
            }
            else{
                ans+="null,";
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return nullptr;

        stringstream ss(data);
        string item;

        getline(ss,item,',');
        TreeNode* root=new TreeNode(stoi(item));

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            TreeNode*node=q.front();
            q.pop();

        if(!getline(ss,item,',')) break;
        if(item!="null"){
            node->left=new TreeNode(stoi(item));
            q.push(node->left);
        }
        if(!getline(ss,item,',')) break;
        if(item!="null"){
            node->right=new TreeNode(stoi(item));
            q.push(node->right);
        }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
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

    void preorder(TreeNode* root, string& res){
        if(!root){
            res += "null,";
            return;
        }
        res += to_string(root->val);
        res += ",";
        preorder(root->left,res);
        preorder(root->right,res);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        preorder(root,res);
        res.pop_back();
        return res;
    }

    /*
    -----------------Deserialize----------------
    */

    TreeNode* construct(vector<string>& str, int& i){
        if(str[i]=="null"){
            i++;
            return NULL;
        }
        TreeNode* node = new TreeNode(stoi(str[i]));
        i++;
        node->left = construct(str,i);
        node->right = construct(str,i);
        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> str;
        string tmp = "";
        for(char ch: data){
            if(ch==','){
                str.push_back(tmp);
                tmp = "";
            }else{
                tmp += ch;
            }
        }
        str.push_back(tmp);
        int i = 0;
        return construct(str,i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
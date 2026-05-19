/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    unordered_map<TreeNode*, vector<TreeNode*>> mp;
    
    void makeGraph(TreeNode* root){
        if(!root->left && !root->right) return;
        if(root->left){
            mp[root].push_back(root->left);
            mp[root->left].push_back(root);
            makeGraph(root->left);
        }
        if(root->right){
            mp[root].push_back(root->right);
            mp[root->right].push_back(root);
            makeGraph(root->right);
        }
        return;
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        makeGraph(root);
        queue<pair<TreeNode*,int>> q;
        q.push({target,0});
        vector<int> res;
        unordered_set<TreeNode*> visited;
        while(!q.empty()){
            auto tmp = q.front();
            q.pop();
            TreeNode* currNode = tmp.first;
            int currDis = tmp.second;
            if(currDis==k) res.push_back(currNode->val);
            visited.insert(currNode);
            for(auto neighbor: mp[currNode]){
                if(visited.find(neighbor)==visited.end())
                q.push({neighbor,currDis+1});
            }
        }
        return res;
    }
};
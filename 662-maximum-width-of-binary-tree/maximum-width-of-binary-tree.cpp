/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        long long res = 0;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0}); // {node,index}
        while(!q.empty()){
            int count = q.size();
            auto start = q.front().second;
            auto end = q.back().second;
            res = max(res,(long long)(end-start+1));
            for(int i=0;i<count;i++){
                auto currNode = q.front().first;
                long long idx = q.front().second-start;
                q.pop();
                if(currNode->left!=NULL){
                    q.push({currNode->left,(long long)2*idx+1});
                }
                if(currNode->right!=NULL){
                    q.push({currNode->right,(long long)2*idx+2});
                }
            }
        }
        return res;
    }
};
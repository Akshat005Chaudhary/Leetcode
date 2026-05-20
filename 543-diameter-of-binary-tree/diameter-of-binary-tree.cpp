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

    int res;

    int solve(TreeNode* root){
        if(!root) return 0;
        if(!root->left && !root->right) return 0;
        int left = 0;
        int right = 0;
        if(root->left){
        left = 1+solve(root->left);
        }
        if(root->right){
        right = 1+solve(root->right);
        }
        res = max(res,left+right);
        int maxi = max(left,right);
        return maxi;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return 0;
        res = INT_MIN;
        solve(root);
        return res;
    }
};
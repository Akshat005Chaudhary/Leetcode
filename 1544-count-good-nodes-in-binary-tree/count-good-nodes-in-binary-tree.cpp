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

    int cnt;

    void recursion(TreeNode* root, int maxi){
        if(root==nullptr) return;
        if(root->val>=maxi) cnt++;
        maxi = max(root->val,maxi);
        recursion(root->left,maxi);
        recursion(root->right,maxi);
    }

    int goodNodes(TreeNode* root) {
        int maxi = INT_MIN;
        cnt = 0;
        recursion(root,maxi);
        return cnt;
    }
};
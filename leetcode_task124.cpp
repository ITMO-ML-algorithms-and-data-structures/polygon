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
    int globalMaxSum = INT_MIN;
    int maxPathSumHelper(TreeNode* root) {
        if(!root) return 0;
        int left = maxPathSumHelper(root->left);
        int right = maxPathSumHelper(root->right);

        int maxSum = root->val + max({0, left, right, left+right});
        int linkableMaxSum = root->val + max({0, left, right});
        globalMaxSum = max(globalMaxSum, maxSum);
        return linkableMaxSum;
    }
public:
    int maxPathSum(TreeNode* root) {
        maxPathSumHelper(root);
        return globalMaxSum;
    }
};

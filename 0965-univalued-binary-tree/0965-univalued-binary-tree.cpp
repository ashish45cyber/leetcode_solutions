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
    bool compare(TreeNode* root, int prev){
        if(root  == NULL){
            return true;
        }
        if(root->val != prev){
            return false;
        }
        return compare(root->left, prev) && compare(root->right, prev);
    }
    bool isUnivalTree(TreeNode* root) {
        return compare(root, root->val);
    }
};
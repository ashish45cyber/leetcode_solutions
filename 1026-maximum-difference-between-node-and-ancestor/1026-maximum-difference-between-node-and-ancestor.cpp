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
    int ans = 0;
    void func(TreeNode* root, vector<int> &res){
    if(root == NULL){
        return;
    }
    for(auto x: res){
        ans = max(ans, abs(root->val-x));
    }
    res.push_back(root->val);
    func(root->left, res);
    func(root->right, res);
    res.pop_back();
    }
    int maxAncestorDiff(TreeNode* root) {
        vector<int> res;
        func(root, res);
        return ans;
    }
};
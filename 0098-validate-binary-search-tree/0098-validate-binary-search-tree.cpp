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

bool validate(TreeNode* node, long long lower, long long upper){
    if(node == nullptr)  return true;
    if(node->val < upper && node->val > lower)
        return validate(node->left, lower, node->val) && 
               validate(node->right, node->val, upper);
    else return false;
}

public:
    bool isValidBST(TreeNode* root) {
        long long int minVal = -1000000000000, maxVal = 1000000000000;
        return validate(root, minVal, maxVal);
    }
};

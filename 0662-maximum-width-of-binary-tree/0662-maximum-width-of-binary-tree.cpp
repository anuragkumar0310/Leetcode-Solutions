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
        long long res = 0;
        function<void(TreeNode*, int, unsigned long long, vector<unsigned long long>&)> dfs = [&](TreeNode* node, int level, unsigned long long index, vector<unsigned long long>& leftMost) {
            if (!node) return;
            if (leftMost.size() == level) leftMost.push_back(index);
            res = max(res, static_cast<long long>(index - leftMost[level] + 1));
            dfs(node->left, level + 1, 2 * index, leftMost);
            dfs(node->right, level + 1, 2 * index + 1, leftMost);
        };
        vector<unsigned long long> leftMost;
        dfs(root, 0, 0, leftMost);
        return res;
    }
};

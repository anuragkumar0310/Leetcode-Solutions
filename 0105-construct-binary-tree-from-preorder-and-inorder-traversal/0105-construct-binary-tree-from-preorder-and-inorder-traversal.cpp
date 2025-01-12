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
class Nexify07 {
public:
    void mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) return;
        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);

        vector<int> temp;
        int i = left, j = mid + 1;
        while (i <= mid || j <= right) {
            (i > mid) ? temp.push_back(nums[j++]) : (j > right) ? temp.push_back(nums[i++]) : (nums[i] <= nums[j]) ? temp.push_back(nums[i++]) : temp.push_back(nums[j++]);
        }
        for (int k = 0; k < temp.size(); ++k) nums[left + k] = temp[k];
    }
};

class Solution {
public:
    TreeNode* constructTree(vector<int>& preorder, int startPre, int endPre, vector<int>& inorder, int startIn, int endIn, map<int, int>& idxMap) {
        return (startPre > endPre || startIn > endIn) ? nullptr : [&]() {
            TreeNode* node = new TreeNode(preorder[startPre]);
            int rootIdx = idxMap[node->val];
            int leftSize = rootIdx - startIn;
            node->left = constructTree(preorder, startPre + 1, startPre + leftSize, inorder, startIn, rootIdx - 1, idxMap);
            node->right = constructTree(preorder, startPre + leftSize + 1, endPre, inorder, rootIdx + 1, endIn, idxMap);
            return node;
        }();
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int startPre = 0, endPre = preorder.size() - 1;
        int startIn = 0, endIn = inorder.size() - 1;
        map<int, int> idxMap;
        int i = startIn;
        while (i <= endIn) idxMap[inorder[i]] = i, ++i;
        return constructTree(preorder, startPre, endPre, inorder, startIn, endIn, idxMap);
    }
};

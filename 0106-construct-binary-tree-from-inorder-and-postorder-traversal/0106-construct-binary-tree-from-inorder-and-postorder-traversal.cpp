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
    map<int,int>m;
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        for(int i=0;i<in.size();i++)m[in[i]]=i;
        TreeNode* root = build(in,0,in.size()-1,post,0,post.size()-1);
        return root;
    }
    TreeNode* build(vector<int>&in, int inS,int inE,vector<int>&post,int postS,int postE){
        if(inS>inE || postS>postE)return NULL;
        TreeNode* root = new TreeNode(post[postE]);
        int index = m[post[postE]];
        int len = inE - index;   
        root->right = build(in,index+1,inE,post,postE-len,postE-1);
        root->left = build(in,inS,index-1,post,postS,postE-len-1);
        return root;
    }
};
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void linkNodes(Node* currentNode, Node* parentNode) {
        if (currentNode == NULL)
            return;
        if (parentNode != NULL)
            parentNode->left->next = parentNode->right;
        if (parentNode != NULL && parentNode->next != NULL)
            parentNode->right->next = parentNode->next->left;
        if (currentNode->left == NULL && currentNode->right == NULL)
            return;
        linkNodes(currentNode->left, currentNode);
        linkNodes(currentNode->right, currentNode);
    }

    Node* connect(Node* root) {
        linkNodes(root, NULL);
        return root;
    }
};

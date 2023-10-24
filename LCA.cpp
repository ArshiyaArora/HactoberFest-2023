class Solution {
private:
    // Private helper function to find the lowest common ancestor of two nodes in a binary tree.
    Node* solve(Node* root, int n1, int n2) {
        // If the root is NULL, there's no ancestor to find.
        if (root == NULL) {
            return NULL;
        }

        // If one of the nodes is found, return the root as the ancestor.
        if (root->data == n1 || root->data == n2) {
            return root;
        }

        // Recursively search for the nodes in the left and right subtrees.
        Node* LeftAns = solve(root->left, n1, n2);
        Node* RightAns = solve(root->right, n1, n2);

        // If both nodes are found in different subtrees, the current root is the lowest common ancestor.
        if (LeftAns != NULL && RightAns != NULL) {
            return root;
        }
        // If one node is found in the left subtree, return that node as the ancestor.
        else if (LeftAns != NULL && RightAns == NULL) {
            return LeftAns;
        }
        // If one node is found in the right subtree, return that node as the ancestor.
        else if (LeftAns == NULL && RightAns != NULL) {
            return RightAns;
        }
        // If neither node is found in the subtrees, return NULL.
        else {
            return NULL;
        }
    }

public:
    // Public function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root, int n1, int n2) {
        // Call the private solve function to find the LCA of the two nodes.
        return solve(root, n1, n2);
    }
};


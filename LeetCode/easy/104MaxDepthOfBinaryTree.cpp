/*Given a binary tree, find its maximum depth.

  The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * 
 };*/

int maxDepth(struct TreeNode* root) {

    int ld, rd;
    if (root)
    {
        ld = maxDepth(root->left);
        rd = maxDepth(root->right);
        if (ld >= rd)
            return ld + 1;
        else
            return rd + 1;
    }
    else
        return 0;
}

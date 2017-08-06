/*Invert a binary tree. */
/*Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so fuck off.*/
struct TreeNode *invertTree(struct TreeNode* root) {
    if (root == NULL)
        return NULL;
    else
    {
        invertTree(root->left);
        invertTree(root->right);
        struct TreeNode *tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        return root;
    }
}

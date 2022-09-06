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
    bool isValidBST(TreeNode* root,TreeNode* l = NULL,TreeNode*  r = NULL) {
        if(root == NULL)
            return true;
        if(l != NULL and l -> val >= root -> val)
            return false;
        if( r != NULL and r -> val <= root -> val )
            return false;
        
        return isValidBST(root -> left, l, root) and isValidBST(root -> right,root , r);
       
    }
};
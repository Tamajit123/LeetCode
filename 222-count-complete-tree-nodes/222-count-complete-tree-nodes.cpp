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
    int left_h(TreeNode* root){
        if(root == NULL)
            return 0;
        int lh = 0;
        while(root){
            lh++;
            root = root -> left;
        }
        return lh;
    }
    
    int right_h(TreeNode* root){
        if(root == NULL)
            return 0;
        int rh = 0;
        while(root){
            rh++;
            root = root -> right;
        }
        return rh;
        
    }
    
    int countNodes(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        int l,r;
        
        l = left_h(root);
        r = right_h(root);
        
        if(l == r)
            return (1 << l) - 1;
        
        return 1 +countNodes(root -> left) + countNodes(root -> right);
    }
};
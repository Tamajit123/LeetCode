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
    int ans = 0;
    void solve(TreeNode* root,int level,int &maxi){
        if(root == NULL)
            return ;
        
        if(maxi == level){
            ans = root -> val;
            maxi++;
        }
            
         solve(root-> left,level+1, maxi);
        solve(root-> right, level+1, maxi);
    }
    int findBottomLeftValue(TreeNode* root) {
        int maxi = 1;
        ans = root-> val;
        solve(root, 0, maxi);
        return ans;
    }
};
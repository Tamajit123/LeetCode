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
    vector<vector<int>> levelOrder(TreeNode* root) {
         
        if( !root)
            return {};
        
        queue<TreeNode*> q;
        q.push(root);
        
        vector<vector<int>> ans;
        
        
        while(!q.empty()){
            
            vector<int> currLevel ;
            int s = q.size();
            
            for(int i = 0; i<s; ++i){
                
                TreeNode *curr = q.front();
                q.pop();
                
                
                if(curr -> left) q.push(curr -> left);
                if(curr -> right ) q.push(curr->right);
                
                currLevel.push_back(curr -> val);
                
            }
            ans.push_back(currLevel);
        }
        return ans;
    }
};
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
    TreeNode* solve(vector<int> &preorder , long mini , long maxi , int &i){

    if(i>=preorder.size()){
        return NULL ; 
    }
    if(preorder[i] < mini || preorder[i] > maxi ){
        return NULL ;
    }
    TreeNode* newnode = new TreeNode(preorder[i++]);
    newnode->left = solve(preorder,mini,newnode->val,i);
    newnode->right = solve(preorder,newnode->val,maxi,i);
    return newnode ; 
}


TreeNode* bstFromPreorder(vector<int>& preorder) {
    int i=0;
    long mini = LONG_MIN;
    long maxi  = LONG_MAX ;
    return solve(preorder,mini,maxi,i);
	
}  
};
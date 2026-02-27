/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) 
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    unordered_map<int, int> inorderIndex;
    int postIdx;

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postIdx = postorder.size() - 1;

        // Build value -> index map for inorder
        for (int i = 0; i < inorder.size(); i++) {
            inorderIndex[inorder[i]] = i;
        }

        return helper(inorder, postorder, 0, inorder.size() - 1);
    }

private:
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder,
                     int left, int right) {
        if (left > right) return nullptr;

        int rootVal = postorder[postIdx--];
        TreeNode* root = new TreeNode(rootVal);

        int index = inorderIndex[rootVal];

        // IMPORTANT: build right first
        root->right = helper(inorder, postorder, index + 1, right);
        root->left  = helper(inorder, postorder, left, index - 1);

        return root;
    }
};
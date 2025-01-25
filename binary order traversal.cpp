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
class Solution
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        queue<TreeNode *> s;
        vector<vector<int>> result;

        if (!root)
            return result;

        s.push(root);

        while (!s.empty())
        {
            int n = s.size();
            vector<int> hi;

            for (int i = 0; i < n; i++)
            {
                TreeNode *current = s.front();
                s.pop();

                hi.push_back(current->val);

                if (current->left)
                    s.push(current->left);
                if (current->right)
                    s.push(current->right);
            }
            result.push_back(hi);
        }
        reverse(result.begin(), result.end());

        return result;
    }
};
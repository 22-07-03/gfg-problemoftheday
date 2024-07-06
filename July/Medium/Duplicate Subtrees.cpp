//Microsoft
class Solution {
public:
    bool dfs(Node* root, int target, vector<pair<int, int>>& parents, int parent) {
        if (root == nullptr) return false;
        
        parents.push_back({root->data, parent});
        
        if (root->data == target) return true;
        
        if (dfs(root->left, target, parents, root->data) || dfs(root->right, target, parents, root->data)) {
            return true;
        }
        
        // Backtrack if target is not found in the current path
        parents.pop_back();
        return false;
    }

    vector<int> Ancestors(Node *root, int target) {
        vector<pair<int, int>> parents;
        vector<int> ans;
        
        if (dfs(root, target, parents, -1)) {
            int current = target;
            for (int i = parents.size() - 1; i >= 0; --i) {
                if (parents[i].first == current) {
                    if (parents[i].second != -1) {
                        ans.push_back(parents[i].second);
                    }
                    current = parents[i].second;
                }
            }
        }
        
        return ans;
    }
};

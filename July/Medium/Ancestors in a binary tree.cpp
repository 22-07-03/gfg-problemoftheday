//AMAZON
class Solution {
public:
    void dfs(Node* root, int& target, vector<pair<int, int>>& parents, int parent) {
        if (root == nullptr) return;

        stack<pair<Node*, int>> st;
        st.push({root, parent});

        while (!st.empty()) {
            auto it = st.top(); st.pop();
            Node* current_node = it.first;
            int parent_data = it.second;

            parents.push_back({current_node->data, parent_data});
            if (current_node->data == target) return;

            if (current_node->right) {
                st.push({current_node->right, current_node->data});
            }
            if (current_node->left) {
                st.push({current_node->left, current_node->data});
            }
        }
    }

    vector<int> Ancestors(Node* root, int target) {
        vector<pair<int, int>> parents;
        vector<int> ans;
        dfs(root, target, parents, -1);

        int current = target;
        for (int i = parents.size() - 1; i >= 0; i--) {
            if (parents[i].first == current) {
                ans.push_back(parents[i].second);
                current = parents[i].second;
            }
        }

        if (!ans.empty() && ans.back() == -1) {
            ans.pop_back();
        }

        return ans;
    }
};
// class Solution {
// public:
//     bool dfs(Node* root, int target, vector<pair<int, int>>& parents, int parent) {
//         if (root == nullptr) return false;
        
//         parents.push_back({root->data, parent});
        
//         if (root->data == target) return true;
        
//         if (dfs(root->left, target, parents, root->data) || dfs(root->right, target, parents, root->data)) {
//             return true;
//         }
        
//         // Backtrack if target is not found in the current path
//         parents.pop_back();
//         return false;
//     }

//     vector<int> Ancestors(Node *root, int target) {
//         vector<pair<int, int>> parents;
//         vector<int> ans;
        
//         if (dfs(root, target, parents, -1)) {
//             int current = target;
//             for (int i = parents.size() - 1; i >= 0; --i) {
//                 if (parents[i].first == current) {
//                     if (parents[i].second != -1) {
//                         ans.push_back(parents[i].second);
//                     }
//                     current = parents[i].second;
//                 }
//             }
//         }
        
//         return ans;
//     }
// };


// class Solution {
// public:
//     void dfs(Node* root, int target, vector<pair<int, int>>& parents, int parent) {
//         if (!root) return;

//         // If the target node is found, record its parent and return
//         if (root->data == target) {
//             parents.push_back({root->data, parent});
//             return;
//         }

//         // Push the current node's data and its parent to the stack
//         if (root->left) {
//             parents.push_back({root->left->data, root->data});
//             dfs(root->left, target, parents, root->data);
//         }
//         if (root->right) {
//             parents.push_back({root->right->data, root->data});
//             dfs(root->right, target, parents, root->data);
//         }
//     }

//     vector<int> Ancestors(Node* root, int target) {
//         vector<pair<int, int>> parents;
//         vector<int> ans;

//         // Start the DFS traversal to find the ancestors
//         dfs(root, target, parents, -1);

//         // Collect the ancestors from the parents vector
//         int current = target;
//         for (int i = parents.size() - 1; i >= 0; i--) {
//             if (parents[i].first == current) {
//                 ans.push_back(parents[i].second);
//                 current = parents[i].second;
//             }
//         }

//         // Remove the initial parent (-1) if present
//         if (!ans.empty() && ans.back() == -1) {
//             ans.pop_back();
//         }

//         return ans;
//     }
// };

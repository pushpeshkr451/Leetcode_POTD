// Last updated: 07/06/2026, 07:56:51
1class Solution {
2public:
3    TreeNode* createBinaryTree(vector<vector<int>>& des) {
4        unordered_map<int,TreeNode*>mp;
5        unordered_set<int>st;
6
7        for(auto it:des){
8            int parent=it[0];
9            int child=it[1];
10            int islef=it[2];
11
12            if(!mp.count(parent)) mp[parent] = new TreeNode(parent);
13
14            if(!mp.count(child)) mp[child] = new TreeNode(child);
15
16            if(islef) mp[parent]->left = mp[child];
17            else mp[parent]->right = mp[child];
18
19            st.insert(child);
20        }
21
22        TreeNode* root;
23        for(auto it:mp){
24            if(st.find(it.first)==st.end()){
25                root=mp[it.first];
26                break;
27            }
28        }
29        return root;
30    }
31};
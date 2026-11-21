class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
         int n = parent.size();

        vector<vector<int>> adj(n);

        // Step 1: Build original tree
        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        vector<int> newParent(n, -1);
        vector<int> prevSame(n, -1);

        int lastSeen[26];
        fill(lastSeen, lastSeen + 26, -1);

        // Step 2: DFS iteratively
        // 0 = enter node, 1 = exit node
        stack<pair<int, int>> st;
        st.push({0, 0});

        while (!st.empty()) {
            auto [u, state] = st.top();
            st.pop();

            int c = s[u] - 'a';

            if (state == 0) {

                // Find closest ancestor with same character
                prevSame[u] = lastSeen[c];

                if (u == 0) {
                    newParent[u] = -1;
                }
                else if (lastSeen[c] != -1) {
                    newParent[u] = lastSeen[c];
                }
                else {
                    newParent[u] = parent[u];
                }

                lastSeen[c] = u;

                // Exit event
                st.push({u, 1});

                // Visit children
                for (int v : adj[u]) {
                    st.push({v, 0});
                }
            }
            else {
                // Restore previous ancestor
                lastSeen[c] = prevSame[u];
            }
        }

        // Step 3: Build modified tree
        vector<vector<int>> newAdj(n);

        for (int i = 1; i < n; i++) {
            newAdj[newParent[i]].push_back(i);
        }

        // Get traversal order
        vector<int> order;
        stack<int> dfs;
        dfs.push(0);

        while (!dfs.empty()) {
            int u = dfs.top();
            dfs.pop();

            order.push_back(u);

            for (int v : newAdj[u]) {
                dfs.push(v);
            }
        }

        // Calculate subtree sizes bottom-up
        vector<int> ans(n, 1);

        for (int i = n - 1; i > 0; i--) {
            int u = order[i];
            ans[newParent[u]] += ans[u];
        }

        return ans;
    }
};
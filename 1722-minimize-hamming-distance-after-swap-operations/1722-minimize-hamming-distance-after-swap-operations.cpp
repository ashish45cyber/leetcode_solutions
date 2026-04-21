class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if (pa != pb)
            parent[pa] = pb;
    }
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        parent.resize(n);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        // Step 1: Build connected components
        for (auto &swap : allowedSwaps) {
            unite(swap[0], swap[1]);
        }

        // Step 2: Group indices
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++) {
            groups[find(i)].push_back(i);
        }

        int hamming = 0;

        // Step 3: Process each group
        for (auto &g : groups) {
            unordered_map<int, int> freq;

            // count source values
            for (int idx : g.second) {
                freq[source[idx]]++;
            }
          for (int idx : g.second) {
                if (freq[target[idx]] > 0) {
                    freq[target[idx]]--;
                } else {
                    hamming++;
                }
            }
        }

        return hamming;  
    }
};
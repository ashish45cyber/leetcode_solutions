class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
         int m = queries.size();

        // Store queries along with their original indices
        vector<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            q.push_back({queries[i], i});
        }

        // Sort logs by time
        sort(logs.begin(), logs.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });

        // Sort queries by time
        sort(q.begin(), q.end());

        vector<int> ans(m);
        unordered_map<int, int> mp;

        int left = 0, right = 0;
        int active = 0;

        for (auto &[time, idx] : q) {

            // Add logs within the upper boundary
            while (right < logs.size() && logs[right][1] <= time) {
                int server = logs[right][0];

                if (mp[server] == 0) {
                    active++;
                }

                mp[server]++;
                right++;
            }

            // Remove logs outside the lower boundary
            while (left < right && logs[left][1] < time - x) {
                int server = logs[left][0];

                mp[server]--;

                if (mp[server] == 0) {
                    active--;
                }

                left++;
            }

            // Servers that received no requests
            ans[idx] = n - active;
        }

        return ans;
    }
};
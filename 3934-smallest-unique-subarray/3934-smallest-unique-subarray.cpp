class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
         int n = nums.size();

        vector<int> sa(n), rank(n), newRank(n);

        // Initialize suffix array
        for (int i = 0; i < n; i++) {
            sa[i] = i;
            rank[i] = nums[i];
        }

        // Build Suffix Array using Doubling
        for (int k = 1; k < n; k *= 2) {
            sort(sa.begin(), sa.end(), [&](int a, int b) {
                if (rank[a] != rank[b])
                    return rank[a] < rank[b];

                int ra = (a + k < n) ? rank[a + k] : -1;
                int rb = (b + k < n) ? rank[b + k] : -1;

                return ra < rb;
            });

            newRank[sa[0]] = 0;

            for (int i = 1; i < n; i++) {
                int a = sa[i - 1];
                int b = sa[i];

                pair<int, int> p1 = {
                    rank[a],
                    (a + k < n) ? rank[a + k] : -1
                };

                pair<int, int> p2 = {
                    rank[b],
                    (b + k < n) ? rank[b + k] : -1
                };

                newRank[b] = newRank[a] + (p1 != p2);
            }

            rank = newRank;

            if (rank[sa[n - 1]] == n - 1)
                break;
        }

        // Build LCP Array using Kasai's Algorithm
        vector<int> lcp(n, 0);
        vector<int> pos(n);

        for (int i = 0; i < n; i++)
            pos[sa[i]] = i;

        int h = 0;

        for (int i = 0; i < n; i++) {
            int p = pos[i];

            if (p == 0) continue;

            int j = sa[p - 1];

            while (i + h < n && j + h < n &&
                   nums[i + h] == nums[j + h]) {
                h++;
            }

            lcp[p] = h;

            if (h > 0) h--;
        }

        // Find minimum unique subarray length
        int ans = n;

        for (int i = 0; i < n; i++) {
            int p = pos[i];

            int mx = lcp[p];

            if (p + 1 < n)
                mx = max(mx, lcp[p + 1]);

            int len = mx + 1;

            if (len <= n - i)
                ans = min(ans, len);
        }

        return ans;
    }
};
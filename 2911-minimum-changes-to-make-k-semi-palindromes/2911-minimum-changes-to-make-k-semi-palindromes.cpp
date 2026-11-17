class Solution {
public:
    int minimumChanges(string s, int k) {
                int n = s.size();
        const int INF = 1e9;

        // cost[i][j] = minimum changes to make s[i...j]
        // a semi-palindrome
        vector<vector<int>> cost(n, vector<int>(n, INF));

        // Precompute costs for every substring
        for (int len = 2; len <= n; len++) {
            for (int l = 0; l + len <= n; l++) {

                // Try every valid divisor d
                for (int d = 1; d < len; d++) {
                    if (len % d != 0)
                        continue;

                    int changes = 0;

                    // Divide characters into d groups
                    for (int r = 0; r < d; r++) {

                        int left = r;
                        int right = (len - 1 - r) / d * d + r;

                        // Compare mirrored characters
                        while (left < right) {
                            if (s[l + left] != s[l + right])
                                changes++;

                            left += d;
                            right -= d;
                        }
                    }

                    cost[l][l + len - 1] =
                        min(cost[l][l + len - 1], changes);
                }
            }
        }

        // DP: dp[i][j] = minimum changes to divide
        // first i characters into j semi-palindromes
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));

        dp[0][0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {

                // Last substring starts at p
                for (int p = 0; p <= i - 2; p++) {

                    if (dp[p][j - 1] == INF)
                        continue;

                    dp[i][j] = min(
                        dp[i][j],
                        dp[p][j - 1] + cost[p][i - 1]
                    );
                }
            }
        }

        return dp[n][k];
    }
};
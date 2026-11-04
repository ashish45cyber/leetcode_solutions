class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) { 
     int n = nums.size();
        // Step 1: Calculate cost of every window of size x
        multiset<int> left, right;

        long long leftSum = 0, rightSum = 0;
        vector<long long> cost;

        for (int i = 0; i < n; i++) {

            // Insert current element
            if (left.empty() || nums[i] <= *left.rbegin()) {
                left.insert(nums[i]);
                leftSum += nums[i];
            } 
            else {
                right.insert(nums[i]);
                rightSum += nums[i];
            }

            // Remove element outside the window
            if (i >= x) {
                int val = nums[i - x];

                auto it = left.find(val);

                if (it != left.end()) {
                    left.erase(it);
                    leftSum -= val;
                } 
                else {
                    it = right.find(val);
                    right.erase(it);
                    rightSum -= val;
                }
            }

            // Balance both multisets
            if (left.size() < right.size()) {
                int val = *right.begin();

                right.erase(right.begin());
                rightSum -= val;

                left.insert(val);
                leftSum += val;
            }
            else if (left.size() > right.size() + 1) {
                int val = *left.rbegin();

                auto it = prev(left.end());
                left.erase(it);
                leftSum -= val;

                right.insert(val);
                rightSum += val;
            }

            // Calculate minimum operations for current window
            if (i >= x - 1) {
                long long median = *left.rbegin();

                long long operations =
                    median * (long long)left.size() - leftSum
                    + rightSum - median * (long long)right.size();

                cost.push_back(operations);
            }
        }

        // Step 2: Dynamic Programming
        const long long INF = 1e18;

        vector<vector<long long>> dp(
            n + 1, vector<long long>(k + 1, INF)
        );

        dp[0][0] = 0;

        for (int i = 1; i <= n; i++) {

            for (int j = 0; j <= k; j++) {

                // Choice 1: Skip current element
                dp[i][j] = dp[i - 1][j];

                // Choice 2: Select a window ending at i-1
                if (j > 0 && i >= x) {
                    dp[i][j] = min(
                        dp[i][j],
                        dp[i - x][j - 1] + cost[i - x]
                    );
                }
            }
        }
        return dp[n][k];
    }
};
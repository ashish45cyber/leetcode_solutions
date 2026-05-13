class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {  
        int n = nums.size();
        vector<int> diff(2 * limit + 2, 0);

        for(int i = 0; i < n / 2; i++) {

            int a = nums[i];
            int b = nums[n - 1 - i];

            int low = 1 + min(a, b);
            int high = limit + max(a, b);

            int sum = a + b;

            /*
                Initially assume:
                every target needs 2 moves

                Then reduce:
                2 -> 1 in [low, high]
                1 -> 0 at exact sum
            */

            // Reduce one move in range [low, high]
            diff[low] -= 1;
            diff[high + 1] += 1;

            // Reduce one more move at exact sum
            diff[sum] -= 1;
            diff[sum + 1] += 1;
        }

        int ans = INT_MAX;

        int curr = n;  
        // n because:
        // total pairs = n/2
        // each pair initially assumed 2 moves
        // total = (n/2)*2 = n

        for(int target = 2; target <= 2 * limit; target++) {

            curr += diff[target];

            ans = min(ans, curr);
        }

        return ans;
    }
};
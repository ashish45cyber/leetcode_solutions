class Solution {
public:
    int countPrimes(int n) {
        if (n < 3) return 0;

        vector<char> composite(n, 0);
        int cnt = 1; 

        for (int i = 3; (long long)i * i < n; i += 2) {
            if (!composite[i]) {
                for (long long j = (long long)i * i; j < n; j += 2 * i) {
                    composite[j] = 1;
                }
            }
        }

        for (int i = 3; i < n; i += 2) {
            if (!composite[i]) cnt++;
        }

        return cnt;
    }
};
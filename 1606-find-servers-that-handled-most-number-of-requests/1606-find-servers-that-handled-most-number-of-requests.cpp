class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
         // Available servers
        set<int> available;

        for (int i = 0; i < k; i++) {
            available.insert(i);
        }

        // Min heap: {finish_time, server_id}
        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > busy;

        vector<int> count(k, 0);

        for (int i = 0; i < arrival.size(); i++) {

            // Release servers whose tasks are completed
            while (!busy.empty() && busy.top().first <= arrival[i]) {
                int server = busy.top().second;
                busy.pop();

                available.insert(server);
            }

            // All servers are busy
            if (available.empty()) {
                continue;
            }

            // Find the first available server >= i % k
            int target = i % k;

            auto it = available.lower_bound(target);

            // Wrap around if no server is found
            if (it == available.end()) {
                it = available.begin();
            }

            int server = *it;

            // Assign request
            count[server]++;

            // Remove server from available set
            available.erase(it);

            // Calculate when server becomes free
            long long finish = (long long)arrival[i] + load[i];

            busy.push({finish, server});
        }

        // Find maximum number of requests handled
        int maxi = *max_element(count.begin(), count.end());

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            if (count[i] == maxi) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
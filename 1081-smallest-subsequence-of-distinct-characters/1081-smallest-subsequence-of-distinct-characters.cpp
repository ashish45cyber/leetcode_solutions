class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> lastIndex(26);

        for (int i = 0; i < s.size(); i++) {
            lastIndex[s[i] - 'a'] = i;
        }

        vector<bool> visited(26, false);
        string ans = "";

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];

            if (visited[ch - 'a'])
                continue;

            while (!ans.empty() &&
                   ans.back() > ch &&
                   lastIndex[ans.back() - 'a'] > i) {

                visited[ans.back() - 'a'] = false;
                ans.pop_back();
            }

            ans.push_back(ch);
            visited[ch - 'a'] = true;
        }

        return ans;
        
    }
};
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        unordered_map<char, int> mp;
        int l = 0, maxfreq = 0, res = 0;
        for(int r=0; r<n; r++){
            mp[s[r]]++;
            maxfreq = max(maxfreq, mp[s[r]]);
            while((r-l+1) - maxfreq > k){
                mp[s[l]]--;
                l++;
            }
            res = max(res, (r-l+1));
        }
        return res;
    }
};
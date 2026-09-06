class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        for(int i=1; i<words.size(); i++){
            string k = words[i];
            string k1 = words[i-1];
            sort(k.begin(), k.end());
            sort(k1.begin(), k1.end());
            if(k == k1){
                words.erase(words.begin() + i);
                i--;
            }
        }
        return words;
    }
};
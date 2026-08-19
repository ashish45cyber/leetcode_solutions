class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        set<int> s1(nums1.begin(), nums1.end());
        set<int> s2(nums2.begin(), nums2.end());
        int common = 0;

        for(int i: s1){
            if(s2.count(i)){
                common++;
            }
        }
        int only1 = s1.size() - common;
        int only2 = s2.size() - common;
        
        int take1 = min((n1/2), only1);
        int take2 = min((n2/2), only2);

        int rem1 = (n1/2) - take1;
        int rem2 = (n2/2) - take2;

        int lastcommon = min(common, rem1+rem2);
        return take1+take2+lastcommon;
    }
};
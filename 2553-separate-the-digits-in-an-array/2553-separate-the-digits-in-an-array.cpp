class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
       vector<int> ans;

        for(int i = 0; i < nums.size(); i++) {

            if(nums[i] < 10) {
                ans.push_back(nums[i]);
            }
            else {
                vector<int> temp;
                int num = nums[i];

                while(num > 0) {
                    temp.push_back(num % 10);
                    num /= 10;
                }

                reverse(temp.begin(), temp.end());

                for(int digit : temp) {
                    ans.push_back(digit);
                }
            }
        }

        return ans;
    }
};
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        sort(costs.begin(), costs.end());
        int count = 0, i=0; 
        while(i < n || coins == 0){
            if(costs[i] <= coins){
                coins = coins - costs[i];
                count++;
            }else{
                break;
            }
            i++;
        }
        return count;
    }
};
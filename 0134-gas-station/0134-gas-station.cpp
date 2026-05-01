class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int start = 0;
        int currgas = 0;

        int totalgas = 0, totalcost = 0;

        for(int val : gas){
            totalgas += val;
        }
        for(int val : cost){
            totalcost += val;
        }
        if(totalgas < totalcost){
            return -1;
        }
        for(int i=0; i<n; i++){
            currgas += gas[i] - cost[i];

            if(currgas < 0){
                start = i+1;
                currgas = 0;
            }
        }
        return start;
    }
};
class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
       priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
       int i = 0, ans = 0;
       int n = apples.size();

       while(i < n || !pq.empty()){
        //to push
        if(i < n && apples[i] > 0 && days[i] > 0){
            int expiryday = i + days[i];
            pq.push({expiryday, apples[i]});
        }
        // to pop
        while(!pq.empty() && pq.top().first <= i){
            pq.pop();
        }
        // to eat
        if(!pq.empty()){
            auto top = pq.top();
            pq.pop();

            top.second--;
            ans++;

            if(top.second > 0){
                pq.push(top);
            }
        }
        i++;
       }
       return ans;
    }
};
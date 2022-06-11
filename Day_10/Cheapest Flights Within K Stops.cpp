typedef tuple<int, int, int> ti;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int, int>>> graph(n);
        
        for (const auto& flight : flights) {
            graph[flight[0]].push_back({flight[2], flight[1]});
        }
        
        vector<vector<int>> visited(n, vector<int>(k+2, INT_MIN/2));
        visited[src][0] = 0;
        
        priority_queue<ti> pq;
        pq.emplace(0, src, 0);
        
        while(pq.size()) {
            
            auto [price, cur, curK] = pq.top();
            pq.pop();
            
            if (cur == dst) {
                return -price;
            }
            
            if (curK == k+1) {continue;}
            
            for (const auto& next : graph[cur]) {
                if (visited[next.second][curK+1] < price-next.first) {
                    visited[next.second][curK+1] = price-next.first;
                    pq.emplace(price-next.first, next.second, curK+1);
                }
            }
        }
        
        return -1;
    }
};

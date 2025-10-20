class Solution {
// Hierholzer’s Algorithm
// Time Complexity: O(E)    Space Complexity: O(V + E)
private:
    void dfs(string curr, unordered_map<string, priority_queue<string, vector<string>, greater<string>>>& graph, vector<string>& itinerary) {
        auto& pq = graph[curr];
        while (!pq.empty()) {
            string next = pq.top();
            pq.pop();
            dfs(next, graph, itinerary); 
        }
        itinerary.push_back(curr);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
        for (auto& t : tickets) {
            graph[t[0]].push(t[1]);
        }
        vector<string> itinerary;
        dfs("JFK", graph, itinerary);
        reverse(itinerary.begin(), itinerary.end());
        return itinerary;
    }
};
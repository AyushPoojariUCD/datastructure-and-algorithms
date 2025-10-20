class Solution {
private:
    void dfs(const string& node, unordered_set<string>& visited, string& result,
             int n, int k) {
        for (int i = 0; i < k; ++i) {
            string edge = node + to_string(i);
            if (!visited.count(edge)) {
                visited.insert(edge);
                dfs(edge.substr(1), visited, result, n, k);
                result += to_string(i);
            }
        }
    } 
public:
    string crackSafe(int n, int k) {
        unordered_set<string> visited;
        string result;
        string start(n - 1, '0');
        dfs(start, visited, result, n, k);
        return result + start;
    }
};
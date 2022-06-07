class Solution {
public: 
    bool dfs(map<int, vector<int>>& adj, int start, int end, vector<bool>& visited) {
        visited[start] = true;
        if(start == end)
            return true;
        
        for(int &x : adj[start]) {
            if(!visited[x] && dfs(adj, x, end, visited)) {
                return true;
            }
        }
        return false;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        map<int, vector<int>> adj;
        
        int n = edges.size();
        vector<bool> visited(n+1, false);
        
        for(int i = 0; i<n; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            
            fill(begin(visited), end(visited), false);

            if(adj.find(u) != adj.end() && adj.find(v) != adj.end()
              && dfs(adj, u, v, visited))
                return edges[i];
            
            //Else, add them to graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        return {};

    }
};
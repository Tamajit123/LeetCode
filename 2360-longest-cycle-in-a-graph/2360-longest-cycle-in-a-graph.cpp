class Solution {
public:
    void dfs(int node, vector<int>& dist_node, vector<bool> &visited, vector<int>& edges,int distance,int &ans,
             vector<bool> &ex_visited){
        if(node != -1){
            if(!visited[node]){
                visited[node] = true;
                ex_visited[node] = true;
                dist_node[node] = distance;
                dfs(edges[node], dist_node, visited, edges, distance+1, ans,ex_visited);
            }
            else if(ex_visited[node]){
                ans = max(ans, distance - dist_node[node]);
            }
            ex_visited[node] = false;
        }
        //return ans;
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        
        vector<int>dist_node(n,0);
        vector<bool> ex_visited(n,false);
        vector<bool>visited(n, false);
        int ans = -1;
        
        for(int i = 0; i<n; i++){
            if(!visited[i])
                dfs(i, dist_node,visited, edges,0, ans,ex_visited);
        }
        return ans;
    }
};
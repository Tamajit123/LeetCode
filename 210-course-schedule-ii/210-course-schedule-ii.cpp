class Solution {
public:
    
    bool dfs(int node,vector<vector<int>>& adj, stack<int>&s, vector<int> &visited ){
        visited[node] = true;
        
        for(auto neighbour: adj[node]){
            if(visited[neighbour] == 1) return true;
            if(visited[neighbour] == 0 && dfs(neighbour,adj,s,visited)) return true;
        }
        visited[node] = 2;
        s.push(node);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        
//         for(int i = 0; i<prerequisites.size(); i++){
//             int u = prerequisites[i][0];
//             int v = prerequisites[i][1];
            
//             adj[v].push_back(u);
//         }
        for(vector<int> &co :prerequisites ){
            adj[co[1]].push_back(co[0]);
        }
        
        
        
        vector<int> ans;
        
        vector<int> visited(numCourses,0);
        
        stack<int>s;
        
        for(int i = 0; i<numCourses; i++){
            if(visited[i] == 0 && dfs(i, adj, s, visited)) return {};
        }
        
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};
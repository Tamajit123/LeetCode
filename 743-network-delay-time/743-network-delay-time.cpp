class Solution {
    struct node{
        int dst;
        int wt;
    };
    
    struct qnode{
        int ver;
        int dist;
    };
    
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
       unordered_map<int,vector<node*>> adj;
        
        for(int i = 0 ; i< times.size(); ++i){
            node *newnode = new node;
            newnode -> dst = times[i][1];
            newnode->wt = times[i][2];
            
            adj[times[i][0]].push_back(newnode);
        }
        
        qnode *qn = new qnode;
        
        qn -> ver = k;
        qn -> dist = 0;
        queue<qnode *> q;
        q.push(qn);
        
        vector<int> distance(n+1, INT_MAX);
        
        distance[k] = 0;
        int time = 0;
        
        while(!q.empty()){
            qnode *curr = q.front();
            q.pop();
            
            for(auto it : adj[curr->ver]){
                qnode *temp = new qnode;
                
                temp -> ver = it -> dst;
                temp ->dist = it->wt + curr -> dist;
                if(distance[temp->ver] > temp->dist){
                    q.push(temp);
                    distance[temp->ver] = it->wt + curr->dist;
                }
            }
        }
        
        for(int i = 1; i<= n; ++i){
            if(distance[i] == INT_MAX)
                return -1;
            
            time = max(time,distance[i]);
        }
        return time;
    }
};
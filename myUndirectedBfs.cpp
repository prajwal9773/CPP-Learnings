#include<iostream

using namespace std;


class Solution{
    public:

   bool solve(int src, vector<int>& adj[], unordered_map<int, bool>& vis){
    queue<int> q;
    unordered_map<int, int> parent;


    q.push(src);
    vis[src] = true;
    parent[src] = -1;

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        for(auto nbr: adj[frontNode]){
            if(nbr == parent[frontNode]){
                continue;
            }
            if(!vis[nbr]){
                q.push(nbr);
                vis[nbr] = true;
                parent[nbr] = frontNode;
            }
            else if(vis[nbr] == true){
                return true;
            }
        }
    }

    return false;

   }


    bool isCycle(int V,  vector<int> adj[]){
        unordered_map<int, bool> vis;
        for(int i =0; i < V; i++){
            if(!vis[i]){
                bool ans = solve(i, adj, vis);
                if(ans == true){
                    return true;
                }
            }
        }



        return false;
    }

}


int main(){
 int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }



    return 0;
}
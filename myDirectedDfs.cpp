#include <bits/stdc++.h>
using namespace std;


class Solution{
    public:

     bool solve(int node, unordered_map<int,bool>& vis, unordered_map<int,bool>& dfsTrack, vector<int> adj[]){
        vis[node] = true;
        dfsTrack[node] = true;

      for(auto nbr : adj[node]){
        if(!vis[node]){
            bool ans = solve(nbr, vis, dfsTrack, adj);
            if(ans == true){
                return true;
            }
        }
        else if(vis[node] == true && dfsTrack[node] == true){
            return true;
        }

      }


        dfsTrack[node] = false;

        return false;

     }

      bool isCyclic(int V, vector<int> adj[]) {
       unordered_map<int,bool> vis;
       unordered_map<int,bool> dfsTrack;
       
       for(int node=0; node<V; node++) {
           if(!vis[node]) {
               bool isCyclic = solve(node, vis, dfsTrack, adj);
               if(isCyclic) {
                   return true;
               }
           }
       }
       return false;
    }
}



int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
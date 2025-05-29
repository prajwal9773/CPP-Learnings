#include<iostream

using namespace std;



class Solution{
    public:


    
    bool solve(int src, unordered_map<int,bool>& vis, int parent, vector<int> adj[]){
        vis[src] = true;
        for(auto nbr : adj[src]){

              if(nbr == parent){
                continue;
              }
            if(!vis[nbr]){
            bool ans = solve(nbr, vis, src, adj);
            if(ans == true){
                return true;
            }
            }
            else if(vis[nbr] == true){
                return false;
            }
        }


        return false;
    }



       bool isCycle(int V, vector<int> adj[]) {
        unordered_map<int,bool> vis;
        for(int i=0;i<V;i++) {
            if(!vis[i]) {
                int parent = -1;
                bool isCyclic = solve(i, vis, parent,adj);
                if(isCyclic == true) {
                    return true;
                }
            }
        }
        return false;
    }

}
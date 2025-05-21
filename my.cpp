#include <iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;



// class Graph{
//     public:
//        unordered_map<int, list<int> > adjlist;
//        void addEdge(int u, int v, bool direction){
//         // 0 -> means undirected
//         //1 -> means directed
//          if(direction == 1){
//             adjlist[u].push_back(v);
//          }
//          else{
//             adjlist[u].push_back(v);
//             adjlist[v].push_back(u);
//          }
       

//        cout<<"prininting adjlist"<< endl;
//           printAdjList();
//        }

//        void printAdjList(){
//         for(auto it : adjlist){
//             cout <<it.first<<"{";
//             for(auto nbr : it.second){
//                 cout<<nbr<<", ";

//             }
//             cout <<"}"<<endl;
//         }

//        }
// };


template<typename T>
class Graph{
    public:
    unordered_map<T, list<pair<T, int> > > adjList;
    void addEdge(T u, T v, int w, bool direction){
        if(direction == 1){
            adjList[u].push_back(make_pair(v, w));
        }
        else{
            adjList[u].push_back(make_pair(v, w));
            adjList[v].push_back(make_pair(u, w));
        }
    }

    void print(){
        for(auto i : adjList){
            cout<<i.first<<" ";
            for(auto it : i.second){
                cout<<"{"<<it.first<<" "<<it.second<<"}";
            }
            cout<<"}"<<endl;
        }
    }

    void bfs(T src, unordered_map<T, bool> &vis){
        queue<int> q;
        q.push(src);
        vis[src] = true;

        while(!q.empty()){
            T frontnode =q.front();
            cout<<frontnode<<endl;
            q.pop();

            for(auto nbr : adjList[frontnode]){
                T nbrdata = nbr.first;
                if(!vis[nbrdata]){
                    q.push(nbrdata);
                    vis[nbrdata] = true;
                }

            }
        }
    }

    void dfs(T src, unordered_map<T, bool> &vis){
        vis[src]= true;
        cout<<src;
        for(auto  nbr : adjList[src]){
            T nbrdata = nbr.first;
            if(!vis[nbrdata]){
                vis[nbrdata] = true;
                dfs(nbrdata, vis);
            }
        }
    }


};




int main(){
    Graph<int> g;
    g.addEdge(1, 2, 2, 1);
     g.addEdge(1, 3, 3, 0);
     g.addEdge(2, 4, 9, 1);
     g.addEdge(2, 3, 5, 1);
     g.addEdge(4, 5, 1, 0);
    
  g.print();

  unordered_map<int, bool> vis;
//   for(int i = 1; i <=3; i++){
//     if(!vis[i]){
//         g.bfs(i, vis);
//     }

   for(int i = 1; i <=5; i++){
    if(!vis[i]){
        g.dfs(i, vis);
    }

  }

    return 0;
}

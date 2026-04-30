#include <bits/stdc++.h>
using namespace std;

int main() {
    int V, E;
    cin >> V >> E;

    vector<pair<int,int>> adj[1000];
    for(int i=0;i<E;i++){
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    vector<bool> vis(V, false);

    pq.push({0, 0});

    int sum = 0;

    while(!pq.empty()) {

        int wt = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(vis[node] == true) continue;

        vis[node] = true;
        sum = sum + wt;

        for(auto it : adj[node]) {
            int nextNode = it.first;
            int edgeWt = it.second;

            if(!vis[nextNode]) {
                pq.push({edgeWt, nextNode});
            }
        }
    }
    cout << sum;
    return 0;
}
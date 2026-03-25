#include<bits/stdc++.h>
using namespace std;
int main(){
    int n , m ;
    cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i = 0; i  < m ; i++){
        int a , b , w;
        cin>> a>> b>>w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }
    vector<long long> dist(n+1, LLONG_MAX);
    vector<long long> parent(n + 1);
    for(int i = 0; i < n+1; i++){
        parent[i] = i;
    }
    priority_queue<pair<long long,long long>, vector<pair<long long,long long>> , greater<pair<long long,long long>>> pq;
    dist[1] = 0;
    pq.push({0,1});
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        auto weight = it.first;
        auto node = it.second;
        if(dist[node] < weight) continue;
        for(auto i : adj[node]){
            int nw = i.first;
            int ne = i.second;

            if(dist[node] + ne < dist[nw]){
                dist[nw] = dist[node] + ne;
                parent[nw] = node;
                pq.push({dist[nw], nw}); 
            }
        }
    }
    if(dist[n] == LLONG_MAX){
        cout<<-1;
        return 0;
    }
    vector<int> arr;
    int n1 = n;
    while(parent[n1] != n1){
        arr.push_back(n1);
        n1 = parent[n1];
    }
    arr.push_back(1);
    reverse(arr.begin(),arr.end());
    for(int i = 0; i < arr.size(); i++){
        cout<<arr[i]<< " ";
    }
}
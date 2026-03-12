#include <bits/stdc++.h>
using namespace std;

// anshikaa codeess 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

#define forr(i, a, b) for (int i = a; i <= b; i++)
#define rep(i, a) for (int i = 0; i < a; i++)
#define all(v) (v).begin(), (v).end()
#define SORT(v) sort(all(v))
#define f first
#define s second
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define pb push_back

const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int maxops;
    cin >> maxops;

    vector<int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    priority_queue<int> pq;

    for(auto &i : arr){
        pq.push(i);
    }
    int cnt = 0;

    while(cnt < maxops){
        int val = pq.top();
        pq.pop();
        cnt++;

        if(val % 2){ 
            if(cnt < maxops && val/2 > 1){
                pq.push(val/2 - 1);
                pq.push(val/2 + 2);
            }
            else{
                pq.push(val/2);
                pq.push(val/2 + 1);
            }
        }
        else{  
            pq.push(val/2);
            pq.push(val/2);
        }
    }
    cout << pq.top();
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'


const int INF = 1e12;
typedef pair<int, int> pii;

vector<vector<pii>> g;
vector<int> dist;
vector<int>  pai;

void dijkstra(int a) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[a] = 0;
    pai[a] = -1;
    pq.push({0, a});

    while (!pq.empty()) {
        auto [atual, u] = pq.top(); pq.pop();
        if (atual > dist[u]) continue;
        for (auto [peso, v] : g[u]) {
            if (dist[u] + peso < dist[v]) {
                dist[v] = dist[u] + peso;
                pq.push({dist[v], v});
                pai[v] = u;
            }
        }
    }
}

signed main() {
    int n, m; cin >> n >> m;
    g.resize(n + 1);
    dist.resize(n + 1, INF);
    pai.resize(n + 1);
    
    while(m--){
        int a, b, w; cin >> a >> b >> w;
        // a--; b--;
        g[a].emplace_back(w, b);
            g[b].emplace_back(w, a);

    }
    
    dijkstra(1);
    
    if(dist[n] == INF)cout << -1 << endl;
    else{
        vector<int> ans;
        for(int i = n; i != -1; i = pai[i]){
            ans.emplace_back(i);
        }
        reverse(ans.begin(), ans.end());
        
        for(auto u : ans)cout << u << " ";
        cout << endl;
    }
    
}

#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;
int n, m, gsum;
map<int, int> a;
vector<int> G[MAXN];
map<int, int> T[MAXN];

void exdfs(int u, int sum){
    // cout<<"exdfs: "<<u<<endl;
    bool flag = true;
    for(int v: G[u]){
        if (T[u][v] || T[v][u]) continue;
        flag = false;
        T[u][v] = 1;
        T[v][u] = 1;
        exdfs(v, sum+a[v]);
    }
    if (flag) {
        gsum = max(gsum, sum);
    }
}

void dfs(int u, int p, int sum){
    // cout<<u<<" "<<p<<" "<<sum<<endl;
    if (u == p){
        // cout<<"dfs: "<<sum<<endl;
        exdfs(u, sum);
        return ;
    }
    for(int v: G[u]){
        if (T[u][v] || T[v][u]) continue;
        T[u][v] = 1;
        T[v][u] = 1;
        dfs(v, p, sum+a[v]);
    }
}

int main(){
    freopen("take.in", "r", stdin);
	freopen("take.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        a[i] = x;
    }
    for(int i=0; i<n-1; i++){
        int u, v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        dfs(u, v, a[u]);
        cout<<gsum<<endl;
        gsum = 0;
        for(int i=0; i<=n; i++){
            T[i].clear();
        }
    }

    return 0;
}
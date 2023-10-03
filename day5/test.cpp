#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int N = 2e5 + 10, M = 2e5 + 10;

int n, m;
int h[N], e[M], ne[M], w[M], idx;
int dist[N], cnt[N];
bool st[N];
vector<int> mst;

struct Edge {
    int a, b, w;
} edges[M];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

void prim() {
    memset(dist, 0x3f, sizeof dist);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, 1});
    dist[1] = 0;
    while (q.size()) {
        auto t = q.top();
        q.pop();
        int ver = t.second, distance = t.first;
        if (st[ver]) continue;
        st[ver] = true;
        if (ver != 1) mst.push_back(cnt[ver]);
        for (int i = h[ver]; ~i; i = ne[i]) {
            int j = e[i];
            if (dist[j] > w[i]) {
                dist[j] = w[i];
                cnt[j] = i;
                q.push({dist[j], j});
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    for (int i = 0; i < m; i ++ ) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c), add(b, a, c);
        edges[i] = {a, b, c};
    }
    prim();
    for (int i = 0; i < m; i ++ ) {
        int a = edges[i].a, b = edges[i].b, c = edges[i].w;
        bool is_mst = false;
        for (auto j : mst) {
            if (j == cnt[a] || j == cnt[b]) {
                is_mst = true;
                break;
            }
        }
        if (is_mst) puts("-1");
        else {
            st[a] = st[b] = false;
            add(a, b, c), add(b, a, c);
            prim();
            int res = 0x3f3f3f3f;
            for (auto j : mst) {
                if (j != cnt[a] && j != cnt[b]) {
                    res = min(res, w[j]);
                }
            }
            printf("%d\n", res);
            add(a, b, 0), add(b, a, 0);
        }
    }
    return 0;
}
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
#define maxN 510
#define maxE 100010
struct edge {
    int v, c;
    int next;
}edges[maxE];
int n, E, s, t, Ma;
int head[maxN];
int cost[maxN];
int visited[maxN];
int cnt = 0;
struct node {
    int id;
    int dis;
    int cos;
    node(int id, int dis, int cos) { this->id = id, this->dis = dis, this->cos = cos; }
    bool operator < (const node& a) const {
        if (dis == a.dis) return cos > a.cos;
        else return dis > a.dis;
    }
};
priority_queue<node> pq;
void add_edge(int u, int v, int c) {
    cnt++;
    edges[cnt].v = v, edges[cnt].c = c;
    edges[cnt].next = head[u];
    head[u] = cnt;
}

int main() {
    int m; cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> n >> E >> s >> t >> Ma;
        memset(head, -1, sizeof(int) * maxN);
        memset(visited, 0x3f, sizeof(int) * maxN);
        // memset(edges, 0, sizeof(edge) * maxE);
        // memset(cost, 0, sizeof(int) * maxN);

        cnt = 0;
        for (int i = 1; i <= n; i++)
            cin >> cost[i];
        for (int i = 0; i < E; i++)
        {
            int u, v, c;
            cin >> u >> v >> c;
            add_edge(u, v, c);
            add_edge(v, u, c);
        }

        int res = -1;
        while (!pq.empty()) pq.pop();
        pq.push(node(s, 0, 0));
        while (!pq.empty())
        {
            int p = pq.top().id;
            int cos = pq.top().cos;
            int dis = pq.top().dis;
            
            if (p == t) 
            {
                res = dis;
                break;
            }
            pq.pop();
            
            visited[p] = min(visited[p], cos);
            for (int j = head[p]; j != -1; j = edges[j].next)
            {
                
                int k = edges[j].v;
                int m = cost[k];
                if ((visited[k] > cos + m) && (cos + m <= Ma))
                {
                    pq.push(node(k, dis + edges[j].c, cos + m));
                }                
            }
        }
        if (res != -1) cout << res << endl;
        else cout << -1 << endl;


    }

}
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
#define N 510
#define E 20010 // 无向边 ！！！ * 2

struct Edge{
    int v, w;
    int next;
}edges[E];

int head[N];
int cnt = 0; // 0的化则head初始化既可以选择-1或者0，如果采用-1则必须在插入边之前memset ;-1则head初始化必然选择-1

void add_edge(int u, int v, int w)
{
    cnt++;
    edges[cnt].v = v;
    edges[cnt].w = w;
    edges[cnt].next = head[u];
    head[u] = cnt;
}

struct Node{
    int pos, dis;
    bool operator < (const Node &node) const{
        return dis > node.dis;
    }
};

priority_queue<Node> pq;
int visited[N];
int dist[N];

int n, e, s, t;

int main() {
    int m; cin >> m;
    while (m--)
    {
        cin >> n >> e >> s >> t;
        memset(head, 0, sizeof(int) * N);
        memset(dist, 0x3f, sizeof(int) * N); // 0x3f
        memset(visited, 0, sizeof(int) * N);
        cnt = 0;
        for (int i = 0; i < e; i++)
        {   
            int u, v, w;
            cin >> u >> v >> w;
            add_edge(u, v, w);
            add_edge(v, u, w);
        }

        while (!pq.empty()) pq.pop();
        Node source; 
        source.pos = s;
        source.dis = 0;
        pq.push(source);
        dist[source.pos] = 0; // 注意dist的初始化,但不需要对vist初始化，否则后面判断会continue
                
        int ans = -1;
        while (!pq.empty())
        {
            int pos = pq.top().pos;
            int dis = pq.top().dis;
            if (pos == t)
            {
                ans = dis;
                break;
            }
            pq.pop();
            if (visited[pos]) continue; // 注意如果已经得到了最短路，则队列中剩下的路径选择不处理
            visited[pos] = 1;

            for (int e = head[pos]; e != 0; e = edges[e].next)
            {
                int to = edges[e].v;
                if (dist[pos] + edges[e].w < dist[to]) {
                    dist[to] = dist[pos] + edges[e].w;
                    if (!visited[to]) {
                        Node node;
                        node.pos = edges[e].v;
                        node.dis = dist[to];
                        pq.push(node);
                        // visited[node.pos] = 1;
                    }
                }
            }
        }        
        cout << ans << endl;        
    }    
    return 0;
}
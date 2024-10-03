#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

typedef pair<int, int> pii;
const int INF = numeric_limits<int>::max();

void dijkstra(int source, vector<vector<pii>>& graph, vector<int>& dist) {
    priority_queue<pii, vector<pii>, greater<pii>> pq; // Min-heap
    dist[source] = 0;
    pq.push({0, source}); 

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        
        if (d > dist[u]) continue;

       
        for (auto edge : graph[u]) {
            int v = edge.first;
            int w = edge.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}


int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<pii>> graph(N + 1); 
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    int S;
    cin >> S;

    vector<int> dist(N + 1, INF); 
    dijkstra(S, graph, dist);

    for (int i = 1; i <= N; i++) {
        if (dist[i] == INF) {
            cout << "-1 ";
        } else {
            cout << dist[i] << " ";
        }
    }
    cout << endl;

    return 0;
}
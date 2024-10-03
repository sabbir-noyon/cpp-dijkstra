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
    pq.push({0, source}); // {distance, node}

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // If the distance is greater than the stored distance, ignore it
        if (d > dist[u]) continue;

        // Explore all neighbors
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

//
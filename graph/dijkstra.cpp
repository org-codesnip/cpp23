#include "graph.h"

#include <queue>
#include <functional>
#include <limits>

using namespace std;

vector<optional<unsigned int>> dijkstra(
    const vector<vector<tuple<size_t, unsigned int>>>& graph,
    const size_t src
) {
    vector<optional<unsigned int>> ret(
        graph.size(), nullopt
    );

    const vector breadth{tuple{numeric_limits<unsigned int>::min(), src}};
    priority_queue heap{greater(), breadth}; // min-heap
    while (!heap.empty()) {
        const auto [dist, v] = heap.top();
        heap.pop(); // why no return value ??

        if (ret[v].value_or(
            numeric_limits<unsigned int>::max()
            ) <= dist) {
            continue; // visited
        }
        ret[v] = dist;

        for (const auto [v_next, w]: graph[v]) {
            heap.emplace(dist + w, v_next);
        }
    }

    return ret;
}

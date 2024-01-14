#include "graph.h"

#include <queue>
#include <limits>
#include <algorithm>

using namespace std;

vector<tuple<size_t, size_t, unsigned int>> prim(
    const vector<vector<tuple<size_t, unsigned int>>>& graph
) {
    vector<tuple<size_t, size_t, unsigned int>> ret;
    if (graph.empty()) return ret;

    vector visited(graph.size(), false);
    const vector breadth{tuple{
        numeric_limits<unsigned int>::min(),
        numeric_limits<size_t>::min(),
        numeric_limits<size_t>::min(),
    }}; // dummy edge
    priority_queue heap{greater(), breadth}; // min-heap
    while (!heap.empty()) {
        const auto [w, v, v_prev] = heap.top();
        heap.pop();

        if (visited[v]) continue;
        visited[v] = true;

        for (const auto [v_next, w_next] : graph[v]) {
            heap.emplace(w_next, v_next, v);
        }

        ret.emplace_back(v_prev, v, w);
    }

    ranges::reverse(ret);
    ret.pop_back();

    return ret;
}

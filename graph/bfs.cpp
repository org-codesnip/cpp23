#include "graph.h"

#include <limits>

using namespace std;

vector<optional<unsigned int>> bfs(
    const vector<vector<size_t>>& graph,
    const size_t src
) {
    vector<optional<unsigned int>> ret(
        graph.size(), nullopt
    );

    unsigned int water_level = 0;
    vector breadth{src};
    while (!breadth.empty()) {
        vector<size_t> breadth_next;
        for (const auto v : breadth) {
            if (ret[v].value_or(numeric_limits<unsigned int>::max()) <= water_level) {
                continue;
            }
            ret[v] = water_level;

            breadth_next.insert(
                breadth_next.end(),
                graph[v].begin(), graph[v].end()
            );
        }

        breadth = breadth_next;
        water_level += 1;
    }

    return ret;
}

#ifndef GRAPH_H
#define GRAPH_H

#include <cstddef>
#include <vector>
#include <optional>
#include <tuple>

std::vector<std::optional<unsigned int>> bfs(
    const std::vector<std::vector<std::size_t>>& graph,
    const std::size_t src
);

std::vector<std::optional<unsigned int>> dijkstra(
    const std::vector<std::vector<std::tuple<std::size_t, unsigned int>>>& graph,
    const std::size_t src
);

#endif //GRAPH_H

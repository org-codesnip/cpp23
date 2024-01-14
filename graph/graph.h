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

std::vector<std::tuple<std::size_t, std::size_t, unsigned int>> prim(
    const std::vector<std::vector<std::tuple<std::size_t, unsigned int>>>& graph
);

class DisjointSet {
private:
    std::vector<std::size_t> m_parents;

public:
    explicit DisjointSet(const std::size_t n);

    std::size_t query(std::size_t token);
    void link(std::size_t token_0, std::size_t token_1);
};

#endif //GRAPH_H

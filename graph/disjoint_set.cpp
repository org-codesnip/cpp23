#include "graph.h"

using namespace std;

vector<size_t> to_parents(const size_t n) {
    vector<size_t> ret;
    ret.reserve(n);

    for (size_t i = 0; i < n; i += 1) {
        ret.push_back(i);
    }

    return ret;
}

DisjointSet::DisjointSet(const size_t n)
    : m_parents(to_parents(n)) {}

size_t DisjointSet::query(size_t token) {
    if (token >= this->m_parents.size()) {
        return 0; // TODO: panic
    }

    auto token_next = this->m_parents[token];
    if (token_next == token) return token;

    token_next = this->query(token_next);
    this->m_parents[token] = token_next;

    return token_next;
}

void DisjointSet::link(size_t token_0, size_t token_1) {
    token_0 = this->query(token_0);
    token_1 = this->query(token_1);

    if (token_0 == token_1) return;

    this->m_parents[token_1] = token_0;
}

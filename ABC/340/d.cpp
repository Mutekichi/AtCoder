#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>
#include <numeric>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <deque>
#include <bitset>
#include <utility>
#include <complex>
#include <climits>
#include <cfloat>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <assert.h>
#include <iomanip>

using namespace std;

class debug_cout {
public:
    debug_cout(bool debug) : debug(debug) {}

    template<typename T>
    debug_cout& operator<<(const T& value) {
        if (debug) {
            cout << value;
        }
        return *this;
    }

    debug_cout& operator<<(std::ostream& (*manip)(std::ostream&)) {
        if (debug) {
            manip(std::cout);
        }
        return *this;
    }

private:
    bool debug;
};

debug_cout dbgcout(true);


class DirectedWeightedGraph {
public:
    struct Edge {
        int from;
        int to;
        long long weight;
        int rev;
    };

    DirectedWeightedGraph(int n) {
        this->n = n;
        this->edges.resize(n);
    }

    void add_edge(int from, int to, long long weight) {
        edges[from].push_back({from, to, weight, (int)edges[to].size()});
        edges[to].push_back({to, from, 0, (int)edges[from].size() - 1});
    }

    vector<Edge> get_edges(int from) {
        return edges[from];
    }

    /**
     * @brief Dinic's algorithm O(V^2 E)
     * 
     * @param s source
     * @param t sink
     * @return max flow
    */
    long long max_flow(int s, int t) {
        long long flow = 0;
        while (true) {
            vector<long long> dist(n, INF);
            dist[s] = 0;
            queue<int> que;
            que.push(s);
            vector<int> iter(n, 0);
            while (!que.empty()) {
                int v = que.front();
                que.pop();
                for (Edge &e : edges[v]) {
                    if (e.weight > 0 && dist[e.to] == INF) {
                        dist[e.to] = dist[v] + 1;
                        que.push(e.to);
                    }
                }
            }
            if (dist[t] == INF) {
                break;
            }
            long long f = 0;
            while ((f = dfs(s, t, INF, dist, iter)) > 0) {
                flow += f;
            }
        }
        return flow;
    }

    /**
     * @brief Get shortest paths from start
     * 
     * @param start start node
     * @param distances distances from start
     * 
     * @note O(E log V) (Dijkstra's algorithm)
     */
    void get_shortest_paths
    (
        int start,
        vector<long long> &distances
    ) {
        distances.resize(n, INF);
        distances[start] = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, start});
        while (!pq.empty()) {
            pair<long long, int> p = pq.top();
            long long d = p.first;
            int u = p.second;
            pq.pop();
            if (d > distances[u]) continue;
            for (auto &e : edges[u]) {
                if (e.weight > 0 && distances[e.to] > distances[u] + e.weight) {
                    distances[e.to] = distances[u] + e.weight;
                    pq.push({distances[e.to], e.to});
                }
            }
        }
    }

    long long min_cut(int a, int b) {
        return max_flow(a, b);
    }

private:
    int n;
    vector<vector<Edge>> edges;
    const long long INF = numeric_limits<long long>::max();

    long long dfs(int v, int t, long long f, vector<long long> &dist, vector<int> &iter) {
        if (v == t) {
            return f;
        }
        for (int &i = iter[v]; i < edges[v].size(); i++) {
            Edge &e = edges[v][i];
            if (e.weight > 0 && dist[v] < dist[e.to]) {
                long long d = dfs(e.to, t, min(f, e.weight), dist, iter);
                if (d > 0) {
                    e.weight -= d;
                    edges[e.to][e.rev].weight += d;
                    return d;
                }
            }
        }
        return 0;
    }
};

template<typename T>
void output_vector(vector<T> v, bool debug) {
    for (int i = 0; i < v.size(); i++) {
        if (debug) {
            dbgcout << v[i] << " ";
        }
        else {
            cout << v[i] << " ";
        }
    }
    if (debug) {
        dbgcout << endl;
    }
    else {
        cout << endl;
    }
}

int main() {

    int n;
    cin >> n;
    
    DirectedWeightedGraph graph(n);

    for (int i = 0; i < n - 1; ++i) {
        long long a, b;
        cin >> a >> b;
        int x;
        cin >> x;
        x--;
        graph.add_edge(i, i + 1, a);
        graph.add_edge(i, x, b);
    }

    vector<long long> dist;
    graph.get_shortest_paths(0, dist);

    cout << dist[n - 1] << endl;

    return 0;
}

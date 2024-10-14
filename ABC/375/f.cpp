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

struct query {
    
}

int main() {

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<pair<long long, int>>> graph(
        n, vector<pair<long long, int>>()
    );

    for (int i = 0; i < m; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        --u;
        --v;
        graph[u].push_back(make_pair(w, v));
        graph[v].push_back(make_pair(w, u));
    }



    vector<vector<long long>> dist(
        n, vector<long long>(n, LLONG_MAX)
    );

    for (int i = 0; i < n; ++i) {
        dist[i][i] = 0;
        for (const auto &edge : graph[i]) {
            dist[i][edge.second] = edge.first;
        }
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] == LLONG_MAX || dist[k][j] == LLONG_MAX) {
                    continue;
                }
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    return 0;
}

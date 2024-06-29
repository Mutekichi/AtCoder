
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

int main() {

    int n, m;
    cin >> n >> m;

    vector<int> a(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
        if (a[i] == 1 || a[i] == n) {
            cout << -1 << endl;
            return 0;
        }
    }

    sort(a.begin(), a.end());

    vector<int> ans(n);
    for (int i = 0; i < n; ++i) ans[i] = i + 1;

    for (int i = 0; i < m; ++i) {
        swap(ans[a[i] - 1], ans[a[i]]);
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i];
        if (i < n - 1) cout << " ";
    } cout << endl;
    
    return 0;
}
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
void print_vector(vector<T> v, bool debug) {
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

    string s, t;
    cin >> s >> t;

    int len = s.size();

    vector<int> a, b;

    for (int i = 0; i < len; ++i) {
        if (s[i] != t[i]) {
            if (s[i] < t[i]) {
                a.push_back(i);
            } else {
                b.push_back(i);
            }
        }
    }

    string current = s;

    cout << a.size() + b.size() << endl;

    for (int i = 0; i < b.size(); ++i) {
        current[b[i]] = t[b[i]];
        cout << current << endl;
    }

    for (int i = a.size() - 1; i >= 0; --i) {
        current[a[i]] = t[a[i]];
        cout << current << endl;
    }

    return 0;
}

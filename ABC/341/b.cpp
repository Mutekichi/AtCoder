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

debug_cout dbgcout(false);

int main() {
    
    int n;
    cin >> n;

    vector<long long> initial(n);


    for (int i = 0; i < n; ++i) {
        cin >> initial[i];
    }

    dbgcout
        << "initial: ";
    for (int i = 0; i < n; ++i) {
        dbgcout << initial[i] << " ";
    }
    dbgcout << endl;

    for (int i = 0; i < n - 1; ++i) {
        long long s, t;
        cin >> s >> t;

        dbgcout
            << "s: " << s << ", "
            << "t: " << t << endl;

        initial[i + 1] += t * (initial[i] / s);
    }

    dbgcout
        << "initial: ";

    cout << initial[n - 1] << endl;

    return 0;
}

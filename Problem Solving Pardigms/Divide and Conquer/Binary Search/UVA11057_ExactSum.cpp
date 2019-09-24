#include <bits/stdc++.h>

using namespace std;

typedef unsigned int u;

// Math
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

// Loop
#define rep(i, n) for (i = 0; i < n; ++i)
#define repn(i, k, n) for (i = k; i <= n; ++i)
#define repr(i, k, n) for (i = k; i >= n; --i)

// INF
#define INF 1000000000

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<long long> vl;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w+", stdout);
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, obj, first, last, diff,minDiff,bestFirst,bestLast;
    bool empty_line(false);
    while (cin >> n) {
        if (empty_line) {
            cout << "\n";
        }
        vi tab(n);
        for (int i = 0; i < n; ++i) {
            cin >> tab[i];
        }
        sort(tab.begin(), tab.end());
        cin >> obj;

        minDiff = INF;
        for (int i = 0; i < n; ++i) {
            first = tab[i];
            last = obj - first;
            if (binary_search(tab.begin()+i+1, tab.end(), last)) {
                diff = abs(last - first);
                if(diff < minDiff)
                {
                    bestFirst = first;
                    bestLast = last;
                    minDiff = diff;
                }
            }
        }
        cout << "Peter should buy books whose prices are " << bestFirst << " and " << bestLast << ".\n";
        empty_line = true;
    }
    cout<<'\n';


    return 0;
}

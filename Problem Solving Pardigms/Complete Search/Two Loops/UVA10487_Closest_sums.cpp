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


template<typename T>
void printList(vector<T> text) {

    for (const auto &value: text)
        std::cout << value << " ";
    std::cout << '\n';
}

int main() {
    /*
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    */

    int n, m, q;
    int t = 1;
    int res = INF;
    int dist = INF;
    while (scanf("%d", &n) && n != 0) {

        vi arr(n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
        }

        res = INF;
        dist = INF;
        bool first(true);
        scanf("%d", &m);
        printf("Case %d:\n", t++);
        for (int j = 0; j < m; ++j) {
            scanf("%d", &q);
            for (int i = 0; i < n; ++i) {
                for (int k = i + 1; k < n; ++k) {
                    if(dist > abs(q - (arr[i] + arr[k])) || first) {
                        dist = abs(q - (arr[i] + arr[k]));
                        res = arr[i] + arr[k];
                        first = false;
                    }
                }
            }
            printf("Closest sum to %d is %d.\n", q, res);
            res = INF;
            dist = INF;
            first = true;
        }
    }
    return 0;
}

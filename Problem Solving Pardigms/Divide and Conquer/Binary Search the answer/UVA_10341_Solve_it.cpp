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
typedef vector<long long> vll;


template<typename T>
void printList(vector<T> text) {

    for (const auto &value: text)
        std::cout << value << " ";
    std::cout << '\n';
}


double function_imp(int p, int q, int r, int s, int t, int u, double x) {
    double res = p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
    return res;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w+", stdout);
    int p, q, r, s, t, u;
    double left(0);
    double right(0);
    float val_mid;
    double mid(0);
    while (cin >> p >> q >> r >> s >> t >> u) {

        if (p * exp(-1) + q * sin(1) + r * cos(1) + s * tan(1) + t + u > 1e-9 || p + r + u < 0) {
            cout << "No solution\n";
            continue;
        }

        left = 0.0;
        right = 1.0;
        for (int i = 0; i < 30; ++i) {
            mid = (left + right) / 2;
            val_mid = function_imp(p, q, r, s, t, u, mid);
            if (val_mid > 0) {
                left = mid;

            } else {
                right = mid;
            }
        }
        cout << std::fixed << std::setprecision(4) << left << '\n';
    }


    return 0;
}





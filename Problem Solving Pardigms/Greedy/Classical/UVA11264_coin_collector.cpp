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


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w+", stdout);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        ll array[n];
        for (int i = 0; i < n; i++)
        {
            cin >> array[i];
        }

        ll sum = array[0];
        int coin = 1;
        for (int i = 1; i < n - 1; i++) {
            if (sum + array[i] < array[i + 1]) {
                sum += array[i];
                coin++;
            }
        }
        coin++;
        cout << coin << endl;
    }

    return 0;
}
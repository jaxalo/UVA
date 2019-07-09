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

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int tc, n, cnt, cmp;
    scanf("%d", &tc);
    while (tc--) {

        //init
        scanf("%d", &n);
        vi arr(n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
        }
        //--

        //process
        cnt = 0;
        for (int i = 1; i < n; ++i) {
            cmp = arr[i];
            for (int j = 0; j < i; ++j) {
                if (arr[j] <= cmp) {
                    cnt++;
                }
            }
        }
        //--

        printf("%d\n", cnt);
    }
    return 0;
}

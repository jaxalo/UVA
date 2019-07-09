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

    int n;
    string temp;
    bool first(true);
    while (scanf("%d", &n) && n != 0) {
        vi arr(n);

        if (!first) {
            printf("\n");
        } else {
            first = false;
        }

        for (int i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
        }

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    for (int l = k + 1; l < n; ++l) {
                        for (int m = l + 1; m < n; ++m) {
                            for (int i1 = m + 1; i1 < n; ++i1) {
                                printf("%d %d %d %d %d %d\n", arr[i], arr[j], arr[k], arr[l], arr[m], arr[i1]);
                            }
                        }
                    }
                }
            }
        }


    }


    return 0;
}

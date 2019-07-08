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
    //freopen("temp.txt", "w", stdout);
    int k, x, y;
    int count(0);
    vii arr;
    for (;;) {
        scanf("%d", &k);
        if (k == NULL)
            break;

        arr.clear();
        //compute answer
        for (int x = 0; x < 1000000; ++x) {
            if (x - k > 0 && (k * x) % (x - k) == 0 && (k * x) / (x - k) > 0) {
                y = (int) ((k * x) / (x - k));
                if (y >= x) {
                    arr.push_back(make_pair(x, y));
                    count++;
                }
            }
        }

        //print
        printf("%d\n", count);
        for (ii rep : arr) {
            printf("1/%d = 1/%d + 1/%d\n", k, rep.second, rep.first);
        }

        //reset
        k = NULL;
        count = 0;
    }

    return 0;
}


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

int length(5);

int getDist(vi &city, int i, int j, int k, int l, int m) {
    int dist(0);
    int temp(INF);

    for (int n = 0; n < length * length; ++n) {
        if (city[n] != 0) {
            temp = min(temp, (int) ((abs(n / length - i / length) + abs(n % length - i % length))));
            temp = min(temp, (int) ((abs(n / length - j / length) + abs(n % length - j % length))));
            temp = min(temp, (int) ((abs(n / length - k / length) + abs(n % length - k % length))));
            temp = min(temp, (int) ((abs(n / length - l / length) + abs(n % length - l % length))));
            temp = min(temp, (int) ((abs(n / length - m / length) + abs(n % length - m % length))));
            temp = city[n] * temp;
            dist += temp;
            temp = INF;
        }
    }
    return dist;
}

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w+", stdout);

    int tc, q, a, b, pop;
    int i, j, k, l, m;
    scanf("%d", &tc);
    int taille(25);

    vi city(length * length);
    while (tc--) {
        //---init
        fill(city.begin(), city.end(), 0);
        scanf("%d", &q);
        while (q--) {
            scanf("%d %d %d", &a, &b, &pop);
            city[a * length + b % length] = pop;
        }
        //--

        //---process
        int minDist(INF);
        vi res(5);
        int dist;
        for (i = 0; i < taille; ++i) {
            for (j = i + 1; j < taille; ++j) {
                for (k = j + 1; k < taille; ++k) {
                    for (l = k + 1; l < taille; ++l) {
                        for (m = l + 1; m < taille; ++m) {
                            dist = getDist(city, i, j, k, l, m);
                            if (minDist > dist) {
                                res[0] = i;
                                res[1] = j;
                                res[2] = k;
                                res[3] = l;
                                res[4] = m;
                                minDist = dist;
                            }
                        }
                    }
                }
            }
        }
        //--

        //--print
        printf("%d %d %d %d %d\n", res[0], res[1], res[2], res[3], res[4]);
        //--
    }

    return 0;

}

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

int manhattanDist(int x1, int y1, int x2, int y2) {
    return abs(y1 - y2) + abs(x1 - x2);
}

int main() {

    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string temp;
    while (cin >> n) {
        //----init
        int mat[n][n];
        getline(cin, temp);
        for (int i = 0; i < n; ++i) {
            getline(cin, temp);
            for (int j = 0; j < n; ++j) {
                mat[i][j] = temp[j] - '0';
            }
        }
        //--get pos of 1 and 3
        vii pos1;
        vii pos3;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 1) {
                    pos1.push_back(make_pair(i, j));
                } else if (mat[i][j] == 3) {
                    pos3.push_back(make_pair(i, j));
                }
            }
        }

        //--
        //----

        //--process
        int dist = INF;
        int res(-1);
        bool first(true);
        for (int i = 0; i < pos1.size(); ++i) {
            for (int j = 0; j < pos3.size(); ++j) {
                if (first) {
                    dist = manhattanDist(pos1[i].first, pos1[i].second, pos3[j].first, pos3[j].second);
                    first = false;
                }
                dist = min(dist, manhattanDist(pos1[i].first, pos1[i].second, pos3[j].first, pos3[j].second));
            }
            res = max(res, dist);
            dist = INF;
        }
        //--

        cout << res << '\n';
    }


    return 0;
}

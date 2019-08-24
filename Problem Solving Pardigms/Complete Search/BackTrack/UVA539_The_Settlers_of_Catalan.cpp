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


int longDist(-INF);

template<typename T>
void printList(vector<T> text) {

    for (const auto &value: text)
        cout << value << " ";
    cout << '\n';
}

bool presentEdge(ii &p1, vii &pairs) {
    for (int i = 0; i < pairs.size(); ++i) {
        if (pairs[i].first == p1.first && pairs[i].second == p1.second) {
            return true;
        }
    }
    return false;
}

bool possibleEdge(int actualPlace, vii &chosen, vii &edges) {
    for (ii edge : edges) {
        if ((edge.first == actualPlace) && !presentEdge(edge, chosen)) {
            return true;
        }
    }
    return false;
}

void getDistanceHelper(int actualPlace, int curDist, vii &chosen, vii &edges) {

    if (!possibleEdge(actualPlace, chosen, edges)) {
        longDist = max(longDist, curDist);
    } else {
        for (ii edge : edges) {
            if (edge.first == actualPlace && !presentEdge(edge, chosen)) {
                chosen.push_back(edge);
                chosen.push_back(make_pair(edge.second,edge.first));
                getDistanceHelper(edge.second, curDist + 1, chosen, edges);
                chosen.pop_back();
                chosen.pop_back();
            }
        }
    }
}

int getDistance(ii edge, vii &edges) {
    longDist = -INF;
    vii chosen;
    getDistanceHelper(edge.first, 0, chosen, edges);
    return longDist;
}


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w+", stdout);
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, dist, maxDist, src, dest;

    while (cin >> n >> m && !(n == 0 && m == 0)) {
        maxDist = -INF;
        vii edges(2 * m);
        for (int i = 0; i < m; ++i) {
            cin >> src >> dest;
            edges[i].first = src;
            edges[i].second = dest;
            edges[2 * m - 1 - i].first = dest;
            edges[2 * m - 1 - i].second = src;
        }
        for (ii edge : edges) {
            dist = getDistance(edge, edges);
            maxDist = max(dist, maxDist);
        }
        cout << maxDist << '\n';
    }
    return 0;
}


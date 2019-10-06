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

    string temp;
    cin >> temp;
    vector<vi> positions(128);
    vi cur_positions(128);
    vector<bool> is_present(128);
    for (int i = 0; i < temp.size(); ++i) {
        positions[temp[i]].push_back(i);
        is_present[temp[i]] = true;
    }

    int tc, pos(0), toFind, value, start;
    bool solved(true);
    string query;
    cin >> tc;
    while (tc--) {
        solved = true;
        pos = 0;
        fill(cur_positions.begin(), cur_positions.end(), 0);
        cin >> query;
        for (int i = 0; i < query.size(); ++i) {
            toFind = query[i];
            if (!is_present[toFind]) {
                solved = false;
                break;
            }

            if (i == 0) {
                value = *lower_bound(positions[toFind].begin(), positions[toFind].end(), 0);
            } else {
                value = *lower_bound(positions[toFind].begin(), positions[toFind].end(), pos + 1);
            }


            if (pos + 1 > value && i != 0) {
                solved = false;
                break;
            } else {
                pos = value;
                if (i == 0) {
                    start = pos;
                }
            }
        }
        if (!solved) {
            cout << "Not matched\n";
        } else {
            cout << "Matched " << start << " " << pos << "\n";
        }

    }
    return 0;
}





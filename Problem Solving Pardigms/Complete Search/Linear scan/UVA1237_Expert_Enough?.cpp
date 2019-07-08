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
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("temp.txt", "w", stdout);
    int testcase(0);
    int q, d, l, h, data, count, a, b;
    string name, answer;
    cin >> testcase;
    for (int i = 0; i < testcase; ++i) {

        //insert into database
        cin >> d;
        map<string, ii> database;
        for (int j = 0; j < d; ++j) {
            cin >> name >> l >> h;
            database.insert(make_pair(name, make_pair(l, h)));
        }
        //--

        //query
        cin >> q;
        for (int k = 0; k < q; ++k) {
            cin >> data;
            count = 0;
            for (const auto elem : database) {
                a = elem.second.first;
                b = elem.second.second;
                if (a <= data && data <= b) {
                    answer = elem.first;
                    count++;
                }
            }

            // print answer
            if (count == 1) {
                cout << answer << "\n";
            } else {
                cout << "UNDETERMINED\n";
            }

            //--

        }

        if (i != testcase - 1) {
            cout << '\n';
        }//--

    }

    return 0;
}


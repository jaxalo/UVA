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


const int NN = 1e5;  // limit for array size
int n_arr;  // array size
int t[2 * NN];

void build() {  // build the tree
    for (int i = n_arr - 1; i > 0; --i) t[i] = t[i << 1] * t[i << 1 | 1];
}

void clearTree() {
    std::fill(t, t + 2*NN, 0);
}

void modify(int p, int value) {  // set value at position p
    for (t[p += n_arr] = value; p > 1; p >>= 1) t[p >> 1] = t[p] * t[p ^ 1];
}

int query(int l, int r) {  // sum on interval [l, r)
    int res = 1;
    for (l += n_arr, r += n_arr; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res *= t[l++];
        if (r & 1) res *= t[--r];
    }
    return res;
}

void printTree() {
    cout << "printT" << endl;
    for (int i = 0; i < 2 * NN; ++i) {
        cout << t[i] << " ; ";
    }
    cout << endl;
}

void solve(int tn, int nq) {
    string toPrint;
    char command;
    int a, b, res;

    //build tree
    clearTree();
    n = tn;
    int temp;
    for (int i = 0; i < tn; ++i) {
        cin >> temp;
        if (temp == 0) {
            t[n + i] = 0;
        } else if (temp > 0) {
            t[n + i] = 1;
        } else {
            t[n + i] = -1;
        }
    }

    build();

    //query
    for (int j = 0; j < nq; ++j) {
        cin >> command >> a >> b;
        if (command == 'C') {
            if (b == 0) {
                b = 0;
            } else if (b > 0) {
                b = 1;
            } else {
                b = -1;
            }
            modify(a - 1, b);
        } else {
            res = query(a - 1, b);
            if (res == 0) {
                toPrint += '0';
            } else if (res > 0) {
                toPrint += '+';
            } else {
                toPrint += '-';
            }
        }
    }

    //print res
    cout << toPrint;
}

int main() {
    std::ios_base::sync_with_stdio(false);

    /**
    freopen ("input.txt","r",stdin);
    freopen ("temp.txt","w",stdout);
    **/
    for (int tn, nq; cin >> tn >> nq; cout << endl) {
        solve(tn, nq);
    }

}


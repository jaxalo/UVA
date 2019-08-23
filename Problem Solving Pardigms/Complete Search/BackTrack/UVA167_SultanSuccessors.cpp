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


template<typename T>
void printList(vector<T> text) {

    for (const auto &value: text)
        cout << value << " ";
    cout << '\n';
}

int maxsum;

bool cross(ii p1, ii p2)
{
    bool res = p1.first == p2.first || p1.second == p2.second;
    int b = p1.second - p1.first;
    bool diag = p2.second == p2.first + b;

    int bp = p1.second + p1.first;
    bool diagp = p2.second == -p2.first + bp;

    return res || diag || diagp;
}


bool isValid(vii &chosen)
{
    for (int i = 0; i < chosen.size(); ++i) {
        for (int j = i+1; j < chosen.size(); ++j) {
            if(cross(chosen[i],chosen[j]))
            {
                return false;
            }
        }
    }
    return true;
}

void solveHelper(vector<vi> &chessBoard, int depth, int currentsum, vii &chosen) {
    if (depth == 8) {
        if (maxsum < currentsum) {
            maxsum = currentsum;
        }
    } else {
        for (int j = 0; j < 8; ++j) {
            ii choice = make_pair(depth,j);
            chosen.push_back(choice);
            if(isValid(chosen))
            {
                solveHelper(chessBoard,depth+1,currentsum+chessBoard[depth][j],chosen);
                chosen.pop_back();
            } else
            {
                chosen.pop_back();
            }

        }
    }
}

void solve(vector<vi> &chessBoard) {
    vii chosen;
    maxsum = -INF;
    solveHelper(chessBoard, 0, 0, chosen);
    int nbDigits = maxsum > 0 ? (int) log10 ((double) maxsum) + 1 : 1;
    int nbSpace = 5 - nbDigits;
    for (int i = 0; i < nbSpace; ++i) {
        cout << " ";
    }
    cout << maxsum << '\n';
}


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w+", stdout);
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);


    int tc(0);
    vector<vi> chessBoard(8);
    for (int i = 0; i < 8; ++i) {
        chessBoard[i].resize(8);
        for (int j = 0; j < 8; ++j) {
            chessBoard[i][j] = 0;
        }
    }
    cin >> tc;
    while (tc--) {
        for (int i = 0; i < 64; ++i) {
            cin >> chessBoard[i / 8][i % 8];
        }
        solve(chessBoard);
    }

    return 0;
}


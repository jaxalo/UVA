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


int search_in_diag(int col, int row, int upper, vector<vi> &mat) {

    int n = mat.size();
    int m = mat[0].size();
    int l = -1;
    int r = min(n - row, m - col);
    while(r - l > 1) {
        int mid = l + (r - l) / 2;
        if(mat[row + mid][col + mid] <= upper)
            l = mid;
        else
            r = mid;
    }
    return l;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w+", stdout);
    int N, M;
    while (cin >> N >> M && N != 0 && M != 0) {
        // init
        vector<vi> matrix(N);
        for (int i = 0; i < N; ++i) {
            matrix[i].resize(M);
        }

        //

        //fill
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                cin >> matrix[i][j];
            }
        }
        //


        int tc;
        cin >> tc;
        while (tc--) {

            int lower, upper, max_size(-INF), lower_elem_row, upper_elem_row;
            cin >> lower >> upper;
            //find lower and upper for each row
            for (int i = 0; i < N; ++i) {
                lower_elem_row = lower_bound(matrix[i].begin(), matrix[i].end(), lower) - matrix[i].begin();
                upper_elem_row = search_in_diag(lower_elem_row, i, upper, matrix);
                max_size = max(max_size, upper_elem_row);
            }

            cout << max_size + 1 << '\n';

        }
        cout << "-\n";


    }


    return 0;
}





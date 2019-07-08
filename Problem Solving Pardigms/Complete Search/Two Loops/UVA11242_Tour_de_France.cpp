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
    int r, f, temp;
    vi a, b;
    while (scanf("%d %d", &r, &f)) {
        if(r == 0)
            break;

        //read input
        a.clear();
        b.clear();
        for (int i = 0; i < r; ++i) {
            scanf("%d", &temp);
            a.push_back(temp);
        }
        for (int j = 0; j < f; ++j) {
            scanf("%d", &temp);
            b.push_back(temp);
        }
	//--

        //create array of drives
        int count(0);
        vector<double> ratios(r *f);
        for (int k = 0; k < r; ++k) {
            for (int l = 0; l < f; ++l) {
                ratios[count++]=(double) b[l] / a[k];
            }
        }
        //--


        //--The correct drive
        sort(ratios.begin(), ratios.end());
        double res = -1;
        for (int m = 1; m < ratios.size(); ++m) {
            res = max(res, ratios[m] / ratios[m - 1]);
        }
        printf("%.2f\n", res);
        //--
    }

}


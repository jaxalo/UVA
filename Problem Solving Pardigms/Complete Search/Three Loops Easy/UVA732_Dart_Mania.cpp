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


    //init possibilites
    set<int> temp;
    for (int i = 0; i <= 20; ++i) {
        temp.insert(i);
        temp.insert(2 * i);
        temp.insert(3 * i);
    }
    temp.insert(50);

    int n = temp.size();
    vi poss(n);
    int count(0);
    for (const auto &tem: temp) {
        poss[count++] = tem;
    }

    //--

    bool visited[70][70][70];


    int q;
    while (scanf("%d", &q) && q > 0) {

        for (int i = 0; i < 70; ++i) {
            for (int j = 0; j < 70; ++j) {
                for (int k = 0; k < 70; ++k) {
                    visited[i][j][k] = false;
                }
            }
        }


        int cntCombi(0);
        int cntPerm(0);
        for (int i = 0; i < poss.size(); ++i) {
            for (int j = 0; j < poss.size(); ++j) {
                for (int k = 0; k < poss.size(); ++k) {
                    if (q - (poss[i] + poss[j] + poss[k]) == 0) {
                        cntPerm++;
                        if (visited[i][j][k] == false) {
                            cntCombi++;
                            visited[i][j][k] = true;
                            visited[i][k][j] = true;
                            visited[j][i][k] = true;
                            visited[j][k][i] = true;
                            visited[k][j][i] = true;
                            visited[k][i][j] = true;

                        }
                    }


                }
            }
        }

        if (cntCombi != 0 || cntPerm != 0) {
            printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", q, cntCombi);
            printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", q, cntPerm);

        } else {
            printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", q);
        }
        printf("**********************************************************************\n");

    }
    printf("END OF OUTPUT\n");

    return 0;
}

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


vector<vi> resChosen;

vi getNbPaths(vector<vi> &matrix, int rep) {
    int n = matrix.size();

    vector<vi> resMatrix(n);
    for (int i = 0; i < n; ++i) {
        resMatrix[i].resize(n);
        fill(resMatrix[i].begin(), resMatrix[i].end(), 0);
    }

    for (int l = 0; l < rep - 1; ++l) {
        if (l == 0) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    for (int k = 0; k < n; ++k) {
                        resMatrix[i][j] += matrix[i][k] * matrix[k][j];
                    }
                }
            }
        } else {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    for (int k = 0; k < n; ++k) {
                        resMatrix[i][j] += resMatrix[i][k] * matrix[k][j];
                    }
                }
            }
        }
    }

    vi path = resMatrix[0];
    return path;
}

void printLines() {
    for (int i = 0; i < resChosen.size(); ++i) {
        cout << "(1,";
        for (int j = 0; j < resChosen[i].size(); ++j) {
            cout << resChosen[i][j];
            if (j != resChosen[i].size() - 1) {
                cout << ",";
            }
        }
        cout << ")\n";

    }
}

void getPathHelper(vector<vi> &matrix, int lpath, int actualPlace, int dest, vi &chosen, vb &visited) {
    if (lpath == 0 && actualPlace == dest) {
        resChosen.push_back(chosen);
    } else if (lpath == 0 && actualPlace != dest) {
        return;
    } else {
        for (int i = 0; i < matrix[actualPlace].size(); ++i) {
            if (matrix[actualPlace][i] == 1 && visited[i] == false) {
                chosen.push_back(i + 1);
                visited[i] = true;
                getPathHelper(matrix, lpath - 1, i, dest, chosen, visited);
                chosen.pop_back();
                visited[i] = false;
            }
        }

    }

}


void getPath(vector<vi> &matrix, int lpath, int dest) {
    vi chosen;

    vb visited(matrix.size());
    fill(visited.begin(), visited.end(), false);
    visited[0] = true;
    getPathHelper(matrix, lpath, 0, dest, chosen, visited);



}


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w+", stdout);
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, lpath, sep;
    bool firstTime(true);
    while (cin >> n >> lpath) {

        if(!firstTime) {
            cout << endl;
        }
        firstTime = false;
        vector<vi> matrix(n);
        for (int i = 0; i < n; ++i) {
            matrix[i].resize(n);
        }
        for (int i = 0; i < n * n; ++i) {
            cin >> matrix[i / n][i % n];
        }

        vi path = getNbPaths(matrix, lpath);
        resChosen.clear();
        for (int i = 1; i < n; ++i) {
            getPath(matrix, lpath, i);
        }
        if(resChosen.empty())
        {
            cout << "no walk of length " << lpath << '\n';
        } else {
            sort(resChosen.begin(), resChosen.end());
            printLines();
        }


        cin >> sep;
    }

    return 0;
}


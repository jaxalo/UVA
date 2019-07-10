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

    int tc,a,b,c,z;
    scanf("%d",&tc);
    while (tc--)
    {
        bool solved(false);
        scanf("%d %d %d",&a,&b,&c);
        for (int x = - sqrt(c) - 2 ; x < sqrt(c) + 2 && !solved; ++x) {
            for (int y =  - sqrt(c) - 2 ; y <  sqrt(c) + 2 && !solved; ++y) {
                z = a - x - y;
                if(x != y && y != z && x != z && x * y * z == b and x*x + y*y +z*z == c)
                {
                    printf("%d %d %d\n",x,y,z);
                    solved = true;
                    break;
                }
            }
        }
        if(solved == false)
        {
            printf("No solution.\n");
        }
    }

    return 0;
}

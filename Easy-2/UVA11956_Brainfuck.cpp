#include <bits/stdc++.h>
using namespace std;



int main(){
    int cur;
    int tc;
    string ops;
    char op;
		vector<int>memory(102);
    scanf("%d", &tc);

    for(int x=1; x<=tc; x++){
        cin>>ops;
        fill(memory.begin(), memory.end(), 0);
        cur = 0;

        for(int y=0; y<ops.size(); y++){
            op = ops[y];

            if(op == '>')
                cur = (cur + 1) % 100;


            if(op == '<')
            		cur = (cur + 99) % 100;


            if(op == '+')
                memory[cur] = (memory[cur] + 1) % 256;


            if(op == '-')
                memory[cur] = (memory[cur] + 255) % 256;

        }

        printf("Case %d:", x);

        for(int k=0; k<100; k++){
                printf(" %02X", memory[k]);
        }

				printf("\n");
    }
		return 0;
}

#include <stdio.h>
using namespace std;
int memo[100004];
int main(){
    int n,m;
    int a,b;
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++){
        scanf("%d", &memo[i]);
        memo[i] += memo[i-1];
    }
    
    for(int i=0;i<m;i++){
        scanf("%d %d",&a,&b);
        printf("%d\n",memo[b]-memo[a-1]);
    }
}
#include <stdio.h>
using namespace std;
int dp[100004];
int main(){
    int n,m;
    int a,b;
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++){
        scanf("%d", &dp[i]);
        dp[i] += dp[i-1];
    }
    
    for(int i=0;i<m;i++){
        scanf("%d %d",&a,&b);
        printf("%d\n",dp[b]-dp[a-1]);
    }
}
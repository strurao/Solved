#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int N;
    scanf("%d", &N);
    
    int A[1004]; 
    for(int i = 1; i <= N; i++) scanf("%d", &A[i]);

    int dp[1004]; 
    for(int i = 1; i <= N; i++) dp[i] = A[i];

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j < i; j++)
        {
            if(A[i] > A[j])
            {
                dp[i] = max(dp[i], dp[j] + A[i]);
            }
        }
    }
    
    int maxSum = dp[1];
    for(int i = 2; i <= N; i++)
    {
        if(dp[i] > maxSum)
        {
            maxSum = dp[i];
        }
    }

    printf("%d", maxSum);

    return 0;
}
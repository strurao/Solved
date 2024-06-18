#include<bits/stdc++.h>
using namespace std;
int N,M;
vector<int> result;

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    result = vector<int>(N+M);
    
    for(int i=0; i<N+M; i++)
    {
        cin >> result[i];
    }
    sort(result.begin(), result.end());
    
    for(const int &r : result)
    {
        cout<<r<<" ";
    }
    return 0;
}
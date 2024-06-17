// 다솜이보다 표수가 많은 후보들의 표를, 다솜이의 표가 많아질 때까지 매수
#include <bits/stdc++.h>
using namespace std;

int votes[104];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int cnt =0;
    int people;
    int ds;
    
    cin >> people;
    cin >> ds;
    
    for(int i=0; i<people-1; i++){
        cin >> votes[i];
    }
    
    while(true){
        int maxvote =0;
        int idx = 0;
        
        for(int i=0; i<people-1; i++){
            if(maxvote < votes[i]){
                maxvote = votes[i];
                idx=i;
            }
        }
        if(ds > maxvote){
            cout << cnt << '\n';
            break;
        }
        ds++;
        votes[idx]--;
        cnt++;
    }
}
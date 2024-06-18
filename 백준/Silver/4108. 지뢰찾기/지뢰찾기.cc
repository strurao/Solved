#include <bits/stdc++.h>
using namespace std;

int r,c;
char matrix[104][104]; //지뢰여부
int dx[8] = {-1, -1, 0, 1, 1,  1,  0, -1}; //row
int dy[8] = { 0,  1, 1, 1, 0, -1, -1, -1}; //column

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
     
    cin >> r >> c;
    
    while(r&&c){
        for (int i = 0; i < r; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < c; j++) {
                matrix[i][j] = s[j];
            }
        }
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (matrix[i][j] == '.') {
                    int cnt = 0;
                    for (int k = 0; k < 8; k++) {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        
                        if (matrix[nx][ny] == '*' && nx < r && nx >= 0 && ny < c && ny >= 0 )
                        {
                            cnt++;
                        }
                    }
                    matrix[i][j] = cnt+'0';
                }
            }
        }
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cout << matrix[i][j];
            }
            cout << "\n";
        }
        
        cin>>r>>c;
    }
    return 0;
}
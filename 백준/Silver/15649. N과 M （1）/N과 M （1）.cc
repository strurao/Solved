#include <iostream>
#define MAX 9
using namespace std;

int n,m;
int arr[MAX]={0,}; // 배열의 첫 번째 요소를 0으로 명시적으로 초기화하고, 나머지 요소들은 암시적으로 0으로 초기화
bool visited[MAX]={0,};

void dfs(int cnt){ // cnt는 현재까지 선택된 숫자의 개수
    if(cnt==m){ // 기저 조건: m개의 숫자를 모두 선택했을 때
        for(int i=0; i<m; i++) cout << arr[i] << ' ';
        cout << '\n'; // 한 순열을 출력한 후 줄바꿈
        return;
    }
    for(int i=1; i<=n; i++){ // 1부터 n까지 모든 숫자에 대해
        if(!visited[i]){
            visited[i]=true;
            arr[cnt]=i;
            dfs(cnt+1); // 다음 숫자 선택을 위해 재귀 호출
            visited[i]=false; // 백트래킹: 다른 순열을 위해 현재 숫자의 선택을 취소
        }
    }
}

int main(){
    cin >> n >> m;
    dfs(0);
}

/*
1부터 N까지의 숫자 중에서 M개를 고르는 모든 순열을 생성하고 출력하자!

각 숫자는 순열에서 딱 한번만 사용되므로, 각 숫자를 인덱스로 가지는 bool형 배열인 visited를 선언하고,

해당 숫자를 뽑았는지 유무를 저장한다. 

숫자를 앞에서부터 한개씩 뽑아가면서 visited가 M개만큼 true가 되면, 출력을 해주는 재귀함수를 활용하면 된다.
*/
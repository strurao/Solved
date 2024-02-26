#include <vector> 
using namespace std; 

int check[200]; 

void dfs(int current_computer, int n, vector<vector<int>> computers) { 
  // current_computer번째 컴퓨터를 체크했다고 표시하기
  check[current_computer] = 1;

  for(int i=0; i<n; i++) { 
    // current_computer와 연결된 컴퓨터들 탐색시작. 
    if(check[i] == 0 && computers[current_computer][i] == 1) {   
      // 다른 컴퓨터와 연결되어 있고, 그 컴퓨터가 아직 탐색하지 않은 컴퓨터라면 탐색 시작
      dfs(i, n, computers); 
    } 
  } 
} 

int solution(int n, vector<vector<int>> computers) { 
  int answer = 0;

  for(int i=0; i<n; i++) { 
    // 아직 검사하지 않은 컴퓨터일때 탐색 시작
    if(check[i] == 0) { 
      dfs(i, n, computers);
      
      // 재귀적으로 호출한 dfs함수가 여기로 돌아올때가 연결된 그래프 하나이므로 answer+1을 해준다.
      answer++; 
    } 
  } 

  return answer;
}

/*
그래프의 연결된 노드들을 따라서 탐색하다가 연결이 끊기면 
네트워크 하나가 끝난것이므로 +1 해주며 네트워크의 개수를 구하면 된다

각 컴퓨터별로 탐색여부를 체크하는 과정이 필요하다는것이다.
그리고 재귀적으로 dfs함수를 호출할때, 탐색하는 컴퓨터의 번호가 달라지므로 
dfs함수의 매개변수로 탐색할 컴퓨터의 번호를 받아야한다는것을 알 수 있다.

문제에서 컴퓨터의 개수는 200개 이하라고 하였으므로, 
크기 200인 배열을 선언하여 각 컴퓨터별로 탐색여부를 체크하여 표시한다.
*/
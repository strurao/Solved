// 방법 1.
#include <iostream>
#include <algorithm> 
using namespace std;

int a[9];
int main() {
	for (int i = 0; i < 9; i++) {
		cin >> a[i];
	}
	sort(a, a + 9); //난장이들의 키를 오름차순으로 정렬한다. 
	do {
		int sum = 0;
		for (int i = 0; i < 7; i++) sum += a[i];
		if (sum == 100) break;
	} while (next_permutation(a, a + 9));
	for (int i = 0; i < 7; i++) cout << a[i] << "\n";
	return 0;
}

/*
next_permutation 함수는 배열의 현재 순열을 다음 순열로 변경합니다. 
만약 현재 순열의 합이 100이 아니라면, while 루프는 next_permutation 함수를 호출하여 배열의 다음 순열로 넘어갑니다. 
이 과정은 모든 순열을 탐색하거나 합이 100인 순열을 찾을 때까지 반복됩니다.
*/

// 방법 2.
#include<bits/stdc++.h>
using namespace std;
int a[9]; 
int n = 9, r = 7; 
void solve(){  
    int sum = 0; 
    for(int i = 0; i < r; i++){
        sum += a[i];  
    }
    if(sum == 100){ 
      sort(a, a + 7);  
      for(int i = 0; i < r; i++) cout << a[i] << "\n"; 
      exit(0);
    } 
}
void print(){
  for(int i = 0; i < r; i++) cout << a[i] << " "; 
  cout << '\n';
}
void makePermutation(int n, int r, int depth){
    if(r == depth){ 
        solve();
        return;
    }
    for(int i = depth; i < n; i++){
        swap(a[i], a[depth]);
        makePermutation(n, r, depth + 1);
        swap(a[i], a[depth]);
    }
    return;
}
int main(){
    for(int i = 0; i < n; i++){
        cin >> a[i];
    } 
    makePermutation(n, r, 0);
    return 0;
}

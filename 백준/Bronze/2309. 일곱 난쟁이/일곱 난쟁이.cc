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

#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    // answersize만큼 for문을 돌려서 한 번에 한 글자씩 answer를 따오고, 한 번 돌릴 때마다 startidx부터 k+i까지 돌린다.
    // 이렇게 한도를 두고 돌려야 answersize만큼의 answer 글자들을 뽑아올 수 있기 때문이다.
    int answersize = number.size() - k; // return값의 길이는 number의 사이즈에서 k를 뺀 것
    int startidx = 0; // 시작 index
    for(int i = 0; i < answersize; ++i){ // answersize만큼 반복
        char maxint = number[startidx]; // 처음에는 startidx의 값이 최대값
        int maxidx = startidx; // 처음에는 maxidx가 startidx
        for(int j = startidx; j <= k+i; j++){ // startidx부터 k+i까지 확인해서 max값 찾음 -k
            if(maxint < number[j]){ // 더 큰 값이 나오면 그 값의 index와 number를 저장
                maxint = number[j];
                maxidx = j;
            }
        }
        startidx = maxidx + 1; // 다음번에는 maxindex + 1에서부터 시작
        answer += maxint; // answer에 가장 큰 수를 넣는다
    }
    
    return answer;
}

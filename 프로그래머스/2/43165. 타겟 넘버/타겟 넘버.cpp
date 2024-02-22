#include <string>
#include <vector>

using namespace std;

// 벡터, 정답 횟수, 찾아야하는 수, 들어간 깊이, 현재까지 합
void dfs(vector<int>& numbers, int& answer, int target, int count=0, int sum=0){
    if(count==numbers.size()-1){
        if(target==sum+numbers[count]) answer++;
        if(target==sum-numbers[count]) answer++;
        return;
    }
    dfs(numbers, answer, target, count+1, sum+numbers[count]);
    dfs(numbers, answer, target, count+1, sum-numbers[count]);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    dfs(numbers, answer, target);
    return answer;
}
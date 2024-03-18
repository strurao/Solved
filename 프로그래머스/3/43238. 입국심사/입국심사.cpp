#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times)
{
    long long answer = 0;
    sort(times.begin(), times.end());   //입국심사 시간 오름차순 정렬

    long long left = 1; //최소시간
    long long right = n * (long long)times.back();  //최대로 걸리는 시간

    while (left <= right)
    {
        long long mid = (left + right) / 2;
        long long passed = 0;   //지나간 사람수
        for (int i = 0; i < times.size(); i++)
            passed += (mid / (long long) times[i]);
        if (passed >= n)
        {   //주어진 인원과 같거나 더많이 지나갈수 있다면
            right = mid - 1;
            answer = mid;   //현재 걸린 시간으로 정답 갱신
        }
        else left = mid + 1;
    }
    return answer;
}
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> m1={1,2,3,4,5};
vector<int> m2={2,1,2,3,2,4,2,5};
vector<int> m3={3,3,1,1,2,2,4,4,5,5};
    
vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int count[3]={0,0,0};
    int max_score=0;
    
    for(int i=0; i<answers.size(); i++)
    {
        if(answers[i]==m1[i%5])
            count[0]++;
        if(answers[i]==m2[i%8])
            count[1]++;
        if(answers[i]==m3[i%10])
            count[2]++;
    }
    max_score=max(max(count[0],count[1]),count[2]);
    for(int i=0; i<3; i++){
        if(max_score==count[i])
            answer.push_back(i+1);
    }
    return answer;
}
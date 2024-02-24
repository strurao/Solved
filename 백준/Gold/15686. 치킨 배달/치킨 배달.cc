#include<bits/stdc++.h>
using namespace std;
int n,m,a[54][54],result=987654321;
vector<vector<int>> chicken_list; // 가능한 모든 치킨집 조합을 저장
vector<pair<int,int>> home, chicken; // home 벡터는 모든 집의 위치를 저장하고, chicken 벡터는 모든 치킨집의 위치를 저장

// 가능한 모든 치킨집의 조합을 찾아 chicken_list에 저장
// 조합을 구현하기 위해 재귀 함수를 통해 구현했다
void combi(int start, vector<int> v){
    if(v.size()==m){ // 조합의 크기는 m이다. 이는 사용자가 최대 m개의 치킨집을 선택할 수 있다는 의미.
        chicken_list.push_back(v); // 조합 크기가 m이면, 현재 조합을 chicken_list에 추가
        return;
    }
    for(int i=start+1; i<chicken.size(); i++){
        v.push_back(i);
        combi(i, v);
        v.pop_back(); // 탐색 후 현재 치킨집 제거 (백트래킹)
    }
    return;
}

int main(){
    cin >> n >> m; // n은 도시의 크기, m은 선택할 수 있는 최대 치킨집의 수
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> a[i][j];
            if(a[i][j]==1) home.push_back({i,j});
            if(a[i][j]==2) chicken.push_back({i,j});
        }
    }
    vector<int> v;
    combi(-1,v);
    for(vector<int> cList : chicken_list){
        int ret = 0;
        for(pair<int,int> h: home){
            int _min = 987654321;
            for(int ch : cList){
                int _dist = abs(h.first - chicken[ch].first)+abs(h.second-chicken[ch].second);
                _min = min(_min, _dist);
            }
            ret+=_min;
        }
        result = min(result, ret);
    }
    cout << result << "\n";
    return 0;
}

/*
도시에 있는 치킨집 중에서 최대 M개를 고르고, 나머지 치킨집은 모두 폐업시켜야 한다. 
어떻게 고르면, 도시의 치킨 거리가 가장 작게 될지 구하는 프로그램을 작성하시오.

조합을 떠올린 후에는 아래와 같은 순서로 답을 구하면 된다

- 조합으로 M개의 치킨집을 뽑는다
- 각 집에서 M개의 치킨집까지의 거리 중 최솟값들을 구하여 더한다
- 위의 과정을 반복하며 가장 최소의 거리 합이 나오는 조합의 거리 값을 구한다
*/
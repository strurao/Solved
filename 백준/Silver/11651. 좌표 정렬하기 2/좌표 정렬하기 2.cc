#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> points;
int n;

int main(){
	cin >> n;
	int x,y;

	for(int i=0; i<n; i++)
	{
		cin >> x >> y;
		points.push_back({y,x});
	}
	sort(points.begin(), points.end());

	for(int i=0; i<n; i++)
    {
        cout << points[i].second << " " << points[i].first << '\n';
    }
    return 0;
}
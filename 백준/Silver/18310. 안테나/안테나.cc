#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, num;
    vector<int> v;
    cin >> n;
     
    for(int i=0; i<n; i++)
    {
        cin >> num;
        v.push_back(num);
    }
    
    sort(v.begin(), v.end());
    cout << v[(n-1)/2];
}
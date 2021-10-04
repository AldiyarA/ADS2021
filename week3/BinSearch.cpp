#include <iostream>
#include <vector>

using namespace std;

int binSearch(vector<int> &a, int k){
    int n = a.size();
    int l = 0;
    int r = n-1;
    while (r>=l)
    {
        int m = (l+r) / 2;
        if (a[m] == k) return m;
        if (a[m] < k){
            l = m+1;
        }else r = m - 1;
    }
    return -1;
}

int main(){
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    int m; cin >> m;
    cout<<binSearch(v, m);
    return 0;
}
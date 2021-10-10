#include <bits/stdc++.h>

using namespace std;

void quicksort(vector<int> &a, int l, int r){
    int i = l;
    int j = r;
    int p = a[(i+j)/2];
    while (i < j)
    {
        while (a[i] < p) i++;
        while (p < a[j]) j--;
        if (i <= j){
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if (l < j) quicksort(a, l, j);
    if (i < r) quicksort(a, i, r);
}

int main(){
    int n = rand() % 150;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        v[i] = rand() % 1000;
    }
    cout<<"Before sort:\n";
    for(int i : v) cout<<i<<" ";
    quicksort(v, 0, n-1);
    cout<<"\nAfter sort:\n";
    for(int i : v) cout<<i<<" ";
    cout<<"\n";
    return 0;
}
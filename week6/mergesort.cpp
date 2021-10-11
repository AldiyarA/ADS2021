#include <bits/stdc++.h>

using namespace std;
int inv; // Глобальная переменная, используется для посчета инверсий
void merge(vector<int> &a, int l, int m, int r){
    int sz1 = m-l+1;
    int sz2 = r-m;
    vector<int> a1(sz1);
    vector<int> a2(sz2);
    for (int i = 0; i < sz1; i++){
        a1[i] = a[l+i];
    }
    for (int i = 0; i < sz2; i++){
        a2[i] = a[m+1+i];
    }
    int idx = l, idx1 = 0, idx2 = 0;
    while (idx1 < sz1 && idx2 < sz2)
    {
        if (a1[idx1] <= a2[idx2]){
            a[idx++] = a1[idx1++];
        }else{
            a[idx++] = a2[idx2++];
            inv+=(sz1-idx1); // Если a1[idx1] > a2[idx2],
        }// то это означает что все числа после a1[idx1] так же больше a2[idx2], и все они являются инверсиями.
    }// Поэтому мы добавляем колличество элемен что осталось
    while (idx1 < sz1){
        a[idx++] = a1[idx1++];
    }
    while (idx2 < sz2){
        a[idx++] = a2[idx2++];
    }
}
void mergeSort(vector<int> &a, int l, int r){
    if (l >= r) return;
    int m = (r+l) / 2;
    mergeSort(a, l, m);
    mergeSort(a, m+1, r);
    merge(a, l, m, r);
}

int main(){
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    cout<<"Before sort:\n";
    for(int i : v) cout<<i<<" ";
    mergeSort(v, 0, n-1);
    cout<<"\nAfter sort:\n";
    for(int i : v) cout<<i<<" ";
    cout<<"\nNumber of inversions: "<<inv;
    return 0;
}

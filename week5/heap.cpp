#include <bits/stdc++.h>

using namespace std;

struct myHeap
{
    vector<int> a;
    int sz;
    myHeap(){
        sz = 0;
    }
    int parent(int i){
        return (i-1) / 2;
    }
    int left(int i){
        return 2*i+1;
    }
    int right(int i){
        return 2*i+2;
    }
    void insert(int k){
        sz++;
        a.push_back(k);
        heapifyUp(sz-1);
    }
    int getMin(){
        return a[0];
    }
    void heapifyDown(int i){
        if (left(i)>sz-1){
            return;
        }
        int j = left(i);
        if (right(i) < sz && a[right(i)]<a[j]){
            j = right(i);
        }
        if (a[i] > a[j]){
            swap(a[i], a[j]);
            heapifyDown(j);
        }
    }
    void heapifyUp(int i){
        while (i > 0 && a[parent(i)] > a[i])    
        {
            swap(a[parent(i)], a[i]);
            i = parent(i);
            // heapifyUp(parent(i));
            // return;
        } 
    }
    int extractMin(){
        int mini = a[0];
        swap(a[0], a[sz-1]);
        sz--;
        a.pop_back();
        heapifyDown(0);
        return mini;
    }
    void deckKey(int i, int new_value){
        a[i] = new_value;
        heapifyUp(i);
    }
    void incKey(int i, int new_value){
        a[i] = new_value;
        heapifyDown(i);    
    }
    void print(){
        for (int i = 0; i < sz; i++){
            cout<<a[i]<<" ";
        }
        cout<<"\n";
    }
};

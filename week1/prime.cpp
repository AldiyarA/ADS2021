#include <bits/stdc++.h>

using namespace std;

int color[100000000]; // 0 - prime, 1 - not prime

void print_primes(int n){
    for (int i = 2; i * i <= n; i++){
        if (!color[i]){
            for (int j = 2; j * i <= n; j++){
                color[j*i] = 1;
            }
        }
    }
    for (int i = 2; i <= n; i++){
        if (!color[i]) cout<<i<<" ";
    }
}

int main(){
    int n;
    cin >> n;
    print_primes(n);
}

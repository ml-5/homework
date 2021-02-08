#include<iostream>
using namespace std;
const int N = 1e5 + 10;
int n, k;
int q[N];
int quick_sort(int l, int r, int k){
    if(l == r) return q[l];

    int x = q[l], i = l - 1, j = r + 1;
    while(i < j){
        while(q[++i] < x);
        while(q[--j] > x);
        if(i < j) swap(q[i], q[j]);
    }
    int s1 = j - l + 1;
    if(k <= s1) quick_sort(l, j, k);
    else quick_sort(j + 1, r, k- s1);
}
int main(){
     scanf("%d %d",&n,&k);
    for(int i = 0; i < n; i++) scanf("%d", &q[i]);
    cout << quick_sort(0, n - 1, k) << endl;
    return 0;
}


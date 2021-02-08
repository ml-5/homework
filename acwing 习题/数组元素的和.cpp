/*ÇóA[i] + B[j] == k µÄ (i , j) ¶Ô
*/
#include<iostream>
using namespace std;
const int N=100010;
int n,m,x;
int A[N],B[N];

int main(){
    cin>>n>>m>>x;
    for(int i=0;i<n;i++) cin>>A[i];
    for(int i=0;i<m;i++) cin>>B[i];
    
    for(int i=0,j=m-1;i<n;i++){
        while(j>=0&&A[i]+B[j]>x) j--;
        if(j>=0&&A[i]+B[j]==x) cout<<i<<' '<<j<<endl;
    }
    return 0;
}
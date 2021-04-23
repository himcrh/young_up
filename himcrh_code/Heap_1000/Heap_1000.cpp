#include<bits/stdc++.h>
using namespace std;
int heap[1010];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    //前n大，元素数为m
    for(int i=1;i<=n;i++)
        scanf("%d",&heap[i]);
    for(int i=2;i<=n;i++){
        int k=i;
        while(k>0){
            if(heap[k]>=heap[k>>1])
                break;
            else
                swap(heap[k],heap[k>>1]);
            k=k>>1;
        }
    }
    for(int i=n+1;i<=m;i++){
        int x;
        scanf("%d",&x);
        heap[1]=x>heap[1]?x:heap[1];
        int k=2;//k指向孩子
        while(k<=n){
            if(min(heap[k],heap[k+1])>heap[k>>1])
                break;
            k=k+1>n?k:(heap[k]<=heap[k+1]?k:k+1);
            if(heap[k>>1]>heap[k])
                swap(heap[k>>1],heap[k]);
            k=k<<1;
        }
    }
    for(int i=1;i<=n;i++){
        printf("%d ",heap[i]);
    }
    return 0;
}
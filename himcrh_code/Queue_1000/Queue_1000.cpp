#include<bits/stdc++.h>
using namespace std;
const int N = 1e9;
int main(){
    priority_queue<int,vector<int>,greater<int>> q;
    for(int i=1;i<=1000;i++){
        int x;
        scanf("%d",&x);
        q.push(x);
    }
    for(int i=1001;i<=N;i++){
        int x;
        scanf("%d",&x);
        q.push(x);
        q.pop();
    }
    while(q.size()){
        printf("%d ",q.top());
        q.pop();
    }
    return 0;
}
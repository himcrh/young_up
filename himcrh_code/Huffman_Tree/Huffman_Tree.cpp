#include<bits/stdc++.h>
using namespace std;
struct Huffs{
    int lc,rc;//左子、右子
};
struct deals{
    int weight;//权重
    int pos;//对应Huff位置
};
struct cmp{
    bool operator() (const deals& a, const deals& b){
        return a.weight >= b.weight;//小值优先
    }
};
vector<Huffs>Huff;
priority_queue<deals,vector<deals>,cmp> deal;
void ret(int p,string code){
    if(Huff[p].lc<0)
        cout<<p<<"\t"<<code<<endl;
    else{
        ret(Huff[p].lc,code+'0');
        ret(Huff[p].rc,code+'1');
    }
}
int main(){
    int n;//字符数
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        Huff.push_back({-1,-1});
        deal.push({x,int(Huff.size()-1)});
    }
    while(int(deal.size())!=1){
        deals ld=deal.top();
        deal.pop();
        deals rd=deal.top();
        deal.pop();
        Huff.push_back({ld.pos,rd.pos});
        deal.push({ld.weight+rd.weight,int(Huff.size()-1)});
    }
    for(int i=0;i<int(Huff.size());i++){
        cout<<i<<"\t"<<Huff[i].lc<<"\t"<<Huff[i].rc<<endl;
    }
    ret(int(Huff.size()-1),"");
    return 0;
}
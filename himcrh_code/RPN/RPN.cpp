// 逆波兰表达式
#include <bits/stdc++.h>
using namespace std;

double caculate(double a,double b,char c){
    switch(c){
        case '*':return a*b;
        case '/':return a/b;
        case '+':return a+b;
        default:return a-b;
    }
}

int main(){
	string Input_str;
    getline(cin,Input_str);
	istringstream p(Input_str);
    string s;
    stack<string>str;
    stack<double>num;
    while(p>>s)
        str.push(s);
    while (str.size()){
        string str_fr=str.top();
        str.pop();
        if(str_fr[0]>='0'&&str_fr[0]<='9')
            num.push(atof(str_fr.c_str()));
        else{
            double a=num.top();
            num.pop();
            double b=num.top();
            num.pop();
            num.push(caculate(a,b,str_fr[0]));
        }
    }
    printf("%.6lf",num.top());
	return 0;
}
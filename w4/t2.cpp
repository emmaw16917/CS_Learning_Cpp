#include<iostream>
#include<cstring>
#include<string>
using namespace std;
const string alpha[10]={"零", "壹", "贰", "叁", "肆","伍","陆", "柒", "捌", "玖"};
const string beta[4]={"仟","","拾", "佰"};
const string theta[3]={"","万","亿"};
class Number{
    private:
        int num[20];
        string chinese;
    public:
        Number(string s);
        string getChinese();
};
Number::Number(string s){
    int len=s.length();
    num[0]=len;
    for(int i=1;i<=len;i++) num[i]=s[len-i]-'0';

    chinese="";
}
string Number::getChinese(){
    for(int i=num[0];i>=1;i--){
        if(i%4!=1){
            if(num[i]!=0)
                chinese+=alpha[num[i]]+beta[i%4];
            bool pre=(num[i+1]!=0),suf=0;
            for(int j=i-1;j>=(i-1)/4*4+1;j--) suf|=(num[j]!=0);
            bool zero=pre&suf;
            if(num[i]==0&&zero)
            	chinese+=alpha[num[i]];
        }
        else{
            if(num[i]!=0) chinese+=alpha[num[i]];
            chinese+=theta[i/4];
            if(num[i]==0&&(i/4>0)) chinese+=alpha[num[i]];
        }
    }
    return chinese;
}
int main(){
    string s;
    cin>>s;
    Number a(s);
    cout<<a.getChinese()<<"元整"<<endl;
    return 0;
}

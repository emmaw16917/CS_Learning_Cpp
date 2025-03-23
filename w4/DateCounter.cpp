#include<iostream>
#include<cctype>
#include<string>
using namespace std;
const int days[2][13]={{0,31,28,31,30,31,30,31,31,30,31,30,31},
                       {0,31,29,31,30,31,30,31,31,30,31,30,31}};
class DATE_COUNTER{
    private:
        int y,m,d;
    public:
        void getDate(string s);
        int countDays(string s);
        int countDays(string _begin,string _end);
};
void DATE_COUNTER::getDate(string s){
    y=m=d=0;
    int i=0;
    for(;isdigit(s[i]);i++) y=y*10+s[i]-'0';
    i++;
    for(;isdigit(s[i]);i++) m=m*10+s[i]-'0';
    i++;
    for(;isdigit(s[i]);i++) d=d*10+s[i]-'0';
}
int DATE_COUNTER::countDays(string s){
    getDate(s);
    int cnt=0;
    for(int i=1900;i<y;i++){
        if((i%4==0&&i%100!=0)||(i%400==0)) cnt+=366;
        else cnt+=365;
    }
    bool f=((y%4==0&&y%100!=0)||(y%400==0));
    for(int i=1;i<m;i++) cnt+=days[f][i];
    cnt+=d;
    return cnt;
}
int DATE_COUNTER::countDays(string _begin,string _end){
    int cnt0=countDays(_begin);
    int cnt1=countDays(_end);
    int ans=cnt1-cnt0;
    if(ans<0) ans=-1;
    cout<<ans<<endl;
    return ans;
}
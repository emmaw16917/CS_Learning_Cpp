#include <string>
#include <cstring>
#include <TranStr.hpp>
TRANSFORMER::TRANSFORMER(){
    printf("START TRANSFORMER\n");
}
TRANSFORMER::~TRANSFORMER(){
    printf("CLOSE TRANSFORMER\n");
}
void TRANSFORMER::printString(std::string str, int rowCount){
    int len=str.length();
    char o[40][300];
    memset(o,' ',sizeof(o));
    int x=0,y=0,pos=1;
    for(int i=0;i<len;i++){
        o[x][y]=str[i];
        if(pos==1){
            x++;
            if(x>=rowCount){
                x-=2;
                y+=2;
                pos=2;
            }
        }
        else if(pos==2){
            x--;y+=2;
            if(x<0){
                x+=2;y-=2;
                pos=1;
            }
        }
    }
    for(int i=0;i<rowCount;i++){
        o[i][y+1]='\0';
        printf("%s\n",o[i]);
    }
}
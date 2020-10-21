#include<iostream>
#include<stack>
#include<string>
using namespace std;
static int flag[16];

void hexToDec(int &a){//0x to decimal
    if(a>='A'&&a<='F') a=a-'A'+10;
}

void decToBin(int a,int fl[],int num){
    stack<int> stack1;
    int x;
    for(int it=0;it<4;it++){
        if(a==0) stack1.push(0);
        else {
            x=a%2;
            stack1.push(x);
        }
        a=a/2;
    }
    int n=0;
    while(!stack1.empty()){
        fl[n+(num-1)*4]=stack1.top();
        n++;
        stack1.pop();
    }
}

int strToInt(int a){
    if(a>='0'&&a<='9') return a-'0';
    else return a;
}

int main(){
    string hex;
    int x;
    while(cin>>hex){
        for(int i=0;i<4;i++){
            x=strToInt(hex[i]);
            hexToDec(x);
            decToBin(x,flag,i+1);
        }
        cout<<"CF:"<<flag[15]<<"  PF:"<<flag[13]<<"  PF:"<<flag[13]<<"  AF:"<<flag[11]<<"  ZF:"<<flag[9]<<"  SF:"<<flag[8]<<"  IF:"<<flag[6]<<"  DF:"<<flag[5]<<"  OF:"<<flag[4];
        cout<<endl;
    }
    
    system("pause");
}
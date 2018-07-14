#include<bits/stdc++.h>
using namespace std;

int win[8][3]={{0,1,2},{3,4,5},{6,7,8},
                {0,3,6},{1,4,7},{2,5,8},
                {0,4,8},{2,4,6}};

bool Cwin(char *board,char c){
    for(int i=0;i<8;i++){
        if(board[win[i][0]]==c && board[win[i][1]]==c && board[win[i][2]]==c)
            return true;
    }

    return false;
}

bool isValidBoard(char board[]){
    int xCount=0,oCount=0;

    for(int i=0;i<9;i++){
        if(board[i]=='X')
            xCount++;
        if(board[i]=='O')
            oCount++;
    }

    if(xCount==(oCount+1) || xCount==oCount){
        if(Cwin(board,'O')){
            if(Cwin(board,'X'))
                return false;
            return (xCount==oCount);
        }

        if(Cwin(board,'X') && xCount==(oCount+1))
            return true;
    }

    return false;
}

int main(){
    char board[9];
    int t;
    cin>>t;
    while(t--){
        for(int i=0;i<9;i++)
            cin>>board[i];

        isValidBoard(board)?cout<<"Valid"<<endl:cout<<"Invalid"<<endl;
    }
    
    return 0;
}
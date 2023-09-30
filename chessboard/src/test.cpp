//
// This 'test' belongs to the 'algorithm_design',part of the 'chessboard' project
//
// Created by aaron on 23-9-30.
// Copyright (c) 2023 aaron. All rights reserved.
//
// The source file follows the GPL3.0 protocol and is distributed with the file.
// If you do not receive the GPL3.0 protocol ontology or you find a bug,
// please let me know (email: fly_aaron.li@outlook.com)
#include <iostream>

int tile=0;
int a[4][4];
void ChessBoard(int tr,int tc,int dr,int dc,int size){
    if(size==1){
        return;
    }
    int t;
    int s;
    t=tile++;
    s=size/2;
    if(dr<tr+s&&dc<tc+s)
        ChessBoard(tr,tc,dr,dc,s);
    else{
        a[tr+s-1][tc+s-1]=t;
        ChessBoard(tr,tc,tr+s-1,tc+s-1,s);
    }
    if(dr<tr+s&&dc>=tc+s)
        ChessBoard(tr,tc+s,dr,dc,s);
    else{
        a[tr+s-1][tc+s]=t;
        ChessBoard(tr,tc+s,tr+s-1,tc+s,s);
    }
    if(dr>=tr+s&&dc<tc+s)
        ChessBoard(tr+s,tc,dr,dc,s);
    else{
        a[tr+s][tc+s-1]=t;
        ChessBoard(tr+s,tc,tr+s,tc+s-1,s);
    }
    if(dr>=tr+s&&dc>=tc+s)
        ChessBoard(tr+s,tc+s,dr,dc,s);
    else{
        a[tr+s][tc+s]=t;
        ChessBoard(tr+s,tc+s,tr+s,tc+s,s);
    }
}
int main(){
    int x,y,count,i,j;
    printf("在8x8的棋盘中输入特殊格的位置x,y");
    scanf("%d  %d",&x,&y);
    ChessBoard(0,0,x,y,4);
    for( i=0;i<4;i++){
        count=0;
        for( j=0;j<4;j++){
            printf("%d ",a[i][j]);
            count++;
            if(count==4)
                printf("\n");
        }
    }
    getchar();
    getchar();
    getchar();
}
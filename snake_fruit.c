#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>

int height=15,width=25;
int x=7,y=7,fruitx=3,fruity=3;
int score=0;
char ch=' ';
char direction=' ';


void move(){
    if(_kbhit()){
        ch=getch();  //no need to press enter 
        if(ch=='w'||ch=='a'||ch=='s'||ch=='d'){
            direction=ch;
        }
    }
    switch(direction){
        case 'w':
                x--;
                break;
        case 's':
                x++;
                break;
        case 'a':
                y=y-2;//to identify the movement
                break;
        case 'd':
                y=y+2;//to identify the movement
                break;
    }
}
void logic(){
    if(x==fruitx && y==fruity){
        score=score+10;
        //generate a random fruit
        fruitx=rand()%(height-2)+1;
        fruity=rand()%(width-2)+1;
    }

    // boundry conditions
    // if(x<=0){
    //     x=1;
    // }
    // if(x>=height-1){
    //     x=height-2;
    // }
    // if(y<=0){
    //     y=1;
    // }
    // if(y>=width-1){
    //     y=width-2;
    // }
    if(x<=0||x>=height-1||y<=0||y>=width-1){
        printf("\n!!!GAME OVER...!!!");
        exit(0);
    }
}

void drawbox(){
    system("cls");  //clear
    int i,j;
    for(i=0;i<height;i++){
        for(j=0;j<width;j++){
            if(i==0 || i==height-1 || j==0|| j==width-1){
                printf("*");
            }
            else if(i==x &&j==y){
                printf("o");
            }
            else if(i==fruitx && j==fruity){
                printf("x");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
   // printf("\n");
    printf("\nTotal score:%d\n",score);
   // printf("\n");
}

void main(){
    while(1){
         
        drawbox();
        move(); 
        logic(); 
        Sleep(1000); 
    }
}



#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<string.h>
#define SIZE 10
#define N 35
char mine[12][12]={{0}};
int step=65;
char second[2][4];



void gotoxy(int x,int y)
{
    COORD pos ;
    pos.X = x ; 
    pos.Y = y ;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE) , pos) ;
}


void color(int a)
{
    HANDLE hConsole = GetStdHandle((STD_OUTPUT_HANDLE)) ; 
    SetConsoleTextAttribute(hConsole,a) ;
}

void file_in()
{
    FILE *fp ;
    if( (fp = fopen("D:\\最佳时间.txt" , "a+")) == NULL)
    {
        printf("文件打开失败") ;
        exit(0) ;
    }
    if( (fgets(second[0], 5, fp) ) == NULL)
    {
        second[0][0] = '9' ;
        second[0][1] = '9' ;
        second[0][2] = '9' ;
        second[0][3] = '9' ;
    }
    fclose(fp) ;
}

void file_out()
{
    FILE *fp;
    if( (fp=fopen("D:\\最佳时间.txt","w"))==NULL)
    {
        printf("文件打开失败");
        exit(0);
    }
    fputs(second[1],fp);
    fclose(fp);

}
    



void init_mine()
{
    int count,x,y;
    srand((unsigned)time(NULL));
    for(count=0;count<N; )
    {
        x=rand()%10+1;
        y=rand()%10+1;
        if(!mine[y][x])
        {
            mine[y][x]=1;
            count++;
        }
    }
    gotoxy(3,0);
    for(x=1;x<=SIZE;x++)
    {
        color(13);
        printf("%d ",x);
    }
    for(x=1;x<=SIZE;x++)
    {
        gotoxy(0,x);
        printf("%d ",x);
    }
    for(y=1;y<=SIZE;y++)
    {
        gotoxy(2,y);
        for(x=1;x<=SIZE;x++)
        {
            color(11);
            printf("□");
        }
    }
    
    gotoxy(45,0);
    color(12);
    printf("Saolei");
    gotoxy(36,3);
    color(12);
    printf("The best time :");
    printf("%c%c%c%c second",second[0][0],second[0][1],second[0][2],second[0][3]);
    gotoxy(36,6);
    printf("The time used ：0   second");
    gotoxy(36,9);
    printf("Reminding steps：65 steps");
    color(14);
    gotoxy(0,11);
    printf(" Input the position ( x , y )\n\n");
    color(11);
    printf("      Notice ：when x=0 and y=0,the game is over!!!!");
    color(14);
}

void show_mine(int x,int y)
{
    int num;
    if(mine[y][x])
    {
        color(11);
        gotoxy(x*2,y);
        printf("●");
        gotoxy(22,10);
        for(y=1;y<11;y++)
            for(x=1;x<11;x++)
            {
                gotoxy(x*2,y);
                if(mine[y][x])
                    printf("●");
                else
                {   
                    num=mine[y+1][x]+mine[y+1][x+1]+mine[y+1][x-1]+mine[y][x+1]+mine[y][x-1]+mine[y-1][x]+mine[y-1][x+1]+mine[y-1][x-1];
                    printf("%d ",num);
                }
            }
        printf("踩中雷区阵亡，请再接再厉!!!");
        exit(0);
    }
    else
    {
        num=mine[y+1][x]+mine[y+1][x+1]+mine[y+1][x-1]+mine[y][x+1]+mine[y][x-1]+mine[y-1][x]+mine[y-1][x+1]+mine[y-1][x-1];
        gotoxy(x*2,y);
        printf("%d ",num);
        gotoxy(53,9);
        printf("%d",--step);
    }

}



main()
{
    int t=time(NULL);
    char x,y,x1,y1;
    x1 = 'c';

    second[0][4]='\0';          
    second[1][4]='\0';           
    file_in();                   
    
    init_mine();                
    gotoxy(23,11);        
    for(x=0,y=0;x1 !=0||y1 !=0;)
    {
        Sleep(1000);
        if(kbhit())
        {
            gotoxy(23,11);
            scanf("%d",&x1);
            gotoxy(27,11);
            scanf("%d",&y1);
            gotoxy(23,11);
            printf("（x , y )    ");
        }
        gotoxy(52,6);
        printf("%d",time(NULL)-t);
        if(x1 >0 && x1 <11 && y1>0 && y1<11&&( x!=x1 || y!=y1))
        {
            y=y1;
            x=x1;
            show_mine(x,y);
        }
        
        if(!step)
        {
            gotoxy(10,5);
            printf("真棒！！您赢了！！");
            second[1][0]=(time(NULL)-t)/1000+48;
            second[1][1]=(time(NULL)-t)/100%10+48;
            second[1][2]=(time(NULL)-t)/10%10+48;
            second[1][3]=(time(NULL)-t)%10+48;
        if(strcmp(second[0],second[1])>0)            
            {
                printf("并且成功打破记录");
                file_out();
            }
        exit(0);
        }
    }
exit(0);
}


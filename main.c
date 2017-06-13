#include "snake.h"

int main(void)
{
    Link * head = (Link *)malloc(sizeof(Link));
    Link * swap, * temp;
    winsize size;                   //创建窗口大小的类型；
    wsize(&size);                   //获取当前窗口的大小；
    int x = size.x;               //将x定义为行，留一行获取输入；
    int y = size.y / 2;             //将y定义为列,因为字符borders占两个位置所以除2；
    int bdr = bdrc();               //将符号装换成数字储存
    long arr[x][y];                 //创建数组
    int fx,fy,sx,sy,snake;
    fx = 10;                        //食物x坐标
    fy = 15;                        //食物y坐标
    head->x = 10;                        //蛇的零时y坐标
    head->y = 9;                         //蛇的零时y坐标
    head->s = 1;                      //蛇的长度
    head->next = NULL;
    for(int xf = 0; xf < x; xf++){
        for(int yf = 0; yf < y; yf++)
            arr[xf][yf] = bdr;
    }
    progress();
    while(1){
        int n = 0;
        if(head->x == fx && head->y == fy){   //检测是否吃到食物
            printf("\a");
            fx = mrand(x);
            fy = mrand(y);
            head->s++;
            temp = (Link *)malloc(sizeof(Link));
            temp->x = head->x;
            temp->y = head->y;
            temp->s = head->s;
            temp->next = NULL;
            plus(head,temp);
        }
        if(border(head->x,head->y,x,y))
            break;                  //检测蛇是否撞到边框
        temp = head;
        int arry[head->s][2];
        copy(head,arry);
        for(int xf = 0; xf < x; xf++){
            for(int yf = 0; yf < y; yf++){
                if(border(xf,yf,x,y))
                    printf(black"%s",arr[xf][yf]);
                else if(xf == fx && yf == fy)
                    printf(yellow"%s",arr[xf][yf]);
                else if(snakes(xf,yf,arry,n)){
                    printf(cyan"%s",arr[xf][yf]);
                    n++;
                }
                else
                    printf(black"%s",arr[xf][yf]);
            }
            printf("\n");
        }
        update(head);
        if(ctrl(&head->x, &head->y) == false)
            break;
        printf("\033]c");
    }

    system("clear");
    over(head,&size);
    return 0;
}

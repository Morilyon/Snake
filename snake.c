#include "snake.h"

bool mwrite(Score score)
{
    FILE * fp;
    fp = fopen(".history","a");
    if(fwrite(&score,sizeof(Score),1,fp)){
        fclose(fp);
        return true;
    }
    else
        return false;
}

bool mread(void)
{
    FILE * fp;
    Score temp;
    fp = fopen(".history","r");
    if(fp != NULL){
        while(!feof(fp)){
            fread(&temp,sizeof(Score),1,fp);
            printf(red"%.2d\t%s\t\t%d\n",2,temp.name,temp.integer);
        }
    }
    else
        return false;


    fclose(fp);

    return true;
}



bool body(Link * head)
{
    Link * temp;
    temp = head->next;
    while(temp != NULL){
        if(head->x == temp->x && head->y == head->y)
            return true;
        temp = temp->next;
    }
    return false;
}

void over(Link * head, winsize * size)
{
    system("reset");
    int x = size->x-1;
    int y = size->y / 2;
    int bdr = bdrc();
    for(int of = 0; of < x; of++){
        for(int tf = 0; tf < y; tf++){
            if(of == 0 || tf == 0 || of == x-1 || tf == y-1)
                printf(black"%s",bdr);
            else if (of == x/4-1){
                if(tf == y/2)
                    printf(color"%.2d",head->s);
                else
                    printf(black"%s",bdr);
            }
            else if (of == x/4){
                if(tf == y/2-2)
                    printf(color"%s","游");
                else if(tf == y/2-1)
                    printf(color"%s","戏");
                else if(tf == y/2)
                    printf(color"%s","结");
                else if(tf == y/2+1)
                    printf(color"%s","束");
                else if(tf == y/2+2)
                    printf(color"%s","!!");
                else
                    printf(black"%s",bdr);
            }else
                printf(black"%s",bdr);
        }
        printf("\n");
    }
    sleep(1);
    system("reset");
}


void stemp(Link * head)
{
    Link * temp;
    temp = head;
    while(temp != NULL){
        printf(" (%d %d) ",temp->x,temp->y);
        temp = temp->next;
    }

}
void ysqrt(int arr[][2], int num)
{
    int x,y;

    for(int of = 0; of < num; of++){
        for(int tf = of+1; tf < num; tf++){
            if(arr[of][1] > arr[tf][1]){
                x = arr[of][0];
                y = arr[of][1];
                arr[of][0] = arr[tf][0];
                arr[of][1] = arr[tf][1];
                arr[tf][0] = x;
                arr[tf][1] = y;
            }
        }
    }
}

void xsqrt(int arr[][2], int num)
{
    int x,y;

    for(int of = 0; of < num; of++){
        for(int tf = of+1; tf < num; tf++){
            if(arr[of][0] > arr[tf][0]){
                x = arr[of][0];
                y = arr[of][1];
                arr[of][0] = arr[tf][0];
                arr[of][1] = arr[tf][1];
                arr[tf][0] = x;
                arr[tf][1] = y;
            }
            if(arr[of][0] == arr[tf][0]){
                if(arr[of][1] > arr[tf][1]){
                    x = arr[of][0];
                    y = arr[of][1];
                    arr[of][0] = arr[tf][0];
                    arr[of][1] = arr[tf][1];
                    arr[tf][0] = x;
                    arr[tf][1] = y;
                }
            }
        }
    }
}

void copy(Link * head, int arr[][2])
{
    Link * temp;

    int f;
    for(temp = head, f = 0; temp != NULL ; temp = temp->next, f++){
        arr[f][0] = temp->x;
        arr[f][1] = temp->y;
    }
    ysqrt(arr,head->s);
    xsqrt(arr,head->s);

}



bool snakes(int x, int y, int arr[][2], int num)
{
    return (arr[num][0] == x && arr[num][1] == y)? true: false;
}


void plus(Link * head, Link * temp)
{

    Link * swap;
    swap = head;
    while(swap != NULL){
        if(swap->next == NULL){
            swap->next = temp;
            break;
        }
        swap = swap->next;
    }

}

void output(Link * head)
{
    Link * temp;
    temp = head;
    while(temp != NULL){
        printf(" <%d %d %d> \n",temp->x, temp->y, temp->s);
        temp = temp->next;
    }

}
int mrand(int x)
{//随机数
    return rand() % (x-1) + 1;
}


bool dire(int l,int n)
{
    return (n == l+256 || n == l-256)? false: true;
}
bool ctrl(int * sx, int * sy)
{//操作
    int i;
    static int w = 256;
    i = system("./getche");
    if(i > 1024)
        i = w;
    if(i == 256){//上
        (*sx)--;
        w = i;
    }
    if(i == 512){//下
        (*sx)++;
        w = i;
    }
    if(i == 768){//左
        (*sy)--;
        w = i;
    }
    if(i == 1024){//右
        (*sy)++;
        w = i;
    }

    return true;
}


bool border(int x,int y,int h, int l)
{//检测当前位置是否为边框
    return (x == 0 || y == 0 || x == h || y == l)? true: false;
}


int bdrc(void)
{//将border字符装换为int类型储存
    FILE * fp;
    int temp;
    fp = fopen(".logo", "w+");
    fseek(fp,0,SEEK_SET);
    fprintf(fp,"%d",chs);
    fseek(fp,0,SEEK_SET);
    fscanf(fp,"%d",&temp);
    fclose(fp);
    system("rm .logo");
    return temp;
}

void update(Link * head)
{
    int x,y;
    int f;
    Link  * temp;
    int swap[head->s-1][2];
    for(temp = head, f = 0; temp != NULL && f < head->s-1; temp = temp->next, f++){
        swap[f][0] = temp->x;
        swap[f][1] = temp->y;
    }
    for(temp = head->next, f = 0; temp != NULL && f < head->s-1; temp = temp->next, f++){
        temp->x = swap[f][0];
        temp->y = swap[f][1];
    }
}




void progress(void)
{
    winsize size;
    wsize(&size);
    double Y = size.y;
    double X = size.x;
    for(int i = 0; i <= Y; i++)
    {
        for(int b = 0; b < X; b++){
            if(b == X-2){
                printf(dark_gray"%.2f%\n",percentage(i,Y));
            }
            else if (b == X-1)
                printf(dark_gray"Loading...\n");
            else
                printf("\n");
        }
        for(int x = 0; x < i; x++){
            if(x == i-1)
                printf(dark_gray"%c",'>');
            else
                printf(dark_gray"%c",'=');
        }
        printf("\n");
        usleep(20000);
        system("clear");
    }
}

double percentage(double x, double y)
{
    return (x/y) * 100;
}

char getch(void)
{
    char ch;
    system(UNECHO);
    system(UNICANON);
    ch = getchar();
    system(ICANON);
    system(ECHO);

    return ch;
}

int getint(void)
{
    int i;
    system(UNECHO);
    system(UNICANON);
    scanf("%d",&i);
    system(ICANON);
    system(ECHO);

    return i;
}

char getche(void)
{
    char ch;
    system(UNICANON);
    ch = getchar();
    system(ICANON);
    return ch;
}

void wsize(winsize * size)
{
    FILE *fp;
    system("stty -a > temp.txt");
    fp = fopen("temp.txt","r");
    fseek(fp,22,SEEK_SET);
    fscanf(fp,"%d",&size->x);
    fseek(fp,34,SEEK_SET);
    fscanf(fp,"%d",&size->y);
    fclose(fp);
    system("rm temp.txt");
    //不能返回局部变量的地址
}



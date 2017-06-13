#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define UNECHO "stty -echo"//关闭回显
#define ECHO "stty echo"//打开回显
#define UNICANON "stty -icanon"//关闭回车
#define ICANON " stty icanon"//打开回车

char getche(void)
{
    char ch;
    system(UNICANON);
    ch = getchar();
    system(ICANON);
    return ch;
}

int main(void)
{

    char ch;
    int i;
    pid_t id = fork();
    if(id == 0){
        usleep(65000);
        system("killall ./getche");
    }
    else{
        ch = getche();
        switch(ch){
            case 'w':
                i = 1;
                break;
            case 's':
                i = 2;
                break;
            case 'a':
                i = 3;
                break;
            case 'd':
                i = 4;
                break;
        }
        return i;
    }

    return i;
}

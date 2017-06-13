#ifndef SNAKE_H
#define SNAKE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>
#define black        "\033[0;30m"
#define dark_gray    "\033[1;30m"
#define cyan         "\033[0;36m"
#define red          "\033[0;31m"
#define yellow       "\033[0;33m"
#define color        "\033[40;31m"
#define chs "██"

#define UNECHO "stty -echo"//关闭回显
#define ECHO "stty echo"//打开回显
#define UNICANON "stty -icanon"//关闭回车
#define ICANON " stty icanon"//打开回车



struct SCORE{
    char name[20];
    unsigned int integer;
};

typedef struct SCORE Score;

struct LINK{
    int x;
    int y;
    int s;
    struct LINK * next;
};

typedef struct LINK Link;

typedef struct WINSIZE{
    int x;
    int y;
}winsize;


bool mwrite(Score score);
int mrand(int);
bool body(Link * head);
void over(Link * head, winsize * size);
void stemp(Link * head);
void ysqrt(int arr[][2], int num);
void xsqrt(int arr[][2], int num);
void copy(Link * head, int arr[][2]);
bool snakes(int x, int y, int arr[][2], int num);
void plus(Link * head, Link * temp);
void output(Link * head);
int mrand(int x);
bool dire(int l,int n);
bool ctrl(int * sx, int * sy);
bool border(int x,int y,int h, int l);
int bdrc(void);
void update(Link * head);
char getche(void);
char getch(void);
void wsize(winsize *);
int getint(void);
double percentage(double x, double y);
void progress(void);

#endif

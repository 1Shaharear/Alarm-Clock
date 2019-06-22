#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<graphics.h>
#include<time.h>
void main()
{
int i,j,k,hour,min,g,y=1;
struct time t;
char msg[80];
int gd=DETECT,gm;          /* GRAPHICS INITIALIZATION*/
initgraph(&gd,&gm,"..//bgi");   /*THE PATH SHOULD BE GIVEN*/

gettime(&t);
setcolor(14);
sprintf(msg,"The current time is: %d  %02d  %02d", t.ti_hour,t.ti_min,t.ti_sec);
outtextxy(150,50,msg);
outtextxy(40,100,"GIVE ONLY THE HOUR AND MINUTE YOU WANT TO SET THE ALARM(hh,mm)");
outtextxy(97,149,"HOUR:");
gotoxy(19,10);
scanf("%d",&hour);       /*GETS THE HOUR AND SECOND TO SET THE ALARM*/
outtextxy(85,198,"MINUTE:");
gotoxy(20,13);
scanf("%d",&min);
outtextxy(485,400,"SAKTHIVEL");
outtextxy(460,430,"FIRST SOFT TECH");
if( t.ti_hour > hour )  goto b;
else if(hour == t.ti_hour && min<=t.ti_min )   goto b;
else
{
for(i=t.ti_hour;i<=hour;i++)
{
for(j=t.ti_min;j<60;j++)
{
k=0;
while(k<60)
{
cleardevice();
k++;
setfillstyle(1,1);
bar(510,170,90,230);
settextstyle(1,0,3);
sprintf(msg,"%d   %d   %d",i,j,k);
outtextxy(230,188,msg);
sound(1000);
delay(100);
nosound();
sleep(1);
if(j==min && i==hour)
{
cleardevice();
while(!kbhit())
{
delay(300);
sound(1000);
setcolor(y);
outtextxy(250,200,"WAKE UP");
delay(300);
nosound();
y++;
}
goto a;
}}}}}
a:
getch();
exit(0);
b:
cleardevice();
outtextxy(250,250,"INVALID TIME");
getch();
}
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>
void boundaryfill(int x,int y,int fill,int boundry)
{
	if((getpixel(x,y)!=fill)&&(getpixel(x,y)!=boundry))
	{
		putpixel(x,y,fill);
		boundaryfill(x+1,y,fill,boundry);
		boundaryfill(x-1,y,fill,boundry);
		boundaryfill(x,y+1,fill,boundry);
		boundaryfill(x,y-1,fill,boundry);
	}
}
void signal(int p,int q,int r,int s)
{
	/*First Sig*/
	circle(470,390,15);
	boundaryfill(470,390,p,WHITE);
	/*Second Sig*/
	circle(470,90,15);
	boundaryfill(470,90,q,WHITE);
	/*Third Sig*/
	circle(170,90,15);
	boundaryfill(170,90,r,WHITE);
	/*Fourth Sig*/
	circle(170,390,15);
	boundaryfill(170,390,s,WHITE);
}
void block()
{
	struct linesettingstype lstype;
	setlinestyle(DASHED_LINE,0.1,1);
	line(320,360,320,480);
	line(320,0,320,120);
	line(0,240,200,240);
	line(440,240,640,240);

	getlinesettings(&lstype);
	setlinestyle(SOLID_LINE,0.1,1);
	getlinesettings(&lstype);

	/*FIRST BLOCK*/
	line(200,0,200,120);
	line(200,120,0,120);
	/*SEC BLOCK*/
	line(0,360,200,360);
	line(200,360,200,480);
	/*Third Block*/
	line(440,0,440,120);
	line(440,120,640,120);
	/*Fourth Block*/
	line(440,360,640,360);
	line(440,360,440,480);

}

void car1()
{
	int i;

	for(i=0;i<640;i=i+15)
	{
		block();
		/***CAR BODY ******/
		line(0+i,320,40+i,320);
		line(80+i,320,170+i,320);
		line(210+i,320,250+i,320);
		line(250+i,320,250+i,300);
		line(250+i,300,190+i,280);
		line(190+i,280,150+i,250);
		line(150+i,250,60+i,250);
		line(60+i,250,30+i,280);
		line(30+i,280,0+i,290);
		line(0+i,290,0+i,320);

		/***CAR Windows***/
		line(115+i,255,115+i,280);
		line(115+i,280,180+i,280);
		line(180+i,280,145+i,255);
		line(145+i,255,115+i,255);

		line(110+i,255,110+i,280);
		line(110+i,280,45+i,280);
		line(45+i,280,70+i,255);
		line(70+i,255,110+i,255);

		/**Wheels**/
		circle(60+i,320,17);
		circle(190+i,320,17);

		signal(2,4,4,4);
		cleardevice();
	}
}

void car2(int j ,int k)
{
	int i;
	struct linesettingstype lstype;
	for(i=j;i<=k;i=i+15)
	{
		block();
		rectangle(340,0+i,420,100+i);
		signal(4,4,4,2);
		cleardevice();
	}
}
void car3()
{
	int i;
	struct linesettingstype lstype;
	for(i=480;i>0;i=i-15)
	{
		block();
		rectangle(220,i,300,i-100);
		signal(4,2,4,4);
		cleardevice();
	}
}
void car4()
{
	int i;
	struct linesettingstype lstype;
	car2(-100,20);
	for(i=-220;i<660;i=i+15)
	{
		block();
		rectangle(340,20,420,120);
		//CAR BODY
		line(640-i,220,600-i,220);
		line(560-i,220,470-i,220);
		line(430-i,220,390-i,220);
		line(390-i,220,390-i,200);
		line(390-i,200,450-i,180);
		line(450-i,180,490-i,150);
		line(490-i,150,580-i,150);
		line(580-i,150,620-i,180);
		line(620-i,180,640-i,190);
		line(640-i,190,640-i,220);
		circle(580-i,220,20);
		circle(450-i,220,20);
		//CAR Windows
		line(540-i,156,540-i,182);
		line(540-i,182,605-i,182);
		line(605-i,182,573-i,156);
		line(573-i,156,540-i,156);
		//Left
		line(535-i,156,535-i,182);
		line(535-i,182,465-i,182);
		line(465-i,182,497-i,156);
		line(497-i,156,535-i,156);
		signal(4,4,2,4);
		cleardevice();
	}
}
void main()
{
int i;
int gd=DETECT,gm;
initgraph(&gd,&gm," ");
car1();
car3();
car4();
car2(20,480);
getch();
closegraph();
}



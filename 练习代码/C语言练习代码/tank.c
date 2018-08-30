#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
int  x,y,p,q,l,w,score=0,crash=0;         //crash检测子弹与目标坦克是否碰撞//
int *point_x=&x,*point_y=&y;
int x_1,y_1;
int *p_x1=&x_1,*p_y1=&y_1;
char kbdirection,formerdirection,ch2,targetcolor='W';            //kbdirection为键盘输入方向，formerdirection用来记录前一次的己方坦克方向，ch2记录目标坦克前一次方向,color用来记录坦克颜色//
char *ch_2=&ch2;            //指针变量ch_2指向ch2//     
char *target_color=&targetcolor;           //指针变量指向color//  
char *point_kbdirection=&kbdirection;            //键盘输入的方向//            
int main()
{
void judge();
void tank_w(int x,int y);
void tank_s(int x,int y);
void tank_a(int x,int y);
void tank_d(int x,int y);
int coordinate_x();
int coordinate_y();
void move_shell(char ch,int q,int x,int y);
void move_targets(int *x,int *y,char *color);
printf("请选择自己坦克的速度:1.慢  2.中  3.快 \n           ");
scanf("%d",&p);
printf("注意!:1.白色线条的是您的坦克.\n      2.其他颜色的坦克是敌方坦克.\n");
printf("按任意键继续.\n");
getch();
x=260,y=450;                       //x,y代表坦克中心坐标//
l=640,w=480;                       //l,w代表初始化窗口的长和宽，可调整//
p=2*p;                               //p为坦克移动速度，可调整//
q=15;                               //q为子弹移动速度，可调整//
initgraph(l,w);
outtextxy(250,200,"简易坦克游戏");
outtextxy(250,220,"按任意键进入");
getch();
cleardevice();
setfillcolor(BLACK);  
setcolor(WHITE);                   
tank_w(x,y); 
outtextxy(0,0,"按Esc键退出                          w,s,a,d分别控制坦克上下左右移动                        空格键发射炮弹");
outtextxy(0,20,"黄色坦克->10每个  绿色坦克->20每个   红色坦克->30每个   蓝色坦克->40每个  .");
outtextxy(0,40,"按任意键继续");
getch();
cleardevice();
tank_w(x,y);
x_1=coordinate_x(),y_1=coordinate_y();            //目标坦克坐标//
move_targets(p_x1,p_y1,target_color);                                //目标坦克坐标的指针变量//
do
{
switch(kbdirection)
	{
     case 'w':
		 {
			 formerdirection='w';
			 {if((y-31)>0){y-=p;bar(x-36,y-36+p,x+36,y+36+p);setcolor(WHITE);tank_w(x,y);}
			  if(crash==0)move_targets(p_x1,p_y1,target_color);else setcolor(WHITE),judge(),*target_color='W',
				  line(*p_x1-30,*p_y1-30,*p_x1+30,*p_y1+30),line(*p_x1-30,*p_y1+30,*p_x1+30,*p_y1-30),
				  Sleep(50),bar(*p_x1-36,*p_y1-36,*p_x1+36,*p_y1+36),*p_x1=coordinate_x(),
				  *p_y1=coordinate_y(),crash=0;}
		 }break;
     case 's':
		 {
			 formerdirection='s';
			 {if((y+31)<w){y+=p;bar(x-36,y-36-p,x+36,y+36-p);setcolor(WHITE);tank_s(x,y);}
			 if(crash==0)move_targets(p_x1,p_y1,target_color);else setcolor(WHITE),judge(),*target_color='W',
				 line(*p_x1-30,*p_y1-30,*p_x1+30,*p_y1+30),line(*p_x1-30,*p_y1+30,*p_x1+30,*p_y1-30),
				 Sleep(50),bar(*p_x1-36,*p_y1-36,*p_x1+36,*p_y1+36),*p_x1=coordinate_x(),
				 *p_y1=coordinate_y(),crash=0;}
		 }break;
     case 'a':
		 {
			 formerdirection='a';
			 {if((x-31)>0){x-=p;bar(x-36+p,y-36,x+36+p,y+36);setcolor(WHITE);tank_a(x,y);}
			 if(crash==0)move_targets(p_x1,p_y1,target_color);else setcolor(WHITE),judge(),*target_color='W',
				 line(*p_x1-30,*p_y1-30,*p_x1+30,*p_y1+30),line(*p_x1-30,*p_y1+30,*p_x1+30,*p_y1-30),
				 Sleep(50),bar(*p_x1-36,*p_y1-36,*p_x1+36,*p_y1+36),*p_x1=coordinate_x(),
				 *p_y1=coordinate_y(),crash=0;}
		 }break;
	 case 'd':
		 {
			 formerdirection='d';
			 {if((x+31)<l){x+=p;bar(x-36-p,y-36,x+36-p,y+36);setcolor(WHITE);tank_d(x,y);}
			 if(crash==0)move_targets(p_x1,p_y1,target_color);else setcolor(WHITE),judge(),*target_color='W',
				 line(*p_x1-30,*p_y1-30,*p_x1+30,*p_y1+30),line(*p_x1-30,*p_y1+30,*p_x1+30,*p_y1-30),
				 Sleep(50),bar(*p_x1-36,*p_y1-36,*p_x1+36,*p_y1+36),*p_x1=coordinate_x(),
				 *p_y1=coordinate_y(),crash=0;}
		 }break;
	 case ' ':{move_shell(formerdirection,q,x,y);
		       kbdirection=formerdirection;
		       switch(kbdirection)
			   {
			     case 'w':y+=p;break;
			     case 's':y-=p;break;
			     case 'a':x+=p;break;
			     case 'd':x-=p;break;
			   }
			  }break;
	 default:kbdirection=getch();break;
	}
 if(kbdirection==27)break;     
}
while(1);
cleardevice();
setcolor(WHITE);
outtextxy(280,230,"按任意键退出");
outtextxy(250,250,"退出后显示本次得分");
getch();
printf("您本次得分为 %d .\n",score);
getch();
closegraph();
return 0;
}



void tank_w(int x,int y)
{
circle(x,y,10);
circle(x,y,4);
rectangle(x-15,y-10,x+15,y+10);
rectangle(x-25,y-20,x-15,y+20);
line(x-25,y-15,x-15,y-15);
line(x-25,y-10,x-15,y-10);
line(x-25,y-5,x-15,y-5);
line(x-25,y+0,x-15,y+0);
line(x-25,y+5,x-15,y+5);
line(x-25,y+10,x-15,y+10);
line(x-25,y+15,x-15,y+15);
rectangle(x+25,y-20,x+15,y+20);
line(x+25,y-15,x+15,y-15);
line(x+25,y-10,x+15,y-10);
line(x+25,y-5,x+15,y-5);
line(x+25,y+0,x+15,y+0);
line(x+25,y+5,x+15,y+5);
line(x+25,y+10,x+15,y+10);
line(x+25,y+15,x+15,y+15);      //以上几行为规则部分//
line(x-15,y-20,x-5,y-10);       //以下两行为两条斜线//
line(x+15,y-20,x+5,y-10);
rectangle(x-4,y-31,x+4,y+0);    //以下两行为炮筒//
line(x-4,y-27,x+4,y-27);                  
}


void tank_s(int x,int y)
{
circle(x,y,10);
circle(x,y,4);
rectangle(x-15,y-10,x+15,y+10);
rectangle(x-25,y-20,x-15,y+20);
line(x-25,y-15,x-15,y-15);
line(x-25,y-10,x-15,y-10);
line(x-25,y-5,x-15,y-5);
line(x-25,y+0,x-15,y+0);
line(x-25,y+5,x-15,y+5);
line(x-25,y+10,x-15,y+10);
line(x-25,y+15,x-15,y+15);
rectangle(x+25,y-20,x+15,y+20);
line(x+25,y-15,x+15,y-15);
line(x+25,y-10,x+15,y-10);
line(x+25,y-5,x+15,y-5);
line(x+25,y+0,x+15,y+0);
line(x+25,y+5,x+15,y+5);
line(x+25,y+10,x+15,y+10); 
line(x+25,y+15,x+15,y+15);     //以上几行为规则部分//
line(x-15,y+20,x-5,y+10);      //以下两行为两条斜线//
line(x+15,y+20,x+5,y+10); 
rectangle(x+4,y+0,x-4,y+31);   //以下两行为炮筒//
line(x-4,y+27,x+4,y+27);      
}



void tank_a(int x,int y)
{
circle(x,y,10);
circle(x,y,4);
rectangle(x+10,y-15,x-10,y+15);
rectangle(x+20,y-25,x-20,y-15);
line(x+15,y-25,x+15,y-15);
line(x+10,y-25,x+10,y-15);
line(x+5,y-25,x+5,y-15);
line(x+0,y-25,x+0,y-15);
line(x-5,y-25,x-5,y-15);
line(x-10,y-25,x-10,y-15);
line(x-15,y-25,x-15,y-15);
rectangle(x+20,y+25,x-20,y+15);
line(x+15,y+25,x+15,y+15);
line(x+10,y+25,x+10,y+15);
line(x+5,y+25,x+5,y+15);
line(x-0,y+25,x-0,y+15);
line(x-5,y+25,x-5,y+15);
line(x-10,y+25,x-10,y+15);
line(x-15,y+25,x-15,y+15);      //以上几行为规则部分//
line(x-20,y-15,x-10,y-5);       //以下两行为两条斜线//
line(x-20,y+15,x-10,y+5);
rectangle(x-31,y+4,x+0,y-4);    //以下两行为炮筒//
line(x-27,y-4,x-27,y+4);
}


void tank_d(int x,int y)
{
circle(x,y,10);
circle(x,y,4);
rectangle(x+10,y-15,x-10,y+15);
rectangle(x+20,y-25,x-20,y-15);
line(x+15,y-25,x+15,y-15);
line(x+10,y-25,x+10,y-15);
line(x+5,y-25,x+5,y-15);
line(x+0,y-25,x+0,y-15);
line(x-5,y-25,x-5,y-15);
line(x-10,y-25,x-10,y-15);
line(x-15,y-25,x-15,y-15);
rectangle(x+20,y+25,x-20,y+15);
line(x+15,y+25,x+15,y+15);
line(x+10,y+25,x+10,y+15);
line(x+5,y+25,x+5,y+15);
line(x-0,y+25,x-0,y+15);
line(x-5,y+25,x-5,y+15);
line(x-10,y+25,x-10,y+15);
line(x-15,y+25,x-15,y+15);      //以上几行为规则部分//
line(x+20,y-15,x+10,y-5);       //以下两行为两条斜线//
line(x+20,y+15,x+10,y+5);
rectangle(x+0,y-4,x+31,y+4);    //以下两行为炮筒//
line(x+27,y-4,x+27,y+4);
}

void move_shell(char ch,int q,int x,int y)
{
void tank_w(int x,int y);
void tank_s(int x,int y);
void tank_a(int x,int y);
void tank_d(int x,int y);
setcolor(WHITE);
	if(ch=='w')
	{
		for(int i=0;;i+=q)
		{
			rectangle(x-4,y-41-i,x+4,y-37-i);
			Sleep(1);
            bar(x-4,y-41-i,x+4,y-37-i);
			if((y-46-i)<0)break;
			if(((*p_x1-x)*(*p_x1-x)+(*p_y1-(y-41-i))*(*p_y1-(y-41-i)))<36*36){crash=1;break;}
		}
	}
	if(ch=='s')
	{
		for(int i=0;;i+=q)
		{
			rectangle(x-4,y+41+i,x+4,y+37+i);
			Sleep(1);
            bar(x-4,y+41+i,x+4,y+37+i);
			if((y+46+i)>480)break;
			if(((*p_x1-x)*(*p_x1-x)+(*p_y1-(y+41+i))*(*p_y1-(y+41+i)))<36*36){crash=1;break;}
		}
	}
	if(ch=='d')
	{
		for(int i=0;;i+=q)
		{
			rectangle(x+41+i,y+4,x+37+i,y-4);
			Sleep(1);
            bar(x+41+i,y+4,x+37+i,y-4);
			if((x+46+i)>640)break;
			if(((*p_x1-(x+41+i))*(*p_x1-(x+41+i))+(*p_y1-y)*(*p_y1-y))<36*36){crash=1;break;}
		}
	}
	if(ch=='a')
	{
		for(int i=0;;i+=q)
		{
		    rectangle(x-37-i,y-4,x-41-i,y+4);
			Sleep(1);
            bar(x-37-i,y-4,x-41-i,y+4);
			if((x-46-i)<0)break;
			if(((*p_x1-(x-41-i))*(*p_x1-(x-41-i))+(*p_y1-y)*(*p_y1-y))<36*36){crash=1;break;}
		}
	}
}


void move_targets(int *x,int *y,char *color)
{
void tank_w(int x,int y);
void tank_s(int x,int y);
void tank_a(int x,int y);
void tank_d(int x,int y);
srand((unsigned)time(NULL));
int n=rand()%4+1;
do
{
  int r=0,t=0;
  if(*color=='W')                         
  {
	switch(n)
	{
	case 1:{setcolor(RED);*color='R';}break;                          //转换色彩,值1,2,3,4分别转换成RED,GREEN,YELLOW,BLUE//
	case 2:{setcolor(GREEN);*color='G';}break;
	case 3:{setcolor(YELLOW);*color='Y';}break;
	case 4:{setcolor(BLUE);*color='B';}break;
	} 
  }
  else switch(*color)
		{
         case 'R':setcolor(RED);break;
		 case 'G':setcolor(GREEN);break;
		 case 'Y':setcolor(YELLOW);break;
		 case 'B':setcolor(BLUE);break;
		}

  int ww,ss,aa,dd;  
  aa=rand()%150+10;dd=rand()%150+10;ww=rand()%150+10;ss=rand()%150+10;
  do
  {
   char ch_temp;
   n=rand()%4+1;
   switch(n)
   {
   case 1 :if(*y>36){ch_temp='W';}break;                  //转换方向,值1,2,3,4分别转换成上，下，左，右//
   case 2 :if(*y<444){ch_temp='S';}break;
   case 3 :if(*x>36){ch_temp='A';}break;
   case 4 :if(*x<604){ch_temp='D';}break;
   }
   switch(ch_temp)
   {
   case 'W':if(ww!=0)
			{
			 for(int i=1;i<=ww;i++)
			 {
		      if((*y-36)>0)
			  {*y-=1;Sleep(50);bar(*x-36,*y-36+1,*x+36,*y+36+1);tank_w(*x,*y);}
			 if(kbhit()){*point_kbdirection=getch();r=1;break;}
			  }
			 ww=0;
			}break;
   case 'S':if(ss!=0)
			{
	         for(int i=1;i<=ss;i++)
			 {
		     if((*y+36)<480)
			 {*y+=1;Sleep(50);bar(*x-36,*y-36-1,*x+36,*y+36-1);tank_s(*x,*y);}
			 if(kbhit()){*point_kbdirection=getch();r=1;break;}
			 }
			 ss=0;
			}break;
   case 'A':if(aa!=0)
			{
			 for(int i=1;i<=aa;i++)
			 {
		     if((*x-36)>0)
			 {*x-=1;Sleep(50);bar(*x-36+1,*y-36,*x+36+1,*y+36);tank_a(*x,*y);}
			 if(kbhit()){*point_kbdirection=getch();r=1;break;}
			 }
			 aa=0;
			}break;
   case 'D':if(dd!=0)
			{
			 for(int i=1;i<=dd;i++)
			 {
		     if((*x+36)<640)
			 {*x+=1;Sleep(50);bar(*x-36-1,*y-36,*x+36-1,*y+36);tank_d(*x,*y);}
			 if(kbhit()){*point_kbdirection=getch();r=1;break;}
			 }
			 dd=0;
			}break;
   }
   if(r==1){t=1;break;}
   if((aa==0)&&(dd==0)&&(ww==0)&&(ss==0))break;
  }
   while(1); 

if(t==1)break;
}
while(1);
         
}


int coordinate_x()

{
int n;
srand((unsigned)time(NULL));
while(1)
{
n=rand()%568+36;
if((n<(*point_x-72))||(n>(*point_x+72)))break;
}
return n;
}


int coordinate_y()
{
int n;
srand((unsigned)time(NULL));
while(1)
{
n=rand()%408+36;
if((n<(*point_y-72))||(n>(*point_y+72)))break;
}
return n;
}

void judge()
{
switch(targetcolor)
{
case 'R':score+=30;break;
case 'B':score+=40;break;
case 'Y':score+=10;break;
case 'G':score+=20;break;
}
}
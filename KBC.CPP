#include<stdlib.h>
#include<conio.h>
#include<iostream.h>
#include<dos.h>
#include<graphics.h>

union REGS in,out;
void sounddevice();
int q1(int);
int q2(int);
int q3(int);
int q4(int);
int q5(int);
int q6(int);
int q7(int);
int q8(int);
int q9(int);
int q10(int);

int callmouse()
{
	in.x.ax=1;
	int86(51,&in,&out);
	return 1;
}

void mouseposition(int &xpos,int & ypos,int & click)
{
	in.x.ax=3;
	int86(51,&in,&out);
	click=out.x.bx;
	xpos=out.x.cx;
	ypos=out.x.dx;
}
int mousehide()
{
	in.x.ax=2;
	int86(51,&in,&out);
	return 1;
}

void setposition(int & xpos,int & ypos)
{
	in.x.ax=4;
	in.x.cx=xpos;
	in.x.dx=ypos;
	int86(51,&in,&out);
}


void circlekbc()
{
	int x=250,y=150;
	setfillstyle(9,BLUE);
	circle(x,y,100);
	floodfill(x,y,15);
	circle(x,y,70);
	arc(x,y,5,170,65);
	arc(x,y,5,170,64);
	arc(x,y,190,350,65);
	arc(x,y,190,350,64);

	settextstyle(7,0,4);
	outtextxy(x-90,y-20,"CROREPATI");

	settextstyle(8,0,3);
	outtextxy(x-84,y-52,"K");
	outtextxy(x-70,y-75,"A");
	outtextxy(x-54,y-87,"U");
	outtextxy(x-34,y-98,"N");

	outtextxy(x-4,y-104,"B");
	outtextxy(x+12,y-102,"A");
	outtextxy(x+30,y-95,"N");
	outtextxy(x+48,y-85,"E");
	outtextxy(x+62,y-70,"G");
	outtextxy(x+72,y-52,"A");

	outtextxy(x-84,y+18,"K");
	outtextxy(x-70,y+35,"A");
	outtextxy(x-54,y+53,"U");
	outtextxy(x-34,y+64,"N");

	outtextxy(x-4,y+70,"B");
	outtextxy(x+14,y+65,"A");
	outtextxy(x+30,y+60,"N");
	outtextxy(x+48,y+50,"E");
	outtextxy(x+62,y+36,"G");
	outtextxy(x+72,y+17,"A");

  //	settextstyle(13,0,3);
  //	outtextxy(190,100,"Rs.");
}

void circlekbc(int x, int y)
{
	setfillstyle(9,BLUE);
	circle(x,y,100);
	floodfill(x,y,15);
	circle(x,y,70);
	arc(x,y,5,170,65);
	arc(x,y,5,170,64);
	arc(x,y,190,350,65);
	arc(x,y,190,350,64);

	settextstyle(7,0,4);
	outtextxy(x-90,y-20,"CROREPATI");

	settextstyle(8,0,3);

	outtextxy(x-84,y+18,"K");
	outtextxy(x-84,y-52,"K");delay(100);

	outtextxy(x-70,y+35,"A");
	outtextxy(x-70,y-75,"A");delay(100);

	outtextxy(x-54,y+53,"U");
	outtextxy(x-54,y-87,"U");delay(100);

	outtextxy(x-34,y+64,"N");
	outtextxy(x-34,y-98,"N");delay(100);

	outtextxy(x-4,y+70,"B");
	outtextxy(x-4,y-104,"B");delay(100);

	outtextxy(x+14,y+65,"A");
	outtextxy(x+12,y-102,"A");delay(100);

	outtextxy(x+30,y+60,"N");
	outtextxy(x+30,y-95,"N");delay(100);

	outtextxy(x+48,y+50,"E");
	outtextxy(x+48,y-85,"E");delay(100);

	outtextxy(x+62,y+36,"G");
	outtextxy(x+62,y-70,"G");delay(100);

	outtextxy(x+72,y+17,"A");
	outtextxy(x+72,y-52,"A");delay(100);

  //	settextstyle(13,0,3);
  //	outtextxy(190,100,"Rs.");
}

int check(int x, int y)
{
	if(x>280 && y>350 && x<320 && y<390)
		return 1 ;
	else if(x>340 && y>350 && x<380 && y<390)
		exit(0);
	else
		return 0;
	return 0;
}

int secpage()
{
	cleardevice();
	int a=280,b=350;
	settextstyle(7,0,4);
	outtextxy(180,20,"WELCOME TO KBC");

	circlekbc(330,200);

	rectangle(a,b,a+40,b+40);
	line(a+10,b+10,a+30,b+20);
	line(a+10,b+30,a+30,b+20);
	line(a+10,b+10,a+10,b+30);
	setfillstyle(9,WHITE);
	floodfill(a+11,b+20,15);

	rectangle(340,b,380,b+40);
	line(345,b+4,375,b+34);
	line(345,b+5,375,b+35);
	line(345,b+6,375,b+36);

	line(375,b+4,345,b+34);
	line(375,b+5,345,b+35);
	line(375,b+6,345,b+36);

	int x,y,cl,ch;
	do{
		mouseposition(x,y,cl);
		gotoxy(18,14);
		if(cl==1)
		{
			ch=check(x,y);
		}
		if(ch==1)
			return 1;
	}while(!kbhit());
	return 0;
}

void frame()
{
	setfillstyle(9,0);
	rectangle(2,2,638,476);
	floodfill(443,305,15);


	rectangle(4,4,438,300);


	rectangle(4,304,438,472);

	line(4,380,438,380);
	line(4,426,438,426);
	line(218,380,218,472);


	rectangle(442,4,634,300);

	rectangle(442,4,634,30);
	rectangle(442,30,634,60);
	rectangle(442,60,634,90);
	rectangle(442,90,634,120);
	rectangle(442,120,634,150);
	rectangle(442,150,634,180);
	rectangle(442,180,634,210);
	rectangle(442,210,634,240);
	rectangle(442,240,634,270);
	rectangle(442,270,634,300);

       /*	line(442,30,634,30);
	line(442,60,634,60);
	line(442,90,634,90);
	line(442,120,634,120);
	line(442,150,634,150);
	line(442,180,634,180);
	line(442,210,634,210);
	line(442,240,634,240);
	line(442,270,634,270);
	*/
	setfillstyle(9,7);
	rectangle(442,304,634,472);
	line(442,388,634,388);
	floodfill(443,305,15);

	settextstyle(7,0,2);
	outtextxy(450,408,"Made By:-");
	outtextxy(450,438,"Dishant Rathi");
	outtextxy(470,306,"HELP LINE :-");

	setfillstyle(7,0);
	ellipse(492,356,0,360,40,20);
	fillellipse(492,356,40,20);

	setfillstyle(7,0);
	ellipse(582,356,0,360,40,20);
	fillellipse(582,356,40,20);

	settextstyle(7,0,2);
	outtextxy(464,344,"50-50");
	outtextxy(560,344,"Votes");

}

void score()
{
	settextstyle(2,0,6);
	//setcolor(YELLOW);
	outtextxy(448,6,"10.  1 Crore");
	outtextxy(448,36,"9.   50,00,000");
	outtextxy(448,66,"8.   25,00,000");
	outtextxy(448,96,"7.   12,50,000");
	outtextxy(448,126,"6.    6,40,000");
	outtextxy(448,156,"5.    3,20,000");
	outtextxy(448,186,"4.    1,60,000");
	outtextxy(448,216,"3.      80,000");
	outtextxy(448,246,"2.      40,000");
	outtextxy(448,276,"1.      20,000");
}

void colscore(int c)
{
	int sc=BLUE;
	switch(c)
	{
		case 10:setfillstyle(9,sc);
			rectangle(442,4,634,30);
			floodfill(443,5,15);

		case 9:setfillstyle(9,sc);
			rectangle(442,30,634,60);
			floodfill(443,31,15);

		case 8:setfillstyle(9,sc);
			rectangle(442,60,634,90);
			floodfill(443,61,15);

		case 7:setfillstyle(9,sc);
			rectangle(442,90,634,120);
			floodfill(443,91,15);

		case 6:setfillstyle(9,sc);
			rectangle(442,120,634,150);
			floodfill(443,121,15);

		case 5:setfillstyle(9,sc);
			rectangle(442,150,634,180);
			floodfill(443,151,15);

		case 4:setfillstyle(9,sc);
			rectangle(442,180,634,210);
			floodfill(443,181,15);

		case 3:setfillstyle(9,sc);
			rectangle(442,210,634,240);
			floodfill(443,211,15);

		case 2:setfillstyle(9,sc);
			rectangle(442,240,634,270);
			floodfill(443,241,15);

		case 1:setfillstyle(9,sc);
			rectangle(442,270,634,300);
			floodfill(443,271,15);
			break;


		default:c=0;
	}
	switch(c)
	{
		case 10:setfillstyle(9,2);
			rectangle(442,4,634,30);
			floodfill(443,5,15);
			break;
		case 9:setfillstyle(9,2);
			rectangle(442,30,634,60);
			floodfill(443,31,15);
			break;
		case 8:setfillstyle(9,2);
			rectangle(442,60,634,90);
			floodfill(443,61,15);
			break;
		case 7:setfillstyle(9,2);
			rectangle(442,90,634,120);
			floodfill(443,91,15);
			break;
		case 6:setfillstyle(9,2);
			rectangle(442,120,634,150);
			floodfill(443,121,15);
			break;
		case 5:setfillstyle(9,2);
			rectangle(442,150,634,180);
			floodfill(443,151,15);
			break;
		case 4:setfillstyle(9,2);
			rectangle(442,180,634,210);
			floodfill(443,181,15);
			break;
		case 3:setfillstyle(9,2);
			rectangle(442,210,634,240);
			floodfill(443,211,15);
			break;
		case 2:setfillstyle(9,2);
			rectangle(442,240,634,270);
			floodfill(443,241,15);
			break;
		case 1:setfillstyle(9,2);
			rectangle(442,270,634,300);
			floodfill(443,271,15);
			break;

		default:c=0;
	}
}

void op(char ch,int color=4)
{
	switch(ch)
	{
		case 'a':
		case 'A':setfillstyle(9,color);
			 rectangle(4,380,218,426);
			 floodfill(5,381,15);
			 break;

		case 'b':
		case 'B':setfillstyle(9,color);
			 rectangle(4,426,218,472);
			 floodfill(5,427,15);
			 break;

		case 'c':
		case 'C':setfillstyle(9,color);
			 rectangle(218,380,438,426);
			 floodfill(225,381,15);
			 break;

		case 'd':
		case 'D':setfillstyle(9,color);
			 rectangle(218,426,438,472);
			 floodfill(225,427,15);
			 break;

		default:ch=NULL;
	}
	delay(2000);
}

char area(int x, int y,int q)
{
	static int ff=0,v=0;
	int color=4;
	if(x>4 && y>380 && x<218 && y<426)            //a
	{
		setfillstyle(9,color);
		rectangle(4,380,218,426);
		floodfill(5,381,15);
		return 'a';
	}
	else if(x>4 && y>426 && x<218 && y<472)          //b
	{
		setfillstyle(9,color);
		rectangle(4,426,218,472);
		floodfill(5,427,15);
		return 'b';
	}
	else if(x>218 && y>380 && x<438 && y<426)       //c
	{
		setfillstyle(9,color);
		rectangle(218,380,438,426);
		floodfill(225,381,15);
		return 'c';
	}
	else if(x>218 && y>426 && x<438 && y<472)      //d
	{
		setfillstyle(9,color);
		rectangle(218,426,438,472);
		floodfill(225,427,15);
		return 'd';
	}

	else if(x>452 && y>336 && x<532 && y<376) //50-50
	{
		if(ff!=0){
		line(452,336,532,376);
		line(532,336,452,372);}
		else{
		ff++;
		cleardevice();
		colscore(q);
		frame();
		circlekbc(200,150);
		score();
		switch(q)
		{
			case 1:return q1(1);
			case 2:return q2(1);
			case 3:return q3(1);
			case 4:return q4(1);
			case 5:return q5(1);
			case 6:return q6(1);
			case 7:return q7(1);
			case 8:return q8(1);
			case 9:return q9(1);
			case 10:return q10(1);
			default:;
		}    }

	}

	else if(x>542 && y>336 && x<622 && y<376)   //votes
	{
		if(v!=0){
		line(542,336,622,376);
		line(622,336,542,376);}
		else{
		v++;
		settextstyle(3,0,3);
		switch(q)
		{
			case 1:outtextxy(10,20,"(A) 60 %");
			       outtextxy(10,60,"(B) 20 %");
			       outtextxy(10,100,"(C) 10 %");
			       outtextxy(10,140,"(D) 10 %"); break;

			case 2:outtextxy(10,20,"(A) 20 %");
			       outtextxy(10,60,"(B) 15 %");
			       outtextxy(10,100,"(C) 50 %");
			       outtextxy(10,140,"(D) 15 %"); break;

			case 3:outtextxy(10,20,"(A) 15 %");
			       outtextxy(10,60,"(B) 5 %");
			       outtextxy(10,100,"(C) 10 %");
			       outtextxy(10,140,"(D) 70 %"); break;

			case 4:outtextxy(10,20,"(A) 20 %");
			       outtextxy(10,60,"(B) 40 %");
			       outtextxy(10,100,"(C) 20 %");
			       outtextxy(10,140,"(D) 20 %"); break;

			case 5:outtextxy(10,20,"(A) 15 %");
			       outtextxy(10,60,"(B) 10 %");
			       outtextxy(10,100,"(C) 5 %");
			       outtextxy(10,140,"(D) 60 %"); break;

			case 6:outtextxy(10,20,"(A) 10 %");
			       outtextxy(10,60,"(B) 5 %");
			       outtextxy(10,100,"(C) 5 %");
			       outtextxy(10,140,"(D) 80 %"); break;

			case 7:outtextxy(10,20,"(A) 15 %");
			       outtextxy(10,60,"(B) 10 %");
			       outtextxy(10,100,"(C) 65 %");
			       outtextxy(10,140,"(D) 10 %"); break;

			case 8:outtextxy(10,20,"(A) 25 %");
			       outtextxy(10,60,"(B) 55 %");
			       outtextxy(10,100,"(C) 20 %");
			       outtextxy(10,140,"(D) 10 %"); break;

			case 9:outtextxy(10,20,"(A) 20 %");
			       outtextxy(10,60,"(B) 10 %");
			       outtextxy(10,100,"(C) 10 %");
			       outtextxy(10,140,"(D) 60 %"); break;

			case 10:outtextxy(10,20,"(A) 45 %");
			       outtextxy(10,60,"(B) 30 %");
			       outtextxy(10,100,"(C) 20 %");
			       outtextxy(10,140,"(D) 5 %"); break;


		} }
	}
	return 0;

}

int q1(int a=0)
{
	settextstyle(3,0,3);

	outtextxy(10,310,"Q 1: The International Literacy Day Is");
	outtextxy(70,340,"Observed On");

	outtextxy(10,390,"(A) Sep 8");
	outtextxy(10,435,"(B) Nov 28");        //a
	if(a==0){
	outtextxy(222,390,"(C) May 2");
	outtextxy(222,435,"(D) Sep 22");}
	sounddevice();

	char ch;
  //	ch=getch();
  //	op(ch);
	int x,y,cl;
	do{
		mouseposition(x,y,cl);
		gotoxy(18,14);
		if(cl==1)
		{
			ch=area(x,y,1);
		}
		if(ch=='a'||ch=='b'||ch=='c'||ch=='d' || ch==2)
			break;
	}while(!kbhit());
	op('a',2);

	if(ch=='a' || ch=='A'|| ch==2)
		return 2;

	return 0;

}

int q2(int a=0)
{
	settextstyle(3,0,3);
	outtextxy(10,310,"Q 2: The Language Of Lakshadweep.");
	outtextxy(70,340,"A Union Territory Of India, Is");
	if(a==0){
	outtextxy(10,390,"(A) Tamil");
	outtextxy(10,435,"(B) Hindi");}        //c
	outtextxy(222,390,"(C) Malayalam");
	outtextxy(222,435,"(D) Telugu");
	sounddevice();

	char ch;
       //	ch=getch();
       //	op(ch);
	int x,y,cl;
	do{
		mouseposition(x,y,cl);
		gotoxy(18,14);
		if(cl==1)
		{
			ch=area(x,y,2);
		}
		if(ch=='a'||ch=='b'||ch=='c'||ch=='d' || ch==3)
			break;
	}while(!kbhit());
	op('c',2);

	if(ch=='c' || ch==3)
		return 3;
	return 0;
}


int q3(int a=0)
{
	settextstyle(3,0,3);
	outtextxy(10,310,"Q 3: Bahubali Festival Is Related To");
	outtextxy(70,340,"");
	if(a==0){
	outtextxy(10,390,"(A) Islam");
	outtextxy(10,435,"(B) Hinduism");}        //d
	outtextxy(222,390,"(C) Buddhish");
	outtextxy(222,435,"(D) Jainism");
	sounddevice();

	char ch;
	//ch=getch();
	//op(ch);
	int x,y,cl;
	do{
		mouseposition(x,y,cl);
		gotoxy(18,14);
		if(cl==1)
		{
			ch=area(x,y,3);
		}
		if(ch=='a'||ch=='b'||ch=='c'||ch=='d' ||ch==4)
			break;
	}while(!kbhit());
	op('d',2);

	if(ch=='d' || ch==4)
		return 4;
	return 0;
}


int q4(int a=0)
{
	settextstyle(3,0,3);
	outtextxy(10,310,"Q 4: What Day Is Observed as The");
	outtextxy(70,340,"World Standards Day");

	outtextxy(10,390,"(A) June 26");
	outtextxy(10,435,"(B) Oct 14");
	if(a==0){        //b
	outtextxy(222,390,"(C) Nov 15");
	outtextxy(222,435,"(D) Dec 2");}
	sounddevice();

	char ch;
	//ch=getch();
	//op(ch);
	int x,y,cl;
	do{
		mouseposition(x,y,cl);
		gotoxy(18,14);
		if(cl==1)
		{
			ch=area(x,y,4);
		}
		if(ch=='a'||ch=='b'||ch=='c'||ch=='d' || ch==5)
			break;
	}while(!kbhit());
	op('b',2);

	if(ch=='b' || ch==5)
		return 5;
	return 0;
}


int q5(int a=0)
{
	settextstyle(3,0,3);
	outtextxy(10,310,"Q 5: Who Is The Author Of The Epic");
	outtextxy(70,340,"Meghdoot");

	outtextxy(10,390,"(A) Vishakadatta");
	if(a==0){
	outtextxy(10,435,"(B) Valmiki");        //d
	outtextxy(222,390,"(C) Banabhatta");}
	outtextxy(222,435,"(D) Kalidas");
	sounddevice();

	char ch;
	//ch=getch();
	//op(ch);
	int x,y,cl;
	do{
		mouseposition(x,y,cl);
		gotoxy(18,14);
		if(cl==1)
		{
			ch=area(x,y,5);
		}
		if(ch=='a'||ch=='b'||ch=='c'||ch=='d' || ch==6)
			break;
	}while(!kbhit());
	op('d',2);

	if(ch=='d' || ch==6)
	{

		return 6;
	}
	return 0;
}


int q6(int a=0)
{
	settextstyle(3,0,3);
	outtextxy(10,310,"Q 6: Ghototkach In Mahabharat Was");
	outtextxy(70,340,"The Son Of");

	outtextxy(10,390,"(A) Duryodhana");
	if(a==0){
	outtextxy(10,435,"(B) Arjuna");        //d
	outtextxy(222,390,"(C) Yudhishthir");}
	outtextxy(222,435,"(D) Bhima");
	sounddevice();

	char ch;
	//ch=getch();
	//op(ch);
	int x,y,cl;
	do{
		mouseposition(x,y,cl);
		gotoxy(18,14);
		if(cl==1)
		{
			ch=area(x,y,6);
		}
		if(ch=='a'||ch=='b'||ch=='c'||ch=='d' ||ch==7)
			break;
	}while(!kbhit());
	op('d',2);

	if(ch=='d' || ch==7)
		return 7;
	return 0;
}


int q7(int a=0)
{
	settextstyle(3,0,3);
	outtextxy(10,310,"Q 7: Van Mahotsav Was Started By");
	outtextxy(70,340,"");

	if(a==0){
	outtextxy(10,390,"(A) MaharshiKarve");
	outtextxy(10,435,"(B) GangadharTilak");}        //c
	outtextxy(222,390,"(C) K . M, Munshi");
	outtextxy(222,435,"(D) Sanjay Gandhi");
	sounddevice();

	char ch;
	//ch=getch();
	//op(ch);
	int x,y,cl;
	do{
		mouseposition(x,y,cl);
		gotoxy(18,14);
		if(cl==1)
		{
			ch=area(x,y,7);
		}
		if(ch=='a'||ch=='b'||ch=='c'||ch=='d' ||ch==8)
			break;
	}while(!kbhit());
	op('c',2);

	if(ch=='c' || ch==8)
		return 8;
	return 0;
}

int q8(int a=0)
{
	settextstyle(3,0,3);
	outtextxy(10,310,"Q 8: The First Month Of The Indian");
	outtextxy(70,340,"National Calender Is");

	outtextxy(10,390,"(A) Magha");
	outtextxy(10,435,"(B) Chaitra");        //b
	if(a==0){
	outtextxy(222,390,"(C) Ashadha");
	outtextxy(222,435,"(D) Vaishakha");}
	sounddevice();

	char ch;
	//ch=getch();
	//op(ch);
	int x,y,cl;
	do{
		mouseposition(x,y,cl);
		gotoxy(18,14);
		if(cl==1)
		{
			ch=area(x,y,8);
		}
		if(ch=='a'||ch=='b'||ch=='c'||ch=='d' || ch==9)
			break;
	}while(!kbhit());
	op('b',2);

	if(ch=='b' || ch==9)
		return 9;
	return 0;
}


int q9(int a=0)
{
	settextstyle(3,0,3);
	outtextxy(10,310,"Q 9: Which Of The Following Is Not");
	outtextxy(70,340,"a Dance From Kerala");

	if(a==0){
	outtextxy(10,390,"(A) Kathakali");
	outtextxy(10,435,"(B) Mohiniattam");}        //d
	outtextxy(222,390,"(C) Ottan Thullal");
	outtextxy(222,435,"(D) Yaksha Gana");
	sounddevice();

	char ch;
	//ch=getch();
	//op(ch);
	int x,y,cl;
	do{
		mouseposition(x,y,cl);
		gotoxy(18,14);
		if(cl==1)
		{
			ch=area(x,y,9);
		}
		if(ch=='a'||ch=='b'||ch=='c'||ch=='d' || ch==10)
			break;
	}while(!kbhit());
	op('d',2);

	if(ch=='d' || ch==10)
		return 10;
	return 0;
}


int q10(int a=0)
{
	settextstyle(3,0,3);
	outtextxy(10,310,"Q 10: World Health Day Is Observed");
	outtextxy(85,340,"On");

	outtextxy(10,390,"(A) Apr 7");
	if(a==0){
	outtextxy(10,435,"(B) Mar 6");        //a
	outtextxy(222,390,"(C) May 15");}
	outtextxy(222,435,"(D) Apr 28");
	sounddevice();

	char ch;
	//ch=getch();
	//op(ch);
	int x,y,cl;
	do{
		mouseposition(x,y,cl);
		gotoxy(18,14);
		if(cl==1)
		{
			ch=area(x,y,10);
		}
		if(ch=='a'||ch=='b'||ch=='c'||ch=='d' || ch==11)
			break;
	}while(!kbhit());
	op('a',2);

	if(ch=='a' || ch==11)
		return 11;
	return 0;
}

void soundsc()
{
	sound(450);
	delay(300);
	sound(500);
	delay(300);
	sound(600);
	delay(300);
	sound(400);
	delay(300);
	sound(450);
	delay(100);
	nosound();
	delay(500);
}

void textsc(int t)
{
	circlekbc(300,200);
	int x=150,y=350;
	switch(t)
		{
			case 1: settextstyle(7,0,4);
				outtextxy(x,y,"You Score 20,000 ");break;
			case 2: settextstyle(7,0,4);
				outtextxy(x,y,"You Score 40,000 ");break;
			case 3: settextstyle(7,0,4);
				outtextxy(x,y,"You Score 80,000 ");break;
			case 4: settextstyle(7,0,4);
				outtextxy(x,y,"You Score 1,60,000 ");break;
			case 5: settextstyle(7,0,4);
				outtextxy(x,y,"You Score 3,20,000 ");break;
			case 6: settextstyle(7,0,4);
				outtextxy(x,y,"You Score 6,40,000 ");break;
			case 7: settextstyle(7,0,4);
				outtextxy(x,y,"You Score 12,50,000");break;
			case 8: settextstyle(7,0,4);
				outtextxy(x,y,"You Score 25,00,000");break;
			case 9: settextstyle(7,0,4);
				outtextxy(x,y,"You Score 50,00,000");break;
			case 10:settextstyle(7,0,4);
				outtextxy(x,y,"You Score 1 Crore ");break;
			default:settextstyle(7,0,4);
				outtextxy(x,y,"You Score 0");
		}
}

void startpage()
{
	circlekbc(320,200);
	rectangle(2,350,632,360);
	settextstyle(7,0,3);
	outtextxy(2,310,"LOADING. . . . . .");

	for(int i=2;i<632;i++)
	{
		rectangle(2,350,i,360);
		delay(10);
	}
}

void inter()
{
	cleardevice();
	frame();
	circlekbc();

}

void star(int xmin,int xmax,int ymin,int ymax)
{
	int x,y,r;

	x=(xmax+xmin)/2;
	y=(ymax+ymin)/2;
	r=5;

	circle(x,y,r);

	int v=1,i=1;

	while(1)
	{
		if(x-(i*r)<=xmin || x+(i*r)>=xmax || y-(i*r)<=ymin || y+(i*r)>=ymax)
			break;

		if(v<=15)
		{
			circle(x,y,r*i);
			setfillstyle(1,v);
			floodfill(x+((r*i)-i),y,WHITE);
			v++;
		}
		else
			v=1;
		i++;
		delay(200);
	}
}

void sounddevice()
{
	int a;
	for(a=5;a<10;a++)
	{
		sound(100*a);
		delay(200);
	}
	nosound();
}

void main()
{
	clrscr();
	int x,y,gd=DETECT,gm;

	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	int c=1,t,a=0,b=0;
	setposition(a,b);
	gotoxy(10,9);
	callmouse();
	startpage();
	c=secpage();
	while(c!=0)
	{
		cleardevice();
		t=c-1;
		switch(c)
		{
			case 1: delay(2000); inter(); colscore(c);score();c=q1();break;
			case 2: textsc(c-1) ;soundsc(); inter(); colscore(c); score();c=q2();break;
			case 3: textsc(c-1) ;soundsc(); inter(); colscore(c); score();c=q3();break;
			case 4: textsc(c-1) ;soundsc(); inter(); colscore(c); score();c=q4();break;
			case 5: textsc(c-1) ;soundsc(); inter(); colscore(c); score();c=q5();break;
			case 6: textsc(c-1) ;soundsc(); inter(); colscore(c); score();c=q6();break;
			case 7: textsc(c-1) ;soundsc(); inter(); colscore(c); score();c=q7();break;
			case 8: textsc(c-1) ;soundsc(); inter(); colscore(c); score();c=q8();break;
			case 9: textsc(c-1) ;soundsc(); inter(); colscore(c); score();c=q9();break;
			case 10:textsc(c-1) ;soundsc(); inter(); colscore(c); score();c=q10();break;
			case 11:textsc(c-1) ;soundsc(); inter(); delay(50);c=0;break;
			default : c=0;
		}
	}
	cleardevice();

	textsc(t);
	mousehide();
	if(t==10)
	{
		settextstyle(7,0,4);
		outtextxy(150,30,"CONGRATULATION");
		star(4,54,4,54);
		star(50,150,50,150);
		star(4,54,150,200);
		star(554,604,4,54);
		star(450,550,50,150);
		star(554,604,150,200);
	}
	if(t<10){
		settextstyle(7,0,4);
		outtextxy(200,30,"GAME OVER");
	}
	getch();
}
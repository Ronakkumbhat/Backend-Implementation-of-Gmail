#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<graphics.h>
#include<dos.h>
char eid[20],ufn[20],p[20];

class account
{

      char id[20],fn[10],ln[10],pass[20],gen[10],coun[10],loc[10],pno[10],sq[50],sa[20];
      int dd,mm,yy,ch;

   public:

      void password();

      void input()
      {
	 clrscr();
	 cout<<"\n First Name:";
	 cin>>fn;
	 cout<<"\n Last Name:";
	 cin>>ln;
	 cout<<"\n Date of Birth:";
	 cin>>dd>>mm>>yy;
	 gender();
	 cout<<"\n Location:";
	 cin>>loc;
	 cout<<"\n Country:";
	 cin>>coun;
	 cout<<"\n Phone Number:";
	 cin>>pno;
	 clrscr();
	 cout<<"\n Email ID:";
	 cin>>id;
	 password();
	 cout<<"\n Security Question:";
	 gets(sq);
	 cout<<"\n Security Answer (1 word):";
	 cin>>sa;
      }

      void gender()
      {
	 cout<<"\n Gender:"<<"\t 1.Male  2.Female  3.Others";
	 cout<<"\n Enter:";
	 cin>>ch;

	 if(ch==1)
	     strcpy(gen,"Male");
	 else if(ch==2)
	     strcpy(gen,"Female");
	 else if(ch==3)
	     strcpy(gen,"Others");
      }

      void output()
      {
	 cout<<"\n First Name:"<<fn;
	 cout<<"\n Last Name:"<<ln;
	 cout<<"\n Date of Birth:"<<dd<<"."<<mm<<"."<<yy;
	 cout<<"\n Password:"<<pass;
	 cout<<"\n Gender:"<<gen;
	 cout<<"\n Nationality:"<<coun;
	 cout<<"\n Email ID:"<<id;
      }

      char* ret_fn()
      {
	 return fn;
      }

      char* ret_id()
      {
	 return id;
      }

      char* ret_pass()
      {
	 return pass;
      }

      char* ret_sq()
      {
	 return sq;
      }

      char* ret_sa()
      {
	 return sa;
      }

};

class message:public account
{

      char from[10],to[10],sub[10],msg[500];

   public:

      void input1()
      {
	 strcpy(from,eid);
	 cout<<"\n From:"<<from;
	 cout<<"\n To:";
	 cin>>to;
	 cout<<"\n Subject:";
	 gets(sub);
	 cout<<"\n Message:";
	 gets(msg);
      }

      void output1()
      {
	 cout<<"\n From:"<<from;
	 cout<<"\n To:"<<to;
	 cout<<"\n Subject:"<<sub;
	 cout<<"\n Message:"<<msg;
	 cout<<"\n\n";
      }

      char* ret_from()
      {
	 return from;
      }

      char* ret_to()
      {
	 return to;
      }

}s;

void account::password()
{
   a:
   int k=0;
   char p[20],p1[20],p2[20],c=' ';
   cout<<"\n Enter Password:";

   while(c!=char(13))
   {
      c=getch();
      if(c!=char(13))
      {
	 if(c!='\b')
	 {
	    p1[k]=c;
	    cout<<"*";
	    k++;
	 }

	 else
	    k--;
      }
   }
   p1[k]='\0';
   strcpy(pass,p1);

   k=0;
   c=' ';
   cout<<"\n Confirm Password:";

   while(c!=char(13))
   {
      c=getch();
      if(c!=char(13))
      {
	 if(c!='\b')
	 {
	    p2[k]=c;
	    cout<<"*";
	    k++;
	 }
	 else
	    k--;
      }
   }
   p2[k]='\0';
   strcpy(p,p2);

   if(strcmp(pass,p)==0)
      cout<<"\n Password Confirmed!";

   else
   {
      cout<<"\n Passwords don't match! Try again";
      getch();
      clrscr();
      goto a;
   }
}

void signup()
{
   cout<<"\n NEW ACCOUNT";
   s.input();
   ofstream fo("email.dat",ios::binary|ios::app);
   fo.write((char*)&s,sizeof(s));
   fo.close();
}

void changepass()
{
   a:
   int k=0;
   char c,p[20];
   fstream f("email.dat",ios::binary|ios::in|ios::out|ios::app);

   cout<<"\n Enter your current password:";
   while(c!=char(13))
   {
      c=getch();
      if(c!=char(13))
      {
	 if(c!='\b')
	 {
	    p[k]=c;
	    cout<<"*";
	    k++;
	 }

	 else
	    k--;
      }
   }
   p[k]='\0';

   if(strcmp(::p,p)==0)
   {
      while(f.read((char*)&s,sizeof(s)))
      {
	 if(strcpy(eid,s.ret_id())==0)
	 {
	    s.password();
	    f.seekg(f.tellg()-sizeof(s));
	    f.write((char*)&s,sizeof(s));
	    cout<<"\n Password changed! \n";
	    break;
	 }
      }
   }

   cout<<"\n Password Incorrect!";
   cout<<"\n Press ENTER to retry.";
   cout<<"\n Press BACKSPACE to exit.";

   c=getch();
   if(c=='\b')
   {
      f.close();
      clrscr();
      return;
   }

   else if(c==char(13))
   {
      clrscr();
      f.close();
      goto a;
   }

   f.close();
}

int countmsg()
{
   ifstream fi("server.dat",ios::binary);
   int c=0;
   while(fi.read((char*)&s,sizeof(s)))
   {
      if(strcmp(eid,s.ret_to())==0)
	 c++;
   }
   fi.close();
   return c;
}


void compose()
{
   clrscr();
   ofstream fo("server.dat",ios::binary|ios::app);
   s.input1();
   fo.write((char*)&s,sizeof(s));
   fo.close();
}

void inbox()
{
   clrscr();
   ifstream fi("server.dat",ios::binary);
   char c;
   while(!fi)
   {
      cout<<"\n No mails received";
      return;
   }

   while(fi.read((char*)&s,sizeof(s)))
   {
      if(strcmp(eid,s.ret_to())==0)
	 s.output1();
   }
   cout<<"\n Press ENTER to retry";
   cout<<"\n Press BACKSPACE to exit.";
   c=getch();
   if(c==char(13))
      compose();
   fi.close();
}

void outbox()
{
   ifstream fi("server.dat",ios::binary);
   while(!fi)
   {
      cout<<"\n No mails found!";
      return;
   }
   while(fi.read((char*)&s,sizeof(s)))
   {
      if(strcmp(eid,s.ret_from())==0)
	 s.output1();
   }
   fi.close();
}

void searchinbox()
{
   ifstream fi("server.dat",ios::binary);
   char t[20],c;
   cout<<"\n SENDER ID:";
   cin>>t;
   while(fi.read((char*)&s,sizeof(s)))
   {
      if(strcmp(eid,s.ret_to())==0 && strcmp(t,s.ret_from())==0)
	 s.output1();
   }
   cout<<"\n Press ENTER to reply.";
   cout<<"\n Press BACKSPACE to exit.";
   c=getch();
   if(c==char(13))
      compose();
   fi.close();
}

void searchoutbox()
{
   ifstream fi("server.dat",ios::binary);
   char t[20];
   cout<<"\n Receiver ID:";
   cin>>t;
   while(fi.read((char*)&s,sizeof(s)))
   {
      if(strcmp(eid,s.ret_from())==0 && strcmp(t,s.ret_to())==0)
	 s.output1();
   }
}

void delacc()
{
   ifstream fi("email.dat",ios::binary);
   ofstream fo("temp.dat",ios::binary);
   a:
   clrscr();
   int k=0;
   char p[20],c=' ',r;
   cout<<"\n Enter Password:";
   while(c!=char(13))
   {
      c=getch();
      if(c!=char(13))
      {
	 if(c!='\b')
	 {
	    p[k]=c;
	    cout<<"*";
	    k++;
	 }

	 else
	    k--;
      }
   }
   p[k]='\0';

   if(strcmp(::p,p)==0)
   {
      while(fi.read((char*)&s,sizeof(s)))
      {
	 if(strcmp(eid,s.ret_id())==0)
	    cout<<"\n Your Account has been deleted!";

	 else
	    fo.write((char*)&s,sizeof(s));
      }
      remove("email.dat");
      rename("temp.dat","email.dat");
      fo.close();
      return;
   }

   cout<<"\n Password Incorrect!";
   cout<<"\n Press ENTER to retry.";
   cout<<"\n Press BACKSPACE to exit.";

   r=getch();
   if(r==char(13))
      goto a;
   else if(r=='\b')
      return;
   remove("email.dat");
   rename("temp.dat","email.dat");
   fo.close();
}

void home()
{
   clrscr();
   int flag=0;
   cout<<"\n\t\t\t WELCOME "<<ufn;
   cout<<"\n You have "<<countmsg()<<" new messages!";
   int ch;
   do
   {
      cout<<"\n1.Inbox \n2.Compose \n3.Sent \n4.Search Inbox \n5.Search Outbox \n6.Change Password \n7.Delete Account \n8.Logout";
      cout<<"\n Enter your choice:";
      cin>>ch;
      switch(ch)
      {
	 case 1:inbox();
		break;

	 case 2:compose();
		break;

	 case 3:outbox();
		break;

	 case 4:searchinbox();
		break;

	 case 5:searchoutbox();
		break;

	 case 6:changepass();
		break;

	 case 7:delacc();
		flag=1;
		break;

	 case 8:clrscr();
		strcpy(eid,NULL);
		strcpy(::p,NULL);
		flag=1;
		getch();
		clrscr();
		break;

	 default:cout<<"\n Enter the right choice!";
      }
   }while(flag==1);
}

void signin()
{
   a:
   int k=0;
   char c=' ',ch,id[20],p[20];
   ifstream fi("email.dat",ios::binary);
   clrscr();
   gotoxy(32,32);
   cout<<"\n SIGN IN";
   gotoxy(32,33);
   cout<<"\n Email ID:";
   cin>>id;
   gotoxy(32,34);
   cout<<"\n Password:";

   while(c!=char(13))
   {
      c=getch();
      if(c!=char(13))
      {
	 if(c!='\b')
	 {
	    p[k]=c;
	    cout<<"*";
	    k++;
	 }
	 else
	    k--;
      }
   }
   p[k]='\0';

   while(fi.read((char*)&s,sizeof(s)))
   {
      if(strcmp(id,s.ret_id())==0 && strcmp(p,s.ret_pass())==0)
      {
	    strcpy(ufn,s.ret_fn());
	    strcpy(eid,id);
	    strcpy(::p,p);
	    home();
	    return;
      }
   }
   cout<<"\n Email ID or password incorrect!";
   cout<<"\n Press ENTER to retry.";
   cout<<"\n Press BACKSPACE to exit.";
   c=getch();
   if(c=='\b')
   {
      fi.close();
      clrscr();
      return;
   }
   else if(c==char(13))
   {
      clrscr();
      fi.close();
      goto a;
   }
}

void main()
{
   int gd=DETECT,gm;
   initgraph(&gd,&gm,"c:\\tc\\bgi");
   setcolor(RED);
   settextstyle(0,HORIZ_DIR,7);
   outtextxy(200,210,"E");
   setcolor(WHITE);
   settextstyle(0,HORIZ_DIR,5);
   delay(2000);
   outtextxy(260,225,"MAIL");
   setfillstyle(SOLID_FILL,DARKGRAY);
   bar(200,280,440,290);
   char s[2];
   for(int i=200;i<=440;i+=1)
   {
      setfillstyle(SOLID_FILL,LIGHTGRAY);
      bar(200,280,i,290);
      setcolor(WHITE);
      settextstyle(0,HORIZ_DIR,1.5);
      outtextxy(200,270,"Loading...");
      delay(20);
   }
   setcolor(WHITE);
   closegraph();
   int ch;
   remove("email.dat");
   remove("server.dat");
   do
   {
      cout<<"\n\n1.SIGN UP \n2.SIGN IN \n3.EXIT";
      cout<<"\n Enter your choice:";
      cin>>ch;
      switch(ch)
      {
	 case 1:signup();
		break;

	 case 2:signin();
		break;

	 case 3:cout<<"\n Thank You!";
		break;
      }
   }while(ch!=3);
  getch();
}

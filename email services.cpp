#include<fstream>
#include<conio.h>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
char a[50];
int k=0; int z=0; int j=0; int i=0; int p=0;
class mails
{
    private:
        char mail[50]; char email[50]; char pass[50]; char sub[50]; char mess[100]; char emailid[50];
        char fname[20],lname[20],uname[50];
        char password[20]; char password1[20]; int dd,mm,yr;
        long double phoneno; char address[20];
        int otp,code; 
    public:
        void mail1()
        {
            cin>>mail;

        }
        void email1()
        {
            cin>>email;
        }
        void pass1(char c[50])
        {
            strcpy(pass,c);
        }
        void sub1()
        {
            cin>>sub;
        }
        void mess1()
        {
            cin>>mess;
        }
        void emailid1()
        {
            cin>>emailid;
        }
        void fname1()
        {
            cin>>fname;
        }
        void lname1()
        {
            cin>>lname;
        }
        void uname1()
        {
            cin>>uname;
        }
        void pd(char r[50])
        {
            strcpy(password,r);strcpy(password1,r);
        }
        void password2(char s[50])
        {
            strcpy(password,s);
        }
        void password3(char p[50])
        {
            strcpy(password1,p);
        }
        void date1()
        {
            cout<<"\n date:"; cin>>dd; cout<<"\n month:"; cin>>mm; cout<<"\n year:"; cin>>yr;
        }
        void pno1()
        {
            cin>>phoneno;
        }
        void address1()
        {
            cin>>address;
        }
        void otp1()
        {
            cin>>otp;
        }
        void code1(int y)
        {
            code=y;
        }
        char *username5()
        {
            return uname;
        }
        char *el5()
        {
            return email;
        }
        char *psd5()
        {
            return password;
        }
        char *firstname5()
        {
            return fname;
        }
        char *lastname5()
        {
            return lname;
        }
        char *password15()
        {
            return password1;
        }
}m[50];
class message
{
    char message[800],subject[60],sender[20],receiver[20]; 
    public:
        char *receive()
        {
            return receiver;
        }
        char *send()
        {
            return sender;
        }
        void disp()
        {
            cout<<"\n from :"<<sender; cout<<"\n to :"<<receiver; cout<<"\n subject :"<<subject; cout<<"\n message :"<<message;
        }
        void getmess()
        {   
            system("cls");
            cout<<"\n from :"<<::a; strcpy(sender,::a); cout<<"\n to:"; cin>>receiver;
            cout<<"\n subject :"; cin>>subject; cout<<"\n message:"; cin>>message;
            cout<<"\n \t\t\t\t\t send"; getch();
        }
};
void disp_gmail(); void signup(); void signin(); void display();
void password_change(); void compose();
void inbox(); void outbox();
int main()
{
    system("cls");
    remove("messag.dat");
    char str[100];
    cout<<"\n\n\n\n\n\n     google"; cout<<"\n\n\n\n    enter your search:"; cin.getline(str,100);
    disp_gmail(); getch();
    return 0;
}
void disp_gmail()
{
    system("cls");
    remove("message.dat");  
    int ch;
    g:
        cout<<"     GMAIL \n"; cout<<"\n    1.sign in \n"; cout<<"\n    2.sign up \n"; cout<<"\n    3.back \n"; cout<<"\n   enter your choice:"; cin>>ch;
        switch(ch)
        {   
            case 1:signin();break; 
            case 2:signup();break; 
            case 3:break;
            default:cout<<"enter the right choice"; 
            goto g;
        }
}
void signup()
{
    system("cls"); 
    int ch; 
    b:
        system("cls");
        cout<<"\n   create an account   \n"; 
        cout<<"\n FIRST NAME:";
        m[::i].fname1();
        cout<<"\n LAST NAME:"; m[::i].lname1();
        cout<<"\n USERNAME:"; m[::i].uname1();
        cout<<"\n CREATE A PASSWORD:";
        int k=0;
        char pass[20],c=' '; 
        while(c!=char(13))
        {
            c=getch(); 
            if(c!=char(13))
            {
                if(c!='\b')
                {
                    cout<<"*"; 
                    pass[k]=c; k++;
                }
                else
                {
                    k--;
                }
            }
        }
        pass[k]='\0'; m[::i].password2(pass);
        cout<<"\n\n CONFIRM YOUR PASSWORD:";
        int u=0;char as[20],h=' '; 
        while(h!=char(13))
        {
            h=getch(); 
            if(h!=char(13))
            {
                if(h!='\b')
                {  
                    cout<<"*"; as[u]=h; u++;
                }
                else
                {
                    u--;
                }
            }
        }
        as[u]='\0'; m[::i].password3(as);
        if(strcmp(m[::i].psd5(),m[::i].password15())==0)
        {
            cout<<"\n\n ENTER YOUR BIRTH DATE";m[::i].date1(); 
            cout<<"\n GENDER"; cout<<"\n1.male"; cout<<"\n2.female"; cout<<"\n3.others";
            cout<<"\n choose your gender:"; cin>>ch;
            cout<<"\n MOBLE PHONE NUMBER:+91-";m[::i].pno1();
            cout<<"\n LOCATION:"; m[::i].address1();
            cout<<"\n   continue    \n"; getch();
        }
        else
        {
            cout<<"\n password mismatch ";
            getch(); 
            goto b;
        }
        system("cls");
        cout<<"\n enter your otp:"; m[::i].otp1();
        cout<<"\n otp verified"; m[::i].code1(::i);
        ::i++;
        cout<<"\n   sign up"; getch();
        system("cls");
        signin();
}
void signin()
{
    system("cls"); 
    int j=0; 
    int i=0; 
    fg:
        system("cls");
        cout<<"\n\n\n   sign in"; 
        cout<<"\n ENTER YOUR EMAIL:";m[::z].email1();
        cout<<"\n ENTER YOUR PASSWORD:";
        int k=0;
        char pass[20],ch=' '; 
        while(ch!=char(13))
        {
            ch=getch(); 
            if(ch!=char(13))
            {
                if(ch!='\b')
                {
                    cout<<"*"; pass[k]=ch; k++;
                }
                else
                {
                    k--;
                }
            }
        }
        pass[k]='\0'; m[::z].pass1(pass);
        for(i=0;i<=::i;i++)
        {
            if(strcmp(m[::z].el5(),m[i].username5())==0)
            {
                j=i;
            }
        }
        if(strcmp(m[j].psd5(),pass)==0)
        {
            cout<<"\n\n sign in"; strcpy(::a,m[::z].el5());
            ::z++;
            ::j++;
            getch();
            system("cls"); 
            display();
        }
        else
        {
            cout<<"\n wrong password"; 
            getch();
            goto fg;
        }
}
void display()
{
    system("cls"); 
    int ch;
    for(int k=0;k<=::i;k++)
    {
        if(strcmp(::a,m[k].username5())==0)
        {
            cout<<"\n name : "<<m[k].firstname5()<<" "<<m[k].lastname5(); cout<<"\n email : "<<m[k].username5();break;
        }
    }
    cout<<"\n1.compose \n2.inbox \n3.password change \n4.outbox \n5.logout"; cout<<"\n enter your choice:";
    cin>>ch; switch(ch)
    {
        case 1:compose(); break;
        case 2:inbox();break;
        case 4:outbox();break; 
        case 3:password_change();break;
        case 5:cout<<"\n log out"; disp_gmail(); break;
        default:cout<<" ";
    }
}
void password_change()
{
    char sf[50]; system("cls");
    hj:
        cout<<"\n ENTER YOUR PASSWORD:";
        int u=0;
        char as[20],h=' ';
        while(h!=char(13))
        {
            h=getch(); 
            if(h!=char(13))
            {
                if(h!='\b')
                {
                    cout<<"*"; as[u]=h; u++;
                }
                else
                {
                    u--;
                }
            }
        }
        as[u]='\0';
        for(int i=0;i<=::i;i++)
        {
            if(strcmp(::a,m[i].username5())==0)
            {
                j=i; break;
            }
        }
        if(strcmp(as,m[j].password15())==0)
        {
            cout<<"\n\n enter new password:"; 
            int k=0;char pass[20],ch=' '; 
            while(ch!=char(13))
            {
                ch=getch(); 
                if(ch!=char(13))
                {
                    if(ch!='\b')
                    {
                        cout<<"*"; pass[k]=ch; k++;
                    }
                    else
                    {
                        k--;    
                    }
                }
            }
            pass[k]='\0';
            m[j].pd(pass);
        }
        else
        {
            cout<<"\n type the correct password"; goto hj;
        }
        display();
}
void compose()
{
    message m;
    ofstream fo("messag.dat",ios::binary|ios::app); m.getmess();
    fo.write((char*)&m,sizeof(m));
    fo.close(); 
    display();
}
void outbox()
{
    ifstream fi("messag.dat",ios::binary); 
    message m; 
    while(fi.read((char*)&m,sizeof(m)))
    {
        if(strcmp(::a,m.send())==0)
        {
            m.disp(); cout<<"\n";
        }
    }
    getch();
    fi.close(); display();
}
void inbox() 
{
    ifstream fi("messag.dat",ios::binary); 
    message m; 
    while(fi.read((char*)&m,sizeof(m)))
    {
        if(strcmp(::a,m.receive())==0)
        {
            m.disp(); cout<<"\n";
        }
    }
    getch();
    fi.close(); 
    display();
}

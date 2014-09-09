#include <iostream>
#include<fstream.>
#include<windows.h>
#include<string.h>
#include<stdio.h>

using namespace std;

char inp1[100],inp2[100],num1[100],num2[100],ans[100],FinalAnswer[100];int stuff;int len;
bool tag;

void gotoxy (int x, int y)
{
    COORD coord; // coordinates
    coord.X = x; coord.Y = y; // X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void rvrs(int ch)
{
    int j,k;
    if(ch==0)
    {

        len=strlen(inp1);
        for(j=len-1,k=0;j>=0;--j,++k)
            num1[k]=inp1[j];
        num1[k]='\0';

        len=strlen(inp2);
        for(j=len-1,k=0;j>=0;--j,++k)
            num2[k]=inp2[j];
        num2[k]='\0';
    }

    else if(ch==1)
    {
        len=strlen(ans);
        for(j=len-1,k=0;j>=0;--j,++k)
            FinalAnswer[k]=ans[j];
        FinalAnswer[k]='\0';
    }

}

void subtract()
{
    for(int i=0;num1[i]!='\0';++i)
    {
        if(num1[i]>num2[i])
        {
            stuff=(num1[i]-num2[i])%48;
            ans[i]=stuff+48;
        }
        else if(num1[i]<num2[i])
        {
            if(num1[i+1]!='\0')
                --num1[i+1];
            else if(num1[i+1]=='\0')
                tag=true;
            stuff=((num1[i]%48)+10)-(num2[i]%48);
            ans[i]=stuff+48;
        }
        else
            ans[i]=0+48;
    }

    rvrs(1);
}

void input()
{
    ifstream fin("File.txt",ios::in);
    fin.getline(inp1,100,'-');
    fin.getline(inp2,100);
    fin.close();
}

void display(int x)
{
    if(x==0)
    {
        cout<<"\n\n\n\n\n\t\t";
        for(int i=0;inp1[i]!='\0';++i)
        {
            cout<<inp1[i];Sleep(100);
        }
        cout<<"\n\t      - ";
        for(int i=0;inp2[i]!='\0';++i)
        {
            cout<<inp2[i];Sleep(100);
        }
        cout<<"\n\t\t";
        for(int i=(strlen(inp1)>strlen(inp2)?strlen(inp1):strlen(inp2));i>0;--i)
        {
            cout<<'-';Sleep(100);
        }
    }
    else if(x==1)
    {
        cout<<"\n\n\tAnswer: ";
        for(int i=0;FinalAnswer[i]!='\0';++i)
        {
            cout<<FinalAnswer[i];Sleep(100);
        }
    }
}

int main()
{
    cout << "Hello world!" << endl;
    input();    display(0);    rvrs(0);    subtract();
    cout<<endl;system("Pause");
    gotoxy(0,9);cout<<"                                   ";gotoxy(0,9);
    display(1);cout<<"\n\n\n\n\n";

    return 0;
}

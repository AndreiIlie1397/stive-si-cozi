#include<iostream>
#include <string.h>
using namespace std;
struct nod
{
    char info;
    nod *back;
};
nod *varf=NULL;
void push(char a, nod *&varf)
{
    nod *c;
    if(!varf)
    {
        varf=new nod;
        varf->info=a;
        varf->back=0;
    }
    else
    {
        c=new nod;
        c->back=varf;
        c->info=a;
        varf=c;
    }
}
char pop(nod *&varf)
{
    nod* c;
    c=varf;
    varf=varf->back;
    return c->info;
}
char peek(nod *&varf)
{
    if(varf==NULL)
        return 'x';
    return varf->info;
}
int paranteze(nod *&varf)
{
    int i, k=0;
    char s[1000];
    cout<<"Introduceti parantezele: "<<endl;
    cin>>s;
    for(i=0; i<strlen(s); i++)
    {
        if(s[i]=='(')
        {
            push(s[i],varf);
            k++;
        }
        else if(s[i]==')' && k==0)
        {
            cout<<"Sirul nu este corect parantezat"<<endl;
            cout<<"Pozitia primei paranteze care nu se inchide este: "<<i+1<<endl;
            return 0;
        }
        else
        {
            pop(varf);
            k--;
        }
    }
    if(peek(varf)=='x')
        cout<<endl<<"Sirul este corect parantezat"<<endl;
    if(peek(varf)=='(')
        cout<<endl<<"Sirul este corect parantezat"<<endl;
}
int main()
{
    paranteze(varf);
    return 0;
}

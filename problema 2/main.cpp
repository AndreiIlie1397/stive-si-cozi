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
void caracter(nod *&varf)
{
    int i;
    char s[1000];
    cout<<"Introduceti caracterele: "<<endl;
    cin>>s;
    for(i=0; i<strlen(s); i++)
    {
        if(peek(varf)=='x')
            push(s[i],varf);
        else if(peek(varf)!=s[i])
            pop(varf);
        else if(peek(varf)==s[i])
            push(s[i],varf);
    }
    if(peek(varf)=='x')
        cout<<endl<<"Numar egal de caractere."<<endl;
    else
        cout<<"Numar inegal de caractere."<<endl;
}
int main()
{
    caracter(varf);
    return 0;
}

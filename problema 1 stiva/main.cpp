#include<iostream>
using namespace std;
struct nod
{
    int info;
    nod *back;
};
nod *varf;
void push(int a, nod *&v)
{
    nod *c;
    if(!v)
    {
        v=new nod;
        v->info=a;
        v->back=0;
    }
    else
    {
        c=new nod;
        c->back=v;
        c->info=a;
        v=c;
    }
}
void afisare(nod *v)
{
    nod *c;
    c=v;
    while(c)
    {
        cout<<c->info<<" ";
        c=c->back;
    }
}
int peek(nod *&v)
{
    nod* c;
    c=v;
     cout<<endl<<"Elementul aflat in varful stivei este(nu elimina elementul din varf): ";
    return c->info;
}
int pop(nod *&v)
{
    if(!v)
    cout<<"Stiva este vida si nu mai avem ce elimina";
 else
    {
    nod* c;
    c=v;
    v=v->back;
     cout<<endl<<"Elementul aflat in varful stivei este(se elimina elementul din varf): ";
    return c->info;
}
}
bool empty(nod *&v)
{
    if(!v)
        return cout<<endl<<"Stiva este vida."<<endl;
    else
        return cout<<endl<<"In stiva sunt elemente."<<endl;
}
int search(int a, nod *&v)
{
    int gasit=0, poz=0;
    while((v!=NULL)&&(!gasit))
    {
        if(v->info==a)
            gasit=1;
        v=v->back;
        poz++;
    }
    if(gasit==0)
       return -1;
    else
        return poz-1;
}
int main()
{
    int n,a;
    cout<<"Introduceti numarul de noduri: ";
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cout<<"valoarea de adaugat in stiva: ";
        cin>>a;
        push(a, varf);
    }
    cout<<endl;
    afisare(varf);
    cout<<endl<<"Introduceti valoarea pe care doriti sa o adaugati in stiva: ";
    cin>>a;
    push(a,varf);
    afisare(varf);
    cout<<peek(varf);
    cout<<endl;
    afisare(varf);
    cout<<pop(varf);
    cout<<endl;
    afisare(varf);
    empty(varf);
    cout<<"Introduceti elementul pe care doriti sa il cautati in stiva: ";
    cin>>a;
    cout<<search(a, varf);
    cout<<endl;
    return 0;
}

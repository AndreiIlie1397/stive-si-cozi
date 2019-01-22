#include<iostream>
using namespace std;
struct nod
{
    int info;
    nod *next;
};
nod *varf, *sf;
void push(int a, nod *&v)
{
    nod *c;
    if(!v)
    {
        v=new nod;
        v->info=a;
        v->next=0;
        sf=v;
    }
    else
    {
        c=new nod;
        sf->next=c;
        c->info=a;
        sf=c;
        sf->next=0;
    }
}
void afisare(nod *v)
{
    nod *c;
    c=v;
    while(c)
    {
        cout<<c->info<<" ";
        c=c->next;
    }
}
int pop(nod *&v)
{
    nod* c;
  if(!v)
    cout<<"Coada este vida si nu mai avem ce elimina";
 else
    {
        c=v;
     v=v->next;
     cout<<endl<<"Primul element din coada este (se elimina primul element): ";
     return c->info;
     }
}
int peek(nod *&v)
{
    nod* c;
    c=v;
    cout<<endl<<"Primul element din coada este(nu elimina elementul din varf): ";
    return c->info;
}
bool empty(nod *&v)
{
    if(!v)
       return  cout<<endl<<"Coada este vida."<<endl;
    else
       return cout<<endl<<"In coada sunt elemente."<<endl;
}
int search(int a, nod *&v)
{
    int gasit=0, poz=0;
    while((v!=NULL)&&(!gasit))
    {
        if(v->info==a)
            gasit=1;
        v=v->next;
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
        cout<<"valoarea de adaugat in coada: ";
        cin>>a;
        push(a, varf);
    }
    cout<<endl;
    afisare(varf);
    cout<<endl<<"Introduceti valoarea pe care doriti sa o adaugati in coada: ";
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

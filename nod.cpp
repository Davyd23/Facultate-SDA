#include<iostream>
using namespace std;

struct nod{
int inf;
nod *adr;
};

nod* creare();
void parcurgere(nod *prim);
nod* elimina(nod *prim,int info);
nod* inserare(nod *prim,int info,int info1);
nod* insereaza_prim(nod *prim,int info);
int main()
{
    nod *cap;
    cap=creare();
    parcurgere(cap);

    int val;
    char activitate;
    cout<<"Ce facem cu lista?\n a-adauga element \n e-elimina element \n c-adauga un nou cap de lista \n n-nimic \n";cin>>activitate;
    while(activitate!='n' && activitate!='N'){
        switch(activitate){
            case 'a': case 'A': cout<<"ce valoare adaugam? :";cin>>val;
                                int val_adaugare;
                                cout<<"dupa ce valoare adaugam? :";cin>>val_adaugare;
                                cap=inserare(cap,val_adaugare,val);
                                cout<<"Lista are noua forma:"<<endl;
                                parcurgere(cap);
                                break;
            case'e': case 'E':  cout<<"ce valoare sa eliminam? :";
                                cin>>val;
                                cap=elimina(cap,val);
                                cout<<"valori ramase sunt:"<<endl;
                                parcurgere(cap);
                                break;
            case'c': case 'C':  cout<<"Ce info adaugam pe prima pozitie? :";
                                cin>>val;
                                cap=insereaza_prim(cap,val);
                                cout<<"lista are noua forma:"<<endl;
                                parcurgere(cap);
                                break;
            default:cout<<"Litera introdusa nu exista in lista de optiuni."<<endl;
        }
        cout<<"Ce facem cu lista?\n a-adauga element \n e-elimina element \n c-adauga un nou cap de lista\n n-nimic \n";cin>>activitate;
    }

    return 0;
}
nod* creare(){
    int inf;
    char a;
    nod *prim,*p,*q;
    prim=new nod;
    cout<<"Introduceti info din primul nod prim->inf=";
    cin>>inf;
    prim->inf=inf;
    prim->adr=NULL;
    q=prim;

    cout<<"Sfarsitul listei? [D/N] : ";
    cin>>a;

    while(a=='N' || a=='n')
        {
        p=new nod;cout<<"citeste informatia din p p->inf=";
        cin>>inf;
        p->inf=inf;
        p->adr=NULL;
        q->adr=p;
        q=p;
        cout<<"Sfarsitul listei? [D/N] : ";
        cin>>a;
    }
    return prim;
}

void parcurgere(nod *cap){
    nod *q;
    if(!cap){
        cout<<"lista este vida"<<endl;
        return ;
    }
    cout<<"Continutul listei este:"<<endl;
    for(q=cap;q;q=q->adr){
        cout<<q->inf<<" ";
    }
    cout<<endl;
}

nod* elimina(nod *prim ,int info){
    nod *q;

    while((*prim).inf==info){
        q=(*prim).adr;
        delete prim;
        prim=q;
    }

    q=prim;
    while(q->adr){
        if((q->adr)->inf==info){
            nod *r;
            r=q->adr;
            q->adr=r->adr;
            delete r;
        }else{
            q=q->adr;
        }
    }
    return prim;
}

nod* inserare(nod* prim,int info ,int info1){
    nod *c,*d;
    c=prim;

    while((c->adr) && (c->inf!=info)){
        c=c->adr;
    }
    d=new nod;
    d->inf=info1;
    if(!c->adr){
        d->adr=NULL;
        c->adr=d;
    }else{
        d->adr=c->adr;
    }
    c->adr=d;
    return prim;
}
nod* insereaza_prim(nod *prim,int info){
    nod *nou_prim=new nod;
    nou_prim->inf=info;
    nou_prim->adr=prim;
    return nou_prim;
}

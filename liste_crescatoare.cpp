#include<iostream>
using namespace std;

struct nod{
    int val;
    nod *urm;
    nod *ant;
};
struct lista{
    nod *cap;
    nod *coada;
};

nod* initializare(nod *ant,nod *urm,int val);
lista creare();
lista crescator(lista l);
void parcurgere(lista l);
lista unire_crescator(lista l1,lista l2);
lista unire(lista l1,lista l2);

int main(){
    cout<<"Se vor crea 2 liste care se vor ordona automat!"<<endl;
    cout<<endl<<"Lista 1"<<endl;
    lista l1=creare();
    l1=crescator(l1);
    cout<<"Lista 1 ordonata crescator este:"<<endl;
    parcurgere(l1);

    cout<<endl<<"Lista 2"<<endl;
    lista l2=creare();
    l2=crescator(l2);
    cout<<"Lista 2 ordonata crescator este:"<<endl;
    parcurgere(l2);

    lista l;

    char a;
    cout<<endl<<"Ce uniune a listelor facem?\n c-unim listele cu valorile in ordine crescatoare\n u-unim listele in ordine: ";cin>>a;
    while(a!='n' && a!='N'){
        switch(a){
            case'c':case'C':    l=unire_crescator(l1,l2);
                                cout<<"Listele s-au combinat in lista urmatoare:";
                                parcurgere(l);
                                break;
            case'u':case'U':    cout<<"Lista 1 este prima?[D/N]: ";cin>>a;
                                if(a=='D'||a=='d'){
                                    l=unire(l1,l2);
                                    cout<<endl<<"Unirea listelor in ordinea aleasa este:"<<endl;
                                    parcurgere(l);
                                }else if (a=='N'||a=='n'){
                                    l=unire(l2,l1);
                                    cout<<endl<<"Unirea listelor in ordinea aleasa este:"<<endl;
                                    parcurgere(l);
                                }else{
                                cout<<"nu stiu aceasta ordine!"<<endl;
                                }
                                break;

        }
        cout<<endl<<"Ce uniune a listelor facem?\n c-unim listele cu valorile in ordine crescatoare\n u-unim listele in ordine\n n-nimic: ";cin>>a;
    }
    return 0;
}

lista creare(){
    lista l;
    int val;

    cout<<"Introduceti valoarea din cap: ";cin>>val;
    nod *cap=initializare(NULL,NULL,val);

    l.cap=cap;

    nod *p=cap;
    char a;
    cout<<"Mai introducem valori in lista?[D/N]: ";cin>>a;
    while(a=='D' || a=='d'){

        cout<<"Ce valoare introducem in noul nod?: ";cin>>val;
        nod *nou=initializare(p,NULL,val);
        p->urm=nou;
        p=p->urm;

        cout<<"Mai introducem valori in lista?[D/N]: ";cin>>a;
    }

    l.coada=p;

    return l;
}

lista crescator(lista l){
    // interschimbarea valori din cap cu cea mai mica din lista
    nod *p=l.cap;

    while(p){
        if(p->val<(l.cap)->val){
            int aux=p->val;
            p->val=(l.cap)->val;
            (l.cap)->val=aux;
        }
        p=p->urm;
    }

    char schimbare=1;

    while(schimbare){
        schimbare=0;
        p=l.cap;

        while(p->urm){
            if(p->val>(p->urm)->val){
                int aux=p->val;
                p->val=(p->urm)->val;
                (p->urm)->val=aux;

                schimbare=1;
            }
            p=p->urm;
        }
    }

    return l;
}

void parcurgere(lista l){
    for(nod *p=l.cap;p;p=p->urm){
        cout<<p->val<<" ";
    }
    cout<<endl;
}

lista unire_crescator(lista l1,lista l2){

    lista l;
    nod *cap1=l1.cap;
    nod *cap2=l2.cap;
    int val;


    if(cap1->val<cap2->val){
        val=cap1->val;
        cap1=cap1->urm;
    }else{
        val=cap2->val;
        cap2=cap2->urm;
    }

    nod *cap=initializare(NULL,NULL,val);
    l.cap=cap;

    nod *p=l.cap;

    while (cap1 && cap2){
        nod *nou=initializare(p,NULL,0);
        p->urm=nou;

        if(cap1->val<cap2->val){
            nou->val=cap1->val;
            cap1=cap1->urm;
        }else{
            nou->val=cap2->val;
            cap2=cap2->urm;
        }
        p=p->urm;
    }

    while(cap1){
        nod *nou=initializare(p,NULL,cap1->val);

        p->urm=nou;
        p=p->urm;

        cap1=cap1->urm;
    }
    while(cap2){
        nod *nou=initializare(p,NULL,cap2->val);

        p->urm=nou;
        p=p->urm;

        cap2=cap2->urm;
    }

    l.coada=p;

    return l;
}

nod* initializare(nod *ant,nod *urm,int val){
    nod *nou=new nod;
    nou->ant=ant;
    nou->urm=urm;
    nou->val=val;

    return nou;
}

lista unire(lista l1,lista l2){
    lista l;
    nod *cap=initializare(NULL,NULL,(l1.cap)->val);
    l.cap=cap;

    nod *p=cap;
    nod *cap1=(l1.cap)->urm;

    while(cap1){
        nod *nou=initializare(p,NULL,cap1->val);
        p->urm=nou;
        p=p->urm;

        cap1=cap1->urm;
    }

    nod *cap2=l2.cap;

    while(cap2){
        nod *nou=initializare(p,NULL,cap2->val);
        p->urm=nou;
        p=p->urm;

        cap2=cap2->urm;
    }

    l.coada=p;

    return l;
}

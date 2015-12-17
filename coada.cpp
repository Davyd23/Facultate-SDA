#include<iostream>
using namespace std;

struct nod{
    int val;
    nod *urm;
    nod *ant;
};
struct coada{
    nod *cap;
    nod *capat;
};

coada creare();
coada adauga(coada coada);
coada elimina(coada coada);
void parcurgere(coada coada);

int main(){
    coada coada=creare();

    char a;
    cout<<endl<<"Ce facem cu aceasta coada?\n a-adauga element\n e-elimina element\n p-parcurge\n n-nimic: ";cin>>a;
    while(a!='n' && a!='N'){
        switch(a){
            case'a':case'A': coada=adauga(coada);break;
            case'e':case'E': coada=elimina(coada);break;
            case'p':case'P': parcurgere(coada);break;
        }
        cout<<endl<<"Ce facem cu aceasta coada?\n a-adauga element\n e-elimina element\n p-parcurge\n n-nimic: ";cin>>a;
    }

    return 0;
}

coada creare(){
    nod *cap=new nod;
    cout<<"Introduceti valoare initiala din coada: ";cin>>cap->val;
    cap->urm=NULL;
    cap->ant=NULL;

    coada coada;
    coada.cap=cap;
    coada.capat=cap;

    nod*p=cap;

    char a;
    cout<<"Mai adaugam elemente? [D/N]:";cin>>a;

    while(a=='D' || a=='d'){
        nod *nou=new nod;
        cout<<"Introduceti valoare din coada: ";cin>>nou->val;
        nou->urm=NULL;
        nou->ant=p;
        p->urm=nou;
        p=p->urm;

        cout<<"Mai adaugam elemente? [D/N]:";cin>>a;
    }
    coada.capat=p;

    return coada;
}
void parcurgere(coada coada){
    if(coada.cap==NULL){
        cout<<endl<<"coada este goala!"<<endl;
        return;
    }
    cout<<endl;
    for(nod *p=coada.cap;p;p=p->urm){
        cout<<p->val<<" ";
    }
    cout<<endl;
}
coada elimina(coada coada){
    if(!(coada.cap)){
        cout<<endl<<"coada este goala!"<<endl;
        return coada;
    }
    if(!((coada.cap)->urm)){
        coada.cap=NULL;
        coada.capat=NULL;

        cout<<endl<<"coada a devenit vida!"<<endl;
        return coada;
    }

    coada.cap=(coada.cap)->urm;
    (coada.cap)->ant=NULL;

    return coada;
}
coada adauga(coada coada){
    nod *nou=new nod;
    cout<<endl<<"introduceti valoarea pt. noul element: ";cin>>nou->val;
    nou->urm=NULL;

    if(!coada.cap){
        nou->ant=NULL;
        coada.cap=nou;
        coada.capat=nou;
        return coada;
    }

    nou->ant=coada.capat;
    (coada.capat)->urm=nou;
    coada.capat=nou;

    return coada;
}

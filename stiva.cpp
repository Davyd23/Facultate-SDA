#include<iostream>
using namespace std;

struct nod{
    int val;
    nod *urm;
    nod *ant;
};
struct stiva{
    nod *cap;
    nod *coada;
};

stiva creare();
stiva adauga(stiva stiva);
stiva elimina(stiva stiva);
void parcurgere(stiva stiva);

int main(){
    stiva stiva=creare();

    char a;
    cout<<endl<<"Ce facem cu aceasta stiva?\n a-adauga element\n e-elimina element\n p-parcurge\n n-nimic: ";cin>>a;
    while(a!='n' && a!='N'){
        switch(a){
            case'a':case'A': stiva=adauga(stiva);break;
            case'e':case'E': stiva=elimina(stiva);break;
            case 'p':case'P': parcurgere(stiva);break;
        }
        cout<<endl<<"Ce facem cu aceasta stiva?\n a-adauga element\n e-elimina element\n p-parcurge\n n-nimic: ";cin>>a;
    }


    return 0;
}

stiva creare(){
    nod *cap=new nod;
    cout<<"Introduceti valoare initiala din stiva: ";cin>>cap->val;
    cap->urm=NULL;
    cap->ant=NULL;

    stiva stiva;
    stiva.cap=cap;
    stiva.coada=cap;

    nod*p=cap;

    char a;
    cout<<"Mai adaugam elemente? [D/N]:";cin>>a;

    while(a=='D' || a=='d'){
        nod *nou=new nod;
        cout<<"Introduceti valoare din stiva: ";cin>>nou->val;
        nou->urm=NULL;
        nou->ant=p;
        p->urm=nou;
        p=p->urm;

        cout<<"Mai adaugam elemente? [D/N]:";cin>>a;
    }
    stiva.coada=p;

    return stiva;
}
void parcurgere(stiva stiva){
    if(stiva.cap==NULL){
        cout<<endl<<"stiva este goala!"<<endl;
        return;
    }
    cout<<endl;
    for(nod *p=stiva.coada;p;p=p->ant){
        cout<<p->val<<" ";
    }
    cout<<endl;
}
stiva adauga(stiva stiva){
    nod *nou=new nod;
    cout<<endl<<"Introduceti valoare din stiva: ";cin>>nou->val;
    nou->urm=NULL;

    if(stiva.cap==NULL){
        nou->ant=NULL;
        stiva.cap=nou;
        stiva.coada=nou;
        return stiva;
    }

    nou->ant=stiva.coada;
    (stiva.coada)->urm=nou;
    stiva.coada=nou;

    return stiva;
}
stiva elimina(stiva stiva){
    if(!(stiva.coada)){
        cout<<endl<<"Stiva este vida!"<<endl;
        return stiva;
    }
    if(!((stiva.coada)->ant)){
        stiva.coada=NULL;
        stiva.cap=NULL;

        cout<<"Oficial stiva este vida!"<<endl;

        return stiva;
    }

    stiva.coada=(stiva.coada)->ant;
    (stiva.coada)->urm=NULL;

    return stiva;
}

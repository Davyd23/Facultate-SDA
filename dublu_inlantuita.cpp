#include<iostream>
#include<string>
using namespace std;

struct nod{
    int inf;
    nod *ant;
    nod *urm;
};
struct lista{
    nod *prim;
    nod *ultim;
};

lista creare();
nod* init_nod(nod *ant,nod *urm);
lista elimina_nod_de_la_cap(lista l);
lista elimina_nod_de_la_coada(lista l);
lista elimina_cap(lista l);
lista elimina_coada(lista l);
lista adauga_nod_final(lista l);
lista adauga_nod_cap(lista l);
lista adauga_nod(lista l);
lista lista_nula(lista l,int inf);
lista ordoneaza_crescator(lista l);
lista ordoneaza_descrescator(lista l);
void parcurgere_lista(lista tabel);
void parcurgere_lista_invers(lista tabel);
int main(){

    cout<<"Vom crea o lista\n";
    lista l=creare();
    parcurgere_lista(l);


    char a;
    cout<<"Ce doriti sa faceti cu lista?:\n "
    <<"e-eliminam element\n"
    <<"a-adaugam element\n"
    <<"p-parcurge lista \n"
    <<"o-ordoneaza lista :";cin>>a;
    cout<<endl;
    while(a!='n' && a!='N'){
            switch(a){
            case 'e':case'E':   cout<<endl<<" Ce tip de eliminare facem?:\n e-elimina nod de la cap \n c-elimina nod de la coada \n"
                        <<" a-elimina doar capul \n b-elimina doar coada: ";cin>>a;
                        cout<<endl;
                        switch(a){
                            case 'e':case'E':l=elimina_nod_de_la_cap(l);break;
                            case 'c':case'C':l=elimina_nod_de_la_coada(l);break;
                            case 'a':case'A':l=elimina_cap(l);break;
                            case 'b':case'B':l=elimina_coada(l);break;
                        }
                        break;
            case 'a':case'A':   cout<<endl<<" Unde vreti sa v-o punem?: \n a-adaugare la cap \n c-adaugare la coada \n e-adaugare dupa element: ";cin>>a;
                                cout<<endl;
                                switch(a){
                                    case 'a':case'A':l=adauga_nod_cap(l);break;
                                    case 'c':case'C':l=adauga_nod_final(l);break;
                                    case 'e':case'E':l=adauga_nod(l);break;
                                }break;
            case 'p':case 'P':  cout<<endl<<"Ce tip de parcurgere facem?: \n d-directa \n i-inversa: ";cin>>a;
                                cout<<endl;
                                switch(a){
                                    case 'd':case'D':parcurgere_lista(l);break;
                                    case 'i':case'I':parcurgere_lista_invers(l);break;
                                }break;
            case 'o':case 'O':  cout<<endl<<"Ce tip de ordonare facem?:\n c-crescatoare \n d-descrescatoare: ";cin>>a;
                                switch(a){
                                    case 'c':case'C':ordoneaza_crescator(l);break;
                                    case 'd':case'D':ordoneaza_descrescator(l);break;
                                }break;
            default:cout<<"aceasta operatiune nu exista!";
        }
        cout<<endl<<"Ce doriti sa faceti cu lista?:\n "
    <<"e-eliminam element\n"
    <<"a-adaugam element\n"
    <<"p-parcurge lista \n"
    <<"o-ordoneaza lista \n n-nimic: ";cin>>a;
    cout<<endl;
    }

    return 0;
}

lista creare(){
    lista tabel;
    nod *prim,*p,*fin;
    char a;
    prim=init_nod(NULL,NULL);
    cout<<"Introduceti informatia din capul listei: ";cin>>prim->inf;
    fin=prim;

    cout<<"Introduceti informatie pt nodul urmator ? [D/N]: ";cin>>a;
    while(a=='d' || a=='D'){

        p=init_nod(fin,NULL);
        cout<<"Introduceti informatia din nod: ";cin>>p->inf;
        fin->urm=p;
        fin=fin->urm;

        cout<<"Introduceti informatie pt nodul urmator ? [D/N]: ";cin>>a;
    }
    tabel.prim=prim;
    tabel.ultim=fin;

    return tabel;

}
nod* init_nod(nod *ant,nod *urm){
    nod* val=new nod;
    val->ant=ant;
    val->urm=urm;
    return val;
}
void parcurgere_lista(lista tabel){
    if(!tabel.prim){
        cout<<"Lista este vida."<<endl;
        return;
    }

    cout<<"Lista parcursa are valorile:"<<endl;
    for(nod *p=tabel.prim;p;p=p->urm){
        cout<<p->inf<<" ";
    }
    cout<<endl;
}
void parcurgere_lista_invers(lista tabel){
    if(!tabel.ultim){
        cout<<"Lista este vida."<<endl;
        return;
    }

    cout<<"Lista parcursa invers are valorile:"<<endl;
    for(nod *p=tabel.ultim;p;p=p->ant){
        cout<<p->inf<<" ";
    }
    cout<<endl;
}
lista elimina_nod_de_la_cap(lista l){
    int inf;
    int sem=0;
    nod *prim=l.prim;
    nod *aux;
    if(!prim){
        cout<<"lista este goala."<<endl;
        return l;
    }
    cout<<"Atentie! Se elimina o singura valoare de la cap spre coada.\nCe valoare eliminam?: ";cin>>inf;

    if(!prim->urm && inf==prim->inf){                      //verificare in caz ca exista o singura valoare
        cout<<"Lista a devenit vida!"<<endl;
        l.prim=NULL;
        l.ultim=NULL;
        return l;
    }

    if(prim && inf==prim->inf){                             //verificare in caz ca valoarea ceruta la eliminare este chiar prima valoare din lista
        aux=prim->urm;
        aux->ant=NULL;
        l.prim=aux;
        return l;
    }
    aux=prim->urm;
    while(aux){
        if(aux->inf==inf){
            sem++;
            if(aux->urm){
                nod *ant=aux->ant;   //declararea acestor noduri nu este necesara , dar o fac pt usurinta intelegeri codului
                nod *urm=aux->urm;
                ant->urm=urm;
                urm->ant=ant;
            }else{
                l.ultim=aux->ant;
                (aux->ant)->urm=NULL;
            }
            break;
        }
        aux=aux->urm;
    }
    if(sem==0){
        cout<<endl<<"Valoarea ceruta pt. a fi eliminata nu exista!"<<endl<<endl;
    }
    return l;
}
lista elimina_nod_de_la_coada(lista l){
    int inf;
    int sem=0;
    nod *ult=l.ultim;
    nod *aux;
    if(!ult){
        cout<<"lista este goala."<<endl;
        return l;
    }
    cout<<"Atentie! Se elimina o singura valoare de la coada spre cap.\nCe valoare eliminam?: ";cin>>inf;

    if(!ult->ant && inf==ult->inf){                            //verificare in caz ca exista o singura valoare
        cout<<"lista a devenit vida!"<<endl;
        l.prim=NULL;
        l.ultim=NULL;
        return l;
    }
    if(ult && inf==ult->inf){                //verificare in caz ca valoarea ceruta la eliminare este chiar ultima valoare din lista
        aux=ult->ant;
        aux->urm=NULL;
        l.ultim=aux;
        return l;
    }
    aux=ult->ant;
    while(aux){
        if(aux->inf==inf){
            sem++;
            if(aux->ant){
                nod *ant=aux->ant;   //declararea acestor noduri nu este necesara , dar o fac pt usurinta intelegeri codului
                nod *urm=aux->urm;
                ant->urm=urm;
                urm->ant=ant;
            }else{
                l.prim=aux->urm;
                (aux->urm)->ant=NULL;
            }
            break;
        }
        aux=aux->ant;
    }
    if(sem==0){
        cout<<endl<<"Valoarea ceruta pt. a fi eliminata nu exista!"<<endl<<endl;
    }
    return l;
}
lista elimina_cap(lista l){
    if(!l.prim){
        cout<<"Lista este goala!"<<endl;
        return l;
    }
    if(!(l.prim)->urm){
        l.prim=NULL;
        l.ultim=NULL;
        return l;
    }

    l.prim=(l.prim)->urm;
    (l.prim)->ant=NULL;
    return l;
}
lista elimina_coada(lista l){
    if(!l.ultim){
        cout<<"Lista este goala!"<<endl;
        return l;
    }
    if(!(l.ultim)->ant){
        l.prim=NULL;
        l.ultim=NULL;
        return l;
    }

    l.ultim=(l.ultim)->ant;
    (l.ultim)->urm=NULL;
    return l;
}
lista adauga_nod_cap(lista l){
    nod *cap=new nod;
    cout<<"Introduceti informatia pt. noul cap: ";cin>>cap->inf;
    if(l.prim==NULL){
        return lista_nula(l,cap->inf);
    }
    cap->ant=NULL;
    cap->urm=l.prim;
    (l.prim)->ant=cap;
    l.prim=cap;

    return l;
}
lista adauga_nod_final(lista l){
    nod *cap=new nod;
    cout<<"Introduceti informatia pt. ultimul nod: ";cin>>cap->inf;
    if(l.prim==NULL){
        return lista_nula(l,cap->inf);
    }
    cap->urm=NULL;
    cap->ant=l.ultim;
    (l.ultim)->urm=cap;
    l.ultim=cap;

    return l;
}
lista adauga_nod(lista l){
    int add;
    int inf;
    cout<<"Ce valoare adaugam?: ";cin>>inf;
    if(l.prim==NULL){
        return lista_nula(l,inf);
    }
    cout<<"Se adauga o noua informatie dupa prima informatie gasita(de la cap spre coada,"
    <<" daca nu se gaseste acea informatie se va adauga la capatul listei)"
    <<" care corespunde celei cautate.\nDupa ce informatie adaugam?: ";cin>>add;
    for(nod *p=l.prim;p;p=p->urm){
        if(p->inf==add){
            nod *adaugat=new nod;
            adaugat->inf=inf;
            adaugat->urm=p->urm;
            if(p->urm){
                (p->urm)->ant=adaugat;
            }
            adaugat->ant=p;
            p->urm=adaugat;

            return l;
        }
    }

    nod *adaugat=new nod;
    adaugat->urm=NULL;
    adaugat->inf=inf;
    adaugat->ant=l.ultim;
    (l.ultim)->urm=adaugat;
    l.ultim=adaugat;
    return l;
}
lista lista_nula(lista l,int inf){
   nod *cap=new nod;
   cap->inf=inf;
   cap->ant=NULL;
   cap->urm=NULL;

   l.prim=cap;
   l.ultim=cap;

   return l;
}
lista ordoneaza_crescator(lista l){
    nod *prim=l.prim;
    nod *p;
    int schimbare=1;
    while(schimbare){
            schimbare=0;
      for(p=prim;p->urm;p=p->urm){
            if(p->inf>(p->urm)->inf){
                int aux=p->inf;
                p->inf=(p->urm)->inf;
                (p->urm)->inf=aux;
                schimbare=1;
            }
        }
    }
    return l;
}
lista ordoneaza_descrescator(lista l){
    nod *prim=l.prim;
    nod *p;
    int schimbare=1;
    while(schimbare){
            schimbare=0;
      for(p=prim;p->urm;p=p->urm){
            if(p->inf<(p->urm)->inf){
                int aux=p->inf;
                p->inf=(p->urm)->inf;
                (p->urm)->inf=aux;
                schimbare=1;
            }
        }
    }
    return l;
}


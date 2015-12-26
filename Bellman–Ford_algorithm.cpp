#include<iostream>
#include<limits.h>
#include<conio.h>
using namespace std;
struct arce{
    int nod1;
    int nod2;
    int val;
    arce *urm;
};
struct graf{
    int nr_varfuri;
    int *val_varf;
    bool *varf_schimbat;
    arce **arcs;
};

graf creare();
void calculare(graf mGraf);
graf schimbare(graf mGraf, int nod);
void afisare(graf mGraf);   //functie pt debugging
graf schimbare_bool(graf mGraf,bool boolean);

bool modificare=false;// sa nu verificam fiecare nod, daca e true un nod si-a midificat valoarea

int main(){

    cout<<"Atentie! Graf neorientat."<<endl;
    graf mGraf=creare();
    calculare(mGraf);
    return 0;

}
graf creare(){
    cout<<"Cate noduri are graful?: ";
    int noduri;
    cin>>noduri;

    graf mGraf;
    mGraf.nr_varfuri=noduri;
    mGraf.val_varf=new int[noduri+1];
    for(int i=0;i<=noduri;i++){
        mGraf.val_varf[i]=INT_MAX;
    }

    mGraf.arcs=new arce*[noduri+1]; // ca poz 0 sa fie null

    for(int i=0;i<=noduri;i++){
         mGraf.arcs[i]=NULL;
    }

    char a;
    for(int i=1;i<=noduri;i++){

        arce *cap=new arce;
        cap->nod1=i;
        cap->nod2=i;
        cap->val=0;
        cap->urm=NULL;
        if(mGraf.arcs[i]){
            arce *next=mGraf.arcs[i];
            while(next->urm){
                next=next->urm;
            }

            next->urm=cap;
        }else{
            mGraf.arcs[i]=cap;
        }

        arce *p=cap;
        cout<<"Exista o arca intre nodul "<<i<<" si alt nod?[D/N]: ";cin>>a;

        while(a=='d' || a=='D'){
            arce *nou=new arce;
            nou->nod1=i;
            cout<<"Cu ce nod are legatura?: ";cin>>nou->nod2;
            while(nou->nod2<=i || nou->nod2>noduri){
                cout<<"Eroare, nodul nu exista, introduceti altul: ";cin>>nou->nod2;
            }
            cout<<"Ce valoare are aceasta arca?: ";cin>>nou->val;
            nou->urm=NULL;

            p->urm=nou;
            p=p->urm;

            arce *nou2=new arce;
            nou2->nod1=p->nod2;
            nou2->nod2=p->nod1;
            nou2->val=p->val;
            nou2->urm=NULL;

            if(mGraf.arcs[p->nod2]){
                arce *next=mGraf.arcs[p->nod2];
                while(next->urm){
                    next=next->urm;
                }
                next->urm=nou2;
            }else{
                mGraf.arcs[p->nod2]=nou2;
            }

            cout<<"Mai are legaturi?[D/N]: ";cin>>a;

        }
    }
    return mGraf;
}

void calculare(graf mGraf){

    int cap,coada;
    cout<<"Din ce nod plecam?: ";cin>>cap;
    while(cap<1 || cap>mGraf.nr_varfuri){
        cout<<"Grafurile sunt notate cu valori intre 1 si "<<mGraf.nr_varfuri<<" introduceti din nou un nod de plecare: ";cin>>cap;
    }
    cout<<"In ce nod ajungem?: ";cin>>coada;
    while(coada<1 || coada>mGraf.nr_varfuri){
        cout<<"Grafurile sunt notate cu valori intre 1 si "<<mGraf.nr_varfuri<<" introduceti din nou un nod de sosire: ";cin>>coada;
    }

    mGraf.val_varf[cap]=0;

    if(cap==coada){
        cout<<"Costul drumului este 0!";
        return;
    }
    modificare=true;
    while(modificare){
        modificare=false;
        mGraf=schimbare_bool(mGraf,false); // sa stim daca am modificat in aceasta iteratie nodul sau nu
        mGraf.varf_schimbat[cap]=true;
        mGraf=schimbare(mGraf,cap);
    }


    if(mGraf.val_varf[cap]==INT_MAX){
        cout<<"Din nodul "<<cap<<" nu se poate ajunge in nodul "<<coada<<endl;
    }else{
        cout<<"Ca sa ajungem din "<<cap<<" in "<<coada<<" costul minim este: "<<mGraf.val_varf[coada];
    }
}

graf schimbare(graf mGraf, int nod){

    arce *arc=mGraf.arcs[nod];

    cout<<"Valoarea varfului este: "<<mGraf.val_varf[nod]<<endl;


    while(arc){
        cout<<arc->val<<endl;
        if(!mGraf.varf_schimbat[arc->nod2] && mGraf.val_varf[nod]+arc->val<mGraf.val_varf[arc->nod2]){
            mGraf.varf_schimbat[arc->nod2]=true;
            modificare=true;
            mGraf.val_varf[arc->nod2]=mGraf.val_varf[nod]+arc->val;
            mGraf=schimbare(mGraf,arc->nod2);
        }
        arc=arc->urm;
    }

    return mGraf;
}

void afisare(graf mGraf){
    for(int i=1;i<=mGraf.nr_varfuri;i++){
        cout<<"Arcele nodului "<<i<<" sunt:"<<endl;
        arce *arc=mGraf.arcs[i];
        while(arc){
            cout<<arc->val<<endl;
            arc=arc->urm;
        }
    }
}

graf schimbare_bool(graf mGraf,bool boolean){
    mGraf.varf_schimbat=new bool[mGraf.nr_varfuri+1];
    for(int i=0;i<=mGraf.nr_varfuri;i++){
        mGraf.varf_schimbat[i]=boolean;
    }

    return mGraf;
}

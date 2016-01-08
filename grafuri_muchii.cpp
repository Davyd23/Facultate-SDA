#include<iostream>
using namespace std;

struct nod{
    int nod1;
    int nod2;
    nod *urm;
};
struct graf{
    nod *cap;
    nod *coada;
};

graf adaugare(graf vechi,int cap,int leg);
void parcurgere(graf gr);

int main(){
    graf gr;

    nod *special=new nod;
    special->urm=NULL;

    gr.cap=special;
    gr.coada=special;

    int noduri;
    cout<<"Cate noduri are graful?: ";cin>>noduri;

    if(noduri>0){
            special->nod1=1;
            special->nod2=1;
    }

    for(int i=0;i<noduri;i++){
        char a;
        if(i!=0){
            gr=adaugare(gr , i+1 , i+1);
        }
        cout<<"Nodul "<<i+1<<" are legaturi [D/N]: ";cin>>a;

        while(a=='d' || a=='D'){
            int leg;
            cout<<"Cu cine are legatura?: ";cin>>leg;
            if(leg<=noduri && leg>i+1){

                gr = adaugare(gr,i+1,leg);

            }else{
                cout<<"Nu avem acest nod!"<<endl;
            }
            cout<<"Nodul "<<i+1<<" are legaturi [D/N]: ";cin>>a;
        }
    }
    parcurgere(gr);

    return 0;
}

graf adaugare(graf vechi,int cap,int leg){

    nod *nou=new nod;
    nou->nod1=cap;
    nou->nod2=leg;
    nou->urm=NULL;

    (vechi.coada)->urm=nou;
    vechi.coada=nou;

    return vechi;
}

void parcurgere(graf gr){

    for(nod *p=gr.cap;p;p=p->urm){
        cout<<"("<<p->nod1<<","<<p->nod2<<")";
        if(p->urm){
            cout<<",";
        }
    }
}


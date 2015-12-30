#include<iostream>
using namespace std;

struct list{
    int val;
    list *next;
};

list** creare(int n);
void parcurgere(list** muchii,int n);

int main(){
    int n;
    cout<<"Cate noduri exista in acest graf?: ";cin>>n;

    list **muchii=creare(n);

    cout<<"Listele de adiacenta sunt:"<<endl;
    parcurgere(muchii,n);


    return 0;
}

list** creare(int n){

    list ** muchii=new list*[n];

    char a;
    for(int i=0;i<n;i++){

        int* valori=new int[n];  //ver daca nu a fost adaugat deja altfel adauga valoarea k, iar in vector k-1 devine=1
        for(int j=0;j<n;j++){
            valori[j]=0;
        }

        list *cap=NULL;
        int leg;

        cout<<"Nodul "<<i+1<<" are muchii?[D/N]: ";cin>>a;

        if(a=='d'|| a=='D'){
            cap=new list;
            cout<<"Cu cine are legatura?: ";cin>>leg;
            while(leg<=i+1 || leg>n){
                cout<<"Acest nod nu poate fi acesat,introduceti altul?[D/N]: ";cin>>a;

                if(a=='n' || a=='N'){
                    break;
                }
                cout<<"Introduceti nodul: ";cin>>leg;
            }
            cap->val=leg;
            cap->next=NULL;

            if(a=='n'|| a=='N')cap=NULL;

            valori[leg-1]=1;
        }
        muchii[i]=cap;
        list *p=cap;

        if(a=='d' || a=='D'){
        cout<<"Nodul "<<i+1<<" mai are muchii?[D/N]: ";cin>>a;
        }

        while(a=='d'|| a=='D'){
            cout<<"Cu cine are legatura?: ";cin>>leg;
            while(leg<=i+1 || leg>n || valori[leg-1]==1){

                cout<<"Acest nod nu poate fi acesat,introduceti altul?[D/N]: ";cin>>a;

                if(a=='n' || a=='N'){
                    break;
                }
                cout<<"Introduceti nodul: ";cin>>leg;
            }
            if(a=='n' || a=='N'){
                break;
            }
            valori[leg-1]=1;

            list *nou=new list;
            nou->val=leg;
            nou->next=NULL;

            p->next=nou;
            p=nou;

            cout<<"Nodul "<<i+1<<" mai are muchii?[D/N]: ";cin>>a;
        }
    }

    return muchii;
}
void parcurgere(list** muchii,int n){
    for(int i=0;i<n;i++){
        cout<<"L("<<i+1<<")={";

        list *p=muchii[i];
        while(p){
            cout<<p->val;
            if(p->next)cout<<",";
            p=p->next;
        }
        cout<<"}"<<endl;
    }
}

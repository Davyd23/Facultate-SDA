#include<iostream>
#include<string>
#include<sstream>

using namespace std;

struct nod{
    int inf;
    nod *urm;
};

int** creare(int n);
void parcurgere(int **matrice,int n);
void afisare(int ** matrice,int n);

string parcurgere_adancime(int **matrice,int n,int linie,string drum);
string parcurgere_latime(int **matrice,int n,int linie,string drum);

int main(){
    cout<<"Vom crea un graf orientat"<<endl;
    cout<<"cate elemente are graful?: ";
    int n;
    cin>>n;

    int **matrice=creare(n);

    afisare(matrice,n);

    parcurgere(matrice,n);

    return 0;
}

int** creare(int n){

    int **matrice=new int*[n];
    for(int i=0;i<n;i++){
        matrice[i]=new int[n];

        for(int j=0;j<n;j++){
            matrice[i][j]=0;
        }
    }

    for(int i=0;i<n;i++){
        char a;
        cout<<"Nodul "<<i+1<<" are legaturi?[D/N]: ";cin>>a;

        while(a=='D' || a=='d'){
            int leg;
            cout<<"Cu cine?: ";cin>>leg;

            if(leg<1 || leg>n){
                cout<<"Eroare, nodul nu exista!"<<endl;
            }else{
                matrice[i][leg-1]=1;
            }

            cout<<"Mai are legaturi?: ";cin>>a;
        }
    }

    return matrice;
}
string parcurgere_adancime(int **matrice,int n,int linie,string drum){
    //adaugarea linie ca valoare in string
    int val=linie+1;
    string add;
    ostringstream convert;
    convert<<val;
    add=convert.str();
    drum+=add;
    //drum+=(linie+1);   //for fun comment above and decoment this , values 1-6

    for(int i=0;i<n;i++){
        if(matrice[linie][i]==1){

            string s;
            int nr=(i+1);
            ostringstream convert;
            convert<<nr;
            s=convert.str();
            //cout<<"Intrat pe "<<i+1<<endl;
            if((drum.find(s)==string::npos)){
                //cout<<"iesit pe"<<i+1<<endl;
                drum=parcurgere_adancime(matrice,n,i,drum);
            }
        }
    }
    return drum;
}

void parcurgere(int **matrice,int n){
    string drum="";
    cout<<"intre noduri nu exista spatii deoarece c++ nu se intelege prea bine cu spatiile...."<<endl;
    for(int i=0;i<n;i++){
        drum="";
        drum=parcurgere_adancime(matrice,n,i,drum);
        cout<<"Parcurgerea in adancime din nodul "<<i+1<<": "<<drum<<endl;
    }

    cout<<endl<<endl;

    for(int i=0;i<n;i++){

        string s;
        int nr=(i+1);
        ostringstream convert;
        convert<<nr;
        s=convert.str();
        drum=s;

        drum=parcurgere_latime(matrice,n,i,drum);
        cout<<"Parcurgerea in latime din nodul "<<i+1<<": "<<drum<<endl;
    }
}

void afisare(int ** matrice,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<matrice[i][j]<<" ";
        }
        cout<<endl;
    }
}

string parcurgere_latime(int **matrice,int n,int linie,string drum){

    nod *cap=new nod;
    cap->urm=NULL;
    cap->inf=-1;

    nod *p=cap;

    for(int i=0;i<n;i++){
        if(matrice[linie][i]==1){
            string s;
            int nr=(i+1);
            ostringstream convert;
            convert<<nr;
            s=convert.str();

            if(drum.find(s)==string::npos){

                nod *nou=new nod;
                nou->inf=-1;
                nou->urm=NULL;

                p->inf=i;
                p->urm=nou;
                p=p->urm;

                drum+=s;
            }
        }
    }
    p=cap;

    while(p->inf!=-1){
        drum=parcurgere_latime(matrice,n,p->inf,drum);
        p=p->urm;
    }

    return drum;
}

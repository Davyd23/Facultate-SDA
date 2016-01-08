#include<iostream>
#include<string>
#include<cstring>
#include<map>
using namespace std;

struct nod{
    int val=0;
    int poz;
    bool closed=false;
    nod *ant;
    nod *urm;
};
struct capete{
    nod *cap;
    nod *coada;
};

capete conversion(string s);
int value(char c);
void verificare(capete extreme,string s);
void afisare(int poz1,int poz2,string s);


int main(){
    string expresie;
    cout<<"Introduceti expresia de verificat(Atentie fara spatii): ";cin>>expresie;

    capete extreme=conversion(expresie);
    verificare(extreme,expresie);


    return 0;
}

capete conversion(string s){
    char *c=new char[s.length()];
    strcpy(c,s.c_str());

    nod *cap=new nod;

    for(int i=0;i<s.length();i++){
        if(value(c[i])!=0){
            cap->val=value(c[i]);
            cap->poz=i;
            cap->closed=false;
            cap->ant=NULL;
            cap->urm=NULL;
            break;
        }
    }
    nod *p=cap;
    if(cap->val!=0){
        for(int i=(cap->poz)+1;i<s.length();i++){
            if(value(c[i])!=0){
                nod *nou=new nod;
                nou->poz=i;
                nou->val=value(c[i]);
                nou->closed=false;
                nou->urm=NULL;
                nou->ant=p;

                p->urm=nou;
                p=p->urm;
            }
        }
    }

    capete extreme;
    extreme.cap=cap;
    extreme.coada=p;

    return extreme;
}

int value(char c){
    map<char,int> brackets;
    brackets[')']=-1;
    brackets[']']=-2;
    brackets['}']=-3;
    brackets['(']=1;
    brackets['[']=2;
    brackets['{']=3;

    return brackets[c];
}

void verificare(capete extreme,string s){
    if((extreme.cap)->val<0){
        cout<<"Prima paranteza nu este corecta!"<<endl;
        afisare(-1,(extreme.cap)->poz,s);
        return;
    }
    if((extreme.coada)->val>0){
        cout<<"Ultima paranteza nu este corecta!"<<endl;
        afisare(-1,(extreme.coada)->poz,s);
        return;
    }


    nod *cap=extreme.cap;

    while(cap){
        if((cap->val)>0){
            cap=cap->urm;
        }else{
            nod *invers=cap->ant;
            while(invers && invers->closed){
                invers=invers->ant;
            }
            if(invers && (cap->val+invers->val)==0){
                invers->closed=true;
                cap->closed=true;
            }

            //verificare inchis corect
            if(!cap->closed){
                cout<<"Boss, avem o problema aici:"<<endl;

                if(invers){
                    afisare(invers->poz,cap->poz,s);
                }else{
                    afisare(-1,cap->poz,s);
                    cout<<"nu are cu cine sa se inchida."<<endl;
                }

                return;
            }
            cap=cap->urm;
        }
    }

    cout<<"toate parantezele sunt corecte!"<<endl;
    afisare(-1,-1,s);

}

void afisare(int poz1,int poz2,string s){
    for(int i=0;i<poz1;i++){
        cout<<" ";
    }
    if(poz1!=-1){
        cout<<"|";
    }
    for(int i=poz1+1;i<poz2;i++){
        cout<<" ";
    }
    if(poz2!=-1)cout<<"|"<<endl;

    cout<<s<<endl;
}

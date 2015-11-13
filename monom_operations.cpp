#include<iostream>

using namespace std;
char var;
struct monom{
    char var;
    int grad;
    int coeficient;
    monom *mon;
};
monom* creaza();
void parcurgere(monom *start);
monom* ordonare(monom *mon);
monom* inmultire(monom *ec1,monom *ec2);
monom* adunare(monom *ec1,monom *ec2);
monom* scadere(monom *ec1,monom *ec2);
monom* aduna_termeni(monom *mon);
monom* copiere_valori_poz_curent(monom *mon);
monom* sterge_zero(monom *mon);

int main(){
    cout<<"In acest program , vom face operatii cu 2 ecuati."<<endl;
    cout<<"De ce variabila depind ecuatiile?: ";cin>>var;
    cout<<endl<<"Introduceti prima ecuatie:"<<endl;
    monom *ec1=creaza();
    cout<<"ec 1 ordonata este: ";
    ec1=ordonare(ec1);
    parcurgere(ec1);
    cout<<endl<<"Introduceti cea de-a 2 ecuatie:"<<endl;
    monom *ec2=creaza();
    cout<<"ec 2 ordonata este: ";
    ec2=ordonare(ec2);
    parcurgere(ec2);

    char operatie;
    cout<<endl<<"Ce operatie facem ?\n a-adunare \n s-scadere \n i-inmultire \n n-nimic \n";cin>>operatie;
    while(operatie!='n' && operatie!='N'){
        switch(operatie){
            case 'a':case 'A':{ monom *adunare_fc=adunare(ec1,ec2);
                                cout<<"Adunarea celor 2 functi returneaza: "<<endl;
                                parcurgere(adunare_fc);
                                break;
                              }
            case 'i':case 'I':{ cout<<"Inmultirea celor 2 functi returneaza functia:"<<endl;
                                monom *inmultire_functii=inmultire(ec1,ec2);
                                parcurgere(inmultire_functii);
                                break;
                              }
            case 's':case 'S':{ cout<<"Scaderea celor 2 functi returneaza functia:"<<endl;
                                monom *scadere_functii=scadere(ec1,ec2);
                                parcurgere(scadere_functii);
                                break;
                              }
            default:            cout<<"Operatia nu exista!";
        }
        cout<<endl<<"Ce operatie facem ?\n a-adunare \n s-scadere \n i-inmultire \n n-nimic \n";cin>>operatie;
    }

    return 0;
}

monom* creaza(){
    monom *ecuatie=new monom;
    ecuatie->var=var;
    cout<<"Ce grad are? :";cin>>ecuatie->grad;
    cout<<"Ce coeficient are? :";cin>>ecuatie->coeficient;
    ecuatie->mon=NULL;
    monom *q=ecuatie;

    char continuare;
    cout<<"Ecuatia mai are termeni? [D/N]:";cin>>continuare;

    while (continuare=='D' || continuare=='d'){
        monom *p=new monom;
        p->mon=NULL;
        p->var=var;
        cout<<"Ce grad are? :";cin>>p->grad;
        cout<<"Ce coeficient are? :";cin>>p->coeficient;

        q->mon=p;
        q=q->mon;

        cout<<"Ecuatia mai are termeni? [D/N]:";cin>>continuare;
    }
    return ecuatie;
}

void parcurgere(monom *start){
    monom *q;
    if(!start){
        cout<<"nu avem o ecuatie(monom), adica =0."<<endl;
        return ;
    }
    int nr_elm=0;
    for(q=start;q;q=q->mon){
        if(q->coeficient>0 && nr_elm>0){
            cout<<"+";
        }
        if(q->coeficient!=1){
            cout<<q->coeficient;
        }
        switch(q->grad){
            case 0:break;
            case 1:cout<<q->var;break;
            default:cout<<q->var<<"^"<<q->grad;
        }
        nr_elm++;
    }
    cout<<endl;
}

monom* ordonare(monom *mon){
    int ordonat=1;
    monom *q;
    while(ordonat==1){
        ordonat=0;
        for(q=mon;q;q=q->mon){
            if(q->mon){
               if(q->grad<(q->mon)->grad){
                    ordonat=1;

                    int aux=q->grad;
                    q->grad=(q->mon)->grad;
                    (q->mon)->grad=aux;

                    aux=q->coeficient;
                    q->coeficient=(q->mon)->coeficient;
                    (q->mon)->coeficient=aux;
               }
            }
        }
    }
    return mon;
}

monom* inmultire(monom *ec1,monom *ec2){

    monom *copie_ec1,*copie_ec2;
    monom *ecRez=new monom;
    monom *parcurgere=ecRez;
    int contor=0;

    for(copie_ec1=ec1;copie_ec1;copie_ec1=copie_ec1->mon){
        for(copie_ec2=ec2;copie_ec2;copie_ec2=copie_ec2->mon){
            if(contor==0){
                parcurgere->var=copie_ec1->var;
                parcurgere->grad=copie_ec1->grad+copie_ec2->grad;
                parcurgere->coeficient=copie_ec1->coeficient*copie_ec2->coeficient;
                parcurgere->mon=NULL;
            }else{
                monom *p=new monom;
                p->var=copie_ec1->var;
                p->grad=copie_ec1->grad+copie_ec2->grad;
                p->coeficient=copie_ec1->coeficient*copie_ec2->coeficient;
                p->mon=NULL;

                parcurgere->mon=p;
                parcurgere=parcurgere->mon;
            }

            contor=1;
        }
    }


    return aduna_termeni(ecRez);
}
monom* adunare(monom *ec1,monom *ec2){
    monom *ecuatie=copiere_valori_poz_curent(ec1);

    monom *q=ecuatie;
    for(ec1=ec1->mon;ec1;ec1=ec1->mon){
        monom *p=copiere_valori_poz_curent(ec1);
        q->mon=p;
        q=q->mon;
    }
    for(ec2;ec2;ec2=ec2->mon){
        monom *p=copiere_valori_poz_curent(ec2);
        q->mon=p;
        q=q->mon;
    }
    return aduna_termeni(ecuatie);
}
monom* scadere(monom *ec1,monom *ec2){
    monom *ecuatie=copiere_valori_poz_curent(ec1);

    monom *q=ecuatie;
    for(ec1=ec1->mon;ec1;ec1=ec1->mon){
        monom *p=copiere_valori_poz_curent(ec1);
        q->mon=p;
        q=q->mon;
    }
    for(ec2;ec2;ec2=ec2->mon){
        monom *p=copiere_valori_poz_curent(ec2);
        p->coeficient*=-1;
        q->mon=p;
        q=q->mon;
    }
    return aduna_termeni(ecuatie);
}

monom* aduna_termeni(monom *mon){

    monom *p;
    mon=ordonare(mon);

    monom *ecRetur=copiere_valori_poz_curent(mon);
    monom *ecuatie=ecRetur;

    for(p=mon;p;p=p->mon){
        if(p->mon){
            if(p->grad==(p->mon)->grad){
                ecuatie->coeficient+=(p->mon)->coeficient;
            }else{
                if(ecuatie->coeficient!=0){
                    monom *urm=copiere_valori_poz_curent(p->mon);

                    ecuatie->mon=urm;
                    ecuatie=ecuatie->mon;
                }else{
                    ecuatie->coeficient=(p->mon)->coeficient;
                    ecuatie->grad=(p->mon)->grad;
                }
            }
        }

    }
    if(ecuatie->coeficient==0){
        ecRetur=sterge_zero(ecRetur);
    }
    return ecRetur;
}
monom* copiere_valori_poz_curent(monom *mon){
    monom *urm=new monom;
    urm->var=mon->var;
    urm->grad=mon->grad;
    urm->coeficient=mon->coeficient;
    urm->mon=NULL;

    return urm;
}
monom* sterge_zero(monom *mon){
    if(mon->coeficient==0){
        return NULL;
    }
    for(monom *p=mon;p;p=p->mon){
        if(p->mon){
            if(p->mon->coeficient==0){
                p->mon=NULL;
            }
        }
    }
    return mon;
}

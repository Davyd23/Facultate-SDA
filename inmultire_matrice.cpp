#include<iostream>
using namespace std;


int** creare(int linii,int coloane);
void afiseaza(int **matr,int linii,int coloane);
int** inmultire(int **matr1,int linii1,int coloane1,int **matr2,int linii2,int coloane2);
int main(){
    int linii1,coloane1,linii2,coloane2;

    cout<<"Vom inmultii 2 matrice."<<endl;
    cout<<"Introduceti nr. de linii ale primei matrici: ";cin>>linii1;
    cout<<"Introduceti nr. de coloane ale primei matrici(ale caror valoare va fi nr "
    <<"de linii ale celei de-a 2 matrici: ";cin>>coloane1;

    int **matr1=creare(linii1,coloane1);

    cout<<"Matricea A are forma:"<<endl;
    afiseaza(matr1,linii1,coloane1);



    linii2=coloane1;
    cout<<"Introduceti nr de coloane ale celei dea 2 matrice: ";cin>>coloane2;
    int **matr2=creare(linii2,coloane2);

    cout<<"Matricea B are forma:"<<endl;
    afiseaza(matr2,linii2,coloane2);

    cout<<endl<<"Inmultirea celor 2 matrice are ca rezultat"<<endl;
    int **matr=inmultire(matr1,linii1,coloane1,matr2,linii2,coloane2);
    afiseaza(matr,linii1,coloane2);
return 0;
}
int** creare(int linii,int coloane){
    int **matr=new int*[linii];
    for(int i=0;i<linii;i++){
        matr[i]=new int[coloane];
    }

    for(int i=0;i<linii;i++){
        for(int j=0;j<coloane;j++){
            cout<<"Introduceti elementul a["<<i+1<<"]["<<j+1<<"]=";cin>>matr[i][j];
        }
    }

    return matr;
}
void afiseaza(int **matr,int linii,int coloane){
    for(int i=0;i<linii;i++){
        for(int j=0;j<coloane;j++){
            cout<<matr[i][j]<<" ";
        }
        cout<<endl;
    }
}
int** inmultire(int **matr1,int linii1,int coloane1,int **matr2,int linii2,int coloane2){
    //coloane1==linii2
    int **matr=new int*[linii1];
    for(int i=0;i<linii1;i++){
        matr[i]=new int[coloane2];
    }

    for(int i=0;i<linii1;i++){
        for(int k=0;k<coloane2;k++){
            matr[i][k]=0;
        }
    }

    for(int i=0;i<linii1;i++){
        for(int k=0;k<coloane2;k++){
            for(int j=0;j<coloane1;j++){
                matr[i][k]+=matr1[i][j]*matr2[j][k];
            }
        }
    }
    return matr;
}

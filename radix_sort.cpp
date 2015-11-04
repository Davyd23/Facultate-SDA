#include<iostream>
#include<string>
#include<math.h>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <sstream>
#include <iomanip>
using namespace std;
int ARRAY_SIZE;
int i,j;




void afisare_sir(float array[]){
    for(int i=0;i<ARRAY_SIZE;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}
int nr_cifre(int val){
    int cifre=1;
    while(val/10!=0){
        cifre++;
        val/=10;
    }
    return cifre;
}

void afisare_pozitie_schimbata_radixSort(int** array ,int nr_coloane , int pozInit , int pozFin){

    for(int i=0;i<ARRAY_SIZE;i++){
        if(array[i][0]==1){
            cout<<"+ ";
        }else{
            cout<<"- ";
        }
        for(int j=1;j<nr_coloane;j++){
            cout<<array[i][j]<<" ";
        }
        if(i==pozInit || i==pozFin){
            cout<<"  --";
        }
        cout<<endl;
    }
    cout<<endl;

}
void radixSort(float* dValues){

    string *sValues=new string[ARRAY_SIZE];
    for(int i=0;i<ARRAY_SIZE;i++){
        stringstream ss;
        ss<<dValues[i];
        sValues[i]=ss.str();
    }

    int valoare_modificare=1;  // pentru a muta virgula
    for(int i=0;i<ARRAY_SIZE;i++){
        for(int j=1;j<sValues[i].size();j++){
            if(sValues[i][j]=='.'){
                if(valoare_modificare<pow(10,sValues[i].size()-j-1)){
                    valoare_modificare=pow(10,sValues[i].size()-j-1);
                    setprecision(sValues[i].size()-j-1);
                }
                break;
            }
        }
    }
    int *values=new int[ARRAY_SIZE];
    for(int i=0;i<ARRAY_SIZE;i++){
        values[i]=dValues[i] * valoare_modificare;
    }

    int max_digits=1;

    for(int i=0;i<ARRAY_SIZE;i++){
        if(max_digits<nr_cifre(*(values+i))){
            max_digits=nr_cifre(*(values+i));
        }
    }
    max_digits++; // pentru a trece semnul , 0 negativ , 1 pozitiv
    int** matrix=new int*[ARRAY_SIZE];

    for(int i=0;i<ARRAY_SIZE;i++){
        matrix[i]=new int[max_digits];
    }

    for(int i=0;i<ARRAY_SIZE;i++){
        if(values[i]>=0){
        matrix[i][0]=1;
        }else{
        matrix[i][0]=0;
        values[i]*=-1;
        }
        for(int j=max_digits-1;j>=1;j--){
            matrix[i][j]=(*(values+i))%10;
            *(values+i)/=10;
        }
    }

    int* hold=new int[max_digits];
    int indicator_schimbare=1;
    int j=max_digits-1;

    while(j!=-1){
            //aranjam matricea folosind bubble sort
        indicator_schimbare=0;

        for(int i=0;i<ARRAY_SIZE-1;i++){
            if(matrix[i][j]>matrix[i+1][j]){
                indicator_schimbare=1;

                cout<<endl<<"Aranjam matricea dupa coloana "<<j+1<<":\n";
                afisare_pozitie_schimbata_radixSort(matrix,max_digits,i,i+1);

                hold=matrix[i];
                matrix[i]=matrix[i+1];
                matrix[i+1]=hold;
            }
        }

        if(!indicator_schimbare){
            j--;
        }
    }
    cout<<endl<<"Matricea ordonata are forma:\n";
    afisare_pozitie_schimbata_radixSort(matrix,max_digits,-1,-1);

    int positive=0;
    float* orderedVector=new float[ARRAY_SIZE];
    for(int i=0;i<ARRAY_SIZE;i++){

            if(positive==0){
                if(matrix[i][0]==1){
                    positive=1;
                    for(int j=0;j<i;j++){
                        int crestere=1;
                        orderedVector[i-1-j]=0;
                        for(int k=max_digits-1;k>=1;k--){
                            orderedVector[i-1-j]+=matrix[j][k]*crestere;
                            crestere*=10;
                        }
                        orderedVector[i-1-j]/=valoare_modificare;
                        orderedVector[i-1-j]*=-1;
                    }
                }
            }

            if(positive==1){
                int crestere=1;
                orderedVector[i]=0;
                for(int j=max_digits-1;j>=1;j--){
                    orderedVector[i]+=matrix[i][j]*crestere;
                    crestere*=10;
                }
                orderedVector[i]/=valoare_modificare;
            }
    }

    cout<<endl<<"Sirul aranjat are forma:\n";
    afisare_sir(orderedVector);
}

int main(){
	cout<<"introduce-ti marimea matrici: ";cin>>ARRAY_SIZE;
	float* array=new float[ARRAY_SIZE];
	cout<<"Introduce-ti elementele matrici: \n";

	for(int i=0;i<ARRAY_SIZE;i++){

         	cout<<"a["<<i+1<<"]=";cin>>array[i];
        }
    cout<<endl<<"Sirul aranjat are forma:\n";
    afisare_sir(array);
	 radixSort(array);

    //salvez ca double si il transform in string

    return 0;
}

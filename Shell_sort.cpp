#include<iostream>

#define ARRAY_SIZE 10

using namespace std;

void shellSort(int array[]){

    int pas=ARRAY_SIZE/2;

    while(pas!=0){  // pas descrescator

        for(int k=0;k<pas;k++){ // daca ajunge pe valoare pasului deja a trecut prin acea sectiune din vector

                for(int i=pas+k;i<ARRAY_SIZE;i+=pas){
                    if(array[i]<array[i-pas]){
                        int aux=array[i];
                        array[i]=array[i-pas];
                        array[i-pas]=aux;
                    }
                }
        }
        pas--;
    }

    if(array[0]>array[1]){
        int aux=array[0];
        array[0]=array[1];
        array[1]=aux;
    }

    for(int i=0;i<ARRAY_SIZE;i++){
        cout<<array[i]<<" ";
    }
}

int main(){

int array[ARRAY_SIZE]={10,6,8,7,6,9,5,4,8,2};

shellSort(array);

return 0;
}

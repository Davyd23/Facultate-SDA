#include<iostream>

#define ARRAY_SIZE 10

using namespace std;

void shellSort(int array[]){

    int pas=ARRAY_SIZE/2;
    int j,i;

    while(pas>0){  // pas descrescator

        for(int k=0;k<pas;k++){ // daca ajunge pe valoare pasului deja a trecut prin acea sectiune din vector

                for(i=pas+k;i<ARRAY_SIZE;i+=pas){

                    for(j=i-pas;j>=0;j-=pas){
                        if(array[j]<array[i]){
                            break;
                        }
                    }

                        int aux=array[i];

                        for(int p=i;p>j;p-=pas){
                            array[p]=array[p-pas];
                        }
                        array[j+pas]=aux;
                }
            }
            pas/=2;
        }



        for(i=0;i<ARRAY_SIZE;i++){
            cout<<array[i]<<" ";
        }
    }




int main(){

int array[ARRAY_SIZE]={10,9,8,7,6,5,4,3,2,1};

shellSort(array);

return 0;
}

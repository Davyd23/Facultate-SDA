#include<iostream>

using namespace std;

int* bubble_sort(int array[]){

bool indicator_schimbare=true;

    while(indicator_schimbare){

        indicator_schimbare=false;
        for(int j=1;j<array[0]-2;j++){
            if(array[j]>array[j+1]){

                indicator_schimbare=true;

                int aux=array[j];
                array[j]=array[j+1];
                array[j+1]=aux;
            }
        }
    }
    return array;

}

int main(){  //pt testare

int array[10]={10,1,2,6,5,4,4,2,1,8};  // +1 element la inceput (array[0]) care indica marimea vectorului ( peste care vom sarii)

int* orderedArray=bubble_sort(array);

for(int i=1;i<10;i++){

    cout<<*(orderedArray+i)<<" ";
}

return 0;
}

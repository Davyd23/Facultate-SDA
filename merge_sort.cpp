#include<iostream>

#define ARRAY_SIZE 8
using namespace std;

int* mergeSplitMerge(int* arr1,int elm1,int* arr2,int elm2){
    int startArr1=0;
    int startArr2=0;

    int* orderedPointer=new int[elm1+elm2];

    for(int i=0;i<elm1+elm2;i++){

        if(startArr1<elm1 && (startArr2>=elm2 || *(arr1+startArr1)<*(arr2+startArr2))){

            *(orderedPointer+i)=*(arr1+startArr1);
            startArr1++;

        }else{
            *(orderedPointer+i)=*(arr2+startArr2);
            startArr2++;
        }
    }
    return orderedPointer;
}

int* mergeSplit(int array[],int start,int end){

    if(end-start<1){
        return &array[start];
    }

    int middle=start+(end-start)/2;

    int* firstArr=mergeSplit(array,start,middle);

    int* secondArr=mergeSplit(array,middle+1,end);

    return mergeSplitMerge(firstArr,middle-start+1,secondArr,end-middle);

}

 void mergeSort(int array[]){

    int* orderedArray=mergeSplit(array,0,ARRAY_SIZE-1);

    for(int i=0;i<ARRAY_SIZE;i++){
        cout<<*(orderedArray+i)<<" ";
    }
}

int main(){

int array[ARRAY_SIZE]={3,33,2,2,55,23,22,1};

mergeSort(array);

return 0;
}

#include<iostream>

using namespace std;
int ARRAY_SIZE;

int totalDigits(int value){
    int size=1;
    while(value/10!=0){
        size++;
        value/=10;
    }
    return size;
}

void radix_sort(int* values){
    int max_digits=1;
    for(int i=0;i<ARRAY_SIZE;i++){
        if(max_digits<totalDigits(*(values+i))){
            max_digits=totalDigits(*(values+i));
        }
    }
    int** matrix=new int*[ARRAY_SIZE];

    for(int i=0;i<ARRAY_SIZE;i++){
        matrix[i]=new int[max_digits];
    }

    for(int i=0;i<ARRAY_SIZE;i++){
        for(int j=max_digits-1;j>=0;j--){
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

                hold=matrix[i];
                matrix[i]=matrix[i+1];
                matrix[i+1]=hold;
            }
        }

        if(!indicator_schimbare){
            j--;
        }
    }
    int* orderedVector=new int[ARRAY_SIZE];
    for(int i=0;i<ARRAY_SIZE;i++){
            int crestere=1;
            orderedVector[i]=0;
        for(int j=max_digits-1;j>=0;j--){
            orderedVector[i]+=matrix[i][j]*crestere;
            crestere*=10;
        }
    }

    for(int i=0;i<ARRAY_SIZE;i++){
        cout<<orderedVector[i]<<" ";
    }
}


int main(){

    cout<<"introduceti marimea vectorului: ";cin>>ARRAY_SIZE;
    int* vec=new int[ARRAY_SIZE];

    cout<<"introduceti valorile matrici\n" ;
    for(int i=0;i<ARRAY_SIZE;i++){
        cout<<"a["<<i+1<<"]=";cin>>*(vec+i);
    }

    radix_sort(vec);

    return 0;
}

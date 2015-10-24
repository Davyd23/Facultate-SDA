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
    int j=max_digits-1;
    int i=0;
    int sort_value=0;
    int last_position_changed=0;
    int* hold=new int[max_digits];

    while(i!=ARRAY_SIZE-1 || j!=0){
        if(matrix[i][j]==sort_value){
            hold=matrix[i];
            matrix[i]=matrix[last_position_changed];
            matrix[last_position_changed]=hold;
            last_position_changed++;
        }
        i++;
        if(i==ARRAY_SIZE){
            if(sort_value==9){
                j--;
                i=0;
                sort_value=0;
                last_position_changed=0;
            }else{
                i=0;
                sort_value++;
            }
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

#include<iostream>
using namespace std;

void parcurgere(int **graf,int marime);
int main(){

    int marime;

    cout<<"cate element are graful?: ";cin>>marime;
    int **graf=new int*[marime];
    for(int i=0;i<marime;i++){
        graf[i]=new int[marime];
    }


    for(int i=0;i<marime;i++){
        for(int j=0;j<marime;j++){
            graf[i][j]=0;
        }
        graf[i][i]=1;
    }

    for(int i=0;i<marime;i++){
        char a;
        cout<<"Nodul "<<i+1<<" are legaturi [D/N]: ";cin>>a;

        while(a=='D' || a=='d'){
            int leg;
            cout<<"Cu cine are legatura?: ";cin>>leg;
            leg--;
            if(leg<marime){
                graf[i][leg]=1;
                graf[leg][i]=1;
            }else{
                cout<<"Nu avem acest nod!"<<endl;
            }

            cout<<"Mai avem legaturi?[D/N]: ";cin>>a;
        }
    }

    cout<<"Matricea de legaturi este:"<<endl;
    parcurgere(graf,marime);


    return 0;
}

void parcurgere(int **graf,int marime){
    for(int i=0;i<marime;i++){
        for(int j=0;j<marime;j++){
                cout<<graf[i][j]<<" ";
        }
        cout<<endl;
    }
}

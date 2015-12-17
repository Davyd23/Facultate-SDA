#include<iostream>
#include<math.h>
using namespace std;
bool prim(int n);
int main(){
    int nr;
    cout<<"Introduceti un nr. pt. al verifica daca este prim: ";cin>>nr;
    if(prim(nr)){
        cout<<"Nr. este prim!"<<endl;
    }else{
        cout<<"Nr. nu este prim!"<<endl;
    }
    char a;
    cout<<"Doriti sa verificati existenta altui nr. prim? [D/N]: ";cin>>a;

    while(a=='d' || a=='D'){
        cout<<"Introduceti un nr. pt. al verifica daca este prim: ";cin>>nr;
        if(prim(nr)){
            cout<<"Nr. este prim!"<<endl;
        }else{
        cout<<"Nr. nu este prim!"<<endl;
        }
        cout<<"Doriti sa verificati existenta altui nr. prim? [D/N]: ";cin>>a;
    }

}
bool prim(int n){
    if(n==2 || n==3) return true;

    for(int i=2;i<sqrt(n)+1;i++){
        if(n%i==0) return false;
    }
    return true;
}

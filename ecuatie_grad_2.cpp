#include<iostream>
#include<math.h>

using namespace std;

int main(){

cout<<"ecuatia de gr. 2 este de forma: ax^2+bx+c=0";

int a,b,c;

cout<<"\n introduceti a=";cin>>a;
cout<<"\n introduceti b=";cin>>b;
cout<<"\n introduceti c=";cin>>c;
cout<<"\n";

if(a!=0){
    double preDelta=(double)pow(b,2)-4*a*c;


    if(preDelta>=0){
        double delta=(double)sqrt(preDelta);
        double x1=(-b+delta)/(2*a);
        double x2=(-b-delta)/(2*a);

        cout<<"Soultiile ecuatiei sunt: "<<x1<<"    "<<x2;
    }else
    {
        double delta=(double)sqrt(-preDelta);
        double x1=(double)-b/(2*a);
        double x2=(double)-b/(2*a);
        double valueOfImaginary=(double)delta/(2*a);

        cout<<"Soultiile ecuatiei sunt: "<<x1<<"+i"<<valueOfImaginary<<"    "<<x2<<"-i"<<valueOfImaginary;

    }
}else{
    double x=-c/b;
    cout<<"Soultia ecuatiei este: "<<x;
}
return 0;
}

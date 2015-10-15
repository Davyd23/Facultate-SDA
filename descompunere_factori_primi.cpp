// unordered_map::begin/end example
#include <iostream>
#include <map>
#include<math.h>
using namespace std;

bool prim(int n){
    if(n<4){
        return true;
    }
    for(int i=2;i<sqrt(n)+1;i++){

        if(n%i==0){
            return false;
        }
    }
    return true;
}

map<int,int> factoriPrimi(int val){

    map<int,int>primi;

    if(prim(val)){
        primi[val]++;
        return primi;
    }

    while(val%2==0){
        primi[2]++;
        val/=2;
    }

    while (val!=1){

        for(int i=3;;i+=2){

            if(val%i==0){
                primi[i]++;
                val/=i;
                break;
            }
        }
    }
    return primi;
}



int main ()
{
    int val=10000;
    map<int,int> hMap=factoriPrimi(val);

    map<int,int>::iterator iter;

    cout<<val<<" se desparte in \n";
    for(iter=hMap.begin();iter!=hMap.end();iter++){
        cout<<iter->first<<" la puterea a "<<iter->second<<"\n";
    }

}




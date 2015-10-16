#include<iostream.h>

#define ARRAY_SIZE 10       // atentie la define , modificare marimi vectorului array  se face de aici

void selectionSort(int array[]){

	
	for(int i=0;i<ARRAY_SIZE-1;i++){       
	  int min=array[i];
          int poz=i;

	  for(int j=i+1;j<ARRAY_SIZE;j++){
		if(min>array[j]){
			poz=j;
                        min=array[j];
                }
	  }
	  if(min!=array[i]){
		int aux=array[i];
		array[i]=array[poz];
                array[poz]=aux;
          }
	}
	for(i=0;i<ARRAY_SIZE;i++){
         	cout<<array[i]<<" ";
	}
}

void countingSort(int array[]){    // elemente distincte

	int count[ARRAY_SIZE];
	for(int k=0;k<ARRAY_SIZE;k++){
            count[k]=0;
        }

	for(int i=0;i<ARRAY_SIZE;i++){

		for(int j=0;j<ARRAY_SIZE;j++){

			if(array[i]>array[j]){
                         	count[i]++;
                        }
                }
	}

	int orderedArray[ARRAY_SIZE];

	for(i=0;i<ARRAY_SIZE;i++){

        	orderedArray[count[i]]=array[i];

	}

	cout<<endl;

	for(i=0;i<ARRAY_SIZE;i++){
         	cout<<orderedArray[i]<<" ";
	}

}

void insertionSort(int array[]){

	int j=0;

	for(int i=1;i<ARRAY_SIZE;i++){

	     for(j=i-1;j>=0;j--){

		if(array[j]<=array[i])
			{
				break;
                        }
	     }

	     int aux=array[i];

	     for(int k=i;k>j+1;k--){

             	array[k]=array[k-1];

	     }

	     array[j+1]=aux;

	}
        cout<<endl;
	for(i=0;i<ARRAY_SIZE;i++){
         	cout<<array[i]<<" ";
	}

}

void bubble_sort(int array[]){

int indicator_schimbare=1;

    while(indicator_schimbare){

        indicator_schimbare=0;
	for(int j=0;j<ARRAY_SIZE-1;j++){
            if(array[j]>array[j+1]){

                indicator_schimbare=1;

                int aux=array[j];
		array[j]=array[j+1];           
                array[j+1]=aux;
            }
        }
    }
	cout<<endl;
     	for(int i=0;i<ARRAY_SIZE;i++){
         	cout<<array[i]<<" ";
	}
}

void main(){


	int array[ARRAY_SIZE];

	int n;
	cout<<"introduce-ti marimea matrici , maxim 10: ";cin>>n;
	while (n>10){
         	cout<<"Ati introdus o valoare gresita , introduce-ti din nou , maxim "<<ARRAY_SIZE<<": ";cin>>n;
        }
	cout<<"Introduce-ti elementele matrici: \n";

	for(int i=0;i<n;i++){

         	cout<<"a["<<i+1<<"]=";cin>>array[i];
        }

	 char algoritm;

   	 cout<<"Introduce-ti o variabila pentru sortare, i-Insertion Sort, c-Counting Sort ,b- Bubble Sort ,s- Selection Sort: ";cin>> algoritm;
	 while(algoritm!='n')
	  {
	  	switch(algoritm){

			case 'i':   insertionSort(array);   break;

			case 's': selectionSort(array);break;

			case 'b':bubble_sort(array);break;

			case 'c': countingSort(array);break;


			default : cout<<"Ati introdus o variabila gresita , am ales pt dumneavoastra bubble sort"<<endl; bubble_sort(array);

	 	 }
	  	 cout<<"\n  Introduce-ti o variabila i-Insertion Sort, c-Counting Sort ,b- Bubble Sort ,s- Selection Sort, 'n' pt iesire: ";cin>> algoritm;

          }
 
}

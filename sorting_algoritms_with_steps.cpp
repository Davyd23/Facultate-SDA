#include<iostream>

using namespace std;
int i,j;
int ARRAY_SIZE;

void afisare_sir(int array[]){
    for(int i=0;i<ARRAY_SIZE;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}
int nr_cifre(int val){
    int cifre=1;
    while(val/10!=0){
        cifre++;
        val/=10;
    }
    return cifre;
}
void afisare_pozitie_schimbata(int array[],int poz_init,int poz_fin){

    cout<<endl;
    for(int k=0;k<poz_init;k++){
            cout<<" ";  // spatiul echivalent cu spatiul nostru
        for(int i=0;i<nr_cifre(array[k]);i++){  // spatiul pt valoare , in cas e un nr de forma xx sunt 2 spatii
            cout<<" ";
        }
    }
    for(int k=0;k<nr_cifre(array[poz_init]);k++){  // atatea | cate nr
        cout<<"|";
    }
    cout<<" ";  // spatiul dupa semnalizare locatie
    for(int k=poz_init+1;k<poz_fin;k++){
        cout<<" ";
        for(int i=0;i<nr_cifre(array[k]);i++){  // spatiul pt valoare , in cas e un nr de forma xx sunt 2 spatii
            cout<<" ";
        }
    }
    //cout<<array[poz_fin]<<":"<<array[poz_init]<<endl;
    for(int k=0;k<nr_cifre(array[poz_fin]);k++){  // atatea | cate nr
        cout<<"|";
    }
    cout<<endl;

}

void bubble_sort(int array[]){
    cout<<endl;
    cout<<"Bubble sort, sometimes referred to as sinking sort,"
    <<"is a simple sorting algorithm that repeatedly steps through the list to be sorted,"
    <<"compares each pair of adjacent items and swaps them if they are in the wrong order. \n";

    int indicator_schimbare=1;

        while(indicator_schimbare){

            indicator_schimbare=0;
            for(int j=0;j<ARRAY_SIZE-1;j++){
                if(array[j]>array[j+1]){

                   afisare_pozitie_schimbata(array,j,j+1);
                   afisare_sir(array);

                    indicator_schimbare=1;

                    int aux=array[j];
                    array[j]=array[j+1];
                    array[j+1]=aux;

                    afisare_sir(array);
                }
            }
        }
    cout<<endl<<"Sirul aranjat are forma:\n";
	afisare_sir(array);
}



void selectionSort(int array[]){

    cout<<endl;
    cout<<"The idea of the algorithm is quite simple.";
    cout<<"Array is imaginary divided into two parts - sorted one and unsorted one.";
    cout<<"At the beginning, sorted part is empty, while unsorted one contains whole array.";
    cout<<"At every step, algorithm finds minimal element in the unsorted part and adds it to the end of the sorted one.";
    cout<<"When unsorted part becomes empty, algorithm stops.\n";

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

        afisare_pozitie_schimbata(array,i,poz);
        afisare_sir(array);

		int aux=array[i];
		array[i]=array[poz];
        array[poz]=aux;

        afisare_sir(array);
        }
	}
	cout<<endl<<"Sirul aranjat are forma:\n";
	afisare_sir(array);
}

void countingSort(int array[]){    // elemente distincte

    cout<<endl;
    cout<<"In computer science, counting sort is an algorithm for sorting a collection of objects according to keys that are small integers,";
    cout<<" it is an integer sorting algorithm.";
    cout<<"It operates by counting the number of objects that have each distinct key value,";
    cout<<" and using arithmetic on those counts to determine the positions of each key value in the output sequence.\n";

	int count[ARRAY_SIZE];
	for(int k=0;k<ARRAY_SIZE;k++){
        count[k]=0;
        }
    cout<<endl<<"Sirul initial: ";afisare_sir(array);

	for(int i=0;i<ARRAY_SIZE;i++){

		for(int j=0;j<ARRAY_SIZE;j++){

			if(array[i]>array[j]){
                count[i]++;
            }
        }
        cout<<"Sunt "<<count[i]<<" elemente mai mici ca "<<array[i]<<endl;
	}
	cout<<"Fiecare element ma fi pus in pozitia corecta=>\n";


	int orderedArray[ARRAY_SIZE];

    for(i=0;i<ARRAY_SIZE;i++){
        orderedArray[i]=0;
    }
    afisare_sir(orderedArray);

	for(i=0;i<ARRAY_SIZE;i++){
        orderedArray[count[i]]=array[i];
        afisare_sir(orderedArray);
	}

	cout<<endl;
	cout<<endl<<"Sirul aranjat are forma:\n";
	afisare_sir(orderedArray);
}

void insertionSort(int array[]){
    int j=0;
    cout<<endl;
    cout<<"An sorting algorithm which moves elements one at a time into the correct position.";
    cout<<"The algorithm consists of inserting one element at a time into the previously sorted part of the array,";
    cout<<" moving higher ranked elements up as necessary. To start off,";
    cout<<" the first (or smallest, or any arbitrary) element of the unsorted array is considered to be the sorted part.\n";

	for(int i=1;i<ARRAY_SIZE;i++){
        for(j=i-1;j>=0;j--){
            if(array[j]<=array[i])
            {
                break;
            }
	     }

	     if(i!=j+1){
            afisare_pozitie_schimbata(array,j+1,i);
            afisare_sir(array);
	     }
	     int aux=array[i];
	     for(int k=i;k>j+1;k--){
            array[k]=array[k-1];
        }
        array[j+1]=aux;
        if(i!=j+1){
            afisare_sir(array);
        }
	}
    cout<<endl<<"Sirul aranjat are forma:\n";
	afisare_sir(array);

}

void afisare_pozitie_schimbata_shell_sort(int array[],int poz,int pas,int start_grafic){

    cout<<endl;
    for(int i=0;i<start_grafic;i++){
            cout<<" ";
            for(int k=0;k<nr_cifre(array[i]);k++){
                cout<<" ";
            }
    }
    for(int i=start_grafic;i<=poz;i+=pas){
        for(int k=0;k<nr_cifre(array[i]);k++){
            cout<<"|";
        }
        cout<<" ";
        for(int j=1;j<pas;j++){
            cout<<" ";
            for(int k=0;k<nr_cifre(array[i+j]);k++){
                cout<<" ";
            }
        }
    }
    cout<<endl;

}

void shellSort(int array[]){

    cout<<endl;
    cout<<"Shellsort is a generalization of insertion sort that allows the exchange of items that are far apart. ";
    cout<<"The idea is to arrange the list of elements so that, starting anywhere, considering every hth element gives a sorted list.";
    cout<<"Such a list is said to be h-sorted. Equivalently, it can be thought of as h interleaved lists, ";
    cout<<"each individually sorted. Beginning with large values of h, ";
    cout<<"this rearrangement allows elements to move long distances in the original list, reducing large amounts of disorder quickly, ";
    cout<<"and leaving less work for smaller h-sort steps to do. If the file is then k-sorted for some smaller integer k, ";
    cout<<"then the file remains h-sorted. Following this idea for a decreasing sequence of h values ending in 1 is guaranteed to leave a sorted list in the end.\n";

    int pas=ARRAY_SIZE/2;
    int j,i;

    while(pas>0){  // pas descrescator
        int start_grafic=0;//de unde sa inceapa linile;
        for(int k=0;k<pas;k++){ // daca ajunge pe valoare pasului deja a trecut prin acea sectiune din vector
            for(i=pas+k;i<ARRAY_SIZE;i+=pas){

                afisare_pozitie_schimbata_shell_sort(array,i,pas,start_grafic);
                afisare_sir(array);

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

                afisare_sir(array);


            }
            start_grafic++;
        }
        pas/=2;
    }
    cout<<endl<<"Sirul aranjat are forma:\n";
	afisare_sir(array);
}

void afisare_split_mergeSort(int array[],int start,int end){
    for(int i=start;i<=end;i++){
        cout<<array[i]<<" ";
    }
}

int* mergeSplitMerge(int* arr1,int elm1,int* arr2,int elm2){
    int startArr1=0;
    int startArr2=0;

    int* orderedPointer=new int[elm1+elm2];

    cout<<"Sirurile: ";afisare_split_mergeSort(arr1,0,elm1-1);cout<<"si ";afisare_split_mergeSort(arr2,0,elm2-1);cout<<"se combina in \n";

    for(int i=0;i<elm1+elm2;i++){

        if(startArr1<elm1 && (startArr2>=elm2 || *(arr1+startArr1)<*(arr2+startArr2))){

            *(orderedPointer+i)=*(arr1+startArr1);
            startArr1++;

        }else{
            *(orderedPointer+i)=*(arr2+startArr2);
            startArr2++;
        }
        afisare_split_mergeSort(orderedPointer,0,i);cout<<endl;
    }
    return orderedPointer;
}

void afisare_descompunere_mergeSort(int array[],int start,int middle,int end){

    cout<<"Sirul: ";
    afisare_split_mergeSort(array,start,end);
    cout<<"se desparte in ";
    afisare_split_mergeSort(array,start,middle);
    cout<<"si ";
    afisare_split_mergeSort(array,middle+1,end);
    cout<<endl;
}

int* mergeSplit(int array[],int start,int end){

    if(end-start<1){
        return &array[start];
    }

    int middle=start+(end-start)/2  ;
    afisare_descompunere_mergeSort(array,start,middle,end);

    int* firstArr=mergeSplit(array,start,middle);

    int* secondArr=mergeSplit(array,middle+1,end);

    return mergeSplitMerge(firstArr,middle-start+1,secondArr,end-middle);

}

 void mergeSort(int array[]){
    cout<<endl<<"Conceptually, a merge sort works as follows:\n";
    cout<<"Divide the unsorted list into n sublists, each containing 1 element (a list of 1 element is considered sorted).\n";
    cout<<"Repeatedly merge sublists to produce new sorted sublists until there is only 1 sublist remaining. This will be the sorted list. \n";

    int* orderedArray=mergeSplit(array,0,ARRAY_SIZE-1);
    cout<<endl<<"Sirul aranjat are forma:\n";

    for(int i=0;i<ARRAY_SIZE;i++){
        cout<<*(orderedArray+i)<<" ";
    }

    cout<<endl;
}

void afisare_pozitie_schimbata_radixSort(int** array ,int nr_coloane , int pozInit , int pozFin){

    for(int i=0;i<ARRAY_SIZE;i++){
        for(int j=0;j<nr_coloane;j++){
            cout<<array[i][j]<<" ";
        }
        if(i==pozInit || i==pozFin){
            cout<<"  --";
        }
        cout<<endl;
    }
    cout<<endl;

}

void radixSort(int* values){

    cout<<endl<<"Each key is first figuratively dropped into one level of buckets corresponding to the value of the rightmost digit."
    <<" Each bucket preserves the original order of the keys as the keys are dropped into the bucket. "
    <<"There is a one-to-one correspondence between the buckets and the values that can be represented by the rightmost digit."
    <<" Then, the process repeats with the next neighbouring more significant digit until there are no more digits to process. In other words:\n"

    <<"Take the least significant digit (or group of bits, both being examples of radices) of each key.\n"
    <<"Group the keys based on that digit, but otherwise keep the original order of keys. (This is what makes the LSD radix sort a stable sort.)\n"
    <<"Repeat the grouping process with each more significant digit.\n";

    int max_digits=1;

    for(int i=0;i<ARRAY_SIZE;i++){
        if(max_digits<nr_cifre(*(values+i))){
            max_digits=nr_cifre(*(values+i));
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

                cout<<endl<<"Aranjam matricea dupa coloana "<<j+1<<":\n";
                afisare_pozitie_schimbata_radixSort(matrix,max_digits,i,i+1);

                hold=matrix[i];
                matrix[i]=matrix[i+1];
                matrix[i+1]=hold;
            }
        }

        if(!indicator_schimbare){
            j--;
        }
    }
    cout<<endl<<"Matricea ordonata are forma:\n";
    afisare_pozitie_schimbata_radixSort(matrix,max_digits,-1,-1);

    int* orderedVector=new int[ARRAY_SIZE];
    for(int i=0;i<ARRAY_SIZE;i++){
            int crestere=1;
            orderedVector[i]=0;
        for(int j=max_digits-1;j>=0;j--){
            orderedVector[i]+=matrix[i][j]*crestere;
            crestere*=10;
        }
    }

    cout<<endl<<"Sirul aranjat are forma:\n";
    afisare_sir(orderedVector);
}

int main(){
	cout<<"introduce-ti marimea matrici: ";cin>>ARRAY_SIZE;
	int* array=new int[ARRAY_SIZE];
	cout<<"Introduce-ti elementele matrici: \n";

	for(int i=0;i<ARRAY_SIZE;i++){

         	cout<<"a["<<i+1<<"]=";cin>>array[i];
        }

	 char algoritm;

   	  cout<<"Introduce-ti o variabila:\n i-Insertion Sort\n c-Counting Sort \n b- Bubble Sort \n m-Merge Sort \n s- Selection Sort\n h-Shell Sort \n r-Radix Sort \n n- pentru a nu face nimic: ";cin>> algoritm;
	 while(algoritm!='n')
	  {
	  	switch(algoritm){

			case 'i': insertionSort(array);break;

			case 's': selectionSort(array);break;

			case 'b': bubble_sort(array);break;

			case 'c': countingSort(array);break;

			case 'h': shellSort(array);break;

            case 'm': mergeSort(array);break;

            case 'r': radixSort(array);break;

			default : cout<<"Ati introdus o variabila gresita , am ales pt dumneavoastra bubble sort"<<endl; bubble_sort(array);

	 	 }
	  	 cout<<"\n  Introduce-ti o variabila:\n i-Insertion Sort\n c-Counting Sort \n b- Bubble Sort \n m-Merge Sort \n s- Selection Sort\n h-Shell Sort \n r-Radix Sort \n 'n' pt iesire: ";cin>> algoritm;



    }
return 0;
}

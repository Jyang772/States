#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iomanip>

using namespace std;

const int MAX_STATES = 50;

#define POPULATION

template<typename T>
void Swap(T& x, T& y)
{
    T temp = x;
    x = y;
    y = temp;
}

template<typename T>
void Print(T a[], int na)
{
    for(int i=0; i<na; i++)
        cout << a[i] << " ";
    cout << endl;
}

template<typename T>//				3         8
void ReheapDown(T elements[], int root, int bottom)
// Post: Heap property is restored.
{
    int maxChild;
    int rightChild;
    int leftChild;

    leftChild = root*2+1;//
    rightChild = root*2+2;
    if (leftChild <= bottom)
    {
        if (leftChild == bottom)
            maxChild = leftChild;
        else
        {
            if (*elements[leftChild] <= *elements[rightChild]) //dereference for extra
                maxChild = rightChild;
            else
                maxChild = leftChild;
        }
        if (*elements[root] < *elements[maxChild])
        {
            Swap(elements[root], elements[maxChild]);
            //                      2        8
            ReheapDown(elements, maxChild, bottom);
        }
    }
}

template<typename T> //          9
void HeapSort(T values[], int numValues)
// Post: The elements in the array values are sorted by key.
{

    int index;
    int step = 0;
    // Convert the array of values into a heap.
    for (index = numValues/2 - 1; index >= 0; index--)
    {
        ReheapDown(values, index, numValues-1);
    }
    //cout << "Now a heap!!\n";
    cin.get();
    // Sort the array.
    step = 0;
    for (index = numValues-1; index >=1; index--)
    {
        Swap(values[0], values[index]);
        ReheapDown(values, 0, index-1);
    }
}

template<typename T>//           0             8
void BubbleUp(T values[], int startIndex, int endIndex, bool& sorted)
// Post: Adjacent pairs that are out of order have been
//       switched between values[startIndex]..values[endIndex]
//       beginning at values[endIndex].
{
    sorted = true;
    for (int index = endIndex; index > startIndex; index--)
        if (*values[index] > *values[index-1])
        {
            Swap(values[index], values[index-1]);
            sorted = false;
        }
}

// BubbleSort(a, 9);
template<typename T>//             9
void BubbleSort(T values[], int numValues)
// Post: The elements in the array values are sorted by key.
{
    int current = 0;
    bool sorted = false;

    while (current < numValues - 1 && !sorted)
    {//		0         8
        BubbleUp(values, current, numValues-1,sorted);
        //PrintArray(values,numValues);
        //cin.get();
        //cout << endl;
        current++;
    }
}

struct StateInfo
{
    char name[15];
    int population;
    int area;
    int year;
    int order;
    char capital[15];
    char abbrev[3];
    int zip;
};

#ifndef POPULATION
bool operator>(const StateInfo &s1, const StateInfo &s2){
    return strcmp(s1.name,s2.name) > 0;
}

bool operator<(const StateInfo &s1, const StateInfo &s2){
    return strcmp(s1.name,s2.name) < 0;
}

bool operator>=(const StateInfo &s1, const StateInfo &s2){
    return strcmp(s1.name,s2.name) >= 0;
}

bool operator<=(const StateInfo &s1, const StateInfo &s2){
    return strcmp(s1.name,s2.name) <= 0;
}
#else

bool operator>(const StateInfo &s1, const StateInfo &s2){

    return s1.population > s2.population;
}

bool operator<(const StateInfo &s1, const StateInfo &s2){
    return s1.population < s2.population;
}

bool operator>=(const StateInfo &s1, const StateInfo &s2){

    return s1.population >= s2.population;
}

bool operator<=(const StateInfo &s1, const StateInfo &s2){
    return s1.population <= s2.population;
}
#endif


void test(StateInfo *a){

    cout << a[0].name << endl;
    cout << a[1].name << endl;
}


int main()
{
    StateInfo states[MAX_STATES];
    StateInfo *pStates[MAX_STATES];

    ifstream inBin;
    inBin.open("States.dat",ios::binary);
    if(!inBin){
        cout << "Could not open file!\n";
    }
    else
        cout << "File Opened.\n";

    StateInfo s;
    int i=0;
    int SIZE = sizeof(StateInfo);


    while(i<MAX_STATES && inBin.read((char*)&s,SIZE)){
        states[i++] = s;
    }

    for(int j=0; j<i; j++){
        pStates[j] = &states[j];
    }

//    for(auto i : pStates)
//        cout << i->name << endl;

   // cout << "HeapSort: " << endl;

//     //BubbleSort(pStates,i);
      HeapSort(pStates,i);

    cout << "State: " << setw(10) << " | ";
    cout << setw(12) << "Population:" << " | ";
    cout << setw(15) << "Area Code:" << " | ";
    cout << setw(12) << "Year:" << " | ";
    cout << setw(12) << "Order: " << " | ";
    cout << setw(14) << "Capital:" << " | ";
    cout << setw(12) << "Abbrev.:" << " | ";
    cout << setw(12) << "Zip:" << endl;
    cout << "---------------------------------------------------" << endl;

    for(auto i : pStates){
        cout << i->name << " | ";
        cout << setw(12) << i->population << " | ";
        cout << setw(15) << i->area << " | ";
        cout << setw(12) << i->year << " | ";
        cout << setw(12) << i->order << " | ";
        cout << setw(12) << i->capital << " | ";
        cout << setw(12) << i->abbrev << " | ";
        cout << setw(12) << i->zip << " | " << endl;
    }

//    cout << "---------------------------------------------------" << endl;

    cout << "BubbleSort: " << endl;
    cin.get();
    BubbleSort(pStates,i);

    cout << "State: " << setw(10) << " | ";
    cout << setw(12) << "Population:" << " | ";
    cout << setw(15) << "Area Code:" << " | ";
    cout << setw(12) << "Year:" << " | ";
    cout << setw(12) << "Order: " << " | ";
    cout << setw(14) << "Capital:" << " | ";
    cout << setw(12) << "Abbrev.:" << " | ";
    cout << setw(12) << "Zip:" << endl;
    cout << "---------------------------------------------------" << endl;

    for(auto i : pStates){
        cout << i->name << " | ";
        cout << setw(12) << i->population << " | ";
        cout << setw(15) << i->area << " | ";
        cout << setw(12) << i->year << " | ";
        cout << setw(12) << i->order << " | ";
        cout << setw(12) << i->capital << " | ";
        cout << setw(12) << i->abbrev << " | ";
        cout << setw(12) << i->zip << " | " << endl;
    }



    return 0;
}






//Pointer to an array of pointers.


//    size_t cnt = 10;
//    size_t t = sizeof(stateInfo);
//    FILE *fptr;
//    stateInfo lol[2];
//    fptr = fopen("States.dat","rb");
//    fread(&lol,sizeof(stateInfo),2,fptr);
//    fclose(fptr);

//    cout << lol[0].name << endl;
//    cout << lol[0].population << endl;
//    cout << lol[0].area << endl;
//    cout << lol[0].year << endl;
//    cout << lol[0].order << endl;
//    cout << lol[0].capital << endl;
//    cout << lol[0].abbrev << endl;
//    cout << lol[0].zip << endl;
//    cout << lol[1].name << endl;

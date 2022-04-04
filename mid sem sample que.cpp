#include <iostream>
using namespace std;
void bubbleSort(int *array, int size) {
   for(int i = 0; i<size; i++) {
      int swaps = 0;
      for(int j = 0; j<size-i-1; j++) {
         if(array[j] > array[j+1]) {
            swap(array[j], array[j+1]);
            swaps = 1;
         }
      }
      if(!swaps)
         break;
   }
}
bool checkSetEquality(int set1[], int set2[], int size)
{
    bubbleSort(set1,size);
    bubbleSort(set2,size);
    bool state = false;

    for(int i = 0; i<size; i++)
    {
        if(set1[i] == set2[i]) state = true;
        else state = false;
    }
    return state;
}

void SetDifference(int set1[], int set2[], int size)
{


}

void deleteOriginalElement(int arr[], int &size)
{
    int index;
    cout<<"Enter the index of element to be deleted: ";
    cin>>index;

    for(int i = index; i<size; i++)
    {
        arr[i] = arr[i+1];
    }
    size--;
}

int main()
{
    int n;
    cout<<"Enter the size of both sets: ";
    cin>>n;
    int set1[n], set2[n];

    cout<<"Enter elements in both sets"<<endl;
    for(int i = 0; i<n; i++){
        cin>>set1[i];
    }
    cout<<endl;
    for(int i = 0; i<n; i++){
        cin>>set2[i];
    }
    cout<<endl;

    int equalState = checkSetEquality(set1,set2,n);

    if(equalState == 1){
        deleteOriginalElement(set2, n);
        for(int i = 0; i<n; i++){
            cout<<set2[i]<<" ";
        }
        cout<<endl;
    }
    else{
        int setDiff[n-1];
        SetDifference(set1, set2,n);
    }

    return 0;
}

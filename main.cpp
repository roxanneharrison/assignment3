#include<iostream>
#include <string>
#include <fstream>
using namespace std;

// VARIABLE DECLARATIONS
int size = 7;
int a[7];

// FUNCTION PROTOCOL

// MERGE FUNCTION
void merge(int,int,int);
// SORT FUNCTION
void merge_sort(int low,int high);
// PRINT FUNCTION
void printArray(int a[], int size);

// MAIN FUNCTION
int main()
{


cout<<"* MERGE SORT *"<< endl << endl;
cout << "ORIGINAL LIST: " << endl;
    ifstream file("input.txt");
    if(file.is_open())
    {
        for(int i = 0; i < size; ++i)
        {
            file >> a[i];
        }
    }
// PRINT THE ORIGINAL LIST
 printArray(a, size);
    cout << endl;
// CALL MERGESORT FUNCTION
 merge_sort(0,size-1);
 cout<<endl;
 cout<<"SORTED LIST: "<<endl;
// PRINT THE FINAL LIST
printArray(a, size);
return 0;

}


// SORT FUNCTION
void merge_sort(int low,int high)
{
 int mid;
 if(low<high)
 {
  
  mid = low + (high-low)/2;
  merge_sort(low,mid);
  merge_sort(mid+1,high);
  merge(low,mid,high);
  printArray(a, size);
 }

}

// MERGE FUNCTION
void merge(int low,int mid,int high)
{
 int h,i,j,b[size],k;
 h=low;
 i=low;
 j=mid+1;

 while((h<=mid)&&(j<=high))
 {
  if(a[h]<=a[j])
  {
   b[i]=a[h];
   h++;
  }
  else
  {
   b[i]=a[j];
   j++;
  }
  i++;
 }
 if(h>mid)
 {
  for(k=j;k<=high;k++)
  {
   b[i]=a[k];
   i++;
  }
 }
 else
 {
  for(k=h;k<=mid;k++)
  {
   b[i]=a[k];
   i++;
  }
 }
 for(k=low;k<=high;k++) a[k]=b[k];
}

// PRINT THE LIST IN THE CURRENT ORDER
void printArray(int a[], int size)
{
    
    for(int i=0;i<size;i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

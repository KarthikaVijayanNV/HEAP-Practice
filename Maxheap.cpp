#include<iostream>
using namespace std; // ARRAY WILL BE HEAPIFIED -MAX HEAP  
                    //For eg:                       arr[12,1,3,5,11,9,16]
                    // array after heapification    arr[16,11,12,5,1,9,3]


void heapify(int arr[],int n,int i)
{
    int largest=i;  // assuming the current root node as largest
    int l=2*i+1;     //finding it's left node
    int r=2*i+2;     // finding right node

    if(l<n && arr[l]>arr[largest])   // comparing left is higher or not
        largest=l;
    
    if(r<n && arr[r]>arr[largest])  //comparing right is higher or not
        largest=r;
    
    if(largest!=i)                 // now check whether the largest u found is there in root or not
        {
          swap(arr[i],arr[largest]); // if not then swap
    heapify(arr,n,largest);          // again heapify the effected subtree again
        }
}


void heapsort(int arr[],int n) //control comes here as the function is called
{
    for(int i=n/2-1;i>=0;i--)  // for finding the last root node( root of last non-leaf node) equation=i=n/2 -1 (check if u have doubt)
    heapify(arr,n,i);          // after finding the last root node perform heapify>> control goes to heapify function^^^^up
    
}

void printArray(int arr[],int n)   // function prints the array
{
    for(int i=0;i<n;i++)
      cout<<arr[i]<<" ";
      cout<<endl;

}



int main() 
{
    int  arr[]= {12,15,13,1,3,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    heapsort(arr,n);                   // calling heapsort >>>control go to heaport function ^^ up

    cout<<"The array after heapification: "<<endl;
    printArray(arr,n);


    return 0;

}
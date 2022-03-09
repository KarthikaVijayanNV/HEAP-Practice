#include<bits/stdc++.h>
using namespace std;  // ARRY WILL BE HEAPIFIED -MIN HEAP
                      // for eg:                 arr={12,9,3,5,8,16,11}
                      // array after heapication arr={3,5,11,9,8,16,12}



void heapify(int arr[],int n,int i) // heapify function
{
    int smallest=i;   // assuming root node as largest
    int l=2*i+1;      // getting it's left child
    int r=2*i+2;      // getting it's right child

    if(l<n && arr[l]<arr[smallest])   // comparing with left child
        smallest=l;
    
    if(r<n && arr[r]<arr[smallest])   // comparing with right child
        smallest=r;
    
    if(smallest!=i)                   // checking root is still smaller or not
        {
          swap(arr[i],arr[smallest]);  // if yes then swap
    heapify(arr,n,smallest);           // now heapify the in the subtree again
        }
}


void heapsort(int arr[],int n)  //overall heapsort
{
    for(int i=n/2-1;i>=0;i--)   // starting from the last parent node>> heapify downwar direction
    heapify(arr,n,i);           // calling heapify function

}

void printArray(int arr[],int n)
{
    for(int i=0;i<n;i++)
      cout<<arr[i]<<" ";
      cout<<endl;

}



int main()
{
    int  arr[]= {12,15,13,1,3,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    heapsort(arr,n);

    cout<<"The array after heapification: "<<endl;
    printArray(arr,n);


    return 0;

}
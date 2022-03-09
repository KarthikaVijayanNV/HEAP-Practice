#include<bits/stdc++.h>
using namespace std;       // MAX HEAPSORT FOR PRINTING THE ARRAY IN ASCENDING ORDER

 //steps 
          // 1)Array will be there (binary tree)
          // 2)U have to perform maxheap (heapify the tree as maxheap)
          // 3)Delete one by one (explained below) sorting will be automatically performed when u delete one by one



// Sort the elements in an array in the ascending order  // Increasing order // small  to high
// Using Max heap -> In max heap the largest element will be in the root node 
// Deleting that ...and again heapify.... 2nd largest element will be now as root node ,delete it &heapify
// This process goes on....and at the end we will be getting elemets chucked out in the ascending order

 // eg:            arr={1,3,2,11,13,12}
// after soretd   arr={1,2,3,11,12,13}


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

    for(int i=n-1;i>0;i--)    // after heapification // now delete one by one( sorting)
    {
        swap(arr[0],arr[i]);   // swap with the largest element in the root node with last element in the array
       heapify(arr,i,0);       // again heapify the reduced array.....
    }
    
}

void printArray(int arr[],int n)   // function prints the array
{
    for(int i=0;i<n;i++)
      cout<<arr[i]<<" ";
      cout<<endl;

}



int main()
{
    int  arr[]={12,15,13,1,3,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    heapsort(arr,n);                   // calling heapsort >>>control go to heaport function ^^ up

    cout<<"The sorted arry is: "<<endl;
    printArray(arr,n);


    return 0;

}
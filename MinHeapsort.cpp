#include<bits/stdc++.h>
using namespace std;    //MIN HEAPSORT FOR PRINTING THE ARRAY IN DESCENDING ORDER

//steps 
          // 1)Array will be there (binary tree)
          // 2)U have to perform minheap (heapify the tree as minheap)
          // 3)Delete one by one (explained below) sorting will be automatically performed when u delete one by one

// Sort the elements in an array in the decending order  // Decreasing order // High to small
// Using Min heap In min heap the lmallest element will be in the root node 
// Deleting that ...and again heapify.... 2nd smallest element will be now as root node ,delete it &heapify
// This process goes on....and at the end we will be getting elemets chucked out in the descending order

//            eg: arr={1,3,2,11,13,12}
// after soretd   arr={13,12,11,3,2,1}



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

    for(int i=n-1;i>0;i--)      // in this stage heapification completed Now......kick of the root element
    {
        swap(arr[0],arr[i]);    // root kicked of and swaped with last element in the array
       heapify(arr,i,0);        //heapify that sub tree again..........
    } 
    
}

void printArray(int arr[],int n)
{
    for(int i=0;i<n;i++)
      cout<<arr[i]<<" ";
      cout<<endl;

}



int main()
{
    int  arr[]={12,15,13,1,3,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    heapsort(arr,n);

    cout<<"The sorted arry is: "<<endl;
    printArray(arr,n);


    return 0;

}
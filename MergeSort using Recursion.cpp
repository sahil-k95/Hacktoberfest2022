#include <iostream>
#include "solution.h"
using namespace std;

void arrange(int arr1[],int size1,int arr2[],int size2,int output[]){
    int i=0,j=0,k=0;
    while(i<size1&&j<size2){
        if(arr1[i]<arr2[j]){
                  output[k]=arr1[i]; 
            i++;
            k++;
        }else{
            output[k]=arr2[j];
            j++;
            k++;
        }     
    }
    while(i<size1){
        output[k]=arr1[i];
        i++;
        k++;
    }
    while(j<size2){
        output[k]=arr2[j];
        j++;
        k++;
    }
    
}
void mergeSort(int input[], int size){
	if(size<=1){
        return;
    }
       
    int mid= size/2;
    int part1[1000];
    int part2[1000];
    
    int size1= mid;
    int size2= size-mid;
   int k=0;
    for(int i=0;i<mid;i++){
        part1[i]=input[i];
    }
    for(int i=mid;i<size;i++){
        part2[k]=input[i];
        k++;
    }
    mergeSort(part1,size1);
    mergeSort(part2,size2);
    arrange(part1,size1,part2,size2,input);
        
}
int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}

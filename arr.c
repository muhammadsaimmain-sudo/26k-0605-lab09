#include <stdio.h>


int data(int arr[],int size);

int main(){

int arr[]={1,3,2,4};
int size=4;

data(arr,size);

}



int data(int arr[],int size){
    int max=arr[0];
    int min=arr[0];
   int sum=0;
    for(int i=0;i<size;i++){
      if(arr[i]>max){
       max=arr[i];

      }
     if(arr[i]<min){
        min=arr[i];
     }}

     printf("max :%d \n",max);
printf("min :%d \n",min);

 for(int i=0;i<size;i++){
 sum+=arr[i];        

}
printf("the sum of array is : %d",sum);



}



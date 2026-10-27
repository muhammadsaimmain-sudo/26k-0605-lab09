#include <stdio.h>

int data(int s,int m ,int arr[][m]);


int main(){
  
int arr[3][4]={
   {1,2,3,7},
   {4,5,6,8},
   {6,7,8,9}

};

data(4,3,arr);
   
}













int data(int s,int m,int arr[][m]){
   

      for(int i=0;i<s;i++){
      int sum=0;
      for(int j=0;j<m;j++){
        sum+=arr[i][j];
          
      }
      printf("Sum of %d elemnt is = :%d",i+1,sum);


      }


}
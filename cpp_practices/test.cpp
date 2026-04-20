#include <iostream>

int sumAllOdds(int arr[], int size) {
  int sum = -1;  
 for(int i = 0; i < size; i++){
   if(arr[i] % 2 != 0)
    sum += arr[i];
 }
  return sum;
}

int main(){
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int size = sizeof(arr) / sizeof(arr[0]);
  std::cout << sumAllOdds(arr, size);
}

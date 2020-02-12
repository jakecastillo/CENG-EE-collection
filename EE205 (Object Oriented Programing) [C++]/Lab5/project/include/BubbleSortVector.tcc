void swap(int *xp, int *yp); 
template <typename T>
void BubbleSortVector<T>::sort() {
    // Lookup the bubble sort algorithm online.
    //
    // The algorithm is so-named "bubble sort" because
    // lesser valued elements "bubble up" to the "top" (front)
    // of the array/container/sequence.
    //
    // You'll have to perform a lot of swaps for the algorithm.
    //
    // You are free to write your own swap helper function
    // if you so desire.}
	bool swapped;
	for (int i = 0; i < (*this).size()-1; i++) {
		swapped = false;
	for (int x = 0; x < (*this).size()-x-1; x++){
		if((*this)[x] > (*this)[x+1]){
		swap(&(*this)[x], &(*this)[x+1]);
		swapped = true;
		}
		//Couldn't get algorithm to work correctly.
	}
	if(swapped == false);
	break;
	}
}

void swap(int *xp, int *yp) { 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
}
// void bubbleSort(int arr[], int n) 
// { 
//    int i, j; 
//    bool swapped; 
//    for (i = 0; i < n-1; i++) 
//    { 
//      swapped = false; 
//      for (j = 0; j < n-i-1; j++) 
//      { 
//         if (arr[j] > arr[j+1]) 
//         { 
//            swap(&arr[j], &arr[j+1]); 
//            swapped = true; 
//         } 
//      } 
  
     // IF no two elements were swapped by inner loop, then break 
//      if (swapped == false) 
//         break; 
//    } 
// } 

void exch(int arr[], int i, int j){
    int temp = arr[i];

    arr[i] = arr[j];
    arr[j] = temp;
}

void selection_sort(int arr[], int n){
    for(int i = 0; i < n; i++){
        int min = i;
        for(int j = i+1; j < n; j++){
            if(arr[min] > arr[j]) min = j;
        }
        exch(arr, i, min);
    }
}

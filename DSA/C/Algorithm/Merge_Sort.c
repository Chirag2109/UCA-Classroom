void merge(int arr[], int aux[], int left, int mid, int right) {
    for(int k = left; k <= right; k++)
      aux[k] = arr[k];
  
    int i = left;
    int j = mid + 1;
    for(int k = left; k <= right; k++) {
        if(i > mid) arr[k] = aux[j++];
        else if(j > right) arr[k] = aux[i++];
        else if(aux[i] <= aux[j]) arr[k] = aux[i++];
        else arr[k] = aux[j++];
    }
}

void merge_sort_r(int arr[], int aux[], int left, int right) {
    if(left >= right) return;
    int mid = (left + right) / 2;
    merge_sort_r(arr, aux, left, mid);
    merge_sort_r(arr, aux, mid+1, right);
    merge(arr, aux, left, mid, right);
}

void merge_sort(int arr[], int n) {
    int * aux = (int *) malloc(n * sizeof(int));
    merge_sort_r(arr, aux, 0, n-1);
    free(aux);
}

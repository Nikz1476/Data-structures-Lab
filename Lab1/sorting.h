//header file 
void bubble_sort(int* arr, int length){ 
    for (int i = 0; i < length; i++){ 
        int swap = 0; 
        for (int j = 0; j < length - i -1; j++){ 
            if (arr[j + 1] < arr[j]){ 
                int temp = arr[j]; 
                arr[j] = arr[j + 1]; 
                arr[j + 1] = temp; 
                swap = 1; 
            } 
        } 
        if (swap == 0){ 
            break; 
        } 
    } 
} 
 
void selection_sort(int* arr, int length){ 
    for (int i = 0; i < length - 1; i++){ 
        int min = i;  
        for (int j = i + 1; j < length; j++){ 
            if (arr[j] < arr[min]){ 
                min = j; 
            } 
        } 
        if (min != i){ 
            int temp = arr[i]; 
            arr[i] = arr[min]; 
            arr[min] = temp;  
        } 
    } 
}  
 
void insertion_sort(int* arr, int length){ 
    for (int i = 1; i < length; i++){ 
        int key = arr[i]; 
        int j = i - 1; 
        while (j >= 0 && (arr[j] > key)){ 
            arr[j + 1] = arr[j]; 
            j--;             
        } 
        arr[j + 1] = key; 
    } 
} 
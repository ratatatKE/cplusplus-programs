/*
    Basically contains the functions for inserting into a heap and deleting into a heap.
    Creating the heap uses the insert().
    Deleting from the heap enables us to achieve heap sort. So this file could also have been named heap_sort.c
*/

#include <stdio.h>

// `insert()` should just be called `arrange()`
void insert(int arr[], int idx_of_last_inserted_item){
    int i=idx_of_last_inserted_item, temp_val;
    temp_val=arr[i];
    
    while(i > 1 && temp_val > arr[i/2] ){           // index > first index and temp_val > parent
        arr[i] = arr[i/2];                          // value at i = parent's val
        i=i/2;                                      // adjust i to the parent of current i so that while loop can continuie
    }

    arr[i] = temp_val;                              // finally place the temp value in the array
}


int delete(int arr[], int index_to_store_root_after_deletion){
    //step1: delete in O(1). At the end, we are a COMPLETE BINARY TREE BUT NOT A MAX HEAP.
    int i, j, x, temp, val;
    val = arr[1];                                                   // we always delete the root so take this
    x = arr[index_to_store_root_after_deletion];             
    arr[1] = arr[index_to_store_root_after_deletion];                
    arr[index_to_store_root_after_deletion] = val;                                   // store the deleted item at the last index.

    //step2:  deletion complete, below onwards is re-arranging in O(n log n). At the end, we are a both COMPLETE BINARY TREE and a MAX HEAP
    i= 1;                                                           // put i at NEW ROOT root i.e. new_parent
    j= i*2;                                                         // put j at the root's /new_parent's left child

    while(j <= index_to_store_root_after_deletion-1){                                // should we -1 here? WEIRDLY YES because that's the index we are PROMOTING FROM
        // if j<index_to_store_root_after_deletion & right_child_of_new_parrent > left_child_of_new_parent
        // Notice we don't chare about left_child > right_child because in a BST the right will always be GREATER
        if(j < index_to_store_root_after_deletion-1 && arr[j+1] > arr[j]){           
            j = j + 1;                                              // new_parent's_left_child = right_child_of_j since the latter's greater
        }

        if(arr[i] < arr[j]){                                        // if new_parent < new+parent's_left child then swap them. (We only care about the left child alone since we just modified it).
            temp = arr[i];                                          // store parent's val in temp
            arr[i] = arr[j];                                        // parent_val = parent's_left_child_val
            arr[j] = temp;                                          // parent's_left_child_val = temp

            i=j;                                                    // index of parent = index of parent's left_child
            j=2*j;                                                  // index of j = index of j's left child
        }else{
            break;                                                  // we are already a MAX_HEAP so break.
        }
    }

    // return the deleted val
    return val;
}



int main(){
    int arr[]= { 0,14,15,5,20,30,8,40 };                              // C will autodetermine the size=8
    
    for(int i=2; i<=7; i++){                                          // we start at index 2, index 0 is usually ignored, we consider index 1 already added to heap
        insert(arr, i);
    }

     //first print inserted array
    printf("max heap created:\n");
    for(int i=0; i<8; i++){
        printf("%d ", arr[i]);
    }

     printf("\n\n"); 

    // notice we sent index_to_store_root_after_deletion as argument
    for(int index_to_store_root_after_deletion=7; index_to_store_root_after_deletion  > 1; index_to_store_root_after_deletion--){                                          
        int del = delete(arr, index_to_store_root_after_deletion);           // calls delete(arr,7),delete(arr,6), delete(arr,5), delete(arr,4) ... etc
        printf("deleted root=%d\n", del);
    }

    //then print the final array that will be sorted in heapsort
     printf("\narray after deletion:\n");
    for(int i=0; i<8; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}


/*
Output: 
    0 40 20 30 14 15 5 8 

    deleted root=40
    deleted root=30
    deleted root=20
    deleted root=15
    deleted root=14
    deleted root=8

    array after deletion:
    0 5 8 14 15 20 30 40   // (notice MAX heap sorts ascending, MIN  heap sorts descending)

*/
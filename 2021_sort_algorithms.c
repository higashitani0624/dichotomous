#include<stdio.h>

/* 整列の過程を表示する関数 */
void show_data(int a[], int n, int p, int c, int e){
    int i;
    for(i=0; i<n; i++){
        printf("%d ",a[i]);
        if(i==p)
            printf("| "); 
    }
    printf("compare=%d, exchange=%d \n", c, e);   
}

/* バブルソート */
void bubble_sort(int a[], int n){
    int i, j, t;
    int compare_count=0, exchange_count=0;
    for(i=0; i<n-1; i++){ 
        for(j=n-1; j>i; j--){
            compare_count++;
            if(a[j-1]>a[j]){
                t=a[j]; 
                a[j]=a[j-1]; 
                a[j-1]=t;
                exchange_count++;
            } 
        }
        show_data(a, n, i, compare_count, exchange_count); 
    }
}

/* 選択ソート */
void selection_sort(int a[], int n){
    int i, j, t, lowest, lowkey;
    int compare_count=0, exchange_count=0;
    for(i=0; i<n-1; i++){ 
        lowest=i; 
        lowkey=a[i]; 
        for(j=i+1; j<n; j++){
            compare_count++;
            if(a[j]<lowkey){ 
                lowest=j; 
                lowkey=a[j];
                exchange_count++;
            } 
        }
        t=a[i]; 
        a[i]=a[lowest]; 
        a[lowest]=t;
        show_data(a, n, i, compare_count, exchange_count);
    } 
}

/* 挿入ソート */
void insertion_sort(int a[], int n){
    int i, j, t;
    int compare_count=0, exchange_count=0;
    for(i=1; i<n; i++){ 
        j=i;
        while(j>=1 && compare_count++>=0 && a[j-1]>a[j]){ 
            t=a[j]; 
            a[j]=a[j-1]; 
            a[j-1]=t;
            j--;
            exchange_count++;
        }
        show_data(a, n, i, compare_count, exchange_count); 
    }
}

int main(){
    int a[100];
    int i,n;
    a[0] = 100;
    for(i=1;i<100;i++){
        a[i] = i;
    }
    n = 100;
    printf("bubble sort start\n");
    bubble_sort(a,n);
    printf("\n\n\n\n\n\n\n");
    a[0] = 100;
    for(i=1;i<100;i++){
        a[i] = i;
    }
    printf("selection sort start\n");
    selection_sort(a,n);
    printf("\n\n\n\n\n\n\n");
    a[0] = 100;
    for(i=1;i<100;i++){
        a[i] = i;
    }
    printf("insertion sort start\n");
    insertion_sort(a,n);
}
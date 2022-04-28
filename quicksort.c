//静岡大学総合情報科学技術研究科　CSプログラム　quicksort

#include<stdio.h>
#include <stdlib.h>
#define n 10



void quick(int seq[], int start, int end){
    int i, j;//走査位置
    int temp;//交換用
    int pivot;//基準値

    i = start;//初期走査位置の設定
    j = end;
    pivot = seq[(i+j)/2];//基準値の設定

    while(i <= j){
        while(seq[i] < pivot){//基準値より大きい数を走査
            i++;
        }
        while(seq[j] > pivot){//基準値より小さい数を走査
            j--;
        }
        if(i <= j){//入れ替え
            temp = seq[i];
            seq[i] = seq[j];
            seq[j] = temp;
            i++;//走査を進める
            j--;
        }
    }

    for (int m = 0; m < n; m++){//配列を表示
        printf("%d,",seq[m]);
    }

    printf("\n");

    if(start < j)//基準値より前をソート
        quick(seq, start, j);
    if(i < end)//基準値より後ろをソート
        quick(seq, i, end);
}



int main(){

    int seq[100];//ソートする配列

    for(int i = 0; i < n; i++) {// 0から2147483647までの乱数を100個生成
        seq[i] = (rand() % 10) + 1;
        printf("%d,",seq[i]);
    }
    
    printf("\n\n");

    quick(seq, 0, n-1);//クイックソート
    
    printf("\n");

    for (int m = 0; m < n; m++){//整列後の配列を表示
        printf("%d,",seq[m]);
    }

    return 0;

}
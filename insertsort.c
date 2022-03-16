//静岡大学　総合科学技術専攻科　情報学専攻
//CS ソフトウェア系　大門2-1 挿入ソート


//環境
//VSCode　拡張機能　C/C++


//挿入ソート　フローチャート　=======================================

//insert関数(main関数)
//配列の要素数分　繰り返す
//その数より左側の数と大小比較を行う
//その数が左側の数より小さいかつ、配列の番号が1より大きい場合入れ替えを行う。
//配列の番号を-1する。

//conpare関数
//引数に入っている番号の配列の値を引き算した値を返す。

//swap関数
//入れ替え用の変数を用意して、二つの数を入れ替える。



















#include <stdio.h>
#include <stdlib.h>

int compare(int low, int high){

    printf("compare\n");
    return low - high;

}


void swap(int low, int high,int *data){
    
    int tmp;
    printf("swap\n");
    tmp = *(data+low);
    *(data+low) = *(data+high);
    *(data+high) = tmp;

}


int main(){

    //変数宣言
    int datas[] = {1,2,3,4,5,6};//ソートする配列
    int number = 0;//配列の番号
    int print_number;//表示するときの変数
    int active_number = 0;//入れ替えを行う数の変数
    int max_number = (sizeof(datas)/sizeof(int)) - 1 ;//配列の要素数の合計
    
    //開始表示
    printf("start :");
    for(print_number = 0; print_number <= max_number; print_number++){
        printf(" %d ",datas[print_number]);
    }
    printf("\n");

    //挿入ソート開始
    for(number = 1; number<=max_number; number++){//要素全てを回す
        active_number = number;
        while(active_number>=1 && compare(datas[active_number-1] , datas[active_number])>0){//左の要素と比較する
            swap(active_number-1,active_number,datas);//入れ替える
            active_number--;
        }
        //入れ替え終わるたびに表示する
        printf("turn%d :",number);
        for(print_number = 0; print_number <= max_number; print_number++){
            printf(" %d ",datas[print_number]);
        }
        printf("\n");
    }

}
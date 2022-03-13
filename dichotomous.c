//静岡大学　総合科学技術専攻科　情報学専攻
//CS ソフトウェア系　大門1-2 二分探索


//環境
//VSCode　拡張機能　C/C++


//二分探索フローチャート-------------------------------------------------
//1探索配列格納
//最後、最前の要素数から最小値、最大値、中間値の初期化
//
//while文
//中間値を更新(中間値更新) 
//中間値と目標値との大小、正解判別　*条件分岐
//最小値、最大値の更新（範囲更新）
//最小値、最大値の大小反転により探索失敗 *条件分岐
//--------------------------------------------------------------------

//update_middleフローチャート-------------------------------------------
//high,low,middleをポインタで受け取る
//middle = (high+low) / 2;
//ポインタで値を返す
//---------------------------------------------------------------------

//update_rangeフローチャート--------------------------------------------
//high,low,大小関係を受け取り,high,lowどちらかの範囲を更新する
//---------------------------------------------------------------------










#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>




//中間値更新する関数
void update_middle(int middle_low, int middle_high, int *middle_middle){
   *middle_middle = (middle_high + middle_low) / 2;
   printf("start: low: %d, high: %d, middle: %d\n", middle_low, middle_high, *middle_middle);
}

//範囲更新する関数
void update_range(int *range_low, int *range_high, int range_middle, bool range_direct){
    if(range_direct){
        *range_low = range_middle + 1;
    }else{
        *range_high = range_middle - 1;
    }
    printf("       end: low: %d, high: %d, middle: %d\n", *range_low, *range_high, range_middle);
}






int main(){
    //変数宣言
    int datas[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 
    41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 
    103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 
    167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 
    233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 
    307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 
    379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 
    449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 
    523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 
    607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 
    677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 
    761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 
    853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 
    937, 941, 947, 953, 967, 971, 977, 983, 991, 997};//探索データ
    int target;//探索する値
    int *low, *high, *middle;//最小値、最大値、中間値
    int a, b, c;//最小値、最大値、中間値
    bool direct, result;//更新値
    int number;


    //入力処理
    printf("私は、入力された数が素数かどうかを判別するシステムです\n");
    printf("1~1000までの素数の中で小さい方から何番目の素数なのか、二分探索を用いて判別します。\n");
    printf("探索したい数値を半角で入力し、Enterを押してください ->");
    scanf("%d", &target);
    printf("%dの探索を開始します \n", target);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    //最大値アドレス初期化
    a = sizeof(datas)/sizeof(int);
    a --;
    high = &a;
    //最小値アドレス初期化
    b = 0;
    low = &b;
    //中間値アドレス初期化
    c = 0;
    middle = &c;


    //探索開始
    number = 0;
    while(true){
        //ターン表示
        number ++;
        printf("turn %d ", number);
        //中間値更新
        update_middle(*low,*high,middle);
        //中間値と目標値との大小、正解判別
        if(target > datas[*middle]){
            direct = true;
        }else if(target < datas[*middle]){
            direct = false;
        }else if(target == datas[*middle]){
            result = true;
            break;
        }
        //範囲更新　direct = trueなら最小値更新、direct = falseなら最大値更新
        update_range(low,high,*middle,direct);
        //最小値、最大値の大小反転により探索失敗 *条件分岐
        if(*high < *low){
            result = false;
            break;
        }
    }


    //探索結果出力
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    if(result == true){
        printf("%dは素数です！ \n",target);
        printf("素数の中で小さい方から%d番目です！\n",*middle + 1);
        printf("実際の計算量は%dでした!\n",number);
        printf("システムを終了します");
    }else{
        printf("%dは1~1000までの素数ではありませんでした。\n",target);
        printf("システムを終了します\n");
    }
}
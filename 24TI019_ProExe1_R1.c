#include <stdio.h>
#include <math.h>
#define NUMBER 20

//平均の関数
double average(int v[], int n) {
	int sum = 0; //入力した値の合計を0に初期化する.
	for (int i = 0; i < n; i++) {
		sum += v[i]; //入力した値をsumに足していく
	}
	return (double)sum/n; //足した値を足した回数で割る
}
//標準偏差の関数
double Sdeviation(int v[], int n) {
	double dispersion_before = 0; //分散の合計を0に初期化する.
	for (int i = 0; i < n; i++) {
		//分散の(n-1)する前を求める.
		dispersion_before += pow(v[i] - average(v, n),2);
	}
	//(n-1)で割ったものの平方根を取る.
	return sqrt(dispersion_before / n);
}

int main(int argc, char *argv[]) {
	int integer[NUMBER] = { 0 };//入力した値を格納する.
	int number =0;//入力した個数
	puts("Please input integer:");
	do{	//数字を入力する.もしEOFなら抜ける
		if (scanf_s("%d", &integer[number])==EOF)break;
		number++;		
	}while (integer[number-1] != 0);
	number--;//余計に足された1を引く
	printf("Average: %.1f\n",average(integer, number));//平均の出力
	//標準偏差の出力
	printf("Standard Deviation: %.1f\n", Sdeviation(integer, number));
	return 0;
}
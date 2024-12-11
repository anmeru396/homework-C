#include <stdio.h>
#include <math.h>
#define NUMBER 20

//���ς̊֐�
double average(int v[], int n) {
	int sum = 0; //���͂����l�̍��v��0�ɏ���������.
	for (int i = 0; i < n; i++) {
		sum += v[i]; //���͂����l��sum�ɑ����Ă���
	}
	return (double)sum/n; //�������l�𑫂����񐔂Ŋ���
}
//�W���΍��̊֐�
double Sdeviation(int v[], int n) {
	double dispersion_before = 0; //���U�̍��v��0�ɏ���������.
	for (int i = 0; i < n; i++) {
		//���U��(n-1)����O�����߂�.
		dispersion_before += pow(v[i] - average(v, n),2);
	}
	//(n-1)�Ŋ��������̂̕����������.
	return sqrt(dispersion_before / n);
}

int main(int argc, char *argv[]) {
	int integer[NUMBER] = { 0 };//���͂����l���i�[����.
	int number =0;//���͂�����
	puts("Please input integer:");
	do{	//��������͂���.����EOF�Ȃ甲����
		if (scanf_s("%d", &integer[number])==EOF)break;
		number++;		
	}while (integer[number-1] != 0);
	number--;//�]�v�ɑ����ꂽ1������
	printf("Average: %.1f\n",average(integer, number));//���ς̏o��
	//�W���΍��̏o��
	printf("Standard Deviation: %.1f\n", Sdeviation(integer, number));
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
using namespace std;

/*ypedef struct {
	unsigned int i01 : 1;
	unsigned int i02 : 1;
	unsigned int i03 : 1;
	unsigned int i04 : 1;
	unsigned int i05 : 1;
	unsigned int row7 : 1;
	unsigned int row8 : 1;
} matrix;*/

void slove_relation_matrix(int *matrix1, int *matrix2, int *matrix3, int rank, int times) {
	static int count = 1;
	count++;
	if (times == 0) return;
	for (int i = 0; i < rank; i++) {
		for (int j = 0; j < rank; j++) {
			int temp = 0;
			for (int k = 0; k < rank; k++) {
				//cout << "the" << matrix1[i*rank + k] << matrix2[k*rank] << endl;
				temp += matrix1[i*rank + k] * matrix2[k*rank + j];
			}
			//cout << "the temp is "<<"with i j k ="<<i<<j<< temp<<endl;
			if (temp == 0) matrix3[i*rank + j] = 0;
			else matrix3[i*rank + j] = 1;
			temp = 0;
		}
	}
	cout << "the relation matrix of " << count << " squared is" << endl;
	for (int i = 0; i < rank; i++) {
		for (int j = 0; j < rank; j++) {
			printf(" %d ", matrix3[i*rank + j]);
		}
		cout << endl;
	}
	cout << endl;

	memset(matrix2, 0, sizeof(matrix2));

	slove_relation_matrix(matrix1, matrix3, matrix2, rank, --times);
	return;
}

int main() {
	int rank, times;
	cout << "what is the rank of the matrix: ";
	scanf("%d", &rank);
	int *matrix1 = (int*)malloc(rank*rank * sizeof(int));
	int *matrix2 = (int*)malloc(rank*rank * sizeof(int));
	int *matrix3 = (int*)malloc(rank*rank * sizeof(int));
	for (int i = 0; i < rank; i++) {
		for (int j = 0; j < rank; j++) {
			scanf("%d", &matrix1[i*rank + j]);
			matrix2[i*rank + j] = matrix1[i*rank + j];
			matrix3[i*rank + j] = 0;
		}
	}
	cout << "how many times you want to calculate: ";
	scanf("%d", &times);
	slove_relation_matrix(matrix1, matrix2, matrix3, rank, times);
	system("pause");
}

/*
4
0 1 0 0
1 0 1 0
0 0 0 1
0 0 0 0
4
*/
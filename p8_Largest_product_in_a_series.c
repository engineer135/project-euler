﻿#include <stdio.h>
#include <stdlib.h>

int main(void) {
	/*
	The four adjacent digits in the 1000-digit number that have the greatest product are 9 × 9 × 8 × 9 = 5832.

	73167176531330624919225119674426574742355349194934
	96983520312774506326239578318016984801869478851843
	85861560789112949495459501737958331952853208805511
	12540698747158523863050715693290963295227443043557
	66896648950445244523161731856403098711121722383113
	62229893423380308135336276614282806444486645238749
	30358907296290491560440772390713810515859307960866
	70172427121883998797908792274921901699720888093776
	65727333001053367881220235421809751254540594752243
	52584907711670556013604839586446706324415722155397
	53697817977846174064955149290862569321978468622482
	83972241375657056057490261407972968652414535100474
	82166370484403199890008895243450658541227588666881
	16427171479924442928230863465674813919123162824586
	17866458359124566529476545682848912883142607690042
	24219022671055626321111109370544217506941658960408
	07198403850962455444362981230987879927244284909188
	84580156166097919133875499200524063689912560717606
	05886116467109405077541002256983155200055935729725
	71636269561882670428252483600823257530420752963450

	Find the thirteen adjacent digits in the 1000-digit number that have the greatest product. What is the value of this product?
	
	아... 이게 라인이 다르면 근접한 수가 아니라고 생각해서 한참 헤맸다.
	그냥 숫자들 일렬로 세워놓고 해야 정답이 나옴.

	*/

	char buffer[1100];
	char largeestProduct[14] = { 0 };
	long long multiple = 1, largest = 0;
	int i=0, j=0, digits = 13;
	FILE *fp = NULL;
	fopen_s(&fp, ".\\p8_digits_smaple", "r");

	if (fp == NULL) {
		perror("file not exist!");
		return EXIT_FAILURE;
	}

	printf("start\n");

	// 라인 단위로 읽기
	while (!feof(fp)) {
		fgets(buffer, sizeof(buffer), fp);
		printf("buffer = %s", buffer);
		for (i = 0; i < sizeof(buffer); i++) {
			if (buffer[i] == '\n' || buffer[i] == '\0') {
				break;
			}
			//printf("inside buffer = %c\n", buffer[i]);

			if (buffer[i + digits] == '\n' || buffer[i + digits] == '\0') {// digits 자릿수가 안되는 경우 볼것도 없이 다음 라인으로
				break;
			}

			multiple = 1;
			for (j = 0; j < digits; j++) {
				if (buffer[i+j] == '\n' || buffer[i+j] == '\0') {
					break;
				}
				multiple = multiple * (buffer[i+j] - '0');
				//printf("multiple = %d\n", multiple);
				if (multiple == 0) {
					break;
				}
			}

			if (multiple > largest) {
				largest = multiple;
				for (j = 0; j < digits; j++) {
					largeestProduct[j] = buffer[i + j];
				}
			}
		}
	}
	
	printf("\n largest = %lld\n", largest); // 23514624000
	printf("largest Product = %s\n", largeestProduct); //5576689664895
	
	fclose(fp);

	return 0;
}
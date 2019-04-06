/* 
2019학년도 1학기 SW개발기초 1차 과제 
*/

#include <stdio.h>


// 1번 문제 
int getMinMaxDiff(int n)
{
	int max = -100;
	int min = 100;
	int result = 0;
		
	int a[n-1]; // 배열 선언 
	
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	} // 정수 입력
	
	for(int i = 0 ; i < n; i++) {
		if(a[i] < min) min = a[i];
		if(a[i] > max) max = a[i];
	} // 최솟값, 최댓값 구하기
		
	result = max - min;
	
	return result;
}

void quiz1()
{
	int n ;
	scanf("%d", &n);
	printf("%d", getMinMaxDiff(n));
}


// 2번 문제 
int getDigit(unsigned int n)
{
	int result = 0;
	int i = 1; // 나머지연산을 위한 변수 
	int s = 1; // 자릿수 
	
	while (s < 9){
		if (n % i == n){ // 나머지 연산을 하여 자릿값 계산 
			result = s-1; // result에 자릿값 저장 
			break;
		} 
		s++;
		i = i * 10;	
	}
	
	return result;
}

void quiz2()
{
	unsigned int n;
	
	scanf("%u", &n);
	printf("%d", getDigit(n));
}


//3번 문제 
void printDigitDiff(unsigned int n)
{
	int s = getDigit(n); // 자리숫 받아오기 
	int pow = 1;
	for (int i = 1; i < s; i++){
		pow = pow * 10;
	}
	// printf("%d\n ", pow);		
	
	while(pow >= 10){
		
		/* 확인용 
		printf("pow = %d\n", pow);
		printf("n값 = %d\n첫번쨰 값 = %d \n두번째 값 = %d \n",n, (n / pow), ((n % pow) / (pow / 10)) );
		*/
		
		int result = (n / pow) - ((n % pow) / (pow / 10));
		if (result < 0) result = -result;
		
		printf("%d", result);
		n = n % pow ;
		pow = pow / 10;
	}
}

void quiz3()
{
	unsigned int n;
	scanf("%u", &n);
	printDigitDiff(n);
}


// 4번 문제
int getDigitPattern(unsigned int n) 
{
	int s = getDigit(n); // 자리숫 받아오기 
	int pow = 1;
	for (int i = 1; i < s; i++){
		pow = pow * 10;
	}
	
	int r = 0;
	
	while(pow >= 10){
		int result = (n / pow) - ((n % pow) / (pow / 10));
		
		/*
		if (result < 0) r = 1;
		else r = -1;
		
		if (result < 0 && r == 1) r = 1;		
		else if (result > 0 && r == -1) r = -1;
		else r = 0 ;	
		*/
		
		if (result < 0) r++;
		else r--;
					
		n = n % pow ;
		pow = pow / 10;
	}
	if (r == (s-1)) r = 1;
	else if (r == -(s-1)) r = -1;
	else r = 0 ;
	
	return r;
}

void quiz4()
{
	unsigned int n;
	
	scanf("%u", &n);
	printf("%d", getDigitPattern(n));
}

int main(void)
{
	
	// quiz1();
	// 최댓값 - 최솟값 
	// quiz2();
	// 자릿수 구하기
	// quiz3();
	// 인접한 자릿수 빼기 
	quiz4();
	 	
}



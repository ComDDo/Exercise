/* 
2019�г⵵ 1�б� SW���߱��� 1�� ���� 
*/

#include <stdio.h>


// 1�� ���� 
int getMinMaxDiff(int n)
{
	int max = -100;
	int min = 100;
	int result = 0;
		
	int a[n-1]; // �迭 ���� 
	
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	} // ���� �Է�
	
	for(int i = 0 ; i < n; i++) {
		if(a[i] < min) min = a[i];
		if(a[i] > max) max = a[i];
	} // �ּڰ�, �ִ� ���ϱ�
		
	result = max - min;
	
	return result;
}

void quiz1()
{
	int n ;
	scanf("%d", &n);
	printf("%d", getMinMaxDiff(n));
}


// 2�� ���� 
int getDigit(unsigned int n)
{
	int result = 0;
	int i = 1; // ������������ ���� ���� 
	int s = 1; // �ڸ��� 
	
	while (s < 9){
		if (n % i == n){ // ������ ������ �Ͽ� �ڸ��� ��� 
			result = s-1; // result�� �ڸ��� ���� 
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


//3�� ���� 
void printDigitDiff(unsigned int n)
{
	int s = getDigit(n); // �ڸ��� �޾ƿ��� 
	int pow = 1;
	for (int i = 1; i < s; i++){
		pow = pow * 10;
	}
	// printf("%d\n ", pow);		
	
	while(pow >= 10){
		
		/* Ȯ�ο� 
		printf("pow = %d\n", pow);
		printf("n�� = %d\nù���� �� = %d \n�ι�° �� = %d \n",n, (n / pow), ((n % pow) / (pow / 10)) );
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


// 4�� ����
int getDigitPattern(unsigned int n) 
{
	int s = getDigit(n); // �ڸ��� �޾ƿ��� 
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
	// �ִ� - �ּڰ� 
	// quiz2();
	// �ڸ��� ���ϱ�
	// quiz3();
	// ������ �ڸ��� ���� 
	quiz4();
	 	
}



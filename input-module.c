/*

This file contains functions to facilitate input of mathematical equations.

*/
#include<stdio.h>
#include<string.h>
#include<math.h>
#define EQ_LENGTH 32
#define COEF_LENGTH 8
float getFloat(char coef[COEF_LENGTH]);
void getEq(int n); // Takes number of unknows as input
// driver function
int main(){
	char arr[COEF_LENGTH];
	scanf("%s",arr);
	getFloat(arr);
	return 0;
}
void getEq(int n){
	char eq[EQ_LENGTH];
	float matrix[n][n+1];
	int i, j, k;
	for(i=0;i<n;i++){
		fgets(eq, EQ_LENGTH, stdin);
		// now extract info from eq
		for(j=0;j<strlen(eq);j++){
			if(eq[j]==32){
				continue;
			}
			else if((eq[j]>=48 && eq[j]<=57) || eq[j]=='.' || eq[j]=='/'){
				printf("%c", eq[j]);
			}
			else if(eq[j]=='+' || eq[j]=='-' || eq[j]=='='){
				printf(" ");
			}
		}
	}
}
float getFloat(char coef[COEF_LENGTH]){
	int len, i;
	int decimal_flag=-1, fraction_flag = -1;
	float coef_value = 0;
	len = strlen(coef);
	for(i=0;i<len;i++){
		if(coef[i]>=48 && coef[i]<=57){
			if(fraction_flag>=0){
				fraction_flag = fraction_flag + (coef[i]-48);
				fraction_flag = fraction_flag*10;
				continue;
			}
			coef_value = coef_value + (coef[i]-48);
		}
		else if(coef[i]=='.'){
			coef_value = coef_value/10;
			decimal_flag++;
		}
		else if(coef[i]=='/'){
			// do something here as well
			coef_value = coef_value/10;
			fraction_flag++;
			printf("value at slash %f\n",coef_value);
		}
		if(decimal_flag>=0){
			decimal_flag++;
		}
		coef_value = coef_value*10;
	}
	if(decimal_flag >= 0){
		coef_value = coef_value/pow(10, decimal_flag);
	}
	else{
		coef_value = coef_value/10;
	}
	fraction_flag = fraction_flag/10;
	if(fraction_flag>0){
		coef_value = coef_value/fraction_flag;
	}
	printf("Value: %f\n",coef_value);
}

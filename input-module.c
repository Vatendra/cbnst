/*

This file contains functions to facilitate input of mathematical equations.

*/
#include<stdio.h>
#include<string.h>
#define EQ_LENGTH 32
void getEq(int n); // Takes number of unknows as input
// driver function
int main(){
	getEq(3);
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

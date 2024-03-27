#include "calculator.h"
#include "clockinit.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "math.h"

void add_to_expression(char expression[], char new_char){
	for (int i = 0; i < 16; i++) {
		if (expression[i] == '\0'){
			expression[i] = new_char;
			return;
		}
	}
	SysTick_Wait_ys(10);
}

void reset_expression(char expression[]){

	 memset(expression, '\0', 16);
	 SysTick_Wait_ms(1);
}

float char_to_num(char char_array[]){

    float result = 0;
    int negative = 0;
    int i = 0;

    if (char_array[0] == '-') {
        negative = 1;
        i = 1;
    }

    while (i < 32) {
			if (char_array[i] == '\0'){ break; }
       result = (result * 10) + (char_array[i] - '0');
			 i++;
		}
    if (negative) {
        result = -result;
    }

    return result;
}




void num_to_char(float number, char chars[]){

	sprintf(chars, "%.2f", number);

}


float calculate(char expression[]){
	char cnum1[32]; 
	char cnum2[32];
	char cnum3[32];
	char cnum4[32];
	int num1;
	int num2;
	int num3;
	int num4;
	float ans;
	float nums[8];
	char ops[16];
	int add = 0;
	int sub = 0;
	int mul = 0;
	int div = 0;
	int op_count_const = 0;
	int op_count = 0;

	for (int i=0; i<16; i++){
		if (expression[i] == '\0') {break; }
		if (expression[i] == '*') { add_to_expression(ops, '*'); mul++; op_count++;}
		else if (expression[i] == '/') { add_to_expression(ops, '/'); div++; op_count++;}
		else if (expression[i] == '+') { add_to_expression(ops, '+'); add++; op_count++;}
		else if (expression[i] == '-') { add_to_expression(ops, '-'); sub++; op_count++;}
		else if (op_count == 0) {add_to_expression(cnum1, expression[i]);}
		else if (op_count == 1) {add_to_expression(cnum2, expression[i]);}
		else if (op_count == 2) {add_to_expression(cnum3, expression[i]);}
		else if (op_count == 3) {add_to_expression(cnum4, expression[i]);}
	}
	op_count_const = op_count;
	if (op_count == 0){ 
    sscanf(cnum1, "%d", &num1);
	} else if (op_count == 1) {	
    sscanf(cnum1, "%d", &num1);
    sscanf(cnum2, "%d", &num2);
	} else if (op_count == 2) {	
    sscanf(cnum1, "%d", &num1);
    sscanf(cnum2, "%d", &num2);
    sscanf(cnum3, "%d", &num3);
	} else if (op_count == 3) {
    sscanf(cnum1, "%d", &num1);
    sscanf(cnum2, "%d", &num2);
    sscanf(cnum3, "%d", &num3);  
		sscanf(cnum4, "%d", &num4);
	}
	nums[0] = num1;
	nums[1] = num2;
	nums[2] = num3;
	nums[3] = num4;

	while (op_count>=1){
		while (mul>0){
		for (int i=0; i<8; i++){
			if (ops[i]=='*'){nums[i] = nums[i]*nums[i+1]; nums[i+1]=nums[i]; ops[i]='\0'; mul--;}
			}
		}
		while (div>0){
		for (int i=0; i<8; i++){
			if (ops[i]=='/'){nums[i] = nums[i]/nums[i+1]; nums[i+1]=nums[i]; ops[i]='\0'; div--;}
			}
		}		while (sub>0){
		for (int i=0; i<8; i++){
			if (ops[i]=='-'){nums[i] = nums[i]-nums[i+1]; nums[i+1]=nums[i]; ops[i]='\0'; sub--;}
			}
		}		while (add>0){
		for (int i=0; i<8; i++){
			if (ops[i]=='+') {nums[i] = nums[i]+nums[i+1]; nums[i+1]=nums[i]; ops[i]='\0'; add--;}
			}
		}
		op_count--;
	}
	if (op_count_const < 2){ ans = nums[0]; }
	else { ans = nums[1]; }
	return ans;
}
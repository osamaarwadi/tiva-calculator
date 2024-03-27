#ifndef calculator_h

	float char_to_num(char char_arr[]);
	void num_to_char(float number, char chars[]);
	void add_to_expression(char expression[], char new_char);
	void reset_expression(char expression[]);
	float calculate(char expression[]);

#endif
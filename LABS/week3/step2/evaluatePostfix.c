#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <math.h>
#include "stack.h"


int main()
{
	char str[MAXSIZE + 1];
	stack_t mystack;

	while(1)
	{
		printf("postfix> ");
		if(fgets(str, sizeof(str), stdin) == NULL)
			break; // EOF (Ctrl-D)
		str[strcspn(str, "\n")] = '\0';

		if(strcasecmp(str, "exit") == 0 || strcasecmp(str, "quit") == 0)
			break;

		init_stack(&mystack); // reset for a fresh expression

		char *s = str;
		char ch;
		int val1; int val2;
		int val = 0;
		int is_num = 0;
		int had_error = 0;

		while( (ch = *s++) != '\0')
		{
			if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
			{
				if(is_empty(&mystack)){
					printf("Error: stack underflow\n");
					had_error = 1;
					break;
				}
				val1 = pop(&mystack);
				if(is_empty(&mystack)){
					printf("Error: stack underflow\n");
					had_error = 1;
					break;
				}
				val2 = pop(&mystack);
				switch(ch)
				{
					case '+' : push(&mystack,val2 + val1);
						   break;
					case '-' : push(&mystack,val2 - val1);
						   break;
					case '*' : push(&mystack,val2 * val1);
						   break;
					case '^' : push(&mystack, (int)pow(val2, val1));
						   break;
					case '/' :
						   if(val1 == 0){
							printf("Error: division by zero\n");
							had_error = 1;
						   }
						   else{
							push(&mystack,val2 / val1);
						   }
						   break;
				}
				if(had_error) break;
			}
			else if(ch >= '0' && ch <= '9')
			{
				is_num = 1;
				val = val * 10 + ch - '0';
			}
			else if (ch == ' ')
			{
				if(is_num)
				{
					push(&mystack, val);
					val = 0;
					is_num = 0;
				}
			}
			else{
				printf("Error: invalid character '%c'\n", ch);
				had_error = 1;
				break;
			}
		}

		if(had_error)
			continue;

		if(is_num){push(&mystack, val);}

		val = pop(&mystack);
		if(!is_empty(&mystack)){
			printf("Error: malformed expression, leftover operands\n");
			continue;
		}
		printf("Result = %d\n", val);
	}

	return 0;
}

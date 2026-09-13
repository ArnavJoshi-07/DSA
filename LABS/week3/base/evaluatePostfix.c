#include <stdio.h>
#include <string.h>
#include "stack.h"

// evaluate postfix expression
int main()
{
	char str[MAXSIZE + 1]; char *s = str;
	fgets(str, sizeof(str), stdin);
	str[strcspn(str, "\n")] = '\0';
	printf("input expression : :%s:\n", s);
	stack_t mystack;
	init_stack(&mystack);

	char ch;
	int val1; int val2;
	int val = 0;
	int is_num = 0;
	while( (ch = *s++) != '\0')
	{
		if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
		{
			val1 = pop(&mystack);
			val2 = pop(&mystack);
			switch(ch)
			{
				case '+' : push(&mystack,val2 + val1);
					   break;
				case '-' : push(&mystack,val2 - val1);
					   break;
				case '*' : push(&mystack,val2 * val1);
					   break;
				case '/' :
					   if(val1 == 0){
						printf("Division by zero not allowed!!\n");
						return 1;
					   }
					   else{push(&mystack,val2 / val1);
					   break;}

			}
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
			printf("Invalid Character;\n");
			return 1;
		}
	}
	if(is_num){push(&mystack,val);}

	val = pop(&mystack);
	if(is_empty(&mystack))
	printf("result : %d\n", val);
	else printf("Malformed Expression!!\n");
	deinit_stack(&mystack);

	return 0;
}

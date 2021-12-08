#include<stdio.h>
#include<string.h>
#include<ctype.h>

char a[20],exp1[10],result[10],item;
int top=0,i=0,k=0,l,x;

void push(char item) {
	a[++top]=item; 
}
char pop(void) {
	item=a[top--];
	return(item); 
}

int icp(char item) {
	if(item=='+'||item=='-')
	return(1);
	else if(item=='*'||item=='/')
	return(2);
	else if(item=='^')
	return(3);
	else
	return(0);
}

void quad() {
	int i,x=0;
	char m,n,temp,str1[5],str2[5];
	printf("\n\noperator\top1\top2\tresult\n");
	printf("---------------------------------------");
	for(i=0;i<l;i++) {
		if(isalnum(result[i]))
			push(result[i]); 
		else
		{
			if(isalpha(m=pop()))
			{
				str1[0]=m;
				str1[1]='\0'; 
			}
			else
			{
				str1[0]='t';
				str1[1]=m;
				str1[2]='\0'; 
			}
			if(isalpha(n=pop()))
			{
				str2[0]=n;
				str2[1]='\0'; 
			}
			else
			{
				str2[0]='t';
				str2[1]=n;
				str2[2]='\0'; 
			}
			x++;
			printf("\n   %c\t\t %s\t %s\t t%d\n",result[i],str2,str1,x);
			temp=x+'0';
			push(temp);
		} 
	} 
}

int main()
{
	printf("Enter the infix expression: ");
	scanf("%s",exp1);
	l=strlen(exp1);
	printf("\nPostfix expression: ");
    a[top]='#';
	while((item=exp1[i])!='\0')
	{
		if(isalpha(item)) { 
				printf("%c",item); 
				result[k++]=item;
		}
		else if(item=='+'||item=='-'||item=='*'||item=='/'||item=='^') {
			if(icp(a[top])<icp(item))
				a[++top]=item;
		  	else {
				while(icp(a[top])>=icp(item)){
					printf("%c",a[top]); 
					result[k++]=a[top];  
					top--;
				}
				a[++top]=item;
		  	}

	    }
        i++;
    }
   	while(top>0) {
		printf("%c",a[top]); 
		result[k++]=a[top];
		top--;
    }
quad();
return 0;
}

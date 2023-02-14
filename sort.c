#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void usage();
int is_valid_num(char *word);
void swap(double *x, double *y);
void sort(double *a, int length);

void swap(double *x, double *y)
{
	double temp = *x;
	*x = *y;
	*y = temp;
}

void sort(double *a, int length)
{
	int i = 1;
        while (i < length)
        {
                int j = i;
                while (j > 0 && a[j-1] > a[j])
		{
			swap(&a[j], &a[j-1]);
			j -= 1;
		}
		i += 1;
        }
}

int is_valid_num(char *word)
{
	int found_dot = 0;
	for (int i=0; i<strlen(word); ++i)
	{
		if (word[i] == '-')
		{
            		if (i != 0)
            		{		
                		printf("%s is not a valid number.\n", word);
				return 0;
            		}
            		continue;
        	}
        	if (word[i] == '.')
        	{	
            		if (found_dot == 1)
            		{
                		printf("%s is not a valid number.\n", word);
				return 0;
            		}
            		found_dot = 1;
            		continue;
        	}
        	if (!isdigit(word[i]))
        	{
            		printf("%s is not a valid number.\n", word);
			return 0;
        	}
    	}
	return 1;
}

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("usage: sort [-r] num1 num2 ...\n       -r: reverse sort\n");
		return 1;
	}
	if ((strcmp(argv[1], "-r") == 0) && (argc >= 2))
	{
        	if (argc == 2)
        	{
                	printf("usage: sort [-r] num1 num2 ...\n       -r: reverse sort\n");
                	return 1;
        	}
		double *a = (double *)malloc((argc - 2) * sizeof(double));
                double current;
                for (int i = 2; i < argc; i++)
                {
			int is_number = is_valid_num(argv[i]);
        		if (is_number == 0)
        		{
                		printf("usage: sort [-r] num1 num2 ...\n       -r: reverse sort\n");
                		return 1;
        		}
                        current = atof(argv[i]);
                        a[i-2] = current;
                }
                sort(a, argc - 2);
		for (int i = argc-3; i > -1; i--)
                {
                        printf("%g\n", a[i]);
                }
	}
	else
	{
		double *a = (double *)malloc((argc - 1) * sizeof(double));
		double current;
		for (int i = 1; i < argc; i++)
		{
                        int is_number = is_valid_num(argv[i]);
                        if (is_number == 0)
                        {
                                printf("usage: sort [-r] num1 num2 ...\n       -r: reverse sort\n");
                                return 1;
                        }		
			current = atof(argv[i]);
			a[i-1] = current;
		}
		sort(a, argc - 1);
		for (int i = 0; i < argc-1; i++)
                {
			printf("%g\n", a[i]);
                }

	}	
    	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIGITS 10000  // maximum number of digits in the result

char *divide(char *dividend, char *divisor) 
{
    // allocate memory for the result
    char *result = malloc(MAX_DIGITS + 1);
    memset(result, 0, MAX_DIGITS + 1);

    // determine the sign of the result
    int sign = 1;
    if (dividend[0] == '-' && divisor[0] != '-') 
    sign = -1;
    else if (dividend[0] != '-' && divisor[0] == '-') 
    sign = -1;
    // remove the sign from the dividend and divisor
    if (dividend[0] == '-') 
    dividend++;
    if (divisor[0] == '-') 
    divisor++;
    // pad the dividend with zeros if necessary
    int padding = strlen(divisor) - strlen(dividend);
    if (padding > 0) 
    {
        for (int i = strlen(dividend); i >= 0; i--) 
        dividend[i + padding] = dividend[i];
        for (int i = 0; i < padding; i++) 
        dividend[i] = '0';
    }

    // perform the division
    int quotient_index = 0;
    char *temp = (char *)malloc(strlen(dividend) + 1);
    while (strlen(dividend) >= strlen(divisor)) 
    {
        int quotient = 0;
        while (strcmp(dividend, divisor) >= 0) 
        {
            quotient++;
            char *temp = (char *)malloc(strlen(dividend) + 1);
            strcpy(temp, dividend);
            for (int i = strlen(temp) - 1; i >= 0; i--) 
            {
                temp[i] = temp[i] - '0' - divisor[i] + '0';
                if (temp[i] < '0') 
                {
                    temp[i] += 10;
                    temp[i - 1]--;
                }
            }     
            while (*temp == '0' && strlen(temp) > 1) 
            temp++;
            strcpy(dividend, temp);
            free(temp);
        }
        result[quotient_index++] = quotient + '0';
        char *temp = (char *)malloc(strlen(dividend) + 1);
        strcpy(temp, dividend);
        if (strlen(temp) == strlen(divisor)) 
        {
            for (int i = strlen(temp) - 1; i >= 0; i--) 
            {
                temp[i] = temp[i] - divisor[i] + '0';
                if (temp[i] < '0') 
                {
                temp[i] += 10;
                temp[i - 1]--;
                }
                while (*temp == '0' && strlen(temp) > 1)
                temp++;
            }
        }
        else
        {
            for (int i = strlen(temp) - 1; i > 0; i--) 
            {
                temp[i] = temp[i] - divisor[i] + '0';
                if (temp[i] < '0') 
                {
                    temp[i] += 10;
                    temp[i - 1]--;
                }
            }
            temp[0] = temp[0] - divisor[0] + '0';
        }
    }
    strcpy(dividend,temp);
    free(temp);
    // add the sign to the result
    if (sign == -1) 
    {
        for (int i = strlen(result); i >= 0; i--) 
        result[i + 1] = result[i];
        result[0] = '-';
    }
    return result;
}
int main() {
  char *dividend = (char *)malloc(MAX_DIGITS);
  char *divisor = (char *)malloc(MAX_DIGITS);
  gets(dividend);
  gets(divisor);
  char *result = divide(dividend, divisor);
  printf("%s\n", result);
  free(result);
  return 0;
}
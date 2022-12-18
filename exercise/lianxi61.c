#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIGITS 10000  // maximum number of digits in the result

int compare(char *str1, char *str2);

void subtract(char *str1, char *str2, char *result);

void divide(char *dividend, char *divisor, char *result) {
  // handle case where divisor is larger than dividend
  if (compare(dividend, divisor) < 0) {
    strcpy(result, "0");
    return;
  }

  int dividend_len = strlen(dividend);
  int divisor_len = strlen(divisor);
  int result_len = dividend_len - divisor_len + 1;
  char quotient[MAX_DIGITS];
  char remainder[MAX_DIGITS];
  int i;

  // initialize quotient and remainder
  memset(quotient, 0, MAX_DIGITS);
  memset(remainder, 0, MAX_DIGITS);

  // perform long division
  subtract(dividend,divisor,remainder);
  for (i = 0; i < result_len; i++) {
    quotient[i] = '0';
    while (compare(remainder, divisor) >= 0) {
      quotient[i]++;
      subtract(remainder, divisor, remainder);
    }
    remainder[divisor_len + i] = dividend[i + divisor_len];
  }
  quotient[result_len] = '\0';
  strcpy(result, quotient);
}


int compare(char *str1, char *str2) {
  int len1 = strlen(str1);
  int len2 = strlen(str2);
  int i;

  if (len1 > len2) return 1;
  if (len1 < len2) return -1;
  for (i = 0; i < len1; i++) {
    if (str1[i] > str2[i]) return 1;
    if (str1[i] < str2[i]) return -1;
  }
  return 0;
}

void subtract(char *str1, char *str2, char *result) {
  int len1 = strlen(str1);
  int len2 = strlen(str2);
  int i;
  int borrow = 0;

  for (i = 0; i < len2; i++) {
    int diff = str1[i] - str2[i] - borrow;
    if (diff < 0) {
      borrow = 1;
      diff += 10;
    } else {
      borrow = 0;
    }
    result[i] = diff + '0';
  }
  for (; i < len1; i++) {
    int diff = str1[i] - '0' - borrow;
    if (diff < 0) {
      borrow = 1;
      diff += 10;
    } else {
      borrow = 0;
    }
    result[i] = diff + '0';
  }
  result[i] = '\0';

  // remove leading zeros
  i = 0;
  while (result[i] == '0' && result[i+1] != '\0') {
    i++;
  }
  strcpy(result, result+i);
}
int main() {
  char dividend[MAX_DIGITS];
  char divisor[MAX_DIGITS];
  char result[MAX_DIGITS];

  // read the dividend and divisor from the user
  printf("Enter the dividend: ");
  scanf("%s", dividend);
  printf("Enter the divisor: ");
  scanf("%s", divisor);

  // perform division
  divide(dividend, divisor, result);

  // print the result
  printf("Result: %s\n", result);

  return 0;
}

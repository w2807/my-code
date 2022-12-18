#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 1000 // 被除数和除数的最大长度

int main()
{
    char dividend[MAX_LEN]; // 被除数
    char divisor[MAX_LEN];  // 除数
    char quotient[MAX_LEN]; // 商
    char remainder[MAX_LEN]; // 余数
    int len1, len2; // 被除数和除数的长度
    int i, j;
    int temp, carry; // 临时变量和进位
    int quotient_digit; // 商的每一位

// 读入被除数和除数
    scanf("%s %s", dividend, divisor);
    len1 = strlen(dividend);
    len2 = strlen(divisor);

// 从低位到高位逐位进行除法运算
    for (i = 0; i < len1; i++)
    {
        temp = 0;
        for (j = 0; j < i; j++)
            temp = temp * 10 + quotient[j];
        carry = 0;
        for (j = 0; j < len1 - i; j++)
        {
            temp = temp * 10 + dividend[i + j] - '0';
            if (temp - carry < 0) {
                carry -= divisor[j] - '0';
            }
            quotient_digit = (temp - carry) / (divisor[j] - '0');
            carry = quotient_digit * (divisor[j] - '0');
            quotient[i + j] = quotient_digit + '0';
        }
        remainder[i] = temp - carry + '0';
    }

// 去掉商前导的 0
    i = 0;
    while (quotient[i] == '0' && i < len1 - len2)
        i++;

// 输出商和余数
    for (j = i; j < len1 - len2 + 1; j++)
        printf("%c", quotient[j]);
    printf("\n");
    for (j = 0; j < len2 - 1; j++)
        printf("%c", remainder[j]);
    printf("\n");
    return 0;
}
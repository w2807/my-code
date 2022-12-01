#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int dot_pos(char *in, int len);
int show_mul(int *res_m, char *in1, char *in2, int len1, int len2, int pos1, int pos2);

int test_data(char *in)//Test the data, the data only including number digit or dot. The input as
//string form.
{
  int i, len = strlen(in);

  for (i = 0; i <= len - 1; i++)
    {
      if ( !(0 <= (int)(in[i] - 48) && (int)(in[i] - 48) <= 9 ) && in[i] != '.')// If the in[i]
	// is not number digit and not dot, return 0.
	return 0;
    }

  return 1;
}

int res_dot(char *in1, char *in2, int len1, int len2)
//Decide the position of dot in add and sub computing result, notice this function is not for
//multiplication and division operation. The first argument is input1 as string form, the second
//argument is input2 as string form, the third argument is the length of the first argument, the last
//argument is the length of the second argument.
{
  if (dot_pos(in1, len1) >= dot_pos(in2, len2))
    return dot_pos(in1, len1);

  return dot_pos(in2, len2);
}


int res_len(int len1, int len2, int pos1, int pos2)// Return the length of result, this function is
//not for multiplication and division operation. We treat a number as two parts, one part is before
//dot, and the other is after dot. The length of add result should be the sum of lengths of this
//two parts that corresponding part longer comparing between two plus numbers, and add 1.
    
{
  int len;

  if (pos1 >= pos2)//For before dot, determine which is longer.
    len = pos1;
  else
    len = pos2;

  if ((len1 - pos1) >= (len2 - pos2))//For after dot, determine which is longer.
    len += len1 - pos1;
  else
    len += len2 - pos2;
  
  return len;// Return the sum of this two longer lengths as length of add result.
}


int store(char *in)// Store input as char string.
{
  scanf("%s", in);

  return 0;
}


int t_store(char *in)// Test for store function.
{
  puts(in);

  return 0;
}


int ctoi(char *in, int len_in, int *ini,  int pos, int res_pos)
// Convert char in string to int, and keep their form is uniform, the meaning of uniform is that
//they have same length and aligned dot after convert.
{
  int i, k;
  i = pos - 1;
  k = res_pos - 1;
  
  while (i >= 0)//First convert before dot part.
    {
      ini[k] = (int)(in[i] - 48);
      i--;
      k--;
    }

  i = pos + 1;
  k = res_pos;

  while (i <= len_in - 1)//Then convert after dot part.
    {
      ini[k] = (int)(in[i]-48);
      i++;
      k++;
    }
  
  return 0;
}


int t_ctoi(int *ini, int max_len)// Test for convert function

{
  int i;

  for (i = 0; i <= max_len - 1; i++)
    printf("%d", ini[i]);

  printf("\n");
  
  return 0;
}


int add(int *res, int *ini1, int *ini2, int max_len)
// Add two integer, they store in int array.
{
  int i, tmp, jw = 0, k = max_len;

  for (i = max_len - 1; i >= 0; i--)
    {
      tmp = ini1[i] + ini2[i];// Add the two number digits.
      res[k] = (jw + tmp) % 10;// The result digit should be modulus of sum of carry and two number
      //digits.
      jw = (tmp + jw) / 10;
      k--;
    }

  res[0] = jw;// Note that the carry can be reach the highest position.
  
  return 0;
}


int show_add(int *res, int len, int res_pos)// Show the computing result of addition.
{
  int i;

  if (res[0] != 0)// If no carry in the highest position, we don't need output this digit.
    printf("%d", res[0]);
  
  for (i = 1; i <= len - 1; i++)
    {
      if (i == res_pos + 1)// Because add maybe create carry bit,
	//so dot position different.
	printf(".");

      printf("%d", res[i]);
    }
    
  printf ("\n");

  return 0;
}


int show_sub(int *res, int len, int res_pos, int indi)//Show result of sub operation, the first
//argument is result, the second argument is length of string, the third argument is the dot
//position of sub result, and the last argument is a indicator to judge whether the result is
//a negative number.
{
  int i = 0, start;

  if (indi == 2)// First we need to know which number is larger so that we determine the output of
    //minus.
    printf("-");
  
  while (i <= len - 1 && i != res_pos)//Seek the first no zero position of sub result.
    {
      if (res[i] == 0)
	{
	  i++;
	  continue;
	}

      break;
    }

  start = i;// From the first no zero position output.

  if (start == res_pos)
    printf("0");
  
  for (; start <= len - 1; start++)
    {
      if (start == res_pos)// If the position equal to dot position of sub result.
	printf(".");// Print the dot.

      printf("%d", res[start]);
    }

  printf("\n");
  
  return 0;
}


int judge(int *ini1, int *ini2, int max_len)// Judge the size of this two number for sub operation.
{
  int i;

  for (i = 0; i <= max_len - 1; i++)
    {
      if (ini1[i] == ini2[i])
	continue;

      else if (ini1[i] > ini2[i])// The first argument larger than the second argument, return 1.
	return 1;

      else if (ini2[i] > ini1[i])// The second argument larger than the first argument ,return 2.
	return 2;
    }

  return 0;
}


int sub(int *res, int *ini1, int *ini2, int max_len, int indi)// Subtraction operation, the result
//of sub is store in first argument, the second argument is subtraction number and the third is be
//subtracted, the forth is max length of this two inputs, the last argument is an indicator that
//indict which one is larger(or smaller).
{
  int i, tmp, jw = 0;
  
  if (indi == 1)// By indicator we always use the larger number sub to smaller.
    {
      for (i = max_len - 1; i >= 0; i--)
	{
	  if ((ini1[i] - jw ) < ini2[i])// First minus borrow bit, then compare.
	    {
	      tmp = ini1[i] - jw + 10;// If we need to borrow, we need add ten.
	      res[i] = tmp - ini2[i];
	      jw = 1;
	    }

	  else// Don't borrow.
	    {
	      tmp = ini1[i] - jw;
	      res[i] = tmp - ini2[i];
	      jw = 0;
	    }
	}
    }

  if (indi == 2)
    {
      for (i = max_len - 1; i >= 0; i--)
	{
	  if ((ini2[i] - jw ) < ini1[i])// First minus borrow bit, then compare.
	    {
	      tmp = ini2[i] - jw + 10;
	      res[i] = tmp - ini1[i];
	      jw = 1;
	    }

	  else
	    {
	      tmp = ini2[i] - jw;
	      res[i] = tmp - ini1[i];
	      jw = 0;
	    }
	}
    }
  
  return 0;
}


int mul_sin(int *res_sin, int *ini_m, int width_m,  int mulor)// Multiplication for form such as ,
//4 * 34123, aka only one digit multiply a number, the result is store in the first argument. The
//"normal" number is the second argument, the last number is single digit, 4 example here. And the
//third argument is the length of the second argument. This function is prepare for multiplication
//operation.
{
  int i, k = width_m, jw = 0, tmp;

  for (i = width_m - 1; i >= 0; i--)
    {
      tmp = mulor * ini_m[i] + jw;// Add as temporary value.
      res_sin[k] = tmp % 10;// The result digit should be modules.
      jw = tmp / 10;// Computing carry.
      k--;// Start multiplication with the last digit of second argument, so k--.
    }

  res_sin[0] = jw;// Note that the carry maybe go to the highest digit.

  return 0;
}


int dot_judge(char *in, int len)// Judge the input existing of dot in input.
{
  int i;

  for (i = 0; i <= len - 1; i++)
    {
      if (in[i] == '.')
	return 1;
    }

  return 0;
}


int t_mul_sin(int *res_sin, int width_m)// Test function.
{
  int i;

  if (res_sin[0] != 0)
    printf("%d", res_sin[0]);
  
  for (i = 1; i <= width_m; i++)
    printf("%d", res_sin[i]);
  
  printf("\n");

  return 0;
}

int dot_pos(char *in, int len)// Return the dot position of input string.
{
  int i;

  for (i = 0; i <= len - 1; i++)
    {
      if (in[i] == '.')
	return i;
    }

  return len;
}


int ctoi_m(char *in, int len, int *res_m)// Converting function for multiplication.
{
  int i, k = 0;

  for (i = 0; i <= len - 1; i++)
    {
      if (in[i] != '.')
	{
	  res_m[k] = (int)(in[i] - 48);
	  k++;
	}
    }

  return 0;
}


int t_ctoi_m(int *ini_m, int width_m)// Test function.
{
  int i;
  
  for (i = 0; i <= width_m - 1; i++)
    printf("%d", ini_m[i]);

  printf("\n");
  return 0;
}


int width_m(char *in, int len)// Return the length of input for multiplication operation, sub to
// 1 if there is a dot in input.
{
  int width_m;
  if (dot_judge(in, len))
    width_m = len - 1;
  else
    width_m = len;

  return width_m;
}


int init_tmp(int *tmp_m, int len)// This function is not use.
{
  int i = 0;

  for (i = 0;i <= len - 1; i++)
    tmp_m[i] = 0;

  return 0;
}


int add_m(int *res_m, int *tmp_m, int width_tmp, int offset)// Add for multiplication, the result
//is store in the first argument, and the second argument was added. the third argument is the
//length of the added number, the last number is offset, for example, add 43553354 and 3452355, 
//4355335|4               435533|54                43553|354
//       |  offset is 1,        |   offset is 2,        |    offset is 3.
//3452355|               3452355|                3452355|
{
  int i = 999998 - offset, tmp, jw = 0;
  int j = width_tmp - 1;

  while (j >= 0)
    {
      tmp = tmp_m[j] + res_m[i];
      res_m[i] = (jw + tmp) % 10;
      jw = (tmp + jw) / 10;
      i--;
      j--;
    }

  while (i >= 0)
    {
      tmp = res_m[i];
      res_m[i] = (jw + tmp) % 10;
      jw = (tmp + jw) / 10;
      i--;
    }

  return 0;
}


int mul(int *ini_m1, int *ini_m2, int *res_m, int width_m1, int width_m2)// The multiplication
//operation, the first and second argument are inputs, and result of multiplied is stored in the
//third argument, and the forth argument is the length of the first argument, the last argument is
//the length of the second argument.
{
  int i, offset = 0;
  int *tmp_m = (int*)malloc((width_m1 + 1) * sizeof(int));// This variable is store temporary
  //multiplied result.

  for (i = width_m2 - 1; i >= 0; i--)
    {
      mul_sin(tmp_m, ini_m1, width_m1, ini_m2[i]);//For each element in the second argument,
      //multiply the the first argument.

      add_m(res_m, tmp_m, width_m1 + 1, offset);// Add the temporary result.

      init_tmp(tmp_m, width_m1 + 1);
      
      offset++;//The add in multiplication is offset.
    }
  
  return 0;
}


int find(int *res_m, int dot_pos)// Find the first no zero element in multiplication result until
//dot position, the first argument is result, and the second is the position of dot in result.
{
  int i = 0;

  for (i = 0; i <= dot_pos - 1; i++)
    {
      if (res_m[i] != 0)
	return i;
    }

  return i;
}


int dot_mul(char *in1, char *in2, int len1, int len2, int pos1, int pos2)// Identify the dot
//position of multiplication result.
{ 
  int dot_left = (len1 - pos1 - 1 + len2 - pos2 - 1);

  return 999998 - dot_left;
}


int show_mul1(int *res_m, char *in1, char *in2, int len1, int len2, int pos1, int pos2)// Show the
//result of multiplication result. The first argument is result, the second argument is input1 as
//string form, and the third argument is input2 as string form, the forth argument is the length of
//the second argument, the fifth argument is the length of the third argument, the sixth argument is
//the dot position of the second argument, and the last argument is the dot position of the third
//argument.
{
  int dot_pos = dot_mul(in1, in2, len1, len2, pos1, pos2);// Identify the dot position of result.
  int no_z = find(res_m, dot_pos);// Find the first no zero element in result.
  int i;

  for (i = no_z; i <= dot_pos; i++)// Output before dot position part.
    printf("%d", res_m[i]);

  printf(".");// Print dot.

  for (i = (dot_pos + 1); i <= 999998; i++)// Output after dot position part.
    printf("%d", res_m[i]);
      
  printf("\n");

  return 0;
}


int add_dot_m(char *in1, char *in2)// If the input no dot, add it at length. The two arguments are
//inputs as string form.
{
  int len1 = strlen(in1);
  int len2 = strlen(in2);
  
  if (!dot_judge(in1, len1))
    in1[len1] = '.';

  if (!dot_judge(in2, len2))
    in2[len2] = '.';

  return 1;
}


int main(int argc, char *argv[])
{
  char in1[999999], in2[999999], op;// in1 and in2 are inputs as string form, op is operation such
  //as +, -, *, /.
  int *res_m = (int*)malloc(999999 * sizeof(int));

  printf("Please input the operation that you want(+, -, * or /): ");
  scanf("%c", &op);

  printf("Please input the two operands, parting them by enter:\n");

  printf("The first operand:\n");
  store(in1);
  printf("The second operand:\n");
  store(in2);

  if (op == '*')
    add_dot_m(in1, in2);//If the user want multiplication, first add dot at end if the input no dot.

  int len1 = strlen(in1);
  int pos1 = dot_pos(in1, len1);

  int len2 = strlen(in2);
  int pos2 = dot_pos(in2, len2);

  int  max_len = res_len(len1, len2, pos1, pos2);

  int *ini1 = (int*)malloc(max_len * sizeof(int));
  int *ini2 = (int*)malloc(max_len * sizeof(int));

  int *res = (int*)malloc(max_len * sizeof(int));
  int res_pos = res_dot(in1, in2, len1, len2);
  
  int width_m1 = width_m(in1, len1), width_m2 = width_m(in2, len2);
    
  int *ini_m1 = (int*)malloc(width_m1 * sizeof(int));
  int *ini_m2 = (int*)malloc(width_m2 * sizeof(int));

  ctoi(in1, len1, ini1, pos1, res_pos);
  
  ctoi(in2, len2, ini2, pos2, res_pos);

  ctoi_m(in1, strlen(in1), ini_m1);
  
  ctoi_m(in2, strlen(in2), ini_m2);
  
  if (!(test_data(in1) && test_data(in2)))
    printf("Your data is wrong.\n");

  else
    {
      if (op == '*')
		  {

			  mul(ini_m1, ini_m2, res_m, width_m1, width_m2);
			  printf("Calculation results:\n");
	  show_mul1(res_m, in1, in2, len1, len2, pos1, pos2);
	}

      else if (op == '+')
	{
		add(res, ini1, ini2, max_len);
		printf("Calculation results:\n");
	  show_add(res, max_len + 1, res_pos);
	}

      else if (op == '-')
	{
	  int indi = judge(ini1, ini2, max_len);
	  if (indi == 0)
	    printf("0\n");
      
	  else
	    {
			sub(res, ini1, ini2, max_len, indi);
			printf("Calculation results:\n");
	      show_sub(res, max_len, res_pos, indi);
	    }
	}

      else if (op == '/')
	{
	  
	}

      else
	printf("Your operation is not permitted.\n");
    }
  
  return 0;
}
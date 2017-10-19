#include <cstdio>
#include <cstdlib>
#define MASK 01  /* 掩码 */
int get_bit_high_pos(int n);
int main()
{
	int num = 0;
	printf("please input an integer:\n");
	scanf("%d", &num);
	for(int i=get_bit_high_pos(num);i>=0;i--)
	{
		printf("%d",(num>>i)&1);
	}
//	printf("\n%d",sizeof(bool)); 
//	printf("%d\n%d\n",((~num)&((1<<get_bit_high_pos(num)-1)-1)),1<<get_bit_high_pos(num)-1);
	printf("the high pos of the integer %d is %d.\n", num, get_bit_high_pos(num));
	return 0;
}
int get_bit_high_pos(int n)
{
	unsigned int num = abs(n); /* 取绝对值 */
	int i = 0, pos = 0;
	for (i = 0; i <= 8 * sizeof(int); i++, num >>= 1)   /* 遍历二进制，求解最高位的位置 */
	{
		if ((num & MASK) == MASK)
		{
			pos = i + 1;
		}
	}
	return pos;
}

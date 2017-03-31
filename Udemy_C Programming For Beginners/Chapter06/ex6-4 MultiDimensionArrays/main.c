/*****************************************************************************
@File name:
@Description: ���Զ�ά������÷�
@Author: Harry Wu
@Version: V1.0
@Date: 2017-03-31
@History:
V1.0: ���Զ�ά���飬Ҳ�������������еļ��㷽��
	  ��������ߴ磬���õİ취���ú궨��ROW_SIZE����COLUMN_SIZE���������ط��Ϳ���ֱ��ʹ��

*****************************************************************************/
#include <stdio.h>
#include <stdbool.h>

int grid[3][5] = {
	{ 1,   2,   3,   4,   5 },
	{ 6,   7,   8,   9,   10 },
	{ 11,  12,  13,  14,  15 }
};

int main(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	int row, column;
	int byte_size_grid = sizeof(grid);  //������λ����ĳߴ磬intռ4���ֽڣ��ܹ�15��Ԫ�أ�4*15=60
	int byte_size_grid0 = sizeof(grid[0]);  //��һ������ĳߴ磬int 4�ֽ�*5��Ԫ��=20
	int byte_size_grid00 = sizeof(grid[0][0]);  //��һ��Ԫ�صĳߴ磬ֻ��һ��int��������4
	int row_size = sizeof(grid) / sizeof(grid[0]);  //����
	int column_size = sizeof(grid[0]) / sizeof(grid[0][0]); //������Ҳ����һ�������Ԫ�ظ���
	printf("byte_size_grid = %d\n", byte_size_grid);
	printf("byte_size_grid[0] = %d\n", byte_size_grid0);
	printf("byte_size_grid[0][0] = %d\n", byte_size_grid00);
	printf("row_size = %d\n", row_size);
	printf("column_size = %d\n", column_size);
	for (int row = 0; row < row_size ; row++)
	{
		printf("---- row %d ----\n", row);
		for (int column = 0; column < column_size ; column++)
		{
			printf("Column[%d] = %d\t", column, grid[row][column]);
		}
		printf("\n");
	}
	return 0;
}
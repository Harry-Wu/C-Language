/*****************************************************************************
@File name:
@Description: 测试多维数组的用法
@Author: Harry Wu
@Version: V1.0
@Date: 2017-03-31
@History:
V1.0: 测试多维数组，也加入了数组行列的计算方法
	  关于数组尺寸，更好的办法是用宏定义ROW_SIZE数和COLUMN_SIZE数，其他地方就可以直接使用

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
	int byte_size_grid = sizeof(grid);  //整个二位数组的尺寸，int占4个字节，总共15个元素，4*15=60
	int byte_size_grid0 = sizeof(grid[0]);  //第一行数组的尺寸，int 4字节*5个元素=20
	int byte_size_grid00 = sizeof(grid[0][0]);  //第一个元素的尺寸，只有一个int，所以是4
	int row_size = sizeof(grid) / sizeof(grid[0]);  //行数
	int column_size = sizeof(grid[0]) / sizeof(grid[0][0]); //列数，也即第一行数组的元素个数
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
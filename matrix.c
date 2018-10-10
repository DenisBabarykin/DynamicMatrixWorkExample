#define _CRT_NONSTDC_NO_DEPRECATE // Отключение сообщений об устаревших функциях, не входящих в стандарт
#define _CRT_SECURE_NO_WARNINGS   // Отключение сообщений о небезопасных функциях
#define _CRT_SECURE_NO_DEPRECATE  // Отключение сообщений об устаревших небезопасных функциях

#include <stdio.h>  // Для функций printf() и scanf()
#include <conio.h>  // Для функции getch()
#include <stdlib.h> // Для функций malloc() и free()

int *alloc_linear_memory_matrix_c(int row_count, int col_count);
void free_linear_memory_matrix_c(int *matrix);

int *alloc_linear_memory_matrix_cpp(int row_count, int col_count);
void free_linear_memory_matrix_cpp(int *matrix);

int **alloc_sparse_rows_memory_matrix_c(int row_count, int col_count);
void free_sparse_rows_memory_matrix_c(int **matrix, int row_count);

int **alloc_sparse_rows_memory_matrix_cpp(int row_count, int col_count);
void free_sparse_rows_memory_matrix_cpp(int **matrix, int row_count);

int **alloc_dense_rows_memory_matrix_c(int row_count, int col_count);
void free_dense_rows_memory_matrix_c(int **matrix);

int **alloc_dense_rows_memory_matrix_cpp(int row_count, int col_count);
void free_dense_rows_memory_matrix_cpp(int **matrix);

void input_linear_matrix(int *matrix, int row_count, int col_count);
void output_linear_matrix(int *matrix, int row_count, int col_count);

void input_matrix(int **matrix, int row_count, int col_count);
void output_matrix(int **matrix, int row_count, int col_count);


void main()
{
	int row_count, col_count;
	int *linear_matrix;
	int **matrix;

	printf("Input number of rows and columns:\n");
	scanf("%d%d", &row_count, &col_count);

	printf("\nAllocation memory for linear matrix in c-style...\n");
	linear_matrix = alloc_linear_memory_matrix_c(row_count, col_count);
	printf("Input matrix:\n");
	input_linear_matrix(linear_matrix, row_count, col_count);
	printf("Inputed matrix:\n");
	output_linear_matrix(linear_matrix, row_count, col_count);
	printf("Freeing memory from matrix...\n");
	free_linear_memory_matrix_c(linear_matrix);

	printf("\nAllocation memory for linear matrix in cpp-style...\n");
	linear_matrix = alloc_linear_memory_matrix_cpp(row_count, col_count);
	printf("Input matrix:\n");
	input_linear_matrix(linear_matrix, row_count, col_count);
	printf("Inputed matrix:\n");
	output_linear_matrix(linear_matrix, row_count, col_count);
	printf("Freeing memory from matrix...\n");
	free_linear_memory_matrix_cpp(linear_matrix);

	printf("\nAllocation memory for sparse-row matrix in c-style...\n");
	matrix = alloc_sparse_rows_memory_matrix_c(row_count, col_count);
	printf("Input matrix:\n");
	input_matrix(matrix, row_count, col_count);
	printf("Inputed matrix:\n");
	output_matrix(matrix, row_count, col_count);
	printf("Freeing memory from matrix...\n");
	free_sparse_rows_memory_matrix_c(matrix, row_count);

	printf("\nAllocation memory for sparse-row matrix in cpp-style...\n");
	matrix = alloc_sparse_rows_memory_matrix_cpp(row_count, col_count);
	printf("Input matrix:\n");
	input_matrix(matrix, row_count, col_count);
	printf("Inputed matrix:\n");
	output_matrix(matrix, row_count, col_count);
	printf("Freeing memory from matrix...\n");
	free_sparse_rows_memory_matrix_cpp(matrix, row_count);

	printf("\nAllocation memory for dense-row matrix in c-style...\n");
	matrix = alloc_dense_rows_memory_matrix_c(row_count, col_count);
	printf("Input matrix:\n");
	input_matrix(matrix, row_count, col_count);
	printf("Inputed matrix:\n");
	output_matrix(matrix, row_count, col_count);
	printf("Freeing memory from matrix...\n");
	free_dense_rows_memory_matrix_c(matrix);

	printf("\nAllocation memory for dense-row matrix in cpp-style...\n");
	matrix = alloc_dense_rows_memory_matrix_cpp(row_count, col_count);
	printf("Input matrix:\n");
	input_matrix(matrix, row_count, col_count);
	printf("Inputed matrix:\n");
	output_matrix(matrix, row_count, col_count);
	printf("Freeing memory from matrix...\n");
	free_dense_rows_memory_matrix_cpp(matrix);

	getch();
}


int *alloc_linear_memory_matrix_c(int row_count, int col_count)
{
	return (int *) malloc(row_count * col_count * sizeof(int));
}

void free_linear_memory_matrix_c(int *matrix)
{
	free(matrix);
}


int *alloc_linear_memory_matrix_cpp(int row_count, int col_count)
{
	return new int[row_count * col_count];
}

void free_linear_memory_matrix_cpp(int *matrix)
{
	delete [] matrix;
}


int **alloc_sparse_rows_memory_matrix_c(int row_count, int col_count)
{
	int **matrix = (int **) malloc(row_count * sizeof(int *));
	for (int i = 0; i < row_count; i++)
	{
		matrix[i] = (int *) malloc(col_count * sizeof(int));
	}

	return matrix;
}

void free_sparse_rows_memory_matrix_c(int **matrix, int row_count)
{
	for (int i = 0; i < row_count; i++)
	{
		free(matrix[i]);
	}
	free(matrix);
}


int **alloc_sparse_rows_memory_matrix_cpp(int row_count, int col_count)
{
	int **matrix = new int*[row_count];
	for (int i = 0; i < row_count; i++)
	{
		matrix[i] = new int[col_count];
	}

	return matrix;
}

void free_sparse_rows_memory_matrix_cpp(int **matrix, int row_count)
{
	for (int i = 0; i < row_count; i++)
	{
		delete [] matrix[i];
	}
	delete [] matrix;
}


int **alloc_dense_rows_memory_matrix_c(int row_count, int col_count)
{
	int **matrix = (int **) malloc(row_count * sizeof(int *) + row_count * col_count * sizeof(int));
	int *matrix_body = (int *) (matrix + row_count);
	for (int i = 0; i < row_count; i++)
	{
		matrix[i] = matrix_body + i * col_count;
	}

	return matrix;
}

void free_dense_rows_memory_matrix_c(int **matrix)
{
	free(matrix);
}


int **alloc_dense_rows_memory_matrix_cpp(int row_count, int col_count)
{
	int **matrix = (int **) new char[row_count * sizeof(int *) + row_count * col_count * sizeof(int)];
	int *matrix_body = (int *)(matrix + row_count);
	for (int i = 0; i < row_count; i++)
	{
		matrix[i] = matrix_body + i * col_count;
	}

	return matrix;
}

void free_dense_rows_memory_matrix_cpp(int **matrix)
{
	delete [] matrix;
}


void input_linear_matrix(int *matrix, int row_count, int col_count)
{
	for (int i = 0; i < row_count; i++)
		for (int j = 0; j < col_count; j++)
			scanf("%d", matrix + i * col_count + j);
}

void output_linear_matrix(int *matrix, int row_count, int col_count)
{
	for (int i = 0; i < row_count; i++)
	{
		for (int j = 0; j < col_count; j++)
			printf("%d ", matrix[i * col_count + j]);
		printf("\n");
	}
}


void input_matrix(int **matrix, int row_count, int col_count)
{
	for (int i = 0; i < row_count; i++)
		for (int j = 0; j < col_count; j++)
			scanf("%d", &matrix[i][j]);
}

void output_matrix(int **matrix, int row_count, int col_count)
{
	for (int i = 0; i < row_count; i++)
	{
		for (int j = 0; j < col_count; j++)
			printf("%d ", matrix[i][j]);
		printf("\n");
	}
}

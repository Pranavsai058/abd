#include <stdio.h>
#include <stdlib.h>

struct element {
    int row;
    int col;
    int value;
};

struct sparse_matrix {
    int rows;
    int cols;
    int num_elements;
    struct element *elements;
};

void create_sparse_matrix(struct sparse_matrix *matrix, int rows, int cols, int num_elements) {
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->num_elements = num_elements;
    matrix->elements = (struct element *) malloc(num_elements * sizeof(struct element));
}

void read_sparse_matrix(struct sparse_matrix *matrix) {
    printf("Enter the number of rows, columns and non-zero elements: ");
    scanf("%d %d %d", &matrix->rows, &matrix->cols, &matrix->num_elements);
    matrix->elements = (struct element *) malloc(matrix->num_elements * sizeof(struct element));
    printf("Enter the row, column and value of each non-zero element:\n");
    for (int i = 0; i < matrix->num_elements; i++) {
        scanf("%d %d %d", &matrix->elements[i].row, &matrix->elements[i].col, &matrix->elements[i].value);
    }
}

void print_sparse_matrix(struct sparse_matrix matrix) {
    printf("Sparse Matrix:\n");
    printf("Rows: %d\n", matrix.rows);
    printf("Columns: %d\n", matrix.cols);
    printf("Number of non-zero elements: %d\n", matrix.num_elements);
    printf("Elements:\n");
    for (int i = 0; i < matrix.num_elements; i++) {
        printf("%d %d %d\n", matrix.elements[i].row, matrix.elements[i].col, matrix.elements[i].value);
    }
}

int main() {
    struct sparse_matrix matrix;
    read_sparse_matrix(&matrix);
    print_sparse_matrix(matrix);
}

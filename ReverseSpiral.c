#include <stdio.h>
void spiralMatrix(int rows, int columns, int matrix[rows][columns]);
int main(){
    int rows, columns;
    scanf("%d", &rows);
    scanf("%d", &columns);

    int matrix[rows][columns];

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("\n");
    spiralMatrix(rows, columns, matrix);
}
void spiralMatrix(int rows, int columns, int matrix[rows][columns])
{
    int startRow = 0, startColumn = 0;
    int endRow = rows - 1, endColumn = columns - 1;

    while(startRow <= endRow && startColumn <= endColumn)
    {
        for(int i = startRow; i <= endRow; i++){
            printf("%d ", matrix[i][startColumn]);
        }

        for(int j = startColumn + 1; j <= endColumn; j++){
            printf("%d ", matrix[endRow][j]);
        }

        for(int i = endRow - 1; i >= startRow; i--){
            if(startColumn == endColumn){
                break;
            }
            printf("%d ", matrix[i][endColumn]);
        }

        for(int j = endColumn - 1; j >= startColumn + 1; j--){
            if(startRow == endRow){
                break;
            }
            printf("%d ", matrix[startRow][j]);
        }
        startRow++;
        startColumn++;
        endColumn--;
        endRow--;
    }
}

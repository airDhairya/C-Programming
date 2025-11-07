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

    spiralMatrix(rows, columns, matrix);
}

void spiralMatrix(int rows, int columns, int matrix[rows][columns])
{
    int startRow = 0, startColumn = 0, endRow = rows - 1, endColumn = columns - 1;

    printf("Spiral Matrix 😵‍💫 is : \n");
    while(startRow <= endRow && startColumn <= endColumn){
        //top
        for(int j = startColumn; j <= endColumn; j++){
            printf("%d ", matrix[startRow][j]);
        }
        //right
        for(int i = startRow + 1; i <= endRow; i++){
            printf("%d ", matrix[i][endColumn]);
        }
        //bottom
        for(int j = endColumn - 1; j >= startColumn; j--){
            if(startRow == endRow){
                break;
            }
            printf("%d ", matrix[endRow][j]);
        }
        //left
        for(int i = endRow - 1; i >= startRow + 1; i--){
            if(startColumn == endColumn){
                break;
            }
            printf("%d ", matrix[i][startColumn]);
        }
        startRow++;
        startColumn++;
        endRow--;
        endColumn--;
    }
}

#include <stdio.h>
#include <stdbool.h>
void patternFilter(int array[], int size);
bool palindromeOperator(int num);
bool oddOperation(int num);
int main(){
    int size;
    scanf("%d", &size);

    int array[size];

    for(int i = 0; i < size; i++){
        scanf("%d", &array[i]);
    }

    patternFilter(array, size);
}

void patternFilter(int array[], int size)
{
    for(int i = 0; i < size; i++){
        bool palindromeOperation = palindromeOperator(array[i]);
        bool secondOperation = oddOperation(array[i]);
        if(palindromeOperation){
            int sumOfDigits = 0;
            int num = array[i];
            while (num > 0){
                int digits = num % 10;
                sumOfDigits += digits;
                num /= 10;
            }
            array[i] = sumOfDigits;
        } else if (secondOperation)
        {
            int digitCount = 0;
            int number = array[i];
            while(number > 0){
                digitCount++;
                number /= 10;
            }
            array[i] = digitCount;
        } else{
            array[i] = array[i];
        }
    }
     for (int i = 0; i < size; i++){
            printf("%d ", array[i]);
        }
}

bool palindromeOperator(int num)
{
    int revNum = 0;
    bool palindrome = false;
    int ogNum = num;
    int realNumber = num;
    int sumOfDigits = 0;
    while(num > 0){
        int digits = num % 10;
        revNum = revNum * 10 + digits;
        num /= 10;
    }
    if(revNum != ogNum){
        palindrome = false;
    } else{
        palindrome = true;
    }
    return palindrome;
}

bool oddOperation(int num)
{
    bool isOdd = false;
    bool condition = false;
    int realNum = num;
    if(num % 2 == 0){
        isOdd = false;
    }else{
        if(num % 3 == 0){
            condition = true;
        }
    }
    return condition;
}

#include <stdio.h>
#include<stdbool.h>

void patternFilter(int array[], int size);
void arrayPrinter(int array[], int size);
bool isPalindrome(int num);
bool isOdd(int num);
bool isDivisible3(int num);

int digitsSum(int num);
int digitsCount(int num);

int main(){
    int size;
    printf("Enter the size of the array : ");
    scanf("%d", &size);

    int array[size];

    for(int i = 0; i < size; i++){
        printf("Enter the %d element : ", (i+1));
        scanf("%d", &array[i]);
    }

    patternFilter(array, size);
    arrayPrinter(array, size);

}

void patternFilter(int array[], int size){
    for(int i = 0; i < size; i++){

        bool condition1 = isPalindrome(array[i]);
        bool condition2a = isOdd(array[i]);
        bool condition2b = isDivisible3(array[i]);

        if(condition1){
            array[i] = digitsSum(array[i]);
        } else if (condition2a == false && condition2b  )
        {
            array[i] = digitsCount(array[i]);
        }
        
    }
}

void arrayPrinter(int array[], int size)
{
    for(int i = 0; i < size; i++){
        printf("%d ", array[i]);
    }
}

bool isPalindrome(int num)
{
    int ogNum = num;
    int revNum = 0;
    bool palindrome = false;
    
    while(num > 0){
        int digits = num % 10;
        revNum = revNum * 10 + digits;
        num /= 10;
    }

    if(revNum == ogNum){
        palindrome = true;
    }
    return palindrome;
}

int digitsSum(int num){
    int sum = 0;
    while(num > 0){
        int digits = num % 10; 
        sum += digits;
        num /= 10;
    }
    return sum;
}

int digitsCount(int num)
{
    int digits = 0;
    while(num > 0){
        digits++;
        num /= 10;
    }
    return digits;
}

bool isOdd(int num){
    return (num % 2 == 0);
}

bool isDivisible3(int num)
{
    return (num % 3 == 0);
}

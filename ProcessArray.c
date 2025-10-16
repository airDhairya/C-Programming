#include <stdio.h>
#include<stdbool.h>
#include<math.h>

void ProcessArray(int array[], int size);
void arrayPrinter(int array[], int size);

bool isPalindrome(int num);
bool isPerfectSquare(int num);
bool isDivisible(int num);

int sumOperation(int num);
int factorialOperation(int num);
int primeNumberSum(int num);

int main(){
    int num;
    scanf("%d", &num);

    int array[num];

    for(int i = 0; i < num;i++){
        scanf("%d", &array[i]);
    }

    ProcessArray(array, num);
    arrayPrinter(array, num);
}

void ProcessArray(int array[], int size)
{
    for(int i = 0; i < size; i++){
        bool condition1 = isPalindrome(array[i]);
        bool condition2 = isPerfectSquare(array[i]);
        bool condition3 = isDivisible(array[i]);    

        if(condition1){
            array[i] = sumOperation(array[i]);
        } else if (condition2)
        {
            array[i] = factorialOperation(array[i]);
        }
        else if (condition3)
        {
            array[i] = primeNumberSum(array[i]);
        }
        
    }
}

void arrayPrinter(int array[], int size){
    for(int i = 0; i < size; i++){
        printf("%d ", array[i]);
    }
}

bool isPalindrome(int num){
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

int sumOperation(int num)
{
    int sum = 0;
    int digitCount = 0;
    int ogNum = num;
    while (num > 0)
    {
        digitCount++;
        num /= 10;
    }
    while (ogNum > 0)
    {
        int digits = ogNum % 10;
        sum += pow(digits, digitCount);
        ogNum /= 10;
    }
    
    return sum;
}

int factorialOperation(int num)
{
    int number = pow(num, 0.5);
    if(number <= 1){
        return 1;
    }
    return factorialOperation((number - 1) * (number - 1)) * number;
}

int primeNumberSum(int num)
{
    int sum = 0;

    for(int i = 2; i <= num/i; i++){
        while(num % i == 0){
            sum += i;
            num /= i;
        }
    }

    if(num > 1){
        sum += num;
    }
    return sum;
}
bool isPerfectSquare(int num)
{
    bool perfectSquare = false;
    for(int i = 1; i < num; i++){
        if(i * i == num){
            perfectSquare = true;
        }
    }
    return perfectSquare;
}

bool isDivisible(int num)
{
    return (num % 3 == 0 && num % 7 == 0);
}

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isEven(int count);
bool isPrime(int length);

void toLowerCase(char str[50]);
void stringOperation(char str[50]);
void rightShift(char str[50]);

int vowelCount(char str[50]);

int main(){
    char string[50];

    printf("Enter a string : ");
    scanf(" %[^\n]", string);

    stringOperation(string);

}

void toLowerCase(char str[50])
{
    int length = strlen(str);

    for(int i = 0; i < length; i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            str[i] += 32;
        }
    }
}

void stringOperation(char str[50])
{
    toLowerCase(str);

    int vowelCounter = vowelCount(str);
    bool result = isEven(vowelCounter);
    bool primeResult = isPrime(strlen(str));

    if(result){
        if(primeResult){
            printf("The string length is prime");
        }
        else{
            printf("The string length is not prime");
        }
    }else{
        rightShift(str);
    }
}

void rightShift(char str[50])
{
    for (int i = 0; i < strlen(str); i++)
    {
        str[i] += 1;
    }
    printf("%s", str);
    
}

int vowelCount(char str[50])
{
    int count = 0;
    
    for(int i = 0; i <strlen(str); i++){
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'){
            count++;
        }
    }
    return count;
}

bool isEven(int count){
    return (count % 2 == 0);
}

bool isPrime(int length){
    bool prime = true;

    for(int i = 2; i * i <= length; i++){
        if(length % i == 0){
            prime = false;
        }
    }
    return prime;
}
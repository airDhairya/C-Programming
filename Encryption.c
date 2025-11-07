#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encryption(char str[], int encoder);
void decryption(char str[], int decoder);

int main(){
    char str[10000];
    int shift;
    printf("Enter a string : ");
    scanf(" %[^\n]", str);

    printf("How many alphabets do you wanna shift : ");
    scanf("%d", &shift);

    encryption(str, shift);
    decryption(str, shift);
}

void encryption(char str[], int shift)
{
    printf("\nEncrypted string is : \n");
    for(int i = 0; i < strlen(str); i++){
        char ch = str[i];
        int index;
        int newIndex;
        char newChar;
        if(ch >= 'a' && ch <= 'z'){
            index = ch - 'a';
            newIndex = (index + shift) % 26;
            newChar = newIndex + 'a';
            str[i] = newChar;
        } else if( ch >= 'A' && ch <= 'Z'){
            index = ch - 'A';
            newIndex = (index + shift) % 26;
            newChar = newIndex + 'A';
            str[i] = newChar;
        }else{
            continue;
        }
        printf("%c", str[i]);
    }
}

void decryption(char str[], int decoder)
{
    printf("\n\nThe original string is : \n");
    for(int i = 0; i < strlen(str); i++){
        char ch = str[i];
        int index;
        int originalIndex;
        char originalChar;
        if(ch >= 'a' && ch <= 'z'){
            index = ch - 'a';
            originalIndex = (index - decoder +26) % 26;
            originalChar = originalIndex + 'a';
            str[i] = originalChar;
        }else if( ch >= 'A' && ch <= 'Z'){
            index = ch - 'A';
            originalIndex = (index - decoder + 26) % 26;
            originalChar = originalIndex + 'A';
            str[i] = originalChar;
        }

        printf("%c", str[i]);
    }
}

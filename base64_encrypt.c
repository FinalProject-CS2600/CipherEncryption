#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

// STEPS TO ENCRYPT
// 1. Convert text to decimal(ASCII), then convert to binary(8-bits)
// 2. Put the binary numbers together, then group into 6 bits (Pad with 0's if less than 6 bits(base64 standard))
// 3. Convert binary to decimal
// 4. Convert decimal numbers to corresponding base64 numbers
// 5. Final result should be multiple of 4, if not, add = to the end 

// ** Decrypting = reverse

// NEED TO DO: 
// 1. FINISH CONVERTING ASCII TO BINARY
// 2. PUT BINARY NUMBERS AS ONE STRING -- BREAK INTO 6 PIECES
// 3. MAKE FUNCTION TO CONVERT BINARY TO DECIMAL

int convertToBase(int decimalNum)
{
    char base64[64] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    int index = 0;

    char baseNum;
    

}

char* convertToBinary(int decimalNum)
{
    int arrayIndex = 0;

    //Allocate a pointer
    char* bin = (char *) malloc (32 * sizeof(char));

    while( decimalNum > 0)
    {
        int remainder = decimalNum % 2;
        bin[arrayIndex++] = '0' + remainder;

        decimalNum /= 2;
    }

    bin[arrayIndex] = '\0';

    //Reverse the array using beginning and index -1
    int begin = 0;
    int end = arrayIndex - 1;

    while(begin < end)
    {
        char binaryInt = bin[begin];
        bin[begin] = bin[end];
        bin[end] = binaryInt;
        begin++;
        end--;
    }

    return bin;

}

int convertToDecimal(char* binaryNumber)
{        
    int decNum = 0;
    int power = 1;

    for(int i = strlen(binaryNumber); i >= 0; i--)
    {
        if(binaryNumber[i] == '1')
        {
            decNum += power;
        }

        power = power * 2;

    }
    return decNum;


}

void split_array(char binaryNumber [100])
{
    int counter = 0;

    int remainder = strlen(binaryNumber) % 6;

    //CHECK FOR 0 -- concatenate
    if(remainder != 0)
    {
        printf("Remainder: %d\n", remainder);
        printf("Length of full binary string is not a factor of 6.\n");

        while(remainder > 0)
        {
            strcat(binaryNumber, "0");
            remainder--;
        }
    }

    printf("\nSPLIT STRING: %s\n", binaryNumber);

}

void encrypt()
{
    char userString[100];
    int encryptedString[100];

    int arrayCount = 0;

    //Ask for string for encryption
    printf("Selected mode: Encryption\nPlease put string to encrypt: ");
    scanf("%s", userString);

    //Convert each char in the array into ASCII values
    printf("String: %s\n", userString);

    while(userString[arrayCount] != '\0')
    {
        char stringChar = userString[arrayCount];
        
        //Test value of char
        printf("Char: %c\n", stringChar);

        int asciiNum = stringChar;

        printf("ASCII Value: %d\n", asciiNum);

        encryptedString[arrayCount] = asciiNum;
        arrayCount +=1;

    }
    
    arrayCount = 0;
    char binaryString [100];

    // Convert each ascii value in array into binary number -- combine into one String
    while(encryptedString[arrayCount] != '\0')
    {
        char *binaryNum = convertToBinary(encryptedString[arrayCount]);

        printf("\nASCII: %d\nBINARY NUM: %s\n", encryptedString[arrayCount], binaryNum);

        strcat(binaryString, binaryNum);

        printf("\n Complete string: %s\n", binaryString);

        arrayCount+=1;

    }

    split_array(binaryString);

    // Convert back to decimal


}

void decrypt()
{

}

int main()
{
    char input;
    
    //Print options to the user
    printf("Selected Cipher: Base64\n");
    printf("Mode:\n");
    printf("\te: Encrypt\n");
    printf("\td: Decrypt\n");
    printf("Please enter the mode you would like: ");
    scanf("%c", &input);

    //Run methods based on char
    if (input == 'e') 
    {
        encrypt();

    }
    else if(input == 'd')
    {
        decrypt();
    }
    else 
    {
        printf("Please enter a valid option: ");
    }

    return 0;
        

}
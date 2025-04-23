#include <stdio.h>
#include <ctype.h>

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


void convertToBinary(int decimalNum)
{
    //Each element within the encrypted array = ASCII num
    // Needs to convert each num to binary

    int remainder;
    int moduloArray[100];
    int binaryArray[100];

    int arrayCount = 0;

    while(decimalNum >= 1)
    {
        //Modulo Operation
        remainder = decimalNum % 2;

        if(remainder != 0)
        {
            moduloArray[arrayCount] = 1;
            decimalNum = decimalNum / 2;
        }
        else if(remainder == 0)
        {
            moduloArray[arrayCount] = 0;
            decimalNum = decimalNum / 2;

        }
        arrayCount +=1;
    }

    //Reverse the array to receive the binary number
    int binaryCount = 0;
    while(arrayCount > -1 )
    {
        moduloArray[arrayCount] = binaryArray[binaryCount];
        arrayCount -= 1;
        binaryCount += 1;   
    }

    //Check binary array to ensure correct answer
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
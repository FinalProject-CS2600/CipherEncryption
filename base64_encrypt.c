#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

//  STEPS TO ENCRYPT
//  1. Convert text to decimal(ASCII), then convert to binary(8-bits)
//  2. Put the binary numbers together, then group into 6 bits (Pad with 0's if less than 6 bits(base64 standard))
//  3. Convert binary to decimal
//  4. Convert decimal numbers to corresponding base64 numbers
//  5. Final result should be multiple of 4, if not, add = to the end 

//  ** Decrypting = reverse

char convertToBase(int decimalNum)
{
    char base64[64] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    return base64[decimalNum];

}

char* convertToBinary(int decimalNum)
{
    //  Allocate 9 chars: 8 bits + null terminator
    char* bin = (char*) malloc(9 * sizeof(char));

    //  Fill with '0's for 8 bits
    for (int i = 0; i < 8; i++)
    {
        bin[7 - i] = (decimalNum % 2) + '0';
        decimalNum /= 2;
    }

    //  Null terminator
    bin[8] = '\0';

    return bin;

}

int convertToDecimal(char* binaryNumber)
{        
    int decNum = 0;
    int power = 1;

    // Find the value of the binary number. With each iteration, increase the power by 2. 
    for(int i = strlen(binaryNumber) - 1; i >= 0; i--)
    {
        if(binaryNumber[i] == '1')
        {
            decNum += power;
        }
        power = power * 2;

    }
    return decNum;

}

char* split_array(char input_array [1000], char output_array [2000])
{
    int counter = 0;
    int inputArray_index = 0;
    int outputArray_index = 0;

    int remainder = strlen(input_array) % 6;
    int num_zeroes = 6 - remainder;

    // CHECK FOR 0 -- concatenate 0's to the end to complete the string
    if(remainder != 0)
    {
        //  REMOVE BEFORE ADDING TO MAIN--- TESTING 
        printf("0's needed: %d\n", num_zeroes);
        printf("Length of full binary string is not a factor of 6.\n");

        //  Add 0's and remove 0's needed
        while(num_zeroes > 0)
        {
            strcat(input_array, "0");
            num_zeroes--;
        }
    }

    //  REMOVE BEFORE ADDING TO MAIN--- TESTING 
    printf("\nSTRING (after adding 0's): %s\n", input_array);

    //  Split the strings with white space
    while(input_array[inputArray_index] != '\0')
    {
        //  Add elements to output_array and increase counter
        output_array[outputArray_index++] = input_array[inputArray_index++];
        counter++;

        //  Check when counter = 6, then add a space to the next space in the output_array
        //  Reset counter to 0
        if((counter == 6))
        {
            output_array[outputArray_index++] = ' ';
            counter = 0;
        }
    }

    //  Add the null terminator at the end of the output array to show end of string
    output_array[outputArray_index] = '\0';

    //  REMOVE BEFORE ADDING TO MAIN--- TESTING 
    printf("\nSTRING (after adding whitespace): %s\n", output_array);

    return output_array;

}

void encrypt()
{
    char user_string[100];
    int ascii_array[100];
    char binaryString [1000] = "";
    char spaced_array [2000] = "";

    char base64_string [100]; 

    int array_count = 0;

    // Ask for string for encryption
    printf("Selected mode: Encryption\nPlease put string to encrypt: ");
    scanf("%s", user_string);

    // STEP 1: Convert each char in the array into ASCII values
    printf("String: %s\n", user_string);

    while(user_string[array_count] != '\0')
    {
        char stringChar = user_string[array_count];
        
        //  REMOVE BEFORE ADDING TO MAIN--- TESTING 
        printf("Char: %c\n", stringChar);

        int asciiNum = stringChar;

        //  REMOVE BEFORE ADDING TO MAIN--- TESTING 
        printf("ASCII Value: %d\n", asciiNum);

        ascii_array[array_count] = asciiNum;
        array_count +=1;

    }
    
    array_count = 0;

    //  STEP 2: Convert each ascii value in array into binary number -- combine into one String
    while(ascii_array[array_count] != '\0')
    {
        char *binaryNum = convertToBinary(ascii_array[array_count]);

        //  REMOVE BEFORE ADDING TO MAIN--- TESTING 
        printf("\nASCII: %d\nBINARY NUM: %s\n", ascii_array[array_count], binaryNum);

        //  Concatenate the binary number to the binary string
        strcat(binaryString, binaryNum);

        //  REMOVE BEFORE ADDING TO MAIN--- TESTING
        printf("\n Complete string: %s\n", binaryString);

        //  Increase the index to change every ASCII number
        array_count+=1;
    }

    array_count = 0;

    //  STEP 3 and 4: Group array into groups of 6 equal bits and convert to DECIMAL
    strcpy(spaced_array, split_array(binaryString, spaced_array));
    char binary_number [100];

    int number_index = 0;
    int base_index = 0;

    int decimal_numbers [100];

    //  Get each char until whitespace and make it into a string

    for(int i = 0; i < strlen(spaced_array); i++)
    {
        if(spaced_array[i] == ' ' || spaced_array[i] == '\0')
        {
            binary_number[number_index] = '\0';

            //  REMOVE BEFORE ADDING TO MAIN--- TESTING
            printf("6-bit Binary: %s\n", binary_number);

            number_index = 0;

            int dec_num = convertToDecimal(binary_number);

            //  REMOVE BEFORE ADDING TO MAIN--- TESTING
            printf("Decimal Value: %d\n", dec_num);

            //  Convert decimal number into base64 alphabet
            char base64_conversion = convertToBase(dec_num);

            //  Add the char into string
            base64_string[base_index] = base64_conversion;
            base_index++;

        }
        else
        {
            binary_number[number_index] = spaced_array[i];
            number_index++;

        }
    }

    //  Check if string is multiple of 4 -- if not, add the necessary amount of 0's
    if((strlen(base64_string) % 3) != 0)
    {
        //  Take string length to find the number of 0's needed
        int padding_num = (4 - strlen(base64_string) % 4) % 4;
        int padding_counter = 0;

        while(padding_num > 0)
        {
            base64_string[strlen(base64_string) + padding_counter] = '=';
            padding_num--;
        }

        //  Add null terminator
        base64_string[strlen(base64_string) + padding_counter] = '\0';

    }

    printf("ENCRYPTED STRING: %s", base64_string);

}

int main()
{
    char input;
    
    // Print options to the user
    printf("Selected Cipher: Base64\n");
    printf("Mode:\n");
    printf("\te: Encrypt\n");
    printf("\td: Decrypt\n");
    printf("Please enter the mode you would like: ");
    scanf("%c", &input);

    // Run methods based on char
    if (input == 'e') 
    {
        encrypt();

    }
    else if(input == 'd')
    {

    }
    else 
    {
        printf("Please enter a valid option: ");
    }

    return 0;
        

}
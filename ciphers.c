// FINAL PROJECT --- CIPHER ENCRYPTION

// Program contains functions corresponding to different cipher encryption techniques. 
// Methods: Caesar Cipher, Base64, and Atbash
// 

// GROUP 6 MEMBERS: 
// Amelie Carrillo
// Anson Ng
// Medha Swarnachandrabalaji
// Natalie Tran
// Julianna Arias

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 

// Encryption/Decryption Methods
void caesarCipherEncryption();
void caesarCipherDecryption();

void base64_Encrypt();
char convertToBase();
char* convertToBinary();
char* split_array();
int convertToDecimal();

void Atbash_encryption();

// MAIN FUNCTION
int main() {
	char input;

    // MENU OPTIONS
	printf("Cipher Encryption\n");
    printf("-- Menu Options --\n");

	printf("\tc: Caesar Cipher (alphanumeric)\n");
	printf("\tb: Base64\n");
	printf("\ta: Atbash Cipher (alphabetical)\n");
    printf("\tq: Quit program\n");
	printf("Please enter a character: ");
	scanf(" %c", &input);

    // CAESAR CIPHER SELECTION
	if (input == 'c') {
		printf("Selected Cipher: Caesar Cipher\n");
		printf("Mode:\n");
		printf("\te: Encrypt\n");
		printf("\td: Decrypt\n");
		printf("Please enter the mode you would like: ");
		scanf(" %c", &input);

		if (input == 'e') {
			caesarCipherEncryption();
		}
		else if (input == 'd') {
			caesarCipherDecryption();
		}
		else {
			printf("Invalid selection.\n");
		}
	}
    // BASE64 SELECTION
	else if (input == 'b') {
		printf("Selected Cipher: Base64\n");
		printf("Mode:\n");
		printf("\te: Encrypt\n");
		printf("\td: Decrypt\n");
		printf("Please enter the mode you would like: ");
		scanf(" %c", &input);

		if (input == 'e') {
			base64_Encrypt();
		}
		else if (input == 'd') {
			// run decrypt function
		}
		else {
			//printf("Invalid selection.\n");
		}
	}
    
    // ATBASH SELECTION
	else if (input == 'a') {
		printf("Selected Cipher: Atbash Cipher\n");
		printf("Mode:\n");
		printf("\te: Encrypt\n");
		printf("\td: Decrypt\n");
		printf("Please enter the mode you would like: ");
		scanf(" %c", &input);

		if (input == 'e') {
			Atbash_encryption();
		}
		else if (input == 'd') {
			// run atbash decryption function
		}
		else {
			printf("Invalid selection.\n");
		}
	}

    // QUIT PROGRAM
    else if( input == 'q')
    {
        printf("\nExiting program...\n");
        exit(0);
    }
	else {
		printf("Invalid selection.");
    }
	
	return 0;
}

void caesarCipherEncryption() {
	char message[100];
	int key;

	printf("Selected Mode: Encryption\n");

	printf("Please enter a message to encrypt: ");
	scanf(" %[^\n]s", &message);
	printf("Please enter how many letters to shift: ");
	scanf("%d", &key);

	char encrypted[sizeof(message)];

	for(int i = 0; i < sizeof(message); i++) {
		if (islower(message[i])) {
			encrypted[i] = (message[i] - 97 + key) % 26 + 97;
		}
		else if (isupper(message[i])) {
			encrypted[i] = (message[i] - 65 + key) % 26 + 65;
		}
		else if (isdigit(message[i])) {
			encrypted[i] = (message[i] - 48 + key) % 10 + 48;
		}
		else {
			encrypted[i] = message[i];
		}
	}

	printf("Encrypted message: %s\n", encrypted);
}

void caesarCipherDecryption() {
	char message[100];
	int key;

	printf("Selected Mode: Decryption\n");

	printf("Please enter a message to decrypt: ");
	scanf(" %[^\n]s", &message);
	printf("Please enter how many letters to shift: ");
	scanf("%d", &key);
	
	char decrypted[sizeof(message)];

	for(int i = 0; i < sizeof(message); i++) {
		if (islower(message[i])) {
			decrypted[i] = (message[i] - 97 - key) % 26 + 97;
		}
		else if (isupper(message[i])) {
			decrypted[i] = (message[i] - 65 - key) % 26 + 65;
		}
		else if (isdigit(message[i])) {
			decrypted[i] = (message[i] - 48 - key) % 10 + 48;
		}
		else {
			decrypted[i] = message[i];
		}
	}

	printf("Decrypted message: %s\n", decrypted);
}

void base64_Encrypt()
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
        
        int asciiNum = stringChar;

        ascii_array[array_count] = asciiNum;
        array_count +=1;

    }
    
    array_count = 0;

    //  STEP 2: Convert each ascii value in array into binary number -- combine into one String
    while(ascii_array[array_count] != '\0')
    {
        char *binaryNum = convertToBinary(ascii_array[array_count]);

        //  Concatenate the binary number to the binary string
        strcat(binaryString, binaryNum);

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

            number_index = 0;

            int dec_num = convertToDecimal(binary_number);

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

void Atbash_encryption() {
    // Create table for alphabetical conversion
    char lookup_table[26] = {
        'Z', 'Y', 'X', 'W', 'V', 'U', 'T', 'S',
        'R', 'Q', 'P', 'O', 'N', 'M', 'L', 'K',
        'J', 'I', 'H', 'G', 'F', 'E', 'D', 'C',
        'B', 'A'
    };

    // Read input string up to 999 characters
    char message[1000];
    printf("Enter the message to encrypt/decrypt: ");
    fgets(message, sizeof(message), stdin);

    // Remove newline if present
    size_t len = strlen(message);
    if (len > 0 && message[len - 1] == '\n') {
        message[len - 1] = '\0';
    }

    // Declare another array to hold encrypted/decrpyted message
    char cipher[1000];
    for (int i = 0; message[i] != '\0'; i++) {
        char letter = message[i];
	// preserves the space character
        if (letter == ' ') {
            cipher[i] = ' ';
        } 
	else if (isalpha(letter)) {
            char upper = toupper(letter);
            cipher[i] = lookup_table[upper - 'A'];
        } 
	else {
            cipher[i] = letter; // preserve non-alpha characters
        }
    }
    cipher[strlen(message)] = '\0'; // null terminate the cipher string

    printf("Result: %s\n", cipher);
}


// BASE64 FUNCTIONS
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
        //  Add 0's and remove 0's needed
        while(num_zeroes > 0)
        {
            strcat(input_array, "0");
            num_zeroes--;
        }
    }

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

    return output_array;

}

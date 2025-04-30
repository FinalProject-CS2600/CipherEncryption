// FINAL PROJECT --- CIPHER ENCRYPTION

// Program contains functions corresponding to different cipher encryption techniques; 
// Caesar Cipher, Base64, and Atbash
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

void caesarCipherEncryption();
void caesarCipherDecryption();

int main() {
	char input;

	printf("List of Ciphers:\n");
	printf("\tc: Caesar Cipher (alphanumeric)\n");
	printf("\tb: Base64\n");
	printf("\ta: Atbash Cipher (alphabetical)\n");
	printf("Please enter the cipher you would like: ");
	scanf(" %c", &input);

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
	/*
	if (input == 'b') {
		printf("Selected Cipher: Base64\n");
		printf("Mode:\n");
		printf("\te: Encrypt\n");
		printf("\td: Decrypt\n");
		printf("Please enter the mode you would like: ");
		scanf(" %c", &input);

		if (input == 'e') {
			run base64 encryption function
		}
		if (input == 'd') {
			run base64 decryption function
		}
		else {
			printf("Invalid selection.\n");
		}
	}
	if (input == 'a') {
		printf("Selected Cipher: Atbash Cipher\n");
		printf("Mode:\n");
		printf("\te: Encrypt\n");
		printf("\td: Decrypt\n");
		printf("Please enter the mode you would like: ");
		scanf(" %c", &input);

		if (input == 'e') {
			run atbash cipher encryption function
		}
		if (input == 'd') {
			run atbash decryption function
		}
		else {
			printf("Invalid selection.\n");
		}
	}
	*/
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

//Base64 Function --- will be added later
void base64_Encrypt(){

}

void Atbash_encryption() {
    // Create table for alphabetical conversion
    char lookup_table[26] = {
        'Z', 'Y', 'X', 'W', 'V', 'U', 'T', 'S',
        'R', 'Q', 'P', 'O', 'N', 'M', 'L', 'K',
        'J', 'I', 'H', 'G', 'F', 'E', 'D', 'C',
        'B', 'A'
    };

    char message[1000];
    printf("Enter the message to encrypt/decrypt: ");
    fgets(message, sizeof(message), stdin);

    // Remove newline if present
    size_t len = strlen(message);
    if (len > 0 && message[len - 1] == '\n') {
        message[len - 1] = '\0';
    }

    char cipher[1000];
    for (int i = 0; message[i] != '\0'; i++) {
        char letter = message[i];
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







#include <stdio.h>
#include <ctype.h>

void caesarCipherEncryption();
void caesarCipherDecryption();

int main() {
	char input;

	printf("List of Ciphers:\n");
	printf("\tc: Caesar Cipher\n");
	printf("\tb: Base64\n");
	printf("\ta: Atbash Cipher\n");
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
	scanf("%s", &message);
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
	scanf("%s", &message);
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

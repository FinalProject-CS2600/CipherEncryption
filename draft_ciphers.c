#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Caesar Cipher
void caesarCipherEncryption();
void caesarCipherDecryption();

// Atbash Cipher
void Atbash_encryption();

// Base64
void base64_Encrypt();
void decrypt();
char convertToBase(int decimalNum);
char* convertToBinary(int decimalNum);
int convertToDecimal(char* binaryNumber);
char* split_array(char input_array[1000], char output_array[2000]);

int main() {
    char input;
    int cont = 1;
    
    while(cont == 1) {
        printf("Cipher Encryption\n");
        printf("-- Menu Options --\n");
        printf("\tc: Caesar Cipher\n");
        printf("\tb: Base64\n");
        printf("\ta: Atbash Cipher\n");
        printf("\tq: Quit program\n");
        printf("Please enter a character: ");
        scanf(" %c", &input);

        if (input == 'c') {
            printf("Selected Cipher: Caesar Cipher\n");
            printf("Mode:\n\te: Encrypt\n\td: Decrypt\n");
            printf("Please enter a mode: ");
            scanf(" %c", &input);
            if (input == 'e') caesarCipherEncryption();
            else if (input == 'd') caesarCipherDecryption();
            else printf("Invalid selection.\n\n");
        } else if (input == 'b') {
            printf("Selected Cipher: Base64\n");
            printf("Mode:\n\te: Encrypt\n\td: Decrypt\n");
            printf("Please enter a mode: ");
            scanf(" %c", &input);
            if (input == 'e') base64_Encrypt();
            else if (input == 'd') decrypt();
            else printf("Invalid selection.\n\n");
        } else if (input == 'a') {
            printf("Selected Cipher: Atbash Cipher\n");
            printf("Mode:\n\te: Encrypt/Decrypt (symmetric)\n\td: Encrypt/Decrypt (symmetric)\n");
            printf("Please enter a mode: ");
            scanf(" %c", &input);
            if (input == 'e' || input == 'd') Atbash_encryption();
            else printf("Invalid selection.\n\n");
        } else if (input == 'q') {
            printf("Exiting...\n");
            cont = 0;
        } else {
            printf("Invalid selection.\n\n");
        }
    }
    return 0;
}

// ---------------- Caesar Cipher ----------------

void caesarCipherEncryption() {
    char message[100];
    int key;
    printf("Enter message: ");
    scanf(" %[^\n]", message);
    printf("Enter shift key: ");
    scanf("%d", &key);
    for (int i = 0; message[i]; i++) {
        if (isupper(message[i])) message[i] = (message[i] - 'A' + key) % 26 + 'A';
        else if (islower(message[i])) message[i] = (message[i] - 'a' + key) % 26 + 'a';
        else if (isdigit(message[i])) message[i] = (message[i] - '0' + key) % 10 + '0';
    }
    printf("Encrypted: %s\n", message);
}

void caesarCipherDecryption() {
    char message[100];
    int key;
    printf("Enter message: ");
    scanf(" %[^\n]", message);
    printf("Enter shift key: ");
    scanf("%d", &key);
    for (int i = 0; message[i]; i++) {
        if (isupper(message[i])) message[i] = (message[i] - 'A' - key + 26) % 26 + 'A';
        else if (islower(message[i])) message[i] = (message[i] - 'a' - key + 26) % 26 + 'a';
        else if (isdigit(message[i])) message[i] = (message[i] - '0' - key + 10) % 10 + '0';
    }
    printf("Decrypted: %s\n", message);
}

// ---------------- Atbash Cipher ----------------

void Atbash_encryption() {
    char lookup[26] = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
    char message[1000];
    printf("Enter message: ");
    getchar(); // consume newline
    fgets(message, sizeof(message), stdin);
    size_t len = strlen(message);
    if (len > 0 && message[len - 1] == '\n') message[len - 1] = '\0';
    for (int i = 0; message[i]; i++) {
        if (isalpha(message[i])) {
            char upper = toupper(message[i]);
            message[i] = lookup[upper - 'A'];
        }
    }
    printf("Result: %s\n", message);
}

// ---------------- Base64 ----------------

char convertToBase(int decimalNum) {
    char base64[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    return base64[decimalNum];
}

char* convertToBinary(int decimalNum) {
    char* bin = malloc(9);
    for (int i = 0; i < 8; i++) {
        bin[7 - i] = (decimalNum % 2) + '0';
        decimalNum /= 2;
    }
    bin[8] = '\0';
    return bin;
}

int convertToDecimal(char* bin) {
    int dec = 0, power = 1;
    for (int i = strlen(bin) - 1; i >= 0; i--) {
        if (bin[i] == '1') dec += power;
        power *= 2;
    }
    return dec;
}

char* split_array(char in[1000], char out[2000]) {
    int len = strlen(in);
    int rem = len % 6;
    int pad = (rem == 0) ? 0 : 6 - rem;
    while (pad--) strcat(in, "0");
    int inIdx = 0, outIdx = 0, count = 0;
    while (in[inIdx]) {
        out[outIdx++] = in[inIdx++];
        if (++count == 6) {
            out[outIdx++] = ' ';
            count = 0;
        }
    }
    out[outIdx] = '\0';
    return out;
}

void base64_Encrypt() {
    char user[100], binStr[1000] = "", spaced[2000] = "", b64[100];
    int ascii[100], count = 0;
    printf("Enter text to encrypt: ");
    scanf("%s", user);

    for (int i = 0; user[i]; i++) ascii[i] = user[i];
    for (int i = 0; user[i]; i++) {
        char* bin = convertToBinary(ascii[i]);
        strcat(binStr, bin);
        free(bin);
    }

    split_array(binStr, spaced);

    char chunk[7];
    int idx = 0;
    for (int i = 0; spaced[i]; i++) {
        if (spaced[i] == ' ') {
            chunk[idx] = '\0';
            b64[count++] = convertToBase(convertToDecimal(chunk));
            idx = 0;
        } else {
            chunk[idx++] = spaced[i];
        }
    }
    b64[count] = '\0';

    int pad = (4 - (count % 4)) % 4;
    while (pad--) b64[count++] = '=';
    b64[count] = '\0';

    printf("Encrypted: %s\n", b64);
}

int base64ToDecimal(char c) {
    char base64[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    for (int i = 0; i < 64; i++) if (base64[i] == c) return i;
    return -1;
}

void decrypt() {
    char input[100], binStr[1000] = "", result[100];
    int idx = 0;
    printf("Enter base64 string: ");
    scanf("%s", input);

    for (int i = 0; input[i] && input[i] != '='; i++) {
        int dec = base64ToDecimal(input[i]);
        for (int j = 5; j >= 0; j--) binStr[idx++] = ((dec >> j) & 1) + '0';
    }
    binStr[idx] = '\0';

    int outIdx = 0;
    for (int i = 0; i + 7 < idx; i += 8) {
        char byte[9];
        strncpy(byte, &binStr[i], 8);
        byte[8] = '\0';
        result[outIdx++] = (char)convertToDecimal(byte);
    }
    result[outIdx] = '\0';
    printf("Decrypted: %s\n", result);
}

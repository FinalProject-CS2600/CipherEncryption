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

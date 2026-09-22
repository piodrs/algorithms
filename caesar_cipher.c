#include <assert.h>
#include <stddef.h>
#include <stdio.h>

typedef struct {
	int shift;
} CaesarCipher;

static void caesar_transform(char *text, int shift)
{
	size_t i;
	int base;
	int ch;

	assert(text != NULL);
	shift %= 26;
	if (shift < 0)
		shift += 26;

	for (i = 0; text[i] != '\0'; ++i) {
		ch = text[i];
		if (ch >= 'A' && ch <= 'Z')
			base = 'A';
		else if (ch >= 'a' && ch <= 'z')
			base = 'a';
		else
			continue;
		text[i] = base + (ch - base + shift) % 26;
	}
}

static void caesar_encrypt(const CaesarCipher *cipher, char *text)
{
	assert(cipher != NULL);
	caesar_transform(text, cipher->shift);
}

static void caesar_decrypt(const CaesarCipher *cipher, char *text)
{
	assert(cipher != NULL);
	caesar_transform(text, -(cipher->shift % 26));
}

int main(void)
{
	CaesarCipher cipher = {
		.shift = 3,
	};
	char text[] = "Hello, World! Piod john 778";

	printf("Original: %s\n", text);
	caesar_encrypt(&cipher, text);
	printf("Encrypted: %s\n", text);
	caesar_decrypt(&cipher, text);
	printf("Decrypted: %s\n", text);
	return 0;
}

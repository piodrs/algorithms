#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

void caesar_transform(char *text, int shift)
{
	const char *letters;
	const char *pos;

	assert(text != NULL);
	shift %= 26;
	if (shift < 0)
		shift += 26;

	for (; *text != '\0'; ++text) {
		letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		pos = strchr(letters, *text);
		if (pos == NULL) {
			letters = "abcdefghijklmnopqrstuvwxyz";
			pos = strchr(letters, *text);
		}
		if (pos != NULL)
			*text = letters[(pos - letters + shift) % 26];
	}
}

int main(void)
{
	char text[] = "Hello, World! Piod john 778";

	printf("Original: %s\n", text);
	caesar_transform(text, 3);
	printf("Encrypted: %s\n", text);
	caesar_transform(text, -3);
	printf("Decrypted: %s\n", text);
	return 0;
}

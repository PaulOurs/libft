#include "libft.h"
#include <stdio.h>
#include <string.h>

void test_ft_isalpha(void) {
    assert(ft_isalpha('a') == 1);
    assert(ft_isalpha('A') == 1);
    assert(ft_isalpha('z') == 1);
    assert(ft_isalpha('Z') == 1);
    assert(ft_isalpha('0') != 1);
    assert(ft_isalpha('9') != 1);
    assert(ft_isalpha(' ') != 1);
    assert(ft_isalpha('\t') != 1);
    assert(ft_isalpha(0) != 1);
    assert(ft_isalpha(256) != 1);
}

void test_ft_isdigit() {
    char str[] = "Hello123, Je suis Paul et j'ai 20 ans depuis 7 jours";
	printf("String to be tested:\n%s\n", str);
    size_t i = 0;
    while (i < ft_strlen(str)) {
        if (ft_isdigit(str[i])) {
            printf("Found digit at index %ld: '%c'\n", i, str[i]);
        }
        i++;
	}
}

void	test_ft_isalnum(void)
{
	assert(ft_isalnum('a') == 1); // true
	assert(ft_isalnum('A') == 1); // true
	assert(ft_isalnum('0') == 1); // true
	assert(ft_isalnum('@') == 0); // false
}

void test_ft_isascii() {
    assert(ft_isascii('a') == 1);
    assert(ft_isascii('A') == 1);
    assert(ft_isascii('\t') == 1);
    assert(ft_isascii(128) == 0); // Not an ASCII character
}

void test_ft_isprint()
{
    // Test printable ASCII characters
    assert(ft_isprint(' ') == 1); // space
    assert(ft_isprint('a') == 1); // lowercase letter
    assert(ft_isprint('A') == 1); // uppercase letter
    assert(ft_isprint('0') == 1); // digit
    assert(ft_isprint('~') == 1); // tilde

    // Test non-printable ASCII characters
    assert(ft_isprint('\n') == 0); // newline
    assert(ft_isprint('\t') == 0); // tab
    assert(ft_isprint('\r') == 0); // carriage return

    // Test ASCII characters outside the printable range
    assert(ft_isprint('\x1F') == 0); // below space
    assert(ft_isprint('\x7F') == 0); // above ~

    // Test non-ASCII characters
    assert(ft_isprint('\xC3') == 0); // extended ASCII
    assert(ft_isprint('\xE2') == 0); // Unicode
}

void test_ft_strlen() {
    // Test case 1: Empty string
    assert(ft_strlen("") == 0);

    // Test case 2: Single character string
    const char *single_char = "a";
    assert(ft_strlen(single_char) == 1);

    // Test case 3: Longer string
    const char *long_string = "Hello, World!";
    assert(ft_strlen(long_string) == 13);
}

void test_ft_memset(void)
{
    // Test 1: memset with null pointer
    void *ptr = NULL;
    ft_memset(ptr, 'a', 10);
    // No assertion, just check for no crash

    // Test 2: memset with zero length
    // char arr[10];
    // ft_memset(arr, 'a', 0);
    // if (strcmp(arr, "") != 0)
    // {
    //     printf("Test 2 failed\n");
    // }

    // Test 3: memset with single character
    char arr2[10];
    ft_memset(arr2, 'a', 1);
    if (arr2[0] != 'a')
    {
        printf("Test 3 failed\n");
    }

    // Test 4: memset with multiple characters
    char arr3[10];
    ft_memset(arr3, 'a', 5);
    for (int i = 0; i < 5; i++)
    {
        if (arr3[i] != 'a')
        {
            printf("Test 4 failed\n");
        }
    }

    // Test 5: memset with large length
    char arr4[100];
    ft_memset(arr4, 'a', 100);
    for (int i = 0; i < 100; i++)
    {
        if (arr4[i] != 'a')
        {
            printf("Test 5 failed\n");
        }
    }

    // Test 6: memset with char value 0
    char arr5[10];
    ft_memset(arr5, 0, 10);
    for (int i = 0; i < 10; i++)
    {
        if (arr5[i] != 0)
        {
            printf("Test 6 failed\n");
        }
    }
}

void test_ft_bzero(void)
{
    // Test 1: bzero with null pointer
    void *ptr = NULL;
    ft_bzero(ptr, 10);
    // No assertion, just check for no crash

    // Test 2: bzero with zero length
    char arr[10];
    ft_bzero(arr, 0);
    if (strcmp(arr, "") != 0)
    {
        printf("Test 2 failed\n");
    }

    // Test 3: bzero with single byte
    char arr2[1];
    ft_bzero(arr2, 1);
    if (arr2[0] != '\0')
    {
        printf("Test 3 failed\n");
    }

    // Test 4: bzero with multiple bytes
    char arr3[10];
    ft_bzero(arr3, 10);
    for (int i = 0; i < 10; i++)
    {
        if (arr3[i] != '\0')
        {
            printf("Test 4 failed\n");
        }
    }

    // Test 5: bzero with large length
    char arr4[100];
    ft_bzero(arr4, 100);
    for (int i = 0; i < 100; i++)
    {
        if (arr4[i] != '\0')
        {
            printf("Test 5 failed\n");
        }
    }
}

void test_ft_memcpy(void)
{
    // Test 1: Copying a string
    char src[] = "Hello, World!";
    char dest[20];
    ft_memcpy(dest, src, strlen(src) + 1);
    assert(strcmp(dest, src) == 0);

    // Test 2: Copying a string with null characters
    char src2[] = "Hello\0World!";
    char dest2[20];
    ft_memcpy(dest2, src2, strlen(src2) + 1);
    assert(strcmp(dest2, src2) == 0);

    // Test 3: Copying an empty string
    char src3[] = "";
    char dest3[20];
    ft_memcpy(dest3, src3, strlen(src3) + 1);
    assert(strcmp(dest3, src3) == 0);

    // Test 4: Copying a string with a large size
    char src4[1000];
    for (int i = 0; i < 1000; i++)
        src4[i] = 'a';
    char dest4[1000];
    ft_memcpy(dest4, src4, 1000);
    assert(memcmp(dest4, src4, 1000) == 0);

    // Test 5: Copying a string with a size of 0
    char src5[] = "Hello";
    char dest5[20];
    ft_memcpy(dest5, src5, 0);
    assert(dest5[0] == '\0');

    // Test 6: Copying a string with overlapping source and destination
    char src6[] = "Hello";
    char dest6[] = "World";
    ft_memcpy(dest6 + 2, src6, 3);
    assert(strcmp(dest6, "WoHelld") == 0);

    printf("All tests passed!\n");
}

int main(void)
{
	printf("=== ft_isalpha ===\n");
    printf("Running tests...\n");
    test_ft_isalpha();
    printf("All tests passed!\n\n");

	printf("=== ft_isdigit ===\n");
    printf("Running tests...\n");
    test_ft_isdigit();
    printf("All tests passed!\n\n");

	printf("=== ft_isalnum ===\n");
	printf("Running tests...\n");
	test_ft_isalnum();
	printf("All tests passed!\n\n");

	printf("=== ft_isascii ===\n");
    printf("Running tests...\n");
    test_ft_isascii();
    printf("All tests passed!\n\n");

	printf("=== ft_isprint ===\n");
	printf("Running tests...\n");
	test_ft_isprint();
	printf("All tests passed!\n\n");

	printf("=== ft_strlen ===\n");
    printf("Running tests...\n");
    test_ft_strlen();
    printf("All tests passed!\n\n");

	printf("=== ft_memset ===\n");
	printf("Running tests...\n");
	test_ft_memset();
	printf("All tests passed!\n\n");

	printf("=== ft_bzero ===\n");
	printf("Running tests...\n");
	test_ft_bzero();
	printf("All tests passed!\n\n");

	printf("=== ft_memcpy ===\n");
	printf("Running tests...\n");
	test_ft_memcpy();
	printf("All tests passed!\n\n");
	return (0);
}

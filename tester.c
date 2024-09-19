#include "libft.h"
#include <stdio.h>
#include <string.h>

void test_ft_isalpha(void) {
	printf("=== ft_isalpha ===\n");
	printf("Running tests...\n");
    // Test 1: Alphabetic characters (lowercase and uppercase)
    assert(ft_isalpha('a') == 1);   // Lowercase letter
    assert(ft_isalpha('m') == 1);   // Lowercase letter
    assert(ft_isalpha('z') == 1);   // Lowercase letter
    assert(ft_isalpha('A') == 1);   // Uppercase letter
    assert(ft_isalpha('M') == 1);   // Uppercase letter
    assert(ft_isalpha('Z') == 1);   // Uppercase letter
    printf("Test 1 passed: Alphabetic characters (lowercase and uppercase).\n");

    // Test 2: Non-alphabetic characters
    assert(ft_isalpha('0') == 0);   // Digit
    assert(ft_isalpha(' ') == 0);   // Space
    assert(ft_isalpha('@') == 0);   // Special character
    assert(ft_isalpha('[') == 0);   // Special character
    printf("Test 2 passed: Non-alphabetic characters.\n");

    // Test 3: Boundary values
    assert(ft_isalpha('a') == 1);   // Lower boundary (lowercase)
    assert(ft_isalpha('z') == 1);   // Upper boundary (lowercase)
    assert(ft_isalpha('A') == 1);   // Lower boundary (uppercase)
    assert(ft_isalpha('Z') == 1);   // Upper boundary (uppercase)
    printf("Test 3 passed: Boundary values.\n");

    // Test 4: Characters outside the standard ASCII printable range
    assert(ft_isalpha(127) == 0);   // ASCII DEL (Delete)
    assert(ft_isalpha(128) == 0);   // Character above the printable range
    assert(ft_isalpha(255) == 0);   // Well above the printable range
    printf("Test 4 passed: Characters outside the standard ASCII printable range.\n");

    // Test 5: Negative and non-ASCII values
    assert(ft_isalpha(-1) == 0);    // Negative value
    assert(ft_isalpha(-10) == 0);   // Negative value, much lower
    printf("Test 5 passed: Negative and non-ASCII values.\n");

	printf("All tests passed!\n\n");
}

void test_ft_isdigit() {
	printf("=== ft_isdigit ===\n");
	printf("Running tests...\n");

	// Test 1: Numeric characters
    assert(ft_isdigit('0') == 1);   // Lower boundary
    assert(ft_isdigit('5') == 1);   // Middle digit
    assert(ft_isdigit('9') == 1);   // Upper boundary
    printf("Test 1 passed: Numeric characters.\n");

    // Test 2: Non-numeric characters
    assert(ft_isdigit('a') == 0);   // Lowercase letter
    assert(ft_isdigit('Z') == 0);   // Uppercase letter
    assert(ft_isdigit(' ') == 0);   // Space
    assert(ft_isdigit('@') == 0);   // Special character
    printf("Test 2 passed: Non-numeric characters.\n");

    // Test 3: Boundary values
    assert(ft_isdigit('0') == 1);   // Lower boundary
    assert(ft_isdigit('9') == 1);   // Upper boundary
    printf("Test 3 passed: Boundary values.\n");

    // Test 4: Characters outside the standard ASCII printable range
    assert(ft_isdigit(127) == 0);   // ASCII DEL (Delete)
    assert(ft_isdigit(128) == 0);   // Character above the printable range
    assert(ft_isdigit(255) == 0);   // Well above the printable range
    printf("Test 4 passed: Characters outside the standard ASCII printable range.\n");

    // Test 5: Negative and non-ASCII values
    assert(ft_isdigit(-1) == 0);    // Negative value
    assert(ft_isdigit(-10) == 0);   // Negative value, much lower
    printf("Test 5 passed: Negative and non-ASCII values.\n");
    char str[] = "Hello123, Je suis Paul et j'ai 20 ans depuis 7 jours";
	printf("String to be tested:\n%s\n", str);
    size_t i = 0;
    while (i < ft_strlen(str)) {
        if (ft_isdigit(str[i])) {
            printf("Found digit at index %ld: '%c'\n", i, str[i]);
        }
        i++;
	}

	printf("All tests passed!\n\n");
}

void	test_ft_isalnum(void)
{
	printf("=== ft_isalnum ===\n");
	printf("Running tests...\n");

	// Test 1: Alphabetic characters (lowercase and uppercase)
    assert(ft_isalnum('a') == 1);   // Lowercase letter
    assert(ft_isalnum('z') == 1);   // Lowercase letter
    assert(ft_isalnum('A') == 1);   // Uppercase letter
    assert(ft_isalnum('Z') == 1);   // Uppercase letter
    printf("Test 1 passed: Alphabetic characters (lowercase and uppercase).\n");

    // Test 2: Numeric characters
    assert(ft_isalnum('0') == 1);   // Digit
    assert(ft_isalnum('9') == 1);   // Digit
    printf("Test 2 passed: Numeric characters.\n");

    // Test 3: Non-alphanumeric characters
    assert(ft_isalnum(' ') == 0);   // Space
    assert(ft_isalnum('!') == 0);   // Exclamation mark
    assert(ft_isalnum('@') == 0);   // At symbol
    printf("Test 3 passed: Non-alphanumeric characters.\n");

    // Test 4: Boundary values
    assert(ft_isalnum('a') == 1);   // Lowercase letter (boundary of lower range)
    assert(ft_isalnum('z') == 1);   // Lowercase letter (boundary of upper range)
    assert(ft_isalnum('A') == 1);   // Uppercase letter (boundary of lower range)
    assert(ft_isalnum('Z') == 1);   // Uppercase letter (boundary of upper range)
    assert(ft_isalnum('0') == 1);   // Digit (boundary of lower range)
    assert(ft_isalnum('9') == 1);   // Digit (boundary of upper range)
    printf("Test 4 passed: Boundary values.\n");

    // Test 5: Characters outside the standard ASCII printable range
    assert(ft_isalnum(127) == 0);  // ASCII DEL (Delete)
    assert(ft_isalnum(128) == 0);  // Character above the printable range
    assert(ft_isalnum(255) == 0);  // Well above the printable range
    printf("Test 5 passed: Characters outside the standard ASCII printable range.\n");

	printf("All tests passed!\n\n");
}

void test_ft_isascii()
{
	printf("=== ft_isascii ===\n");
	printf("Running tests...\n");

    // Test 1: ASCII characters within the range
    assert(ft_isascii(0) == 1);    // Null character
    assert(ft_isascii(65) == 1);   // ASCII character 'A'
    assert(ft_isascii(97) == 1);   // ASCII character 'a'
    assert(ft_isascii(127) == 1);  // ASCII DEL (Delete)
    printf("Test 1 passed: ASCII characters within the range.\n");

    // Test 2: Characters outside the ASCII range
    assert(ft_isascii(-1) == 0);   // Below the ASCII range
    assert(ft_isascii(128) == 0);  // Above the ASCII range
    assert(ft_isascii(255) == 0);  // Well above the ASCII range
    printf("Test 2 passed: Characters outside the ASCII range.\n");

    // Test 3: Boundary values
    assert(ft_isascii(0) == 1);    // Lower boundary
    assert(ft_isascii(127) == 1);  // Upper boundary
    printf("Test 3 passed: Boundary values.\n");

	printf("All tests passed!\n\n");
}

void test_ft_isprint()
{
	printf("=== ft_isprint ===\n");
	printf("Running tests...\n");

    // Test 1: Printable characters
    assert(ft_isprint(' ') == 1);   // Space character
    assert(ft_isprint('A') == 1);   // Printable alphabetic character
    assert(ft_isprint('z') == 1);   // Printable alphabetic character
    assert(ft_isprint('0') == 1);   // Printable numeric character
    assert(ft_isprint('~') == 1);   // Printable special character
    printf("Test 1 passed: Printable characters.\n");

    // Test 2: Non-printable characters
    assert(ft_isprint(0) == 0);     // Null character
    assert(ft_isprint(31) == 0);    // ASCII control character (Unit Separator)
    assert(ft_isprint(127) == 0);   // ASCII DEL (Delete)
    printf("Test 2 passed: Non-printable characters.\n");

    // Test 3: Characters outside printable range
    assert(ft_isprint(128) == 0);   // Character above the printable range
    assert(ft_isprint(255) == 0);   // Character well beyond the printable range
    printf("Test 3 passed: Characters outside printable range.\n");

    // Test 4: Boundary values
    assert(ft_isprint(32) == 1);    // Lower boundary (Space character)
    assert(ft_isprint(126) == 1);   // Upper boundary (~ character)
    printf("Test 4 passed: Boundary values.\n");

	printf("All tests passed!\n\n");
}

void test_ft_strlen()
{
	printf("=== ft_strlen ===\n");
	printf("Running tests...\n");

    // Test 1: Basic string length
    const char *str1 = "Hello, World!";
    assert(ft_strlen(str1) == 13);
    printf("Test 1 passed: Basic string length.\n");

    // Test 2: Empty string
    const char *str2 = "";
    assert(ft_strlen(str2) == 0);
    printf("Test 2 passed: Empty string.\n");

    // Test 3: String with spaces and special characters
    const char *str3 = "  Hello \t\n";
    assert(ft_strlen(str3) == 10);
    printf("Test 3 passed: String with spaces and special characters.\n");

    // Test 4: String with only null character
    const char *str4 = "\0";
    assert(ft_strlen(str4) == 0);
    printf("Test 4 passed: String with only null character.\n");

    // Test 5: Large string
    const char *str5 = "This is a long string to test the ft_strlen function with a larger input size.";
    assert(ft_strlen(str5) == 78);
    printf("Test 5 passed: Large string.\n");

	printf("All tests passed!\n\n");
}

void test_ft_memset(void)
{
	printf("=== ft_memset ===\n");
	printf("Running tests...\n");

    // Test 1: Setting a string to a specific character
    char str1[20] = "Hello, World!";
    ft_memset(str1, 'A', 5);
    assert(strncmp(str1, "AAAAA, World!", 13) == 0);
    printf("Test 1 passed: Setting a string to a specific character.\n");

    // Test 2: Setting a block of memory to zero
    char str2[20] = "Hello, World!";
    ft_memset(str2, 0, 13);
    size_t i = 0;
    while (i < 13) {
        assert(str2[i] == '\0');
        i++;
    }
    printf("Test 2 passed: Setting a block of memory to zero.\n");

    // Test 3: Setting an array of integers
    int arr3[5] = {1, 2, 3, 4, 5};
    ft_memset(arr3, 0, sizeof(arr3));
    i = 0;
    while (i < sizeof(arr3) / sizeof(int)) {
        assert(arr3[i] == 0);
        i++;
    }
    printf("Test 3 passed: Setting an array of integers.\n");

    // Test 4: Setting memory with n = 0 (no operation)
    char str4[20] = "NoChange";
    ft_memset(str4, 'X', 0); // Should not change the string
    assert(strcmp(str4, "NoChange") == 0);
    printf("Test 4 passed: Setting memory with n = 0 (no operation).\n");

    // Test 5: Setting a struct's fields
    struct {
        int id;
        char name[10];
        float value;
    } data5;
    ft_memset(&data5, 0xFF, sizeof(data5)); // Set all bytes to 0xFF
    unsigned char *byte_ptr = (unsigned char *)&data5;
    i = 0;
    while (i < sizeof(data5)) {
        assert(byte_ptr[i] == 0xFF);
        i++;
    }
    printf("Test 5 passed: Setting a struct's fields.\n");

	printf("All tests passed!\n\n");
}

void test_ft_bzero(void)
{
	printf("=== ft_bzero ===\n");
	printf("Running tests...\n");

    // Test 1: Zeroing out an entire string
    char str1[] = "Hello, World!";
    ft_bzero(str1, sizeof(str1));
    size_t i = 0;
    while (i < sizeof(str1)) {
        assert(str1[i] == '\0');
        i++;
    }
    printf("Test 1 passed: Zeroing out an entire string.\n");

    // Test 2: Zeroing out part of a string
    char str2[] = "Hello, World!";
    ft_bzero(str2 + 7, 6);  // Zero out "World!"
    assert(strcmp(str2, "Hello, ") == 0);  // Only "Hello, " should remain
    i = 7;
    while (i < 13) {
        assert(str2[i] == '\0');
        i++;
    }
    printf("Test 2 passed: Zeroing out part of a string.\n");

    // Test 3: Zeroing an array of integers
    int arr3[] = {1, 2, 3, 4, 5};
    ft_bzero(arr3, sizeof(arr3));
    size_t j = 0;
    while (j < sizeof(arr3) / sizeof(int)) {
        assert(arr3[j] == 0);
        j++;
    }
    printf("Test 3 passed: Zeroing an array of integers.\n");

    // Test 4: Zeroing with n = 0 (no operation)
    char str4[] = "NoChange";
    ft_bzero(str4, 0);  // Should not alter the string
    assert(strcmp(str4, "NoChange") == 0);
    printf("Test 4 passed: Zeroing with n = 0 (no operation).\n");

    // Test 5: Zeroing a struct
    struct {
        int id;
        char name[10];
        float value;
    } data5 = {42, "Test", 3.14};
    ft_bzero(&data5, sizeof(data5));
    assert(data5.id == 0);
    i = 0;
    while (i < sizeof(data5.name)) {
        assert(data5.name[i] == '\0');
        i++;
    }
    assert(data5.value == 0.0f);
    printf("Test 5 passed: Zeroing a struct.\n");

	printf("All tests passed!\n\n");
}

void test_ft_memcpy(void)
{
	printf("=== ft_memcpy ===\n");
	printf("Running tests...\n");

    // Test 1: Basic copying of a string
    char src1[] = "Hello, World!";
    char dest1[20];
	ft_bzero(dest1, 20);
    ft_memcpy(dest1, src1, 13);
    assert(strcmp(dest1, "Hello, World!") == 0);
    printf("Test 1 passed: Basic copying of a string.\n");

    // Test 2: Copying with `n` equal to 0 (no operation)
    char src2[] = "NoChange";
    char dest2[20] = "Original";
    ft_memcpy(dest2, src2, 0);
    assert(strcmp(dest2, "Original") == 0);
    printf("Test 2 passed: Copying with size of 0 (no operation).\n");

    // Test 3: Copying binary data (integers)
    int src3[] = {1, 2, 3, 4, 5};
    int dest3[5];
    ft_memcpy(dest3, src3, 5 * sizeof(int));
    int i = 0;
    while (i < 5) {
        assert(dest3[i] == src3[i]);
        i++;
    }
    printf("Test 3 passed: Copying binary data (integers).\n");

    // Test 4: Copying a single character
    char src4[] = "A";
    char dest4[2] = {0}; // Initialize to zero
    ft_memcpy(dest4, src4, 1);
    assert(dest4[0] == 'A' && dest4[1] == '\0');
    printf("Test 4 passed: Copying a single character.\n");

    // Test 5: Copying into overlapping regions (not allowed with memcpy)
    // Note: This is to confirm undefined behavior is not handled by ft_memcpy.
    char src5[] = "Overlapping";
    ft_memcpy(src5 + 4, src5, 5); // This is incorrect usage for memcpy
    assert(strcmp(src5, "Overlapping") != 0); // Just a sanity check
    printf("Test 5 passed: Overlapping regions produce undefined behavior.\n");

    // Test 6: Copying non-string data (structs)
    struct {
        int id;
        float value;
    } src6 = {42, 3.14}, dest6;
    ft_memcpy(&dest6, &src6, sizeof(src6));
    assert(dest6.id == src6.id && dest6.value == src6.value);
    printf("Test 6 passed: Copying non-string data (structs).\n");

	printf("All tests passed!\n\n");
}

void test_ft_memmove(void)
{
	printf("=== ft_memmove ===\n");
	printf("Running tests...\n");

	// Test 1: Basic copying with no overlap
    char src1[] = "Hello, World!";
    char dest1[20];
	ft_bzero(dest1, 20);
    ft_memmove(dest1, src1, 13);
    assert(strcmp(dest1, "Hello, World!") == 0);
    printf("Test 1 passed: Basic copying with no overlap.\n");

    // Test 2: Copying within the same buffer (overlapping regions, forward copy)
    char src2[] = "1234567890";
    ft_memmove(src2 + 4, src2, 6);  // Copy "123456" to start at src2[4]
    assert(strcmp(src2, "1234123456") == 0);
    printf("Test 2 passed: Overlapping regions (forward copy).\n");

    // Test 3: Copying within the same buffer (overlapping regions, backward copy)
    char src3[] = "abcdef";
    ft_memmove(src3, src3 + 2, 4);  // Copy "cdef" to start at src3[0]
    assert(strcmp(src3, "cdefef") == 0);
    printf("Test 3 passed: Overlapping regions (backward copy).\n");

    // Test 4: Copying with `n` equal to 0 (no operation)
    char src4[] = "Hello";
    char dest4[20];
    ft_memmove(dest4, src4, 0);
    // No changes expected, dest4 may contain garbage, but should not crash.
    printf("Test 4 passed: Copying with size of 0 (no operation).\n");

    // Test 5: Copying a single character
    char src5[] = "Hello";
    char dest5[20];
    ft_memmove(dest5, src5, 1);
    assert(dest5[0] == 'H');
    printf("Test 5 passed: Copying a single character.\n");

    // Test 6: Source and destination are the same
    char src6[] = "Same";
    ft_memmove(src6, src6, 4);
    assert(strcmp(src6, "Same") == 0);
    printf("Test 6 passed: Source and destination are the same.\n");

	printf("All tests passed!\n\n");
}

int main(void)
{
    test_ft_isalpha();

    test_ft_isdigit();

	test_ft_isalnum();

    test_ft_isascii();

	test_ft_isprint();

    test_ft_strlen();

	test_ft_memset();

	test_ft_bzero();

	test_ft_memcpy();

	test_ft_memmove();
	return (0);
}

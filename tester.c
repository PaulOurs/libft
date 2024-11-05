#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <bsd/string.h>

void test_ft_isalpha(void)
{
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

void test_ft_isdigit()
{
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

void test_ft_memmove() {
    char buffer1[50], buffer2[50];
    char std_buffer1[50], std_buffer2[50];

    // Test 1: Normal case, non-overlapping memory
    strcpy(buffer1, "Hello, World!");
    strcpy(std_buffer1, "Hello, World!");
    ft_memmove(buffer1 + 7, buffer1, 6);         // Custom memmove
    memmove(std_buffer1 + 7, std_buffer1, 6);    // Standard memmove
    assert(strcmp(buffer1, std_buffer1) == 0);
    printf("Test 1 passed: Normal case, non-overlapping.\n");

    // Test 2: Overlapping memory (dest < src)
    strcpy(buffer1, "123456789");
    strcpy(std_buffer1, "123456789");
    ft_memmove(buffer1, buffer1 + 3, 6);
    memmove(std_buffer1, std_buffer1 + 3, 6);
    assert(strcmp(buffer1, std_buffer1) == 0);
    printf("Test 2 passed: Overlapping memory (dest < src).\n");

    // Test 3: Overlapping memory (dest > src)
    strcpy(buffer1, "123456789");
    strcpy(std_buffer1, "123456789");
    ft_memmove(buffer1 + 3, buffer1, 6);
    memmove(std_buffer1 + 3, std_buffer1, 6);
    assert(strcmp(buffer1, std_buffer1) == 0);
    printf("Test 3 passed: Overlapping memory (dest > src).\n");

    // Test 4: n = 0, no memory copied
    strcpy(buffer1, "Hello");
    strcpy(std_buffer1, "Hello");
    ft_memmove(buffer1, "World", 0);   // Custom memmove
    memmove(std_buffer1, "World", 0);  // Standard memmove
    assert(strcmp(buffer1, std_buffer1) == 0);
    printf("Test 4 passed: No copying when n = 0.\n");

    // Test 5: src and dest are the same
    strcpy(buffer1, "No change");
    strcpy(std_buffer1, "No change");
    ft_memmove(buffer1, buffer1, 8);         // Custom memmove
    memmove(std_buffer1, std_buffer1, 8);    // Standard memmove
    assert(strcmp(buffer1, std_buffer1) == 0);
    printf("Test 5 passed: Source and destination are the same.\n");

    // Test 6: Larger memory block, no overlap
    strcpy(buffer1, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    strcpy(buffer2, "abcdefghijklmnopqrstuvwxyz");
    strcpy(std_buffer1, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    strcpy(std_buffer2, "abcdefghijklmnopqrstuvwxyz");
    ft_memmove(buffer2, buffer1, 26);   // Custom memmove
    memmove(std_buffer2, std_buffer1, 26);  // Standard memmove
    assert(strcmp(buffer2, std_buffer2) == 0);
    printf("Test 6 passed: Larger memory block, no overlap.\n");

    printf("All tests passed!\n");
}

void test_ft_strlcpy(void)
{
	printf("=== ft_strlcpy ===\n");
	printf("Running tests...\n");

	char dest[50];
    char std_dest[50];
    size_t ft_len, std_len;

    // Test 1: Destination size larger than source
    ft_len = ft_strlcpy(dest, "Hello, World!", 20);
    std_len = strlcpy(std_dest, "Hello, World!", 20);
    assert(ft_len == std_len);
    assert(strcmp(dest, std_dest) == 0);
    printf("Test 1 passed: Destination size larger than source.\n");

    // Test 2: Destination size smaller than source
    ft_len = ft_strlcpy(dest, "Hello", 3);
    std_len = strlcpy(std_dest, "Hello", 3);
    assert(ft_len == std_len);
    assert(strcmp(dest, std_dest) == 0);
    printf("Test 2 passed: Destination size smaller than source.\n");

    // Test 3: Destination size exactly the length of the source + 1
    ft_len = ft_strlcpy(dest, "Hello", 6);
    std_len = strlcpy(std_dest, "Hello", 6);
    assert(ft_len == std_len);
    assert(strcmp(dest, std_dest) == 0);
    printf("Test 3 passed: Destination size exactly length of source + 1.\n");

    // Test 4: Destination size zero
    ft_len = ft_strlcpy(dest, "Hello", 0);
    std_len = strlcpy(std_dest, "Hello", 0);
    assert(ft_len == std_len);
    assert(strcmp(dest, std_dest) == 0);
    printf("Test 4 passed: Destination size zero.\n");

    // Test 5: Empty source
    ft_len = ft_strlcpy(dest, "", 10);
    std_len = strlcpy(std_dest, "", 10);
    assert(ft_len == std_len);
    assert(strcmp(dest, std_dest) == 0);
    printf("Test 5 passed: Empty source.\n");

    // Test 6: Empty source with size zero
    ft_len = ft_strlcpy(dest, "", 0);
    std_len = strlcpy(std_dest, "", 0);
    assert(ft_len == std_len);
    assert(strcmp(dest, std_dest) == 0);
    printf("Test 6 passed: Empty source with size zero.\n");

    // Test 7: Large source, small destination
    char large_src[50];
    for (size_t i = 0; i < 49; i++) {
        large_src[i] = 'a';
    }
    large_src[49] = '\0'; // Make it a null-terminated string
    ft_len = ft_strlcpy(dest, large_src, 10);
    std_len = strlcpy(std_dest, large_src, 10);
    assert(ft_len == std_len);
    assert(strcmp(dest, std_dest) == 0);
    printf("Test 7 passed: Large source, small destination.\n");

    printf("All tests passed!\n\n");
}

void test_ft_strlcat(void)
{
	printf("=== ft_strlcat ===\n");
	printf("Running tests...\n");

	char dest[50];
    char std_dest[50];
    size_t ft_len, std_len;

    // Test 1: Basic concatenation with enough space in dest
    strcpy(dest, "Hello, ");
    strcpy(std_dest, "Hello, ");
    ft_len = ft_strlcat(dest, "World!", 50);
    std_len = strlcat(std_dest, "World!", 50);
    assert(ft_len == std_len);
    assert(strcmp(dest, std_dest) == 0);
    printf("Test 1 passed: Basic concatenation with enough space.\n");

    // Test 2: Concatenation with limited space
    strcpy(dest, "Hello, ");
    strcpy(std_dest, "Hello, ");
    ft_len = ft_strlcat(dest, "World!", 10);
    std_len = strlcat(std_dest, "World!", 10);
    assert(ft_len == std_len);
    assert(strcmp(dest, std_dest) == 0);
    printf("Test 2 passed: Concatenation with limited space.\n");

    // Test 3: Concatenation with exact size
    strcpy(dest, "Hello, ");
    strcpy(std_dest, "Hello, ");
    ft_len = ft_strlcat(dest, "World!", 13);
    std_len = strlcat(std_dest, "World!", 13);
    assert(ft_len == std_len);
    assert(strcmp(dest, std_dest) == 0);
    printf("Test 3 passed: Concatenation with exact size.\n");

    // Test 4: Concatenation with size 0
    strcpy(dest, "Hello, ");
    strcpy(std_dest, "Hello, ");
    ft_len = ft_strlcat(dest, "World!", 0);
    std_len = strlcat(std_dest, "World!", 0);
    assert(ft_len == std_len);
    printf("Test 4 passed: Concatenation with size 0.\n");

    // Test 5: Concatenation with empty source
    strcpy(dest, "Hello, ");
    strcpy(std_dest, "Hello, ");
    ft_len = ft_strlcat(dest, "", 50);
    std_len = strlcat(std_dest, "", 50);
    assert(ft_len == std_len);
    assert(strcmp(dest, std_dest) == 0);
    printf("Test 5 passed: Concatenation with empty source.\n");

    // Test 6: Concatenation with empty destination
    strcpy(dest, "");
    strcpy(std_dest, "");
    ft_len = ft_strlcat(dest, "World!", 50);
    std_len = strlcat(std_dest, "World!", 50);
    assert(ft_len == std_len);
    assert(strcmp(dest, std_dest) == 0);
    printf("Test 6 passed: Concatenation with empty destination.\n");

    // Test 7: Concatenation with full destination and no space
    strcpy(dest, "Hello, World!");
    strcpy(std_dest, "Hello, World!");
    ft_len = ft_strlcat(dest, "12345", 13);
    std_len = strlcat(std_dest, "12345", 13);
    assert(ft_len == std_len);
    assert(strcmp(dest, std_dest) == 0);
    printf("Test 7 passed: Concatenation with full destination and no space.\n");

    printf("All tests passed!\n\n");
}

void test_ft_toupper(void)
{
	printf("=== ft_toupper ===\n");
	printf("Running tests...\n");

	int ft_res, std_res;

    // Test 1: Lowercase 'a' to 'A'
    ft_res = ft_toupper('a');
    std_res = toupper('a');
    assert(ft_res == std_res);
    printf("Test 1 passed: 'a' to 'A'.\n");

    // Test 2: Lowercase 'z' to 'Z'
    ft_res = ft_toupper('z');
    std_res = toupper('z');
    assert(ft_res == std_res);
    printf("Test 2 passed: 'z' to 'Z'.\n");

    // Test 3: Uppercase 'A' should stay 'A'
    ft_res = ft_toupper('A');
    std_res = toupper('A');
    assert(ft_res == std_res);
    printf("Test 3 passed: 'A' stays 'A'.\n");

    // Test 4: Non-alphabetic character ('1') should remain unchanged
    ft_res = ft_toupper('1');
    std_res = toupper('1');
    assert(ft_res == std_res);
    printf("Test 4 passed: '1' stays '1'.\n");

    // Test 5: Non-alphabetic character ('@') should remain unchanged
    ft_res = ft_toupper('@');
    std_res = toupper('@');
    assert(ft_res == std_res);
    printf("Test 5 passed: '@' stays '@'.\n");

    // Test 6: Space character should remain unchanged
    ft_res = ft_toupper(' ');
    std_res = toupper(' ');
    assert(ft_res == std_res);
    printf("Test 6 passed: ' ' stays ' '.\n");

    // Test 7: Non-printable character (ASCII 7 - bell) should remain unchanged
    ft_res = ft_toupper(7);
    std_res = toupper(7);
    assert(ft_res == std_res);
    printf("Test 7 passed: ASCII bell (7) remains unchanged.\n");

    // Test 8: Upper boundary case - '{'
    ft_res = ft_toupper('{');
    std_res = toupper('{');
    assert(ft_res == std_res);
    printf("Test 8 passed: '{' remains unchanged.\n");

    // Test 9: Lowercase 'b' to 'B'
    ft_res = ft_toupper('b');
    std_res = toupper('b');
    assert(ft_res == std_res);
    printf("Test 9 passed: 'b' to 'B'.\n");

    // Test 10: Non-alphabetic negative number (-1) should remain unchanged
    ft_res = ft_toupper(-1);
    std_res = toupper(-1);
    assert(ft_res == std_res);
    printf("Test 10 passed: -1 remains unchanged.\n");

    printf("All tests passed!\n\n");
}

void test_ft_tolower(void)
{
	printf("=== ft_tolower ===\n");
	printf("Running tests...\n");

	int ft_res, std_res;

    // Test 1: Uppercase 'A' to lowercase 'a'
    ft_res = ft_tolower('A');
    std_res = tolower('A');
    assert(ft_res == std_res);
    printf("Test 1 passed: 'A' to 'a'.\n");

    // Test 2: Uppercase 'Z' to lowercase 'z'
    ft_res = ft_tolower('Z');
    std_res = tolower('Z');
    assert(ft_res == std_res);
    printf("Test 2 passed: 'Z' to 'z'.\n");

    // Test 3: Lowercase 'a' should stay 'a'
    ft_res = ft_tolower('a');
    std_res = tolower('a');
    assert(ft_res == std_res);
    printf("Test 3 passed: 'a' stays 'a'.\n");

    // Test 4: Non-alphabetic character ('1') should remain unchanged
    ft_res = ft_tolower('1');
    std_res = tolower('1');
    assert(ft_res == std_res);
    printf("Test 4 passed: '1' stays '1'.\n");

    // Test 5: Non-alphabetic character ('@') should remain unchanged
    ft_res = ft_tolower('@');
    std_res = tolower('@');
    assert(ft_res == std_res);
    printf("Test 5 passed: '@' stays '@'.\n");

    // Test 6: Space character should remain unchanged
    ft_res = ft_tolower(' ');
    std_res = tolower(' ');
    assert(ft_res == std_res);
    printf("Test 6 passed: ' ' stays ' '.\n");

    // Test 7: Non-printable character (ASCII 7 - bell) should remain unchanged
    ft_res = ft_tolower(7);
    std_res = tolower(7);
    assert(ft_res == std_res);
    printf("Test 7 passed: ASCII bell (7) remains unchanged.\n");

    // Test 8: Upper boundary case - '['
    ft_res = ft_tolower('[');
    std_res = tolower('[');
    assert(ft_res == std_res);
    printf("Test 8 passed: '[' remains unchanged.\n");

    // Test 9: Uppercase 'B' to lowercase 'b'
    ft_res = ft_tolower('B');
    std_res = tolower('B');
    assert(ft_res == std_res);
    printf("Test 9 passed: 'B' to 'b'.\n");

    // Test 10: Non-alphabetic negative number (-1) should remain unchanged
    ft_res = ft_tolower(-1);
    std_res = tolower(-1);
    assert(ft_res == std_res);
    printf("Test 10 passed: -1 remains unchanged.\n");

    printf("All tests passed!\n\n");
}

void test_ft_strchr(void)
{
	printf("=== ft_strchr ===\n");
	printf("Running tests...\n");

	char *ft_res, *std_res;
    const char *str = "Hello, World!";

    // Test 1: Find 'H' in the string
    ft_res = ft_strchr(str, 'H');
    std_res = strchr(str, 'H');
    assert(ft_res == std_res);
    printf("Test 1 passed: Find 'H'.\n");

    // Test 2: Find 'W' in the string
    ft_res = ft_strchr(str, 'W');
    std_res = strchr(str, 'W');
    assert(ft_res == std_res);
    printf("Test 2 passed: Find 'W'.\n");

    // Test 3: Find ',' in the string
    ft_res = ft_strchr(str, ',');
    std_res = strchr(str, ',');
    assert(ft_res == std_res);
    printf("Test 3 passed: Find ','.\n");

    // Test 4: Search for null character '\0'
    ft_res = ft_strchr(str, '\0');
    std_res = strchr(str, '\0');
    assert(ft_res == std_res);
    printf("Test 4 passed: Find null character '\\0'.\n");

    // Test 5: Search for a character not in the string
    ft_res = ft_strchr(str, 'x');
    std_res = strchr(str, 'x');
    assert(ft_res == std_res);
    printf("Test 5 passed: Character not found ('x').\n");

    // Test 6: Find 'l' in the string (first occurrence)
    ft_res = ft_strchr(str, 'l');
    std_res = strchr(str, 'l');
    assert(ft_res == std_res);
    printf("Test 6 passed: Find first 'l'.\n");

    // Test 7: Find space ' ' in the string
    ft_res = ft_strchr(str, ' ');
    std_res = strchr(str, ' ');
    assert(ft_res == std_res);
    printf("Test 7 passed: Find space ' '.\n");

    // Test 8: Empty string, search for 'a'
    const char *empty_str = "";
    ft_res = ft_strchr(empty_str, 'a');
    std_res = strchr(empty_str, 'a');
    assert(ft_res == std_res);
    printf("Test 8 passed: Search in an empty string.\n");

    // Test 9: Empty string, search for '\0'
    ft_res = ft_strchr(empty_str, '\0');
    std_res = strchr(empty_str, '\0');
    assert(ft_res == std_res);
    printf("Test 9 passed: Search for '\\0' in an empty string.\n");

    printf("All tests passed!\n\n");
}

void test_ft_strrchr(void)
{
	printf("=== ft_strrchr ===\n");
	printf("Running tests...\n");

	char *ft_res, *std_res;
    const char *str = "Hello, World!";

    // Test 1: Find last 'o' in the string
    ft_res = ft_strrchr(str, 'o');
    std_res = strrchr(str, 'o');
    assert(ft_res == std_res);
    printf("Test 1 passed: Find last 'o'.\n");

    // Test 2: Find last 'l' in the string
    ft_res = ft_strrchr(str, 'l');
    std_res = strrchr(str, 'l');
    assert(ft_res == std_res);
    printf("Test 2 passed: Find last 'l'.\n");

    // Test 3: Find last 'W' in the string
    ft_res = ft_strrchr(str, 'W');
    std_res = strrchr(str, 'W');
    assert(ft_res == std_res);
    printf("Test 3 passed: Find last 'W'.\n");

    // Test 4: Search for null character '\0'
    ft_res = ft_strrchr(str, '\0');
    std_res = strrchr(str, '\0');
    assert(ft_res == std_res);
    printf("Test 4 passed: Find null character '\\0'.\n");

    // Test 5: Search for a character not in the string
    ft_res = ft_strrchr(str, 'x');
    std_res = strrchr(str, 'x');
    assert(ft_res == std_res);
    printf("Test 5 passed: Character not found ('x').\n");

    // Test 6: Find last 'H' in the string
    ft_res = ft_strrchr(str, 'H');
    std_res = strrchr(str, 'H');
    assert(ft_res == std_res);
    printf("Test 6 passed: Find last 'H'.\n");

    // Test 7: Find space ' ' in the string
    ft_res = ft_strrchr(str, ' ');
    std_res = strrchr(str, ' ');
    assert(ft_res == std_res);
    printf("Test 7 passed: Find space ' '.\n");

    // Test 8: Empty string, search for 'a'
    const char *empty_str = "";
    ft_res = ft_strrchr(empty_str, 'a');
    std_res = strrchr(empty_str, 'a');
    assert(ft_res == std_res);
    printf("Test 8 passed: Search in an empty string.\n");

    // Test 9: Empty string, search for '\0'
    ft_res = ft_strrchr(empty_str, '\0');
    std_res = strrchr(empty_str, '\0');
    assert(ft_res == std_res);
    printf("Test 9 passed: Search for '\\0' in an empty string.\n");

    printf("All tests passed!\n\n");
}
void test_ft_strncmp(void)
{
	printf("=== ft_strncmp ===\n");
	printf("Running tests...\n");

	int ft_res, std_res;

    // Test 1: Compare equal strings with n > 0
    ft_res = ft_strncmp("Hello", "Hello", 5);
    std_res = strncmp("Hello", "Hello", 5);
    assert(ft_res == std_res);
    printf("Test 1 passed: Equal strings with n = 5.\n");

    // Test 2: Compare strings with different characters
    ft_res = ft_strncmp("Hello", "Helxo", 5);
    std_res = strncmp("Hello", "Helxo", 5);
    assert(ft_res == std_res);
    printf("Test 2 passed: Different strings with n = 5.\n");

    // Test 3: Compare strings where s1 is greater than s2
    ft_res = ft_strncmp("Hello", "HelLo", 5);
    std_res = strncmp("Hello", "HelLo", 5);
    assert(ft_res == std_res);
    printf("Test 3 passed: s1 > s2.\n");

    // Test 4: Compare strings where s2 is greater than s1
    ft_res = ft_strncmp("HelLo", "Hello", 5);
    std_res = strncmp("HelLo", "Hello", 5);
    assert(ft_res == std_res);
    printf("Test 4 passed: s1 < s2.\n");

    // Test 5: Compare strings with n = 0 (should return 0)
    ft_res = ft_strncmp("Hello", "Hello", 0);
    std_res = strncmp("Hello", "Hello", 0);
    assert(ft_res == std_res);
    printf("Test 5 passed: n = 0.\n");

    // Test 6: Compare strings with n smaller than the length of the strings
    ft_res = ft_strncmp("Hello", "HelLo", 3);
    std_res = strncmp("Hello", "HelLo", 3);
    assert(ft_res == std_res);
    printf("Test 6 passed: Compare first 3 characters.\n");

    // Test 7: Compare strings of different lengths
    ft_res = ft_strncmp("Hello", "HelloWorld", 10);
    std_res = strncmp("Hello", "HelloWorld", 10);
    assert(ft_res == std_res);
    printf("Test 7 passed: Compare different lengths.\n");

    // Test 8: Compare strings with a null character in s1
    ft_res = ft_strncmp("Hello\0World", "Hello", 10);
    std_res = strncmp("Hello\0World", "Hello", 10);
    assert(ft_res == std_res);
    printf("Test 8 passed: Compare with null character in s1.\n");

    // Test 9: Compare an empty string with a non-empty string
    ft_res = ft_strncmp("", "Hello", 5);
    std_res = strncmp("", "Hello", 5);
    assert(ft_res == std_res);
    printf("Test 9 passed: Compare empty string with non-empty string.\n");

    // Test 10: Compare two empty strings
    ft_res = ft_strncmp("", "", 5);
    std_res = strncmp("", "", 5);
    assert(ft_res == std_res);
    printf("Test 10 passed: Compare two empty strings.\n");

    // Test 11: Compare strings where one string is a prefix of the other
    ft_res = ft_strncmp("Hello", "Hell", 5);
    std_res = strncmp("Hello", "Hell", 5);
    assert(ft_res == std_res);
    printf("Test 11 passed: One string is a prefix of the other.\n");

    printf("All tests passed!\n\n");
}

void test_ft_memchr(void)
{
	printf("=== ft_memchr ===\n");
	printf("Running tests...\n");

	void *ft_res, *std_res;

    // Test 1: Character found in the middle
    char str1[] = "Hello, World!";
    ft_res = ft_memchr(str1, 'W', 13);
    std_res = memchr(str1, 'W', 13);
    assert(ft_res == std_res);
    printf("Test 1 passed: Character 'W' found in the middle.\n");

    // Test 2: Character not found
    ft_res = ft_memchr(str1, 'x', 13);
    std_res = memchr(str1, 'x', 13);
    assert(ft_res == std_res);
    printf("Test 2 passed: Character 'x' not found.\n");

    // Test 3: Character found at the beginning
    ft_res = ft_memchr(str1, 'H', 13);
    std_res = memchr(str1, 'H', 13);
    assert(ft_res == std_res);
    printf("Test 3 passed: Character 'H' found at the beginning.\n");

    // Test 4: Character found at the end
    ft_res = ft_memchr(str1, '!', 13);
    std_res = memchr(str1, '!', 13);
    assert(ft_res == std_res);
    printf("Test 4 passed: Character '!' found at the end.\n");

    // Test 5: Searching with n = 0 (no search should happen, return NULL)
    ft_res = ft_memchr(str1, 'H', 0);
    std_res = memchr(str1, 'H', 0);
    assert(ft_res == std_res);
    printf("Test 5 passed: n = 0 (return NULL).\n");

    // Test 6: Character not found with n less than string length
    ft_res = ft_memchr(str1, 'W', 5);
    std_res = memchr(str1, 'W', 5);
    assert(ft_res == std_res);
    printf("Test 6 passed: Character 'W' not found when n < length.\n");

    // Test 7: Searching for the null byte within the string
    ft_res = ft_memchr(str1, '\0', 14);  // Including null byte in search
    std_res = memchr(str1, '\0', 14);
    assert(ft_res == std_res);
    printf("Test 7 passed: Searching for the null byte.\n");

    // Test 8: Empty string with n > 0 (no match)
    char str2[] = "";
    ft_res = ft_memchr(str2, 'a', 1);
    std_res = memchr(str2, 'a', 1);
    assert(ft_res == std_res);
    printf("Test 8 passed: Empty string, no match.\n");

    // Test 9: Character found with n = 1
    char str3[] = "A";
    ft_res = ft_memchr(str3, 'A', 1);
    std_res = memchr(str3, 'A', 1);
    assert(ft_res == std_res);
    printf("Test 9 passed: Single character string, match found.\n");

    // Test 10: Character not found in n = 1
    ft_res = ft_memchr(str3, 'B', 1);
    std_res = memchr(str3, 'B', 1);
    assert(ft_res == std_res);
    printf("Test 10 passed: Single character string, no match.\n");

    printf("All tests passed!\n\n");
}

void test_ft_memcmp(void)
{
	printf("=== ft_memcmp ===\n");
	printf("Running tests...\n");

	int ft_res, std_res;

    // Test 1: Comparing equal strings
    char str1[] = "Hello, World!";
    char str2[] = "Hello, World!";
    ft_res = ft_memcmp(str1, str2, 13);
    std_res = memcmp(str1, str2, 13);
    assert(ft_res == std_res);
    printf("Test 1 passed: Equal strings comparison.\n");

    // Test 2: Comparing different strings (first differing at the start)
    char str3[] = "Hello, World!";
    char str4[] = "hello, World!"; // Different case 'H' vs 'h'
    ft_res = ft_memcmp(str3, str4, 13);
    std_res = memcmp(str3, str4, 13);
    assert(ft_res == std_res);
    printf("Test 2 passed: Different strings comparison (at start).\n");

    // Test 3: Comparing different strings (first differing in the middle)
    char str5[] = "Hello, World!";
    char str6[] = "Hello, world!"; // Different 'W' vs 'w'
    ft_res = ft_memcmp(str5, str6, 13);
    std_res = memcmp(str5, str6, 13);
    assert(ft_res == std_res);
    printf("Test 3 passed: Different strings comparison (in the middle).\n");

    // Test 4: Comparing different strings with same prefix
    char str7[] = "Hello";
    char str8[] = "Hello, World!"; // str7 is a prefix of str8
    ft_res = ft_memcmp(str7, str8, 5);  // Only compare first 5 characters
    std_res = memcmp(str7, str8, 5);
    assert(ft_res == std_res);
    printf("Test 4 passed: Prefix comparison (equal first 5 characters).\n");

    // // Test 5: Comparing different strings with unequal length (n < min length)
    // ft_res = ft_memcmp(str7, str8, 10);  // Compare more than available in str7
    // std_res = memcmp(str7, str8, 10);
    // assert(ft_res == std_res);
    // printf("Test 5 passed: Prefix comparison (n > length of first string).\n");

    // Test 6: Comparing with zero length (should always return 0)
    ft_res = ft_memcmp(str1, str2, 0);
    std_res = memcmp(str1, str2, 0);
    assert(ft_res == std_res);
    printf("Test 6 passed: Comparison with n = 0.\n");

    // Test 7: Comparing empty strings (n = 0)
    char empty1[] = "";
    char empty2[] = "";
    ft_res = ft_memcmp(empty1, empty2, 0);
    std_res = memcmp(empty1, empty2, 0);
    assert(ft_res == std_res);
    printf("Test 7 passed: Empty strings comparison with n = 0.\n");

    // Test 8: Comparing empty string with non-empty string
    ft_res = ft_memcmp(empty1, str8, 1);
    std_res = memcmp(empty1, str8, 1);
    assert(ft_res == std_res);
    printf("Test 8 passed: Empty string vs non-empty string.\n");

    // Test 9: Comparing arrays of bytes
    unsigned char arr1[] = {0x01, 0x02, 0x03, 0x04};
    unsigned char arr2[] = {0x01, 0x02, 0x03, 0x05};  // Last byte is different
    ft_res = ft_memcmp(arr1, arr2, 4);
    std_res = memcmp(arr1, arr2, 4);
    assert(ft_res == std_res);
    printf("Test 9 passed: Byte arrays comparison (last byte differs).\n");

    // Test 10: Comparing arrays of bytes (same array)
    ft_res = ft_memcmp(arr1, arr1, 4);
    std_res = memcmp(arr1, arr1, 4);
    assert(ft_res == std_res);
    printf("Test 10 passed: Byte arrays comparison (identical arrays).\n");

    printf("All tests passed!\n\n");
}

void test_ft_strnstr(void)
{
	printf("=== ft_strnstr ===\n");
	printf("Running tests...\n");

	char *ft_res, *std_res;

    // Test 1: Searching for an empty string in "Hello, World!"
    char big1[] = "Hello, World!";
    char little1[] = "";
    ft_res = ft_strnstr(big1, little1, 13);
    std_res = strnstr(big1, little1, 13);
    assert(ft_res == std_res);
    printf("Test 1 passed: Searching for an empty string.\n");

    // Test 2: Searching for "World" in "Hello, World!"
    char little2[] = "World";
    ft_res = ft_strnstr(big1, little2, 13);
    std_res = strnstr(big1, little2, 13);
    assert(ft_res == std_res);
    printf("Test 2 passed: Searching for 'World' within the string.\n");

    // Test 3: Searching for "World" but with len smaller than its location
    ft_res = ft_strnstr(big1, little2, 7);  // 'World' starts after 7th character
    std_res = strnstr(big1, little2, 7);
    assert(ft_res == std_res);
    printf("Test 3 passed: Searching with len smaller than the substring position.\n");

    // Test 4: Searching for a substring that does not exist
    char little3[] = "42";
    ft_res = ft_strnstr(big1, little3, 13);
    std_res = strnstr(big1, little3, 13);
    assert(ft_res == std_res);
    printf("Test 4 passed: Searching for a substring that does not exist.\n");

    // Test 5: Searching for a substring that starts at the beginning
    char little4[] = "Hello";
    ft_res = ft_strnstr(big1, little4, 5);  // len covers the exact match length
    std_res = strnstr(big1, little4, 5);
    assert(ft_res == std_res);
    printf("Test 5 passed: Searching for a substring at the beginning.\n");

    // Test 6: Searching for a substring that is partially within the length
    ft_res = ft_strnstr(big1, little2, 11);  // 'World' starts after len=11
    std_res = strnstr(big1, little2, 11);
    assert(ft_res == std_res);
    printf("Test 6 passed: Searching for a substring cut off by len.\n");

    // Test 7: Searching for a substring within an empty string
    char big2[] = "";
    ft_res = ft_strnstr(big2, little1, 1);  // Searching for empty substring
    std_res = strnstr(big2, little1, 1);
    assert(ft_res == std_res);
    printf("Test 7 passed: Searching in an empty string for an empty substring.\n");

    // Test 8: Searching for a non-empty substring within an empty string
    ft_res = ft_strnstr(big2, little4, 5);  // No match because big2 is empty
    std_res = strnstr(big2, little4, 5);
    assert(ft_res == std_res);
    printf("Test 8 passed: Searching for a non-empty substring in an empty string.\n");

    // Test 9: Searching for the full string within itself (boundary case)
    ft_res = ft_strnstr(big1, big1, strlen(big1));
    std_res = strnstr(big1, big1, strlen(big1));
    assert(ft_res == std_res);
    printf("Test 9 passed: Searching for the full string within itself.\n");

    // Test 10: Searching with len = 0 (should return NULL)
    ft_res = ft_strnstr(big1, little2, 0);  // len is 0, should return NULL
    std_res = strnstr(big1, little2, 0);
    assert(ft_res == std_res);
    printf("Test 10 passed: Searching with len = 0.\n");

    printf("All tests passed!\n\n");
}

void test_ft_atoi(void)
{
	printf("=== ft_atoi ===\n");
	printf("Running tests...\n");

	int ft_res, std_res;

    // Test 1: Convert a positive number
    ft_res = ft_atoi("12345");
    std_res = atoi("12345");
    assert(ft_res == std_res);
    printf("Test 1 passed: Convert a positive number.\n");

    // Test 2: Convert a negative number
    ft_res = ft_atoi("-54321");
    std_res = atoi("-54321");
    assert(ft_res == std_res);
    printf("Test 2 passed: Convert a negative number.\n");

    // Test 3: Convert zero
    ft_res = ft_atoi("0");
    std_res = atoi("0");
    assert(ft_res == std_res);
    printf("Test 3 passed: Convert zero.\n");

    // Test 4: Convert a number with leading spaces
    ft_res = ft_atoi("   42");
    std_res = atoi("   42");
    assert(ft_res == std_res);
    printf("Test 4 passed: Convert a number with leading spaces.\n");

    // Test 5: Convert a negative number with leading spaces
    ft_res = ft_atoi("   -123");
    std_res = atoi("   -123");
    assert(ft_res == std_res);
    printf("Test 5 passed: Convert a negative number with leading spaces.\n");

    // Test 6: Convert a number with trailing non-numeric characters
    ft_res = ft_atoi("123abc");
    std_res = atoi("123abc");
    assert(ft_res == std_res);
    printf("Test 6 passed: Convert a number with trailing non-numeric characters.\n");

    // Test 7: Convert a number with a plus sign
    ft_res = ft_atoi("+456");
    std_res = atoi("+456");
    assert(ft_res == std_res);
    printf("Test 7 passed: Convert a number with a plus sign.\n");

    // Test 8: Convert an empty string (should return 0)
    ft_res = ft_atoi("");
    std_res = atoi("");
    assert(ft_res == std_res);
    printf("Test 8 passed: Convert an empty string (should return 0).\n");

    // Test 9: Convert a string with only spaces (should return 0)
    ft_res = ft_atoi("    ");
    std_res = atoi("    ");
    assert(ft_res == std_res);
    printf("Test 9 passed: Convert a string with only spaces (should return 0).\n");

    // Test 10: Convert a string with multiple signs (undefined behavior, both should behave the same)
    ft_res = ft_atoi("--123");
    std_res = atoi("--123");
    assert(ft_res == std_res);
    printf("Test 10 passed: Convert a string with multiple signs (undefined behavior).\n");

    // Test 11: Convert a string with INT_MAX value
    ft_res = ft_atoi("2147483647");
    std_res = atoi("2147483647");
    assert(ft_res == std_res);
    printf("Test 11 passed: Convert INT_MAX value.\n");

    // Test 12: Convert a string with INT_MIN value
    ft_res = ft_atoi("-2147483648");
    std_res = atoi("-2147483648");
    assert(ft_res == std_res);
    printf("Test 12 passed: Convert INT_MIN value.\n");

    printf("All tests passed!\n\n");
}

void test_ft_calloc(void)
{
	printf("=== ft_calloc ===\n");
	printf("Running tests...\n");

	void *ft_res, *std_res;
    int i;

    // Test 1: Allocate 10 integers (should be initialized to zero)
    ft_res = ft_calloc(10, sizeof(int));
    std_res = calloc(10, sizeof(int));
    assert(memcmp(ft_res, std_res, 10 * sizeof(int)) == 0);
    printf("Test 1 passed: Allocate 10 integers (initialized to zero).\n");
    free(ft_res);
    free(std_res);

    // Test 2: Allocate 20 characters (should be initialized to zero)
    ft_res = ft_calloc(20, sizeof(char));
    std_res = calloc(20, sizeof(char));
    assert(memcmp(ft_res, std_res, 20 * sizeof(char)) == 0);
    printf("Test 2 passed: Allocate 20 characters (initialized to zero).\n");
    free(ft_res);
    free(std_res);

    // Test 3: Allocate 0 elements (should return a valid pointer)
    ft_res = ft_calloc(0, sizeof(char));
    std_res = calloc(0, sizeof(char));
    assert(ft_res != NULL);
    assert(std_res != NULL);
    printf("Test 3 passed: Allocate 0 elements (returns a valid pointer).\n");
    free(ft_res);
    free(std_res);

    // Test 4: Allocate 0 size (should return a valid pointer)
    ft_res = ft_calloc(10, 0);
    std_res = calloc(10, 0);
    assert(ft_res != NULL);
    assert(std_res != NULL);
    printf("Test 4 passed: Allocate 0 size (returns a valid pointer).\n");
    free(ft_res);
    free(std_res);

    // Test 5: Allocate 5 doubles (should be initialized to zero)
    ft_res = ft_calloc(5, sizeof(double));
    std_res = calloc(5, sizeof(double));
    assert(memcmp(ft_res, std_res, 5 * sizeof(double)) == 0);
    printf("Test 5 passed: Allocate 5 doubles (initialized to zero).\n");
    free(ft_res);
    free(std_res);

    // Test 6: Allocate large memory and check for zero initialization
    size_t large_size = 100000;
    ft_res = ft_calloc(large_size, sizeof(char));
    std_res = calloc(large_size, sizeof(char));
    assert(memcmp(ft_res, std_res, large_size * sizeof(char)) == 0);
    printf("Test 6 passed: Allocate large memory (initialized to zero).\n");
    free(ft_res);
    free(std_res);

    // Test 7: Allocate 5 integers and check all values are zero
    ft_res = ft_calloc(5, sizeof(int));
    for (i = 0; i < 5; i++) {
        assert(((int*)ft_res)[i] == 0);
    }
    printf("Test 7 passed: Verify allocated memory is zeroed out.\n");
    free(ft_res);

    printf("All tests passed!\n\n");
}

void test_ft_strdup(void)
{
	printf("=== ft_strdup ===\n");
	printf("Running tests...\n");

	char *ft_res;
    char *std_res;

    // Test 1: Duplicate a simple string
    ft_res = ft_strdup("Hello, World!");
    std_res = strdup("Hello, World!");
    assert(strcmp(ft_res, std_res) == 0);
    printf("Test 1 passed: Duplicate a simple string.\n");
    free(ft_res);
    free(std_res);

    // Test 2: Duplicate an empty string
    ft_res = ft_strdup("");
    std_res = strdup("");
    assert(strcmp(ft_res, std_res) == 0);
    printf("Test 2 passed: Duplicate an empty string.\n");
    free(ft_res);
    free(std_res);

    // Test 3: Duplicate a string with special characters
    ft_res = ft_strdup("!@#$%^&*()_+");
    std_res = strdup("!@#$%^&*()_+");
    assert(strcmp(ft_res, std_res) == 0);
    printf("Test 3 passed: Duplicate a string with special characters.\n");
    free(ft_res);
    free(std_res);

    // Test 4: Duplicate a long string
    char long_str[] = "This is a really long string to test the function ft_strdup for large inputs.";
    ft_res = ft_strdup(long_str);
    std_res = strdup(long_str);
    assert(strcmp(ft_res, std_res) == 0);
    printf("Test 4 passed: Duplicate a long string.\n");
    free(ft_res);
    free(std_res);

    // Test 5: Verify that ft_strdup allocates new memory and the content is correct
    char original[] = "Memory Test";
    ft_res = ft_strdup(original);
    assert(ft_res != NULL); // Check memory was allocated
    assert(strcmp(ft_res, original) == 0); // Ensure the content is the same
    printf("Test 5 passed: Verify content is correctly duplicated.\n");
    free(ft_res);

    printf("All tests passed!\n");
}

void test_ft_substr(void)
{
	printf("=== ft_substr ===\n");
	printf("Running tests...\n");

	char *res;

    // Test 1: Normal case
    res = ft_substr("Hello, World!", 7, 5); // Expected: "World"
    assert(strcmp(res, "World") == 0);
    printf("Test 1 passed: Normal case.\n");
    free(res);

    // Test 2: Start index out of bounds
    res = ft_substr("Hello", 10, 5); // Expected: ""
    assert(strcmp(res, "") == 0);
    printf("Test 2 passed: Start index out of bounds.\n");
    free(res);

    // Test 3: Length longer than remaining string
    res = ft_substr("Hello", 3, 10); // Expected: "lo"
    assert(strcmp(res, "lo") == 0);
    printf("Test 3 passed: Length longer than remaining string.\n");
    free(res);

    // Test 4: Empty string as input
    res = ft_substr("", 0, 5); // Expected: ""
    assert(strcmp(res, "") == 0);
    printf("Test 4 passed: Empty string as input.\n");
    free(res);

    // Test 5: Start at the beginning and get full string
    res = ft_substr("Hello", 0, 5); // Expected: "Hello"
    assert(strcmp(res, "Hello") == 0);
    printf("Test 5 passed: Start at the beginning and get full string.\n");
    free(res);

    // Test 6: Start index equals the string length
    res = ft_substr("Hello", 5, 3); // Expected: ""
    assert(strcmp(res, "") == 0);
    printf("Test 6 passed: Start index equals the string length.\n");
    free(res);

    // Test 7: Length of 0 (should return empty string)
    res = ft_substr("Hello", 1, 0); // Expected: ""
    assert(strcmp(res, "") == 0);
    printf("Test 7 passed: Length of 0.\n");
    free(res);

    // Test 8: Substring from middle of the string
    res = ft_substr("Substring test", 3, 6); // Expected: "string"
    assert(strcmp(res, "string") == 0);
    printf("Test 8 passed: Substring from the middle of the string.\n");
    free(res);

    // Test 9: Substring of a single character
    res = ft_substr("Single character", 7, 1); // Expected: "c"
    assert(strcmp(res, "c") == 0);
    printf("Test 9 passed: Substring of a single character.\n");
    free(res);

    printf("All tests passed!\n\n");
}

void test_ft_strjoin(void)
{
	printf("=== ft_strjoin ===\n");
	printf("Running tests...\n");

	char *res;

    // Test 1: Normal case, joining two strings
    res = ft_strjoin("Hello, ", "World!");  // Expected: "Hello, World!"
    assert(strcmp(res, "Hello, World!") == 0);
    printf("Test 1 passed: Normal case.\n");
    free(res);

    // Test 2: Joining an empty string with a non-empty string
    res = ft_strjoin("", "Non-empty");  // Expected: "Non-empty"
    assert(strcmp(res, "Non-empty") == 0);
    printf("Test 2 passed: Empty string with non-empty string.\n");
    free(res);

    // Test 3: Joining a non-empty string with an empty string
    res = ft_strjoin("Non-empty", "");  // Expected: "Non-empty"
    assert(strcmp(res, "Non-empty") == 0);
    printf("Test 3 passed: Non-empty string with empty string.\n");
    free(res);

    // Test 4: Joining two empty strings
    res = ft_strjoin("", "");  // Expected: ""
    assert(strcmp(res, "") == 0);
    printf("Test 4 passed: Joining two empty strings.\n");
    free(res);

    // Test 5: Joining long strings
    res = ft_strjoin("This is a long string ", "and another long string.");
    assert(strcmp(res, "This is a long string and another long string.") == 0);
    printf("Test 5 passed: Joining long strings.\n");
    free(res);

    // Test 6: NULL for first string (should return NULL)
    res = ft_strjoin(NULL, "World!");  // Expected: NULL
    assert(res == NULL);
    printf("Test 6 passed: First string is NULL.\n");

    // Test 7: NULL for second string (should return NULL)
    res = ft_strjoin("Hello", NULL);  // Expected: NULL
    assert(res == NULL);
    printf("Test 7 passed: Second string is NULL.\n");

    // Test 8: NULL for both strings (should return NULL)
    res = ft_strjoin(NULL, NULL);  // Expected: NULL
    assert(res == NULL);
    printf("Test 8 passed: Both strings are NULL.\n");

    printf("All tests passed!\n");
}

void free_split(char **split) {
    int i = 0;
    while (split[i]) {
        free(split[i]);
        i++;
    }
    free(split);
}

// Helper function to compare result from ft_split with expected result
int compare_split(char **split, char **expected) {
    int i = 0;
    while (split[i] && expected[i]) {
        if (strcmp(split[i], expected[i]) != 0) {
            return 0; // Return 0 if mismatch is found
        }
        i++;
    }
    return split[i] == NULL && expected[i] == NULL; // Return 1 if both are NULL
}

void test_ft_split(void)
{
    printf("=== ft_split ===\n");
    printf("Running tests...\n");

    char **ft_res;
    char *expected[10];

    // Test 1: Basic splitting with spaces
    ft_res = ft_split("Hello World This is 42", ' ');
    expected[0] = "Hello"; expected[1] = "World"; expected[2] = "This";
    expected[3] = "is"; expected[4] = "42"; expected[5] = NULL;
    assert(compare_split(ft_res, expected));
    free_split(ft_res);
    printf("Test 1 passed: Basic split with space.\n");

    // Test 2: Splitting with commas
    ft_res = ft_split("Apple,Banana,Cherry", ',');
    expected[0] = "Apple"; expected[1] = "Banana"; expected[2] = "Cherry"; expected[3] = NULL;
    assert(compare_split(ft_res, expected));
    free_split(ft_res);
    printf("Test 2 passed: Split with comma.\n");

    // Test 3: Multiple consecutive delimiters
    ft_res = ft_split("::A::B::C::", ':');
    expected[0] = "A"; expected[1] = "B"; expected[2] = "C"; expected[3] = NULL;
    assert(compare_split(ft_res, expected));
    free_split(ft_res);
    printf("Test 3 passed: Split with multiple consecutive delimiters.\n");

    // Test 4: No delimiter present in the string
    ft_res = ft_split("NoDelimiter", ' ');
    expected[0] = "NoDelimiter"; expected[1] = NULL;
    assert(compare_split(ft_res, expected));
    free_split(ft_res);
    printf("Test 4 passed: No delimiter present in the string.\n");

    // Test 5: Empty string input
    ft_res = ft_split("", ' ');
    expected[0] = NULL;
    assert(compare_split(ft_res, expected));
    free_split(ft_res);
    printf("Test 5 passed: Empty string input.\n");

    // Test 6: String with only delimiters
    ft_res = ft_split(",,,,,", ',');
    expected[0] = NULL;
    assert(compare_split(ft_res, expected));
    free_split(ft_res);
    printf("Test 6 passed: String with only delimiters.\n");

    // Test 7: Delimiter at the beginning and end
    ft_res = ft_split("-Hello-", '-');
    expected[0] = "Hello"; expected[1] = NULL;
    assert(compare_split(ft_res, expected));
    free_split(ft_res);
    printf("Test 7 passed: Delimiter at beginning and end.\n");

    // Test 8: Single character string with a matching delimiter
    ft_res = ft_split("x", 'x');
    expected[0] = NULL;
    assert(compare_split(ft_res, expected));
    free_split(ft_res);
    printf("Test 8 passed: Single character string with matching delimiter.\n");

    printf("All tests passed!\n");
}

void test_ft_itoa(void) {
    printf("=== ft_itoa ===\n");
    printf("Running tests...\n");

    char *result;

    // Test 1: Positive integer
    result = ft_itoa(12345);
    assert(strcmp(result, "12345") == 0);
    free(result);
    printf("Test 1 passed: Positive integer\n");

    // Test 2: Negative integer
    result = ft_itoa(-6789);
    assert(strcmp(result, "-6789") == 0);
    free(result);
    printf("Test 2 passed: Negative integer\n");

    // Test 3: Zero
    result = ft_itoa(0);
    assert(strcmp(result, "0") == 0);
    free(result);
    printf("Test 3 passed: Zero\n");

    // Test 4: Smallest 32-bit integer
    result = ft_itoa(-2147483648);
    assert(strcmp(result, "-2147483648") == 0);
    free(result);
    printf("Test 4 passed: Minimum 32-bit integer\n");

    // Test 5: Largest 32-bit integer
    result = ft_itoa(2147483647);
    assert(strcmp(result, "2147483647") == 0);
    free(result);
    printf("Test 5 passed: Maximum 32-bit integer\n");

    // Test 6: Single-digit positive integer
    result = ft_itoa(7);
    assert(strcmp(result, "7") == 0);
    free(result);
    printf("Test 6 passed: Single-digit positive integer\n");

    // Test 7: Single-digit negative integer
    result = ft_itoa(-3);
    assert(strcmp(result, "-3") == 0);
    free(result);
    printf("Test 7 passed: Single-digit negative integer\n");

    // Test 8: Power of 10
    result = ft_itoa(1000);
    assert(strcmp(result, "1000") == 0);
    free(result);
    printf("Test 8 passed: Power of 10\n");

    printf("All tests passed!\n");
}

char to_upper(unsigned int i, char c) {
    (void)i; // Ignoring 'i' in this function
    if (c >= 'a' && c <= 'z')
        return c - 32;
    return c;
}

char add_index(unsigned int i, char c) {
    return c + i;
}

void test_ft_strmapi(void) {
    printf("=== ft_strmapi ===\n");
    printf("Running tests...\n");

    char *result;

    // Test 1: Convert all characters to uppercase
    result = ft_strmapi("hello", to_upper);
    assert(strcmp(result, "HELLO") == 0);
    free(result);
    printf("Test 1 passed: Convert all to uppercase\n");

    // Test 2: Add index to each character
    result = ft_strmapi("abcd", add_index);
    assert(strcmp(result, "aceg") == 0);  // 'a'+0='a', 'b'+1='c', 'c'+2='e', 'd'+3='g'
    free(result);
    printf("Test 2 passed: Add index to each character\n");

    // Test 3: Empty string
    result = ft_strmapi("", to_upper);
    assert(strcmp(result, "") == 0);
    free(result);
    printf("Test 3 passed: Empty string\n");

    // Test 4: String with special characters
    result = ft_strmapi("HeLLo!123", to_upper);
    assert(strcmp(result, "HELLO!123") == 0);
    free(result);
    printf("Test 4 passed: Mixed case with special characters\n");

    // Test 5: Null input string
    result = ft_strmapi(NULL, to_upper);
    assert(result == NULL);
    printf("Test 5 passed: Null input string\n");

    printf("All tests passed!\n");
}

int main(void)
{
	printf("=== C Library ===\n");
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

	test_ft_strlcpy();

	test_ft_strlcat();

	test_ft_toupper();

	test_ft_tolower();

	test_ft_strchr();

	test_ft_strrchr();

	test_ft_strncmp();

	test_ft_memchr();

	test_ft_memcmp();

	test_ft_strnstr();

	test_ft_atoi();

	test_ft_calloc();

	test_ft_strdup();

	printf("=== C Library ===\n\n");
	printf("=== Additional functions ===\n");

	test_ft_substr();

	test_ft_strjoin();

    test_ft_split();

    test_ft_itoa();

    test_ft_strmapi();
	return (0);
}

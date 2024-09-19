#include <stdio.h>
#include <string.h>
#include <assert.h>

void *ft_memmove(void *dest, const void *src, size_t n) {
    unsigned char *d = (unsigned char *)dest;
    const unsigned char *s = (const unsigned char *)src;

    if (d == s || n == 0) {
        return dest;
    }

    if (d < s) {
        // Copy forward when dest is before src
        for (size_t i = 0; i < n; i++) {
            d[i] = s[i];
        }
    } else {
        // Copy backward when dest is after src
        for (size_t i = n; i > 0; i--) {
            d[i - 1] = s[i - 1];
        }
    }

    return dest;
}

int main() {
    // Test 1: Basic copying with no overlap
    char src1[] = "Hello, World!";
    char dest1[20];
	bzero(dest1, 20);
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

    printf("All tests passed!\n");
    return 0;
}

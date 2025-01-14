#include <stdio.h>
#include "ft_printf.h"

/*int main(void)
{
    int ret;
// ==============================
// expected nums are for printed nums they dont include \n that is why ret - 1
//===============================
    // Testing %x (hexadecimal, lowercase)
    printf("Testing %%x (hexadecimal, lowercase):\n");
    ret = ft_printf("%x\n", 4095);
    printf("Return: %d (Expected: 3)\n", ret - 1); // Expected output: fff

    // Testing %X (hexadecimal, uppercase)
    printf("Testing %%X (hexadecimal, uppercase):\n");
    ret = ft_printf("%X\n", 4095);
    printf("Return: %d (Expected: 3)\n", ret - 1); // Expected output: FFF

    // Testing %s (string)
    printf("Testing %%s (string):\n");
    ret = ft_printf("%s\n", "Hello, World!");
    printf("Return: %d (Expected: 13)\n", ret - 1); // Expected output: Hello, World!

    // Testing %p (pointer)
    printf("Testing %%p (pointer):\n");
    void *ptr = &ret;
    ret = ft_printf("%p\n", ptr);
    printf("Return: %d (Expected: Length of printed pointer address)\n", ret - 1);

    // Testing %u (unsigned decimal)
    printf("Testing %%u (unsigned decimal):\n");
    ret = ft_printf("%u\n", 4294967295U);
    printf("Return: %d (Expected: 10)\n", ret - 1); // Expected output: 4294967295

    // Testing %i (integer)
    printf("Testing %%i (integer):\n");
    ret = ft_printf("%i\n", -42);
    printf("Return: %d (Expected: 3)\n", ret - 1); // Expected output: -42

    // Testing %d (decimal)
    printf("Testing %%d (decimal):\n");
    ret = ft_printf("%d\n", -2147483648);
    printf("Return: %d (Expected: 11)\n", ret - 1); // Expected output: -2147483648

    // Testing %c (character)
    printf("Testing %%c (character):\n");
    ret = ft_printf("%c\n", 'A');
    printf("Return: %d (Expected: 1)\n", ret - 1); // Expected output: A

    // Testing %% (percent sign)
    printf("Testing %%%% (percent sign):\n");
    ret = ft_printf("%%\n");
    printf("Return: %d (Expected: 1)\n", ret - 1); // Expected output: %

    return 0;
}*/



/*int	main(void)
{
	//return values checked with real printf to ensure
    // Testing each specifier

    printf("Testing %%c (character):\n");
    ft_printf("Character: %c\n", 'A');  // Expected: Character: A

    printf("Testing %%s (string):\n");
    ft_printf("String: %s\n", "Hello, World!");  // Expected: String: Hello, World!

    printf("Testing %%p (pointer):\n");
    int x = 42;
    ft_printf("Pointer: %p\n", &x);  // Expected: Pointer: (some memory address, e.g., 0x7ffeeefb080c)

    printf("Testing %%d (decimal integer):\n");
    ft_printf("Decimal (signed): %d\n", -12345);  // Expected: Decimal (signed): -12345
    ft_printf("Decimal (signed): %d\n", 67890);  // Expected: Decimal (signed): 67890

    printf("Testing %%i (signed integer):\n");
    ft_printf("Integer: %i\n", -456);  // Expected: Integer: -456
    ft_printf("Integer: %i\n", 789);  // Expected: Integer: 789

    printf("Testing %%u (unsigned integer):\n");
    ft_printf("Unsigned: %u\n", -1);  // Expected: Unsigned: 12345
    ft_printf("Unsigned: %u\n", 4294967295);  // Expected: Unsigned: 4294967295 (max unsigned int)

    printf("Testing %%x (hexadecimal, lowercase):\n");
    printf("Return : %d", ft_printf("%x", 4095));  // Expected: Hexadecimal (lowercase): ff

	printf("\nTesting %%X (hexadecimal, uppercase):\n");
    ft_printf("Hexadecimal (uppercase): %X\n", 4095);  // Expected: Hexadecimal (uppercase): FF

    printf("Testing %%%% (literal percentage):\n");
    ft_printf("Percentage: %%\n");  // Expected: Percentage: %

	ft_printf("%%d test. with int max + 1 expected -2147483648 and return 24(with text)\n");
	printf("Return : %d\n", ft_printf("Max int + 1 %d ", 2147483648));
	ft_printf("%%d test. with int min - 1 expected 2147483647 and return 23(with text)\n");
	printf("Return : %d\n", ft_printf("Min int - 1 %d ", -2147483649));
	ft_printf("%%d test. with int within range expected 12345 and return 23(with text)\n");
	printf("Return : %d\n", ft_printf("int within range %d ", 12345));
	ft_printf("%%i test. with int min - 1 expected 2147483647 and return 23(with text)\n");
	printf("Return : %d\n", ft_printf("Min int - 1 %d ", -2147483649));
	ft_printf("%%i test. with int min - 1 expected 2147483647 and return 23(with text)\n");
	printf("Return : %d\n", ft_printf("Min int - 1 %d ", -2147483649));
}*/


int	main(void)
{
	int res;

	res = ft_printf("%p", 0);
	printf("\n%d", res);
	res = ft_printf("%p", 15);
	printf("\n%d", res);
	res = ft_printf("%p %p", LONG_MIN, LONG_MAX);
	printf("\n%d", res);
	res = ft_printf("%p %p", ULONG_MAX, -ULONG_MAX);
	printf("\n%d", res);

	
	
	return (res);
}
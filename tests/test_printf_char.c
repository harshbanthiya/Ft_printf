//
//  test_printf_char.c
//  My_printf
//
//  Created by Harsh deepak Banthiya on 2021-06-15.
//

// TEST PRECISION WITH CHAR for undefined behaviour like printf
/*
 
 char zero = 0;
 char space = ' ';
 char printable = 'a';

 // simple char tests
a = ft_printf("%c\n", zero);
b = printf("%c\n", zero);
printf("my - %d, C - %d\n", a, b);
printf("\n\n");

a = ft_printf("%c\n", space);
b = printf("%c\n", space);
printf("my - %d, C - %d\n", a, b);
printf("\n\n");

a = ft_printf("%c\n", printable);
b = printf("%c\n", printable);
printf("my - %d, C - %d\n", a, b);
printf("\n\n");

// Test precision
a = ft_printf("%.c\n", zero);
b = printf("%.c\n", zero);
printf("my - %d, C - %d\n", a, b);
printf("\n\n");

a = ft_printf("%.c\n", space);
b = printf("%.c\n", space);
printf("my - %d, C - %d\n", a, b);
printf("\n\n");

a = ft_printf("%.c\n", printable);
b = printf("%.c\n", printable);
printf("my - %d, C - %d\n", a, b);
printf("\n\n");

// Zero Precision
a = ft_printf("%.0c\n", zero);
b = printf("%.0c\n", zero);
printf("my - %d, C - %d\n", a, b);
printf("\n\n");

a = ft_printf("%.0c\n", space);
b = printf("%.0c\n", space);
printf("my - %d, C - %d\n", a, b);
printf("\n\n");

a = ft_printf("%.0c\n", printable);
b = printf("%.0c\n", printable);
printf("my - %d, C - %d\n", a, b);
printf("\n\n");

// 1 Precision
a = ft_printf("%.1c\n", zero);
b = printf("%.1c\n", zero);
printf("my - %d, C - %d\n", a, b);
printf("\n\n");

a = ft_printf("%.1c\n", space);
b = printf("%.1c\n", space);
printf("my - %d, C - %d\n", a, b);
printf("\n\n");

a = ft_printf("%.1c\n", printable);
b = printf("%.1c\n", printable);
printf("my - %d, C - %d\n", a, b);
printf("\n\n");

// 10 Precision
a = ft_printf("%.10c\n", zero);
b = printf("%.10c\n", zero);
printf("my - %d, C - %d\n", a, b);
printf("\n\n");

a = ft_printf("%.10c\n", space);
b = printf("%.10c\n", space);
printf("my - %d, C - %d\n", a, b);
printf("\n\n");

a = ft_printf("%.10c\n", printable);
b = printf("%.10c\n", printable);
printf("my - %d, C - %d\n", a, b);
printf("\n\n");

//  field width tests
a = ft_printf("%-c\n", zero);
b = printf("%-c\n", zero);
printf("my - %d, C - %d\n", a, b);
printf("\n\n");

a = ft_printf("%-c\n", space);
b = printf("%-c\n", space);
printf("my - %d, C - %d\n", a, b);
printf("\n\n");

a = ft_printf("%-c\n", printable);
b = printf("%-c\n", printable);
printf("my - %d, C - %d\n", a, b);
printf("\n\n");

// -1 field width test
a = ft_printf("%-1c\n", zero);
b = printf("%-1c\n", zero);
printf("my - %d, C - %d\n", a, b);
printf("\n\n");

a = ft_printf("%-1c\n", space);
b = printf("%-1c\n", space);
printf("my - %d, C - %d\n", a, b);
printf("\n\n");

a = ft_printf("%-1c\n", printable);
b = printf("%-1c\n", printable);
printf("my - %d, C - %d\n", a, b);
printf("\n\n");

// -2 Field Width Test
a = ft_printf("%-2c\n", zero);
b = printf("%-2c\n", zero);
printf("my - %d, C - %d\n", a, b);
printf("\n\n");

a = ft_printf("%-2c\n", space);
b = printf("%-2c\n", space);
printf("my - %d, C - %d\n", a, b);
printf("\n\n");

a = ft_printf("%-2c\n", printable);
b = printf("%-2c\n", printable);
printf("my - %d, C - %d\n", a, b);
printf("\n\n");

// Testing invalid format and flags
a = ft_printf("%#c\n", zero);
b = printf("%#c\n", zero);
printf("my - %d, C - %d\n", a, b);
printf("\n\n");

a = ft_printf("%#c\n", space);
b = printf("%#c\n", space);
printf("my - %d, C - %d\n", a, b);
printf("\n\n");

a = ft_printf("%#c\n", printable);
b = printf("%#c\n", printable);
printf("my - %d, C - %d\n", a, b);
printf("\n\n");

// Space flag
a = ft_printf("% c\n", zero);
b = printf("% c\n", zero);
printf("my - %d, C - %d\n", a, b);
printf("\n\n");

a = ft_printf("% c\n", space);
b = printf("% c\n", space);
printf("my - %d, C - %d\n", a, b);
printf("\n\n");

a = ft_printf("% c\n", printable);
b = printf("% c\n", printable);
printf("my - %d, C - %d\n", a, b);
printf("\n\n");

 // zero pad flag
 a = ft_printf("%0c\n", zero);
 b = printf("%0c\n", zero);
 printf("my - %d, C - %d\n", a, b);
 printf("\n\n");

 a = ft_printf("%0c\n", space);
 b = printf("%0c\n", space);
 printf("my - %d, C - %d\n", a, b);
 printf("\n\n");

 a = ft_printf("%0c\n", printable);
 b = printf("%0c\n", printable);
 printf("my - %d, C - %d\n", a, b);
 printf("\n\n");

 // plus flag
 a = ft_printf("%+c\n", zero);
 b = printf("%+c\n", zero);
 printf("my - %d, C - %d\n", a, b);
 printf("\n\n");

 a = ft_printf("%+c\n", space);
 b = printf("%+c\n", space);
 printf("my - %d, C - %d\n", a, b);
 printf("\n\n");

 a = ft_printf("%+c\n", printable);
 b = printf("%+c\n", printable);
 printf("my - %d, C - %d\n", a, b);
 printf("\n\n");
 */
 

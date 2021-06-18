//
//  test_printf_str.c
//  My_printf
//
//  Created by Harsh deepak Banthiya on 2021-06-15.
//
/*
#include <stdio.h>
 //int 	a, b;
 char str[] = "Hello World!";
 char empty[] = "";
 char single[] = "a";
// simple tests

b = printf("c: %s\n", str);
a = ft_printf("m: %s\n", str);
printf("my - %d, C - %d\n", a, b);
printf("Hello World string test\n\n");

b = printf("c: %s\n", empty);
a = ft_printf("m: %s\n", empty);
printf("my - %d, C - %d\n", a, b);
printf("empty string test\n\n");


b = printf("c: %s\n", single);
a = ft_printf("m: %s\n", single);
printf("my - %d, C - %d\n", a, b);
printf("single letter a test \n\n");

// precision

b = printf("c: %.s\n", str);
a = ft_printf("m: %.s\n", str);
printf("my - %d, C - %d\n", a, b);
printf("precision .nothing test \n\n");

b = printf("c: %.s\n", empty);
a = ft_printf("m: %.s\n", empty);
printf("my - %d, C - %d\n", a, b);
printf("precision .nothing test on empty \n\n");

b = printf("c: %.s\n", single);
a = ft_printf("m: %.s\n", single);
printf("my - %d, C - %d\n", a, b);
printf("precision .nothing test on single letter string \n\n");


// precision .0
b = printf("c: %.0s\n", str);
a = ft_printf("m: %.0s\n", str);
printf("my - %d, C - %d\n", a, b);
printf("precision .0 for str \n\n");

b = printf("c: %.0s\n", empty);
a = ft_printf("m: %.0s\n", empty);
printf("my - %d, C - %d\n", a, b);
printf("precision .0 for empty \n\n");

b = printf("c: %.0s\n", single);
a = ft_printf("m: %.0s\n", single);
printf("my - %d, C - %d\n", a, b);
printf("precision .0 for single \n\n");


// precision .1

b = printf("c: %.1s\n", str);
a = ft_printf("m: %.1s\n", str);
printf("my - %d, C - %d\n", a, b);
printf("precision .1 for str \n\n");

b = printf("c: %.1s\n", empty);
a = ft_printf("m: %.1s\n", empty);
printf("my - %d, C - %d\n", a, b);
printf("precision .1 for empty \n\n");

b = printf("c: %.1s\n", single);
a = ft_printf("m: %.1s\n", single);
printf("my - %d, C - %d\n", a, b);
printf("precision .1 for single \n\n");

// precision .9

b = printf("c: %.9s\n", str);
a = ft_printf("m: %.9s\n", str);
printf("my - %d, C - %d\n", a, b);
printf("precision .9 for str \n\n");


b = printf("c: %.9s\n", empty);
a = ft_printf("m: %.9s\n", empty);
printf("my - %d, C - %d\n", a, b);
printf("precision .9 for empty \n\n");

b = printf("c: %.9s\n", single);
a = ft_printf("m: %.9s\n", single);
printf("my - %d, C - %d\n", a, b);
printf("precision .9 for single \n\n");

// precision .20

b = printf("c: %.20s\n", str);
a = ft_printf("m: %.20s\n", str);
printf("my - %d, C - %d\n", a, b);
printf("precision .20 for str \n\n");

b = printf("c: %.20s\n", empty);
a = ft_printf("m: %.20s\n", empty);
printf("my - %d, C - %d\n", a, b);
printf("precision .20 for empty \n\n");

b = printf("c: %.20s\n", single);
a = ft_printf("m: %.20s\n", single);
printf("my - %d, C - %d\n", a, b);
printf("precision .20 for single \n\n");

// Precision left aligned with - flag

b = printf("c: %-.s\n", str);
a = ft_printf("m: %-.s\n", str);
printf("my - %d, C - %d\n", a, b);
printf("precision -.nothing test \n\n");

b = printf("c: %-.s\n", empty);
a = ft_printf("m: %-.s\n", empty);
printf("my - %d, C - %d\n", a, b);
printf("precision -.nothing test on empty \n\n");

b = printf("c: %-.s\n", single);
a = ft_printf("m: %-.s\n", single);
printf("my - %d, C - %d\n", a, b);
printf("precision -.nothing test on single letter string \n\n");

// precision -.0 left

b = printf("c: %-.0s\n", str);
a = ft_printf("m: %-.0s\n", str);
printf("my - %d, C - %d\n", a, b);
printf("precision -.0 for str \n\n");

b = printf("c: %-.0s\n", empty);
a = ft_printf("m: %-.0s\n", empty);
printf("my - %d, C - %d\n", a, b);
printf("precision -.0 for empty \n\n");

b = printf("c: %-.0s\n", single);
a = ft_printf("m: %-.0s\n", single);
printf("my - %d, C - %d\n", a, b);
printf("precision -.0 for single \n\n");


// precision -.1

b = printf("c: %-.1s\n", str);
a = ft_printf("m: %-.1s\n", str);
printf("my - %d, C - %d\n", a, b);
printf("precision -.1 for str \n\n");

b = printf("c: %-.1s\n", empty);
a = ft_printf("m: %-.1s\n", empty);
printf("my - %d, C - %d\n", a, b);
printf("precision -.1 for empty \n\n");

b = printf("c: %-.1s\n", single);
a = ft_printf("m: %-.1s\n", single);
printf("my - %d, C - %d\n", a, b);
printf("precision -.1 for single \n\n");

// precision -.9

b = printf("c: %-.9s\n", str);
a = ft_printf("m: %-.9s\n", str);
printf("my - %d, C - %d\n", a, b);
printf("precision -.9 for str \n\n");


b = printf("c: %-.9s\n", empty);
a = ft_printf("m: %-.9s\n", empty);
printf("my - %d, C - %d\n", a, b);
printf("precision -.9 for empty \n\n");

b = printf("c: %-.9s\n", single);
a = ft_printf("m: %-.9s\n", single);
printf("my - %d, C - %d\n", a, b);
printf("precision -.9 for single \n\n");

// precision -.20

b = printf("c: %-.20s\n", str);
a = ft_printf("m: %-.20s\n", str);
printf("my - %d, C - %d\n", a, b);
printf("precision -.20 for str \n\n");

b = printf("c: %-.20s\n", empty);
a = ft_printf("m: %-.20s\n", empty);
printf("my - %d, C - %d\n", a, b);
printf("precision -.20 for empty \n\n");

b = printf("c: %-.20s\n", single);
a = ft_printf("m: %-.20s\n", single);
printf("my - %d, C - %d\n", a, b);
printf("precision -.20 for single \n\n");

// TEST field width

b = printf("c:%1s\n", str);
a = ft_printf("m:%1s\n", str);
printf("my - %d, C - %d\n", a, b);
printf("field width 1s str test \n\n");

b = printf("c:%1s\n", empty);
a = ft_printf("m:%1s\n", empty);
printf("my - %d, C - %d\n", a, b);
printf("field width 1s empty test \n\n");

b = printf("c:%1s\n", single);
a = ft_printf("m:%1s\n", single);
printf("my - %d, C - %d\n", a, b);
printf("field width 1s single test \n\n");

// field width %2s left

b = printf("c:%2s\n", str);
a = ft_printf("m:%2s\n", str);
printf("my - %d, C - %d\n", a, b);
printf("field width 2s str test \n\n");

b = printf("c:%2s\n", empty);
a = ft_printf("m:%2s\n", empty);
printf("my - %d, C - %d\n", a, b);
printf("field width 2s empty test \n\n");

b = printf("c:%2s\n", single);
a = ft_printf("m:%2s\n", single);
printf("my - %d, C - %d\n", a, b);
printf("field width 2s single test \n\n");


// field width %3s left

b = printf("c:%3s\n", str);
a = ft_printf("m:%3s\n", str);
printf("my - %d, C - %d\n", a, b);
printf("field width 3s str test \n\n");

b = printf("c:%3s\n", empty);
a = ft_printf("m:%3s\n", empty);
printf("my - %d, C - %d\n", a, b);
printf("field width 3s empty test \n\n");

b = printf("c:%3s\n", single);
a = ft_printf("m:%3s\n", single);
printf("my - %d, C - %d\n", a, b);
printf("field width 3s single test \n\n");

// field width %10s left

b = printf("c:%10s\n", str);
a = ft_printf("m:%10s\n", str);
printf("my - %d, C - %d\n", a, b);
printf("field width 10s str test \n\n");

b = printf("c:%10s\n", empty);
a = ft_printf("m:%10s\n", empty);
printf("my - %d, C - %d\n", a, b);
printf("field width 10s empty test \n\n");

b = printf("c:%10s\n", single);
a = ft_printf("m:%10s\n", single);
printf("my - %d, C - %d\n", a, b);
printf("field width 10s single test \n\n");

// field width %15s left

b = printf("c:%15s\n", str);
a = ft_printf("m:%15s\n", str);
printf("my - %d, C - %d\n", a, b);
printf("field width 15s str test \n\n");

b = printf("c:%15s\n", empty);
a = ft_printf("m:%15s\n", empty);
printf("my - %d, C - %d\n", a, b);
printf("field width 15s empty test \n\n");

b = printf("c:%15s\n", single);
a = ft_printf("m:%15s\n", single);
printf("my - %d, C - %d\n", a, b);
printf("field width 15s single test \n\n");

// field width test left align - flag

b = printf("c:%-1s\n", str);
a = ft_printf("m:%-1s\n", str);
printf("my - %d, C - %d\n", a, b);
printf("field width -1s str test \n\n");

b = printf("c:%-1s\n", empty);
a = ft_printf("m:%-1s\n", empty);
printf("my - %d, C - %d\n", a, b);
printf("field width -1s empty test \n\n");

b = printf("c:%-1s\n", single);
a = ft_printf("m:%-1s\n", single);
printf("my - %d, C - %d\n", a, b);
printf("field width -1s single test \n\n");

// field width %2s left

b = printf("c:%-2s\n", str);
a = ft_printf("m:%-2s\n", str);
printf("my - %d, C - %d\n", a, b);
printf("field width -2s str test \n\n");

b = printf("c:%-2s\n", empty);
a = ft_printf("m:%-2s\n", empty);
printf("my - %d, C - %d\n", a, b);
printf("field width -2s empty test \n\n");

b = printf("c:%-2s\n", single);
a = ft_printf("m:%-2s\n", single);
printf("my - %d, C - %d\n", a, b);
printf("field width -2s single test \n\n");


// field width %3s left

b = printf("c:%-3s\n", str);
a = ft_printf("m:%-3s\n", str);
printf("my - %d, C - %d\n", a, b);
printf("field width -3s str test \n\n");

b = printf("c:%-3s\n", empty);
a = ft_printf("m:%-3s\n", empty);
printf("my - %d, C - %d\n", a, b);
printf("field width -3s empty test \n\n");

b = printf("c:%-3s\n", single);
a = ft_printf("m:%-3s\n", single);
printf("my - %d, C - %d\n", a, b);
printf("field width -3s single test \n\n");

// field width %10s left

b = printf("c:%-10s\n", str);
a = ft_printf("m:%-10s\n", str);
printf("my - %d, C - %d\n", a, b);
printf("field width -10s str test \n\n");

b = printf("c:%-10s\n", empty);
a = ft_printf("m:%-10s\n", empty);
printf("my - %d, C - %d\n", a, b);
printf("field width -10s empty test \n\n");

b = printf("c:%-10s\n", single);
a = ft_printf("m:%-10s\n", single);
printf("my - %d, C - %d\n", a, b);
printf("field width -10s single test \n\n");

// field width %15s left

b = printf("c:%-15s\n", str);
a = ft_printf("m:%-15s\n", str);
printf("my - %d, C - %d\n", a, b);
printf("field width -15s str test \n\n");

b = printf("c:%-15s\n", empty);
a = ft_printf("m:%-15s\n", empty);
printf("my - %d, C - %d\n", a, b);
printf("field width -15s empty test \n\n");

b = printf("c:%-15s\n", single);
a = ft_printf("m:%-15s\n", single);
printf("my - %d, C - %d\n", a, b);
printf("field width -15s single test \n\n");

 // test field width with precision

 // 1 width and 0 to 20 precision
 // % 1.s
 printf("my - %d, C - %d\n", printf("c: %1.s\n", str), ft_printf("m: %1.s\n", str));
 printf("field width 1.s str test \n\n");
 printf("my - %d, C - %d\n", printf("c: %1.s\n", empty), ft_printf("m: %1.s\n", empty));
 printf("field width 1.s empty test \n\n");
 printf("my - %d, C - %d\n", printf("c: %1.s\n", single), ft_printf("m: %1.s\n", single));
 printf("field width 1.s single test \n\n");
 
 // % 1.0s
 printf("my - %d, C - %d\n", printf("c: %1.0s\n", str), ft_printf("m: %1.0s\n", str));
 printf("field width 1.0s str test \n\n");
 printf("my - %d, C - %d\n", printf("c: %1.0s\n", empty), ft_printf("m: %1.0s\n", empty));
 printf("field width 1.0s empty test \n\n");
 printf("my - %d, C - %d\n", printf("c: %1.0s\n", single), ft_printf("m: %1.0s\n", single));
 printf("field width 1.0s single test \n\n");
 
 // %1.1s
 printf("my - %d, C - %d\n", printf("c: %1.1s\n", str), ft_printf("m: %1.1s\n", str));
 printf("field width 1.1s str test \n\n");
 printf("my - %d, C - %d\n", printf("c: %1.1s\n", empty), ft_printf("m: %1.1s\n", empty));
 printf("field width 1.1s empty test \n\n");
 printf("my - %d, C - %d\n", printf("c: %1.1s\n", single), ft_printf("m: %1.1s\n", single));
 printf("field width 1.1s single test \n\n");
 
 // %1.9s
 printf("my - %d, C - %d\n", printf("c: %1.9s\n", str), ft_printf("m: %1.9s\n", str));
 printf("field width 1.9s str test \n\n");
 printf("my - %d, C - %d\n", printf("c: %1.9s\n", empty), ft_printf("m: %1.9s\n", empty));
 printf("field width 1.9s empty test \n\n");
 printf("my - %d, C - %d\n", printf("c: %1.9s\n", single), ft_printf("m: %1.9s\n", single));
 printf("field width 1.9s single test \n\n");
 
 // %1.20s
 printf("my - %d, C - %d\n", printf("c: %1.20s\n", str), ft_printf("m: %1.20s\n", str));
 printf("field width 1.20s str test \n\n");
 printf("my - %d, C - %d\n", printf("c: %1.20s\n", empty), ft_printf("m: %1.20s\n", empty));
 printf("field width 1.20s empty test \n\n");
 printf("my - %d, C - %d\n", printf("c: %1.20s\n", single), ft_printf("m: %1.20s\n", single));
 printf("field width 1.20s single test \n\n");
 
 // 2 width and 0 to 20 precision
 // % 2.s
 printf("my - %d, C - %d\n", printf("c: %2.s\n", str), ft_printf("m: %2.s\n", str));
 printf("field width 2.s str test \n\n");
 printf("my - %d, C - %d\n", printf("c: %2.s\n", empty), ft_printf("m: %2.s\n", empty));
 printf("field width 2.s empty test \n\n");
 printf("my - %d, C - %d\n", printf("c: %2.s\n", single), ft_printf("m: %2.s\n", single));
 printf("field width 2.s single test \n\n");
 
 // % 2.0s
 printf("my - %d, C - %d\n", printf("c: %2.0s\n", str), ft_printf("m: %2.0s\n", str));
 printf("field width 2.0s str test \n\n");
 printf("my - %d, C - %d\n", printf("c: %2.0s\n", empty), ft_printf("m: %2.0s\n", empty));
 printf("field width 2.0s empty test \n\n");
 printf("my - %d, C - %d\n", printf("c: %2.0s\n", single), ft_printf("m: %2.0s\n", single));
 printf("field width 2.0s single test \n\n");
 
 // %2.1s
 printf("my - %d, C - %d\n", printf("c: %2.1s\n", str), ft_printf("m: %2.1s\n", str));
 printf("field width 2.1s str test \n\n");
 printf("my - %d, C - %d\n", printf("c: %2.1s\n", empty), ft_printf("m: %2.1s\n", empty));
 printf("field width 2.1s empty test \n\n");
 printf("my - %d, C - %d\n", printf("c: %2.1s\n", single), ft_printf("m: %2.1s\n", single));
 printf("field width 2.1s single test \n\n");
 
 // %2.9s
 printf("my - %d, C - %d\n", printf("c: %2.9s\n", str), ft_printf("m: %2.9s\n", str));
 printf("field width 2.9s str test \n\n");
 printf("my - %d, C - %d\n", printf("c: %2.9s\n", empty), ft_printf("m: %2.9s\n", empty));
 printf("field width 2.9s empty test \n\n");
 printf("my - %d, C - %d\n", printf("c: %2.9s\n", single), ft_printf("m: %2.9s\n", single));
 printf("field width 2.9s single test \n\n");
 
 // %2.20s
 printf("my - %d, C - %d\n", printf("c: %2.20s\n", str), ft_printf("m: %2.20s\n", str));
 printf("field width 2.20s str test \n\n");
 printf("my - %d, C - %d\n", printf("c: %2.20s\n", empty), ft_printf("m: %2.20s\n", empty));
 printf("field width 2.20s empty test \n\n");
 printf("my - %d, C - %d\n", printf("c: %2.20s\n", single), ft_printf("m: %2.20s\n", single));
 printf("field width 2.20s single test \n\n");

 // 3 width and 0 to 20 precision
 // % 3.s
 printf("my - %d, C - %d\n", printf("c: %3.s\n", str), ft_printf("m: %3.s\n", str));
 printf("field width 3.s str test \n\n");
 printf("my - %d, C - %d\n", printf("c: %3.s\n", empty), ft_printf("m: %3.s\n", empty));
 printf("field width 3.s empty test \n\n");
 printf("my - %d, C - %d\n", printf("c: %3.s\n", single), ft_printf("m: %3.s\n", single));
 printf("field width 3.s single test \n\n");
 
 // % 3.0s
 printf("my - %d, C - %d\n", printf("c: %3.0s\n", str), ft_printf("m: %3.0s\n", str));
 printf("field width 3.0s str test \n\n");
 printf("my - %d, C - %d\n", printf("c: %3.0s\n", empty), ft_printf("m: %3.0s\n", empty));
 printf("field width 3.0s empty test \n\n");
 printf("my - %d, C - %d\n", printf("c: %3.0s\n", single), ft_printf("m: %3.0s\n", single));
 printf("field width 3.0s single test \n\n");
 
 // %3.1s
 printf("my - %d, C - %d\n", printf("c: %3.1s\n", str), ft_printf("m: %3.1s\n", str));
 printf("field width 3.1s str test \n\n");
 printf("my - %d, C - %d\n", printf("c: %3.1s\n", empty), ft_printf("m: %3.1s\n", empty));
 printf("field width 3.1s empty test \n\n");
 printf("my - %d, C - %d\n", printf("c: %3.1s\n", single), ft_printf("m: %3.1s\n", single));
 printf("field width 3.1s single test \n\n");
 
 // %3.9s
 printf("my - %d, C - %d\n", printf("c: %3.9s\n", str), ft_printf("m: %3.9s\n", str));
 printf("field width 3.9s str test \n\n");
 printf("my - %d, C - %d\n", printf("c: %3.9s\n", empty), ft_printf("m: %3.9s\n", empty));
 printf("field width 3.9s empty test \n\n");
 printf("my - %d, C - %d\n", printf("c: %3.9s\n", single), ft_printf("m: %3.9s\n", single));
 printf("field width 3.9s single test \n\n");
 
 // %3.20s
 printf("my - %d, C - %d\n", printf("c: %3.20s\n", str), ft_printf("m: %3.20s\n", str));
 printf("field width 3.20s str test \n\n");
 printf("my - %d, C - %d\n", printf("c: %3.20s\n", empty), ft_printf("m: %3.20s\n", empty));
 printf("field width 3.20s empty test \n\n");
 printf("my - %d, C - %d\n", printf("c: %3.20s\n", single), ft_printf("m: %3.20s\n", single));
 printf("field width 3.20s single test \n\n");
 
 // 10 width and 0 to 20 precision
 // % 10.s
 printf("my - %d, C - %d\n", printf("c: %10.s\n", str), ft_printf("m: %10.s\n", str));
 printf("field width 10.s str test \n\n");
 printf("my - %d, C - %d\n", printf("c: %10.s\n", empty), ft_printf("m: %10.s\n", empty));
 printf("field width 10.s empty test \n\n");
 printf("my - %d, C - %d\n", printf("c: %10.s\n", single), ft_printf("m: %10.s\n", single));
 printf("field width 10.s single test \n\n");
 
 // % 10.0s
 printf("my - %d, C - %d\n", printf("c: %10.0s\n", str), ft_printf("m: %10.0s\n", str));
 printf("field width 3.0s str test \n\n");
 printf("my - %d, C - %d\n", printf("c: %10.0s\n", empty), ft_printf("m: %10.0s\n", empty));
 printf("field width 10.0s empty test \n\n");
 printf("my - %d, C - %d\n", printf("c: %10.0s\n", single), ft_printf("m: %10.0s\n", single));
 printf("field width 10.0s single test \n\n");
 
 // %10.1s
 printf("my - %d, C - %d\n", printf("c: %10.1s\n", str), ft_printf("m: %10.1s\n", str));
 printf("field width 10.1s str test \n\n");
 printf("my - %d, C - %d\n", printf("c: %10.1s\n", empty), ft_printf("m: %10.1s\n", empty));
 printf("field width 10.1s empty test \n\n");
 printf("my - %d, C - %d\n", printf("c: %10.1s\n", single), ft_printf("m: %10.1s\n", single));
 printf("field width 10.1s single test \n\n");
 
 // %10.9s
 printf("my - %d, C - %d\n", printf("c: %10.9s\n", str), ft_printf("m: %10.9s\n", str));
 printf("field width 10.9s str test \n\n");
 printf("my - %d, C - %d\n", printf("c: %10.9s\n", empty), ft_printf("m: %10.9s\n", empty));
 printf("field width 10.9s empty test \n\n");
 printf("my - %d, C - %d\n", printf("c: %10.9s\n", single), ft_printf("m: %10.9s\n", single));
 printf("field width 10.9s single test \n\n");
 
 // %10.20s
 printf("my - %d, C - %d\n", printf("c: %10.20s\n", str), ft_printf("m: %10.20s\n", str));
 printf("field width 10.20s str test \n\n");
 printf("my - %d, C - %d\n", printf("c: %10.20s\n", empty), ft_printf("m: %10.20s\n", empty));
 printf("field width 10.20s empty test \n\n");
 printf("my - %d, C - %d\n", printf("c: %10.20s\n", single), ft_printf("m: %10.20s\n", single));
 printf("field width 10.20s single test \n\n");

 
 // 15 width and 0 to 20 precision
 // % 15.s
 printf("my - %d, C - %d\n", printf("c: %15.s\n", str), ft_printf("m: %15.s\n", str));
 printf("field width 15.s str test \n\n");
 printf("my - %d, C - %d\n", printf("c: %15.s\n", empty), ft_printf("m: %15.s\n", empty));
 printf("field width 15.s empty test \n\n");
 printf("my - %d, C - %d\n", printf("c: %15.s\n", single), ft_printf("m: %15.s\n", single));
 printf("field width 15.s single test \n\n");
 
 // % 15.0s
 printf("my - %d, C - %d\n", printf("c: %15.0s\n", str), ft_printf("m: %15.0s\n", str));
 printf("field width 15.0s str test \n\n");
 printf("my - %d, C - %d\n", printf("c: %15.0s\n", empty), ft_printf("m: %15.0s\n", empty));
 printf("field width 15.0s empty test \n\n");
 printf("my - %d, C - %d\n", printf("c: %15.0s\n", single), ft_printf("m: %15.0s\n", single));
 printf("field width 15.0s single test \n\n");
 
 // %15.1s
 printf("my - %d, C - %d\n", printf("c: %15.1s\n", str), ft_printf("m: %15.1s\n", str));
 printf("field width 15.1s str test \n\n");
 printf("my - %d, C - %d\n", printf("c: %15.1s\n", empty), ft_printf("m: %15.1s\n", empty));
 printf("field width 15.1s empty test \n\n");
 printf("my - %d, C - %d\n", printf("c: %15.1s\n", single), ft_printf("m: %15.1s\n", single));
 printf("field width 15.1s single test \n\n");
 
 // %15.9s
 printf("my - %d, C - %d\n", printf("c: %15.9s\n", str), ft_printf("m: %15.9s\n", str));
 printf("field width 15.9s str test \n\n");
 printf("my - %d, C - %d\n", printf("c: %15.9s\n", empty), ft_printf("m: %15.9s\n", empty));
 printf("field width 15.9s empty test \n\n");
 printf("my - %d, C - %d\n", printf("c: %15.9s\n", single), ft_printf("m: %15.9s\n", single));
 printf("field width 15.9s single test \n\n");
 
 // %15.20s
 printf("my - %d, C - %d\n", printf("c: %15.20s\n", str), ft_printf("m: %15.20s\n", str));
 printf("field width 15.20s str test \n\n");
 printf("my - %d, C - %d\n", printf("c: %15.20s\n", empty), ft_printf("m: %15.20s\n", empty));
 printf("field width 15.20s empty test \n\n");
 printf("my - %d, C - %d\n", printf("c: %15.20s\n", single), ft_printf("m: %15.20s\n", single));
 printf("field width 15.20s single test \n\n");

 // Same field width and precision tests with - flags for left justify
 
 // 1 width and 0 to 20 precision
 // % -1.s
 printf("my - %d, C - %d\n", printf("c: %-1.s\n", str), ft_printf("m: %-1.s\n", str));
 printf("field width -1.s str test \n\n");
 printf("my - %d, C - %d\n", printf("c: %-1.s\n", empty), ft_printf("m: %-1.s\n", empty));
 printf("field width -1.s empty test \n\n");
 printf("my - %d, C - %d\n", printf("c: %-1.s\n", single), ft_printf("m: %-1.s\n", single));
 printf("field width -1.s single test \n\n");
 
 // % -1.0s
 printf("my - %d, C - %d\n", printf("c: %-1.0s\n", str), ft_printf("m: %-1.0s\n", str));
 printf("field width -1.0s str test \n\n");
 printf("my - %d, C - %d\n", printf("c: %-1.0s\n", empty), ft_printf("m: %-1.0s\n", empty));
 printf("field width -1.0s empty test \n\n");
 printf("my - %d, C - %d\n", printf("c: %-1.0s\n", single), ft_printf("m: %-1.0s\n", single));
 printf("field width -1.0s single test \n\n");
 
 // %-1.1s
 printf("my - %d, C - %d\n", printf("c: %-1.1s\n", str), ft_printf("m: %-1.1s\n", str));
 printf("field width -1.1s str test \n\n");
 printf("my - %d, C - %d\n", printf("c: %-1.1s\n", empty), ft_printf("m: %-1.1s\n", empty));
 printf("field width -1.1s empty test \n\n");
 printf("my - %d, C - %d\n", printf("c: %-1.1s\n", single), ft_printf("m: %-1.1s\n", single));
 printf("field width -1.1s single test \n\n");
 
 // %1.9s
 printf("my - %d, C - %d\n", printf("c: %-1.9s\n", str), ft_printf("m: %-1.9s\n", str));
 printf("field width -1.9s str test \n\n");
 printf("my - %d, C - %d\n", printf("c: %-1.9s\n", empty), ft_printf("m: %-1.9s\n", empty));
 printf("field width -1.9s empty test \n\n");
 printf("my - %d, C - %d\n", printf("c: %-1.9s\n", single), ft_printf("m: %-1.9s\n", single));
 printf("field width -1.9s single test \n\n");
 
 // %-1.20s
 printf("my - %d, C - %d\n", printf("c: %-1.20s\n", str), ft_printf("m: %-1.20s\n", str));
 printf("field width -1.20s str test \n\n");
 printf("my - %d, C - %d\n", printf("c: %-1.20s\n", empty), ft_printf("m: %-1.20s\n", empty));
 printf("field width -1.20s empty test \n\n");
 printf("my - %d, C - %d\n", printf("c: %-1.20s\n", single), ft_printf("m: %-1.20s\n", single));
 printf("field width -1.20s single test \n\n");
 
 // 2 width and 0 to 20 precision
 // % -2.s
 printf("my - %d, C - %d\n", printf("c: %-2.s\n", str), ft_printf("m: %-2.s\n", str));
 printf("field width -2.s str test \n\n");
 printf("my - %d, C - %d\n", printf("c: %-2.s\n", empty), ft_printf("m: %-2.s\n", empty));
 printf("field width -2.s empty test \n\n");
 printf("my - %d, C - %d\n", printf("c: %-2.s\n", single), ft_printf("m: %-2.s\n", single));
 printf("field width -2.s single test \n\n");
 
 // % -2.0s
 printf("my - %d, C - %d\n", printf("c: %-2.0s\n", str), ft_printf("m: %-2.0s\n", str));
 printf("field width -2.0s str test \n\n");
 printf("my - %d, C - %d\n", printf("c: %-2.0s\n", empty), ft_printf("m: %-2.0s\n", empty));
 printf("field width -2.0s empty test \n\n");
 printf("my - %d, C - %d\n", printf("c: %-2.0s\n", single), ft_printf("m: %-2.0s\n", single));
 printf("field width -2.0s single test \n\n");
 
 // %-2.1s
 printf("my - %d, C - %d\n", printf("c: %-2.1s\n", str), ft_printf("m: %-2.1s\n", str));
 printf("field width -2.1s str test \n\n");
 printf("my - %d, C - %d\n", printf("c: %-2.1s\n", empty), ft_printf("m: %-2.1s\n", empty));
 printf("field width -2.1s empty test \n\n");
 printf("my - %d, C - %d\n", printf("c: %-2.1s\n", single), ft_printf("m: %-2.1s\n", single));
 printf("field width -2.1s single test \n\n");
 
 // %-2.9s
 printf("my - %d, C - %d\n", printf("c: %-2.9s\n", str), ft_printf("m: %-2.9s\n", str));
 printf("field width -2.9s str test \n\n");
 printf("my - %d, C - %d\n", printf("c: %-2.9s\n", empty), ft_printf("m: %-2.9s\n", empty));
 printf("field width -2.9s empty test \n\n");
 printf("my - %d, C - %d\n", printf("c: %-2.9s\n", single), ft_printf("m: %-2.9s\n", single));
 printf("field width -2.9s single test \n\n");
 
 // %-2.20s
 printf("my - %d, C - %d\n", printf("c: %-2.20s\n", str), ft_printf("m: %-2.20s\n", str));
 printf("field width -2.20s str test \n\n");
 printf("my - %d, C - %d\n", printf("c: %-2.20s\n", empty), ft_printf("m: %-2.20s\n", empty));
 printf("field width -2.20s empty test \n\n");
 printf("my - %d, C - %d\n", printf("c: %-2.20s\n", single), ft_printf("m: %-2.20s\n", single));
 printf("field width -2.20s single test \n\n");

 // 3 width and 0 to 20 precision
 // % -3.s
 printf("my - %d, C - %d\n", printf("c: %-3.s\n", str), ft_printf("m: %-3.s\n", str));
 printf("field width -3.s str test \n\n");
 printf("my - %d, C - %d\n", printf("c: %-3.s\n", empty), ft_printf("m: %-3.s\n", empty));
 printf("field width -3.s empty test \n\n");
 printf("my - %d, C - %d\n", printf("c: %-3.s\n", single), ft_printf("m: %-3.s\n", single));
 printf("field width -3.s single test \n\n");
 
 // % -3.0s
 printf("my - %d, C - %d\n", printf("c: %-3.0s\n", str), ft_printf("m: %-3.0s\n", str));
 printf("field width -3.0s str test \n\n");
 printf("my - %d, C - %d\n", printf("c: %-3.0s\n", empty), ft_printf("m: %-3.0s\n", empty));
 printf("field width -3.0s empty test \n\n");
 printf("my - %d, C - %d\n", printf("c: %-3.0s\n", single), ft_printf("m: %-3.0s\n", single));
 printf("field width -3.0s single test \n\n");
 
 // %-3.1s
 printf("my - %d, C - %d\n", printf("c: %-3.1s\n", str), ft_printf("m: %-3.1s\n", str));
 printf("field width -3.1s str test \n\n");
 printf("my - %d, C - %d\n", printf("c: %-3.1s\n", empty), ft_printf("m: %-3.1s\n", empty));
 printf("field width -3.1s empty test \n\n");
 printf("my - %d, C - %d\n", printf("c: %-3.1s\n", single), ft_printf("m: %-3.1s\n", single));
 printf("field width -3.1s single test \n\n");
 
 // %-3.9s
 printf("my - %d, C - %d\n", printf("c: %-3.9s\n", str), ft_printf("m: %-3.9s\n", str));
 printf("field width -3.9s str test \n\n");
 printf("my - %d, C - %d\n", printf("c: %-3.9s\n", empty), ft_printf("m: %-3.9s\n", empty));
 printf("field width -3.9s empty test \n\n");
 printf("my - %d, C - %d\n", printf("c: %-3.9s\n", single), ft_printf("m: %-3.9s\n", single));
 printf("field width -3.9s single test \n\n");
 
 // %-3.20s
 printf("my - %d, C - %d\n", printf("c: %-3.20s\n", str), ft_printf("m: %-3.20s\n", str));
 printf("field width -3.20s str test \n\n");
 printf("my - %d, C - %d\n", printf("c: %-3.20s\n", empty), ft_printf("m: %-3.20s\n", empty));
 printf("field width -3.20s empty test \n\n");
 printf("my - %d, C - %d\n", printf("c: %-3.20s\n", single), ft_printf("m: %-3.20s\n", single));
 printf("field width -3.20s single test \n\n");
 
 // 10 width and 0 to 20 precision
 // % -10.s
 printf("my - %d, C - %d\n", printf("c: %-10.s\n", str), ft_printf("m: %-10.s\n", str));
 printf("field width -10.s str test \n\n");
 printf("my - %d, C - %d\n", printf("c: %-10.s\n", empty), ft_printf("m: %-10.s\n", empty));
 printf("field width -10.s empty test \n\n");
 printf("my - %d, C - %d\n", printf("c: %-10.s\n", single), ft_printf("m: %-10.s\n", single));
 printf("field width -10.s single test \n\n");
 
 // % -10.0s
 printf("my - %d, C - %d\n", printf("c: %-10.0s\n", str), ft_printf("m: %-10.0s\n", str));
 printf("field width -10.0s str test \n\n");
 printf("my - %d, C - %d\n", printf("c: %-10.0s\n", empty), ft_printf("m: %-10.0s\n", empty));
 printf("field width -10.0s empty test \n\n");
 printf("my - %d, C - %d\n", printf("c: %-10.0s\n", single), ft_printf("m: %-10.0s\n", single));
 printf("field width -10.0s single test \n\n");
 
 // %-10.1s
 printf("my - %d, C - %d\n", printf("c: %-10.1s\n", str), ft_printf("m: %-10.1s\n", str));
 printf("field width -10.1s str test \n\n");
 printf("my - %d, C - %d\n", printf("c: %-10.1s\n", empty), ft_printf("m: %-10.1s\n", empty));
 printf("field width -10.1s empty test \n\n");
 printf("my - %d, C - %d\n", printf("c: %-10.1s\n", single), ft_printf("m: %-10.1s\n", single));
 printf("field width -10.1s single test \n\n");
 
 // %-10.9s
 printf("my - %d, C - %d\n", printf("c: %-10.9s\n", str), ft_printf("m: %-10.9s\n", str));
 printf("field width -10.9s str test \n\n");
 printf("my - %d, C - %d\n", printf("c: %-10.9s\n", empty), ft_printf("m: %-10.9s\n", empty));
 printf("field width -10.9s empty test \n\n");
 printf("my - %d, C - %d\n", printf("c: %-10.9s\n", single), ft_printf("m: %-10.9s\n", single));
 printf("field width -10.9s single test \n\n");
 
 // %-10.20s
 printf("my - %d, C - %d\n", printf("c: %-10.20s\n", str), ft_printf("m: %-10.20s\n", str));
 printf("field width -10.20s str test \n\n");
 printf("my - %d, C - %d\n", printf("c: %-10.20s\n", empty), ft_printf("m: %-10.20s\n", empty));
 printf("field width -10.20s empty test \n\n");
 printf("my - %d, C - %d\n", printf("c: %-10.20s\n", single), ft_printf("m: %-10.20s\n", single));
 printf("field width -10.20s single test \n\n");

 
 // 15 width and 0 to 20 precision
 // % -15.s
 printf("my - %d, C - %d\n", printf("c: %-15.s\n", str), ft_printf("m: %-15.s\n", str));
 printf("field width -15.s str test \n\n");
 printf("my - %d, C - %d\n", printf("c: %-15.s\n", empty), ft_printf("m: %-15.s\n", empty));
 printf("field width -15.s empty test \n\n");
 printf("my - %d, C - %d\n", printf("c: %-15.s\n", single), ft_printf("m: %-15.s\n", single));
 printf("field width -15.s single test \n\n");
 
 // %-15.0s
 printf("my - %d, C - %d\n", printf("c: %-15.0s\n", str), ft_printf("m: %-15.0s\n", str));
 printf("field width -15.0s str test \n\n");
 printf("my - %d, C - %d\n", printf("c: %-15.0s\n", empty), ft_printf("m: %-15.0s\n", empty));
 printf("field width -15.0s empty test \n\n");
 printf("my - %d, C - %d\n", printf("c: %-15.0s\n", single), ft_printf("m: %-15.0s\n", single));
 printf("field width -15.0s single test \n\n");
 
 // %-15.1s
 printf("my - %d, C - %d\n", printf("c: %-15.1s\n", str), ft_printf("m: %-15.1s\n", str));
 printf("field width -15.1s str test \n\n");
 printf("my - %d, C - %d\n", printf("c: %-15.1s\n", empty), ft_printf("m: %-15.1s\n", empty));
 printf("field width -15.1s empty test \n\n");
 printf("my - %d, C - %d\n", printf("c: %-15.1s\n", single), ft_printf("m: %-15.1s\n", single));
 printf("field width -15.1s single test \n\n");
 
 // %-15.9s
 printf("my - %d, C - %d\n", printf("c: %-15.9s\n", str), ft_printf("m: %-15.9s\n", str));
 printf("field width -15.9s str test \n\n");
 printf("my - %d, C - %d\n", printf("c: %-15.9s\n", empty), ft_printf("m: %-15.9s\n", empty));
 printf("field width -15.9s empty test \n\n");
 printf("my - %d, C - %d\n", printf("c: %-15.9s\n", single), ft_printf("m: %-15.9s\n", single));
 printf("field width -15.9s single test \n\n");
 
 // %-15.20s
 printf("my - %d, C - %d\n", printf("c: %-15.20s\n", str), ft_printf("m: %-15.20s\n", str));
 printf("field width -15.20s str test \n\n");
 printf("my - %d, C - %d\n", printf("c: %-15.20s\n", empty), ft_printf("m: %-15.20s\n", empty));
 printf("field width -15.20s empty test \n\n");
 printf("my - %d, C - %d\n", printf("c: %-15.20s\n", single), ft_printf("m: %-15.20s\n", single));
 printf("field width -15.20s single test \n\n");
 
*/

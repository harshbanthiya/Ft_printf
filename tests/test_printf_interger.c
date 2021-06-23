
/*
 
 void check_printf(char *format, long arg)
 {
	 int 	a, b;
	 a = ft_printf(format, arg);
	 puts("\nm:");
	 b = printf(format, arg);
	 puts("\nc:");

	 printf("My: %d C: %d\n\n", a, b);
 }

 
 // simple tests
check_printf("%d\n", 159);
check_printf("%d\n", INT_MAX);
check_printf("%d\n", INT_MIN);

// simple flags
check_printf("%+d\n", 0);
check_printf("%+d\n", 9);
check_printf("%+d\n", 34);
check_printf("% d\n", 0);

// Check long   LONG MIN IS AN ISSUE
check_L_printf("%ld\n",(long) 0);
check_L_printf("%ld\n",(long) 165);
check_L_printf("%ld\n",(long) LONG_MAX);
check_L_printf("%li\n",(long) -43);


// Alternate output
long zero = 0, pos = 174234;
check_L_printf("%#lu\n", zero);
check_L_printf("%#lu\n", pos);
check_L_printf("%#lo\n", zero);
check_L_printf("%#lo\n", pos);
check_L_printf("%#lx\n", zero);
check_L_printf("%#lx\n", pos);
check_L_printf("%#lX\n", zero);
check_L_printf("%#lX\n", pos);
// Precision long test
long zero = 0, pos = 2576, neg = -2321;
check_L_printf("%.10d\n", zero);
check_L_printf("%.10d\n", pos);
check_L_printf("%.10d\n", neg);
check_L_printf("%.3d\n", zero);
check_L_printf("%.3d\n", pos);
check_L_printf("%.3d\n", neg);
check_L_printf("%.1d\n", zero);
check_L_printf("%.1d\n", pos);
check_L_printf("%.1d\n", neg);
check_L_printf("%.0d\n", zero);
check_L_printf("%.0d\n", pos);
check_L_printf("%.0d\n", neg);
check_L_printf("%.d\n", zero);
check_L_printf("%.d\n", pos);
check_L_printf("%.d\n", neg);
*/
// precision_unsigned long
/*
unsigned long zero = 0, pos = 24364;

		check_printf("%.10lu\n", zero);
		check_printf("%.10lu\n", pos);
		check_printf("%.3lu\n", zero);
		check_printf("%.3lu\n", pos);
		check_printf("%.1lu\n", zero);
		check_printf("%.1lu\n", pos);
check_printf("%.0lu\n", zero);
		check_printf("%.0lu\n", pos);
		check_printf("%.lu\n", zero);
		check_printf("%.lu\n", pos);

		check_printf("%.10lx\n", zero);
		check_printf("%.10lx\n", pos);
		check_printf("%.3lx\n", zero);
		check_printf("%.3lx\n", pos);
		check_printf("%.1lx\n", zero);
		check_printf("%.1lx\n", pos);
		check_printf("%.0lx\n", zero);
		check_printf("%.0lx\n", pos);
		check_printf("%.lx\n", zero);
		check_printf("%.lx\n", pos);

		check_printf("%.10lX\n", zero);
		check_printf("%.10lX\n", pos);
		check_printf("%.3lX\n", zero);
		check_printf("%.3lX\n", pos);
		check_printf("%.1lX\n", zero);
		check_printf("%.1lX\n", pos);
		check_printf("%.0lX\n", zero);
		check_printf("%.0lX\n", pos);
		check_printf("%.lX\n", zero);
		check_printf("%.lX\n", pos);

		check_printf("%.10lo\n", zero);
		check_printf("%.10lo\n", pos);
		check_printf("%.3lo\n", zero);
		check_printf("%.3lo\n", pos);
		check_printf("%.1lo\n", zero);
		check_printf("%.1lo\n", pos);
		check_printf("%.0lo\n", zero);
		check_printf("%.0lo\n", pos);
		check_printf("%.lo\n", zero);
		check_printf("%.lo\n", pos);

// checking field width
long zero = 0, pos = 25476, neg = -99213;

		check_printf("%1ld\n", zero);
		check_printf("%1ld\n", pos);
		check_printf("%1ld\n", neg);

		check_printf("%2ld\n", zero);
		check_printf("%2ld\n", pos);
		check_printf("%2ld\n", neg);

		check_printf("%5ld\n", zero);
		check_printf("%5ld\n", pos);
		check_printf("%5ld", neg);

		check_printf("%7ld\n", zero);
		check_printf("%7ld\n", pos);
		check_printf("%7ld\n", neg);

		check_printf("%10ld\n", zero);
		check_printf("%10ld\n", pos);
		check_printf("%10ld\n", neg);


// checking field_width_long_zero_pad
long zero = 0, pos = 25476, neg = -99213;

check_printf("%01ld\n", zero);
check_printf("%01ld\n", pos);
check_printf("%01ld\n", neg);

		check_printf("%02ld\n", zero);
		check_printf("%02ld\n", pos);
		check_printf("%02ld\n", neg);

		check_printf("%05ld\n", zero);
		check_printf("%05ld\n", pos);
		check_printf("%05ld\n", neg);

		check_printf("%07ld\n", zero);
		check_printf("%07ld\n", pos);
		check_printf("%07ld\n", neg);

		check_printf("%010ld\n", zero);
		check_printf("%010ld\n", pos);
		check_printf("%010ld\n", neg);


unsigned long zero = 0, pos = 25476;

		check_printf("%1lu", zero);
		check_printf("%1lu", pos);
		check_printf("%2lu", zero);
		check_printf("%2lu", pos);
		check_printf("%5lu", zero);
		check_printf("%5lu", pos);
		check_printf("%7lu", zero);
		check_printf("%7lu", pos);
		check_printf("%10lu", zero);
		check_printf("%10lu", pos);

		check_printf("%1lo", zero);
		check_printf("%1lo", pos);
		check_printf("%2lo", zero);
		check_printf("%2lo", pos);
		check_printf("%5lo", zero);
		check_printf("%5lo", pos);
		check_printf("%7lo", zero);
		check_printf("%7lo", pos);
		check_printf("%10lo", zero);
		check_printf("%10lo", pos);

		check_printf("%1lx", zero);
		check_printf("%1lx", pos);
		check_printf("%2lx", zero);
		check_printf("%2lx", pos);
		check_printf("%5lx", zero);
		check_printf("%5lx", pos);
		check_printf("%7lx", zero);
		check_printf("%7lx", pos);
		check_printf("%10lx", zero);
		check_printf("%10lx", pos);

		check_printf("%1lX", zero);
		check_printf("%1lX", pos);
		check_printf("%2lX", zero);
		check_printf("%2lX", pos);
		check_printf("%5lX", zero);
		check_printf("%5lX", pos);
		check_printf("%7lX", zero);
		check_printf("%7lX", pos);
		check_printf("%10lX", zero);
		check_printf("%10lX", pos);

// field width unsigned zero pad

long zero = 0, pos = 25476;

		check_printf("%01lu", zero);
		check_printf("%01lu", pos);
		check_printf("%02lu", zero);
		check_printf("%02lu", pos);
		check_printf("%05lu", zero);
		check_printf("%05lu", pos);
		check_printf("%07lu", zero);
		check_printf("%07lu", pos);
		check_printf("%010lu", zero);
		check_printf("%010lu", pos);

		check_printf("%01lo", zero);
		check_printf("%01lo", pos);
		check_printf("%02lo", zero);
		check_printf("%02lo", pos);
		check_printf("%05lo", zero);
		check_printf("%05lo", pos);
		check_printf("%07lo", zero);
		check_printf("%07lo", pos);
		check_printf("%010lo", zero);
		check_printf("%010lo", pos);

		check_printf("%01lx", zero);
		check_printf("%01lx", pos);
		check_printf("%02lx", zero);
		check_printf("%02lx", pos);
		check_printf("%05lx", zero);
		check_printf("%05lx", pos);
		check_printf("%07lx", zero);
		check_printf("%07lx", pos);
		check_printf("%010lx", zero);
		check_printf("%010lx", pos);

		check_printf("%01lX", zero);
		check_printf("%01lX", pos);
		check_printf("%02lX", zero);
		check_printf("%02lX", pos);
		check_printf("%05lX", zero);
		check_printf("%05lX", pos);
		check_printf("%07lX", zero);
		check_printf("%07lX", pos);
		check_printf("%010lX", zero);
		check_printf("%010lX", pos);


long zero = 0, pos = 25476, neg = -99213;

		check_printf("%-1ld", zero);
		check_printf("%-1ld", pos);
		check_printf("%-1ld", neg);

		check_printf("%-2ld", zero);
		check_printf("%-2ld", pos);
		check_printf("%-2ld", neg);

		check_printf("%-5ld", zero);
		check_printf("%-5ld", pos);
		check_printf("%-5ld", neg);

		check_printf("%-7ld", zero);
		check_printf("%-7ld", pos);
		check_printf("%-7ld", neg);

		check_printf("%-10ld", zero);
		check_printf("%-10ld", pos);
		check_printf("%-10ld", neg);

// field_width left align long zero pad check again prints trailing zeroes
long zero = 0, pos = 25476, neg = -99213;

		check_printf("%-01ld", zero);
		check_printf("%-01ld", pos);
		check_printf("%-01ld", neg);

		check_printf("%-02ld", zero);

		check_printf("%-02ld", pos);
		check_printf("%-02ld", neg);

		check_printf("%-05ld", zero);
/*
		check_printf("%-05ld", pos);
		check_printf("%-05ld", neg);

		check_printf("%-07ld", zero);
		check_printf("%-07ld", pos);
		check_printf("%-07ld", neg);

		check_printf("%-010ld", zero);
		check_printf("%-010ld", pos);
		check_printf("%-010ld", neg);

unsigned long zero = 0, pos = 25476;

		check_printf("%-1lu", zero);
		check_printf("%-1lu", pos);
		check_printf("%-2lu", zero);
		check_printf("%-2lu", pos);
		check_printf("%-5lu", zero);
		check_printf("%-5lu", pos);
		check_printf("%-7lu", zero);
		check_printf("%-7lu", pos);
		check_printf("%-10lu", zero);
		check_printf("%-10lu", pos);

		check_printf("%-1lo", zero);
		check_printf("%-1lo", pos);
		check_printf("%-2lo", zero);
		check_printf("%-2lo", pos);
		check_printf("%-5lo", zero);
		check_printf("%-5lo", pos);
		check_printf("%-7lo", zero);
		check_printf("%-7lo", pos);
		check_printf("%-10lo", zero);
		check_printf("%-10lo", pos);

		check_printf("%-1lx", zero);
		check_printf("%-1lx", pos);
		check_printf("%-2lx", zero);
		check_printf("%-2lx", pos);
		check_printf("%-5lx", zero);
		check_printf("%-5lx", pos);
		check_printf("%-7lx", zero);
		check_printf("%-7lx", pos);
		check_printf("%-10lx", zero);
		check_printf("%-10lx", pos);

		check_printf("%-1lX", zero);
		check_printf("%-1lX", pos);
		check_printf("%-2lX", zero);
		check_printf("%-2lX", pos);
		check_printf("%-5lX", zero);
		check_printf("%-5lX", pos);
		check_printf("%-7lX", zero);
		check_printf("%-7lX", pos);
		check_printf("%-10lX", zero);
		check_printf("%-10lX", pos);

// field_width unsigned zero pad left align
unsigned long zero = 0, pos = 25476;

		check_printf("%-01lu", zero);
		check_printf("%-01lu", pos);
		check_printf("%-02lu", zero);
		check_printf("%-02lu", pos);
		check_printf("%-05lu", zero);
		check_printf("%-05lu", pos);
		check_printf("%-07lu", zero);
		check_printf("%-07lu", pos);
		check_printf("%-010lu", zero);
		check_printf("%-010lu", pos);

		check_printf("%-01lo", zero);
		check_printf("%-01lo", pos);
		check_printf("%-02lo", zero);
		check_printf("%-02lo", pos);
		check_printf("%-05lo", zero);
		check_printf("%-05lo", pos);
		check_printf("%-07lo", zero);
		check_printf("%-07lo", pos);
		check_printf("%-010lo", zero);
		check_printf("%-010lo", pos);

		check_printf("%-01lx", zero);
		check_printf("%-01lx", pos);
		check_printf("%-02lx", zero);
		check_printf("%-02lx", pos);
		check_printf("%-05lx", zero);
		check_printf("%-05lx", pos);
		check_printf("%-07lx", zero);
		check_printf("%-07lx", pos);
		check_printf("%-010lx", zero);
		check_printf("%-010lx", pos);

		check_printf("%-01lX", zero);
		check_printf("%-01lX", pos);
		check_printf("%-02lX", zero);
		check_printf("%-02lX", pos);
		check_printf("%-05lX", zero);
		check_printf("%-05lX", pos);
		check_printf("%-07lX", zero);
		check_printf("%-07lX", pos);
		check_printf("%-010lX", zero);
		check_printf("%-010lX", pos);


// testing field width precision long
long zero = 0, pos = 25476, neg = -99213;

		check_printf("%10.ld", zero);
		check_printf("%10.ld", pos);
		check_printf("%10.ld", neg);
		check_printf("%5.ld", zero);
		check_printf("%5.ld", pos);
		check_printf("%5.ld", neg);
		check_printf("%2.ld", zero);
		check_printf("%2.ld", pos);
		check_printf("%2.ld", neg);
		check_printf("%1.ld", zero);
		check_printf("%1.ld", pos);
		check_printf("%1.ld", neg);

		check_printf("%10.1ld", zero);
		check_printf("%10.1ld", pos);
		check_printf("%10.1ld", neg);
		check_printf("%5.1ld", zero);
		check_printf("%5.1ld", pos);
		check_printf("%5.1ld", neg);
		check_printf("%2.1ld", zero);
		check_printf("%2.1ld", pos);
		check_printf("%2.1ld", neg);
		check_printf("%1.1ld", zero);
		check_printf("%1.1ld", pos);
		check_printf("%1.1ld", neg);

		check_printf("%10.5ld", zero);
		check_printf("%10.5ld", pos);
		check_printf("%10.5ld", neg);
		check_printf("%5.5ld", zero);
		check_printf("%5.5ld", pos);
		check_printf("%5.5ld", neg);
		check_printf("%2.5ld", zero);
		check_printf("%2.5ld", pos);
		check_printf("%2.5ld", neg);
		check_printf("%1.5ld", zero);
		check_printf("%1.5ld", pos);
		check_printf("%1.5ld", neg);

		check_printf("%10.10ld", zero);
		check_printf("%10.10ld", pos);
		check_printf("%10.10ld", neg);
		check_printf("%5.10ld", zero);
		check_printf("%5.10ld", pos);
		check_printf("%5.10ld", neg);
		check_printf("%2.10ld", zero);
		check_printf("%2.10ld", pos);
		check_printf("%2.10ld", neg);
		check_printf("%1.10ld", zero);
		check_printf("%1.10ld", pos);
		check_printf("%1.10ld", neg);

// Width precision left _align long
long zero = 0, pos = 25476, neg = -99213;

		check_printf("%-10.ld", zero);
		check_printf("%-10.ld", pos);
		check_printf("%-10.ld", neg);
		check_printf("%-5.ld", zero);
		check_printf("%-5.ld", pos);
		check_printf("%-5.ld", neg);
		check_printf("%-2.ld", zero);
		check_printf("%-2.ld", pos);
		check_printf("%-2.ld", neg);
		check_printf("%-1.ld", zero);
		check_printf("%-1.ld", pos);
		check_printf("%-1.ld", neg);

		check_printf("%-10.1ld", zero);
		check_printf("%-10.1ld", pos);
		check_printf("%-10.1ld", neg);
		check_printf("%-5.1ld", zero);
		check_printf("%-5.1ld", pos);
		check_printf("%-5.1ld", neg);
		check_printf("%-2.1ld", zero);
		check_printf("%-2.1ld", pos);
		check_printf("%-2.1ld", neg);
		check_printf("%-1.1ld", zero);
		check_printf("%-1.1ld", pos);
		check_printf("%-1.1ld", neg);

		check_printf("%-10.5ld", zero);
		check_printf("%-10.5ld", pos);
		check_printf("%-10.5ld", neg);
		check_printf("%-5.5ld", zero);
		check_printf("%-5.5ld", pos);
		check_printf("%-5.5ld", neg);
		check_printf("%-2.5ld", zero);
		check_printf("%-2.5ld", pos);
		check_printf("%-2.5ld", neg);
		check_printf("%-1.5ld", zero);
		check_printf("%-1.5ld", pos);
		check_printf("%-1.5ld", neg);

		check_printf("%-10.10ld", zero);
		check_printf("%-10.10ld", pos);
		check_printf("%-10.10ld", neg);
		check_printf("%-5.10ld", zero);
		check_printf("%-5.10ld", pos);
		check_printf("%-5.10ld", neg);
		check_printf("%-2.10ld", zero);
		check_printf("%-2.10ld", pos);
		check_printf("%-2.10ld", neg);
		check_printf("%-1.10ld", zero);
		check_printf("%-1.10ld", pos);
		check_printf("%-1.10ld", neg);


// Field Width precision zero pad long
long zero = 0, pos = 25476, neg = -99213;

		check_printf("%010.ld", zero);
		check_printf("%010.ld", pos);
		check_printf("%010.ld", neg);
		check_printf("%05.ld", zero);
		check_printf("%05.ld", pos);
		check_printf("%05.ld", neg);
		check_printf("%02.ld", zero);
		check_printf("%02.ld", pos);
		check_printf("%02.ld", neg);
		check_printf("%01.ld", zero);
		check_printf("%01.ld", pos);
		check_printf("%01.ld", neg);

		check_printf("%010.1ld", zero);
		check_printf("%010.1ld", pos);
		check_printf("%010.1ld", neg);
		check_printf("%05.1ld", zero);
		check_printf("%05.1ld", pos);
		check_printf("%05.1ld", neg);
		check_printf("%02.1ld", zero);
		check_printf("%02.1ld", pos);
		check_printf("%02.1ld", neg);
		check_printf("%01.1ld", zero);
		check_printf("%01.1ld", pos);
		check_printf("%01.1ld", neg);

		check_printf("%010.5ld", zero);
		check_printf("%010.5ld", pos);
		check_printf("%010.5ld", neg);
		check_printf("%05.5ld", zero);
		check_printf("%05.5ld", pos);
		check_printf("%05.5ld", neg);
		check_printf("%02.5ld", zero);
		check_printf("%02.5ld", pos);
		check_printf("%02.5ld", neg);
		check_printf("%01.5ld", zero);
		check_printf("%01.5ld", pos);
		check_printf("%01.5ld", neg);

		check_printf("%010.10ld", zero);
		check_printf("%010.10ld", pos);
		check_printf("%010.10ld", neg);
		check_printf("%05.10ld", zero);
		check_printf("%05.10ld", pos);
		check_printf("%05.10ld", neg);
		check_printf("%02.10ld", zero);
		check_printf("%02.10ld", pos);
		check_printf("%02.10ld", neg);
		check_printf("%01.10ld", zero);
		check_printf("%01.10ld", pos);
		check_printf("%01.10ld", neg);


unsigned long zero = 0, pos = 25476;

		check_printf("%1.lu", zero);
		check_printf("%1.lu", pos);
		check_printf("%1.lo", zero);
		check_printf("%1.lo", pos);
		check_printf("%1.lx", zero);
		check_printf("%1.lx", pos);
		check_printf("%1.lX", zero);
		check_printf("%1.lX", pos);

		check_printf("%1.1lu", zero);
		check_printf("%1.1lu", pos);
		check_printf("%1.1lo", zero);
		check_printf("%1.1lo", pos);
		check_printf("%1.1lx", zero);
		check_printf("%1.1lx", pos);
		check_printf("%1.1lX", zero);
		check_printf("%1.1lX", pos);

		check_printf("%5.2lu", zero);
		check_printf("%5.2lu", pos);
		check_printf("%5.2lo", zero);
		check_printf("%5.2lo", pos);
		check_printf("%5.2lx", zero);
		check_printf("%5.2lx", pos);
		check_printf("%5.2lX", zero);
		check_printf("%5.2lX", pos);

		check_printf("%10.lu", zero);
		check_printf("%10.lu", pos);
		check_printf("%10.lo", zero);
		check_printf("%10.lo", pos);
		check_printf("%10.lx", zero);
		check_printf("%10.lx", pos);
		check_printf("%10.lX", zero);
		check_printf("%10.lX", pos);

		check_printf("%10.10lu", zero);
		check_printf("%10.10lu", pos);
		check_printf("%10.10lo", zero);
		check_printf("%10.10lo", pos);
		check_printf("%10.10lx", zero);
		check_printf("%10.10lx", pos);
		check_printf("%10.10lX", zero);
		check_printf("%10.10lX", pos);

// field width precision left align unsigned
unsigned long zero = 0, pos = 25476;

		check_printf("%-1.lu", zero);
		check_printf("%-1.lu", pos);
		check_printf("%-1.lo", zero);
		check_printf("%-1.lo", pos);
		check_printf("%-1.lx", zero);
		check_printf("%-1.lx", pos);
		check_printf("%-1.lX", zero);
		check_printf("%-1.lX", pos);

		check_printf("%-1.1lu", zero);
		check_printf("%-1.1lu", pos);
		check_printf("%-1.1lo", zero);
		check_printf("%-1.1lo", pos);
		check_printf("%-1.1lx", zero);
		check_printf("%-1.1lx", pos);
		check_printf("%-1.1lX", zero);
		check_printf("%-1.1lX", pos);

		check_printf("%-5.2lu", zero);
		check_printf("%-5.2lu", pos);
		check_printf("%-5.2lo", zero);
		check_printf("%-5.2lo", pos);
		check_printf("%-5.2lx", zero);
		check_printf("%-5.2lx", pos);
		check_printf("%-5.2lX", zero);
		check_printf("%-5.2lX", pos);

		check_printf("%-10.lu", zero);
		check_printf("%-10.lu", pos);
		check_printf("%-10.lo", zero);
		check_printf("%-10.lo", pos);
		check_printf("%-10.lx", zero);
		check_printf("%-10.lx", pos);
		check_printf("%-10.lX", zero);
		check_printf("%-10.lX", pos);

		check_printf("%-10.10lu", zero);
		check_printf("%-10.10lu", pos);
		check_printf("%-10.10lo", zero);
		check_printf("%-10.10lo", pos);
		check_printf("%-10.10lx", zero);
		check_printf("%-10.10lx", pos);
		check_printf("%-10.10lX", zero);
		check_printf("%-10.10lX", pos);


// field width precision zero pad unsigned
unsigned long zero = 0, pos = 25476;

		check_printf("%01.lu", zero);
		check_printf("%01.lu", pos);
		check_printf("%01.lo", zero);
		check_printf("%01.lo", pos);
		check_printf("%01.lx", zero);
		check_printf("%01.lx", pos);
		check_printf("%01.lX", zero);
		check_printf("%01.lX", pos);

		check_printf("%01.1lu", zero);
		check_printf("%01.1lu", pos);
		check_printf("%01.1lo", zero);
		check_printf("%01.1lo", pos);
		check_printf("%01.1lx", zero);
		check_printf("%01.1lx", pos);
		check_printf("%01.1lX", zero);
		check_printf("%01.1lX", pos);

		check_printf("%05.2lu", zero);
		check_printf("%05.2lu", pos);
		check_printf("%05.2lo", zero);
		check_printf("%05.2lo", pos);
		check_printf("%05.2lx", zero);
		check_printf("%05.2lx", pos);
		check_printf("%05.2lX", zero);
		check_printf("%05.2lX", pos);

		check_printf("%010.lu", zero);
		check_printf("%010.lu", pos);
		check_printf("%010.lo", zero);
		check_printf("%010.lo", pos);
		check_printf("%010.lx", zero);
		check_printf("%010.lx", pos);
		check_printf("%010.lX", zero);
		check_printf("%010.lX", pos);

		check_printf("%010.10lu", zero);
		check_printf("%010.10lu", pos);
		check_printf("%010.10lo", zero);
		check_printf("%010.10lo", pos);
		check_printf("%010.10lx", zero);
		check_printf("%010.10lx", pos);
		check_printf("%010.10lX", zero);
		check_printf("%010.10lX", pos);

// field width intial space long
long zero = 0, pos = 25476, neg = -99213;

		check_printf("% 1ld", zero);
		check_printf("% 1ld", pos);
		check_printf("% 1ld", neg);

		check_printf("% 2ld", zero);
		check_printf("% 2ld", pos);
		check_printf("% 2ld", neg);

		check_printf("% 5ld", zero);
		check_printf("% 5ld", pos);
		check_printf("% 5ld", neg);

		check_printf("% 7ld", zero);
		check_printf("% 7ld", pos);
		check_printf("% 7ld", neg);

		check_printf("% 10ld", zero);
		check_printf("% 10ld", pos);
		check_printf("% 10ld", neg);

		// '+' overrides ' '.
		check_printf("%+ 1ld", zero);
		check_printf("%+ 1ld", pos);
		check_printf("%+ 1ld", neg);

		check_printf("%+ 2ld", zero);
		check_printf("%+ 2ld", pos);
		check_printf("%+ 2ld", neg);

		check_printf("%+ 5ld", zero);
		check_printf("%+ 5ld", pos);
		check_printf("%+ 5ld", neg);

		check_printf("%+ 7ld", zero);
		check_printf("%+ 7ld", pos);
		check_printf("%+ 7ld", neg);

		check_printf("%+ 10ld", zero);
		check_printf("%+ 10ld", pos);
		check_printf("%+ 10ld", neg);

		// Left align should not change the behaviour.
		check_printf("%- 1ld", zero);
		check_printf("%- 1ld", pos);
		check_printf("%- 1ld", neg);

		check_printf("%- 2ld", zero);
		check_printf("%- 2ld", pos);
		check_printf("%- 2ld", neg);

		check_printf("%- 5ld", zero);
		check_printf("%- 5ld", pos);
		check_printf("%- 5ld", neg);

		check_printf("%- 7ld", zero);
		check_printf("%- 7ld", pos);
		check_printf("%- 7ld", neg);

		check_printf("%- 10ld", zero);
		check_printf("%- 10ld", pos);
		check_printf("%- 10ld", neg);
*/

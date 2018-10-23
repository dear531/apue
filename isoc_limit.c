#include <stdio.h>
#include <limits.h>

int main(void)
{
	struct limits_s {
		char *string;
		long long value;
	} limits[] = {
		{"CHAR_BIT", CHAR_BIT},
		{"CHAR_MAX", CHAR_MAX},
		{"CHAR_MIN", CHAR_MIN},
		{"SCHAR_MAX", SCHAR_MAX},
		{"SCHAR_MIN", SCHAR_MIN},
		{"INT_MAX", INT_MAX},
		{"INT_MIN", INT_MIN},
		{"UINT_MAX", UINT_MAX},
		{"SHRT_MAX", SHRT_MAX},
		{"SHRT_MIN", SHRT_MIN},
		{"USHRT_MAX", USHRT_MAX},
		{"LONG_MAX", LONG_MAX},
		{"LONG_MIN", LONG_MIN},
		{"ULONG_MAX", ULONG_MAX},
		{"LLONG_MAX", LLONG_MAX},
		{"LLONG_MIN", LLONG_MIN},
		{"ULLONG_MAX", ULLONG_MAX},
		{"MB_LEN_MAX", MB_LEN_MAX},
		{"FOPEN_MAX", FOPEN_MAX},
	};
	int i = 0;
	for (i = 0; sizeof(limits) / sizeof(*limits) > i; i++)
	{
		if ('U' == limits[i].string[0]) {
			fprintf(stdout, "%s\t:\t%llu\n",
				limits[i].string, limits[i].value);
		} else {
			fprintf(stdout, "%s\t:\t%lld\n",
				limits[i].string, limits[i].value);
		}
	}
	return 0;
}

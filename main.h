#ifndef  _PRINTF_H
#define  _PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>


#define PARAMETERS {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}


/**
 * struct parameters - parameters struct
 *
 * @unsign: flag if unsigned value
 *
 * @flag_plus: on if plus_flag specified
 * @flag_space: on if hashtag_flag specified
 * @hash_flag: on if _flag specified
 * @zero_flag: on if _flag specified
 * @flag_minus: on if _flag specified
 *
 * @width: field width specified
 * @precision: field precision specified
 *
 * @short_modif: on if h_modifier is specified
 * @long_modif: on if l_modifier is specified
 *
 */


typedef struct parames
{
	unsigned int unsign			: 1;

	unsigned int flag_plus		: 1;
	unsigned int flag_space		: 1;
	unsigned int hash_flag	     : 1;
	unsigned int zero_flag		: 1;
	unsigned int flag_minus		: 1;

	unsigned int width;
	unsigned int precision;

	unsigned int short_modif	: 1;
	unsigned int long_modif		: 1;
} params_t;




int _printf(const char *format, ...);

char *convert(long int num, int base, int flags, params_t *params);
int put_unsigned(va_list ap, params_t *params);
int put_addrss(va_list ap, params_t *params);
int put_char(va_list ap, params_t *params);
int put_int(va_list ap, params_t *params);
int put_string(va_list ap, params_t *params);
int put_percent(va_list ap, params_t *params);
int put_STR(va_list ap, params_t *params);
int (*hold_specifier(char *s))(va_list ap, params_t *params);
int hold_put_func(char *s, va_list ap, params_t *params);
int hold_flag(char *s, params_t *params);
int hold_modifier(char *s, params_t *params);
char *hold_width(char *s, params_t *params, va_list ap);

#define OUTPUT_BUFFER_SIZE 1024
#define BUFFER_SH -1

#define FIELD_BUF_SIZE 50

#define STRING_IS_NULL "(null)"


#define LOWERCASE	1
#define CON_UNSIGNED	2

/**
 * struct spec - Struct token
 *
 * @spec: format token
 * @f: The function associated
 */
typedef struct spec
{
	char *spec;
	int (*f)(va_list, params_t *);
} spec_t;


int _digit(int c);
int _stringlength(char *s);
int put_number(char *str, params_t *params);
int right_shift(char *str, params_t *params);
int left_shift(char *str, params_t *params);
int put_s(char *str);
int _putchar(int c);


void init_params(params_t *params, va_list ap);
char *hold_precision(char *p, params_t *params, va_list ap);

int put_hexadicimal(va_list ap, params_t *params);
int put_HEXADICIMAL(va_list ap, params_t *params);
int put_rev(va_list ap, params_t *params);
int rotate_f(va_list ap, params_t *params);
int put_binary(va_list ap, params_t *params);
int put_octal(va_list ap, params_t *params);
int put_from_to(char *start, char *stop, char *except);



#endif

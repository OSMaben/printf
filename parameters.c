#include "main.h"

/**
 * init_params - clears struct fields and reset buf
 * @params: the parameters struct
 * @ap: the argument pointer
 *
 * Return: void
 */
void init_params(params_t *params, va_list ap)
{
	params->unsign = 0;

	params->flag_plus = 0;
	params->flag_space = 0;
	params->hash_flag = 0;
	params->zero_flag = 0;
	params->flag_minus = 0;

	params->width = 0;
	params->precision = UINT_MAX;

	params->short_modif = 0;
	params->long_modif = 0;
	(void)ap;
}

#include "main.h"
/**
 * init_params - clears struct fields and reset buff
 * @para: struct
 * @ap: pointer
 * Return: void value
 */
void init_params(para_t *para, va_list ap)
{
	para->unsign = 0;
	para->plus_flag = 0;
	para->space_flag = 0;
	para->hashtag_flag = 0;
	para->zero_flag = 0;
	para->minus_flag = 0;
	para->width = 0;
	para->precision = UINT_MAX;
	para->h_modifier = 0;
	para->l_modifier = 0;
	(void)ap;
}

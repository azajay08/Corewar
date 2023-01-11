/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:10:35 by ajones            #+#    #+#             */
/*   Updated: 2022/12/21 14:32:15 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../../libft.h"
# include <stdarg.h>

typedef struct s_spec
{
	char			*flag_str;
	char			c;
	int				total;
	int				min;
	int				plus;
	int				zero;
	int				mod;
	int				hash;
	int				width;
	int				prec;
	int				space;
	int				star_w;
	int				star_p;
	int				min_over;
	int				zero_over;
	unsigned int	base;
}					t_spec;

int						ft_printf(const char *format, ...);
int						read_spec(char const *format, va_list *ap,
							t_spec *fspec);
int						form_c(va_list *ap, t_spec *fspec);
int						form_s(va_list *ap, t_spec *fspec);
int						form_di(va_list *ap, t_spec *fspec);
int						form_u(va_list *ap, t_spec *fspec);
int						form_o(va_list *ap, t_spec *fspec);
int						form_x(va_list *ap, t_spec *fspec);
int						form_p(va_list *ap, t_spec *fspec);
int						form_f(va_list *ap, t_spec *fspec);
int						form_perc(t_spec *fspec);
int						numlen_sign(long long int num);
int						is_flag(char c);
int						is_mod(char c);
int						is_form_spec(char c);
int						form_spec_id(va_list *ap, t_spec *fspec);
int						sign_check(t_spec *fspec);
void					init_fspec(t_spec *fspec);
void					init_flags(t_spec *fspec);
void					reset_flags(t_spec *fspec);
void					star_init(va_list *ap, t_spec *fspec);
long long int			manage_di_mods(va_list *ap, t_spec *fspec);
unsigned long long int	manage_u_mods(va_list *ap, t_spec *fspec);
long double				manage_f_mods(va_list *ap, t_spec *fspec);
char					*ft_itoa_signed(long long int num);
char					*ft_itoa_u(unsigned long long int num, t_spec *fspec);
char					*manage_di_zero(char *str_num, t_spec *fspec);
char					*join_str(char *add_str, char *str_num, t_spec *fspec);
char					*handle_space_plus_min(char	*str, t_spec *fspec);
char					*manage_u_width(char *str, t_spec *fspec, int i);
char					*manage_u_prec(char *str, t_spec *fspec,	
							unsigned long long int arg_num);
char					di_zero_spaces(char str, t_spec *fspec,
							long long int arg);
char					handle_space_plus(char c, t_spec *fspec);
char					*nan_inf_dup(char *str, long double num, t_spec *fspec);
char					*make_n_str(t_spec *fspec, long double num);

#endif
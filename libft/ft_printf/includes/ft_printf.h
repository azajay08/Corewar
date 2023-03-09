/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilliam <swilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:10:35 by ajones            #+#    #+#             */
/*   Updated: 2023/03/09 13:52:16 by swilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../../includes/libft.h"
# include <stdarg.h>

//Regular text
#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"

//Regular bold text
#define BBLK "\e[1;30m"
#define BRED "\e[1;31m"
#define BGRN "\e[1;32m"
#define BYEL "\e[1;33m"
#define BBLU "\e[1;34m"
#define BMAG "\e[1;35m"
#define BCYN "\e[1;36m"
#define BWHT "\e[1;37m"

//Regular underline text
#define UBLK "\e[4;30m"
#define URED "\e[4;31m"
#define UGRN "\e[4;32m"
#define UYEL "\e[4;33m"
#define UBLU "\e[4;34m"
#define UMAG "\e[4;35m"
#define UCYN "\e[4;36m"
#define UWHT "\e[4;37m"

//Regular background
#define BLKB "\e[40m"
#define REDB "\e[41m"
#define GRNB "\e[42m"
#define YELB "\e[43m"
#define BLUB "\e[44m"
#define MAGB "\e[45m"
#define CYNB "\e[46m"
#define WHTB "\e[47m"

//High intensty background
#define BLKHB "\e[0;100m"
#define REDHB "\e[0;101m"
#define GRNHB "\e[0;102m"
#define YELHB "\e[0;103m"
#define BLUHB "\e[0;104m"
#define MAGHB "\e[0;105m"
#define CYNHB "\e[0;106m"
#define WHTHB "\e[0;107m"

//High intensty text
#define HBLK "\e[0;90m"
#define HRED "\e[0;91m"
#define HGRN "\e[0;92m"
#define HYEL "\e[0;93m"
#define HBLU "\e[0;94m"
#define HMAG "\e[0;95m"
#define HCYN "\e[0;96m"
#define HWHT "\e[0;97m"

//Bold high intensity text
#define BHBLK "\e[1;90m"
#define BHRED "\e[1;91m"
#define BHGRN "\e[1;92m"
#define BHYEL "\e[1;93m"
#define BHBLU "\e[1;94m"
#define BHMAG "\e[1;95m"
#define BHCYN "\e[1;96m"
#define BHWHT "\e[1;97m"

//Reset
#define RESET "\e[0m"

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
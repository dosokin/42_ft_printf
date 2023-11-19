/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:23:14 by dosokin           #+#    #+#             */
/*   Updated: 2023/11/16 17:54:41 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_formatplus
{
	int					minus;
	int					plus;
	int					space;
	int					hashtag;
	int					zero;
	int					width;
	int					point;
	int					precision;
	int					negative;
}						t_p_format;

typedef struct t_sints
{
	int					i;
	int					j;
	int					y;
	int					l;
	int					rr;
}						t_s_ints;

typedef struct t_int_min_case_data
{
	char				*resultat;
	char				*minint;
	int					zeros;
	int					i;
	int					j;
}						t_minn;

typedef struct t_di_data
{
	int					j;
	int					z;
	int					len;
	int					o;
}						t_ddata;

typedef struct t_u_data
{
	int					j;
	int					z;
	int					len;
	int					o;
}						t_udata;

typedef struct t_x_data
{
	int					l;
	int					j;
	int					zeros;
	int					o;
}						t_xdata;

typedef struct t_main_function_data
{
	int					i;
	int					f;
	unsigned long int	p;
	t_p_format			*flag;
	char				*r;
	int					y;
	int					i_base;
	int					skip;
}						t_main_data;

void					ft_putchar(char c);
int						ccase(char c, t_p_format *infos);
int						ischarinset(char c);
int						scase(char *s, t_p_format *infos, int x,
							int di_redirect);
char					*dicase(int n, t_p_format *infos, int i, char *r);
char					*ucase(unsigned int u, t_p_format *infos,
							int i, char *r);
char					*big_xcase(unsigned int n, t_p_format *infos, int i,
							char *r);
char					*lil_xcase(unsigned int n, t_p_format *infos, int i,
							char *r);
void					definehexa(char *r);
int						format_detect(const char *format, t_main_data *data);
char					*ft_tolower(char *r);
int						ft_printf(const char *format, ...);
t_p_format				*flagset(const char *format, int i);
char					*pcase(unsigned long long n, t_p_format *infos,
							int i, char *r);
int						divilen(unsigned long int p);
int						ft_strlen(char *s);
int						dividlen(unsigned int p);
char					*ft_strdup(const char *s);
int						dividixlen(int n);
char					*intmincase(t_p_format *infos);
char					*case_n_null_prec_null(char *r, t_p_format *infos);
t_ddata					*init_di_data(int n);
int						n_sign_check(int n, t_p_format *infos, t_ddata *data,
							char *r);
char					*di_to_s_process(int n, t_p_format *infos, int i,
							char *r);
void					flag_manage_di(t_p_format *infos,
							char *r, t_ddata *data);
int						lenset_dicase(int n, t_p_format *infos, int i,
							t_ddata *data);
int						ft_isnum(char c);
t_p_format				*initinfo(void);
int						infoset1(const char *format, int debut, int fin,
							t_p_format *info);
int						info_width(const char *format, int debut, int fin,
							t_p_format *info);
t_ddata					*init_di_data(int n);
t_main_data				*init_main_data(void);
void					f_branches(const char *format, t_main_data *data,
							va_list args);
void					no_percent(const char *format,
							t_main_data *data);
char					*ucase(unsigned int u, t_p_format *infos,
							int i, char *r);
void					u_to_s_process(unsigned int u, t_p_format *infos, int i,
							char *r);
void					flag_manage_u(t_p_format *infos, t_udata *data,
							char *r);
int						lenset_ucase(unsigned int u, t_p_format *infos,
							t_udata *data, int i);
t_udata					*init_u_data(unsigned int u);
void					pre_width_manage(t_p_format *info, t_s_ints *data,
							int x);
void					main_content(char *s, t_s_ints *data, int di_redirect);
void					su_width_manage(t_p_format *info, t_s_ints *data);
int						point_trunc_case(t_p_format *info, t_s_ints *data);
int						scase(char *s, t_p_format *info, int x,
							int di_redirect);
void					check_conds1(t_p_format *info, int di_redirect,
							t_s_ints *data);
int						null_s_case(int di_redirect, t_p_format *info);
t_s_ints				*init_data(char *s, t_p_format *info);
int						nullpointer(t_p_format *info);
void					flag_manage_x2(t_p_format *infos, t_xdata *data, int x,
							char *r);
void					flag_manage_x1(unsigned int n, t_p_format *infos,
							t_xdata *data);
char					*lil_xcase(unsigned int n, t_p_format *infos, int i,
							char *r);
char					*big_xcase(unsigned int n, t_p_format *infos, int i,
							char *r);
t_xdata					*init_x_data(void);
void					lil_x_to_s_process(unsigned int n, t_p_format *infos,
							int i, char *r);
void					big_x_to_s_process(unsigned int n, t_p_format *infos,
							int i, char *r);
char					*pcase(unsigned long long n, t_p_format *infos,
							int i, char *r);
char					*pmincase(void);
int						dividplen(unsigned long long p);
void					flag_manage_p1(unsigned long long n, t_p_format *infos,
							t_xdata *data);
void					p_to_s_process(unsigned long long n,
							t_p_format *infos, int i, char *r);
void					flag_manage_p2(t_p_format *infos, t_xdata *data, int x,
							char *r);
int						dividixlenuns(unsigned int n);
int						doublepercent(const char *format, int i);
int						is_a_flag(char c);
int						doublepercent(const char *format, int i);

#endif

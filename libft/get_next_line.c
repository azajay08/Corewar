/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronjones <aaronjones@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:18:36 by ajones            #+#    #+#             */
/*   Updated: 2022/07/07 15:44:33 by aaronjones       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function is used if we know we are at the last
** line. We duplicate the *str into our line variable, 
** and then we free the str, as we do not need the data
** anymore, we don't need to set a point of address at
** the end of the line because we know this is the end 
** the file.
**
*/

static int	end_line_create(char **str, char **line)
{
	*line = ft_strdup(*str);
	ft_strdel(str);
	return (1);
}

/*
** In this function, we know that it is not the end
** of the file, so we need create some memory for the
** line, up to amount of len, given from the previous
** function. We create a temp string again to store the 
** data and then update the current address ready for the
** next line. The *str is freed and then set to temp for 
** this to happen. Once this is done, we can return (1)
** to say that the line has been read. 
*/

static int	new_line_create(char **str, char **line, int len)
{
	char	*temp;

	*line = ft_strsub(*str, 0, len);
	temp = ft_strdup(&((*str)[len + 1]));
	if (!temp)
		return (-1);
	free(*str);
	*str = temp;
	if ((*str)[0] == '\0')
		ft_strdel(str);
	return (1);
}

/*
** The ret_result function is sort of like a final 
** decision on what to return. The ret value determines
** what should be returned. If the ret was lower that 0,
** there has been an error so (-1) will be returned.
** if the ret is 0 and *str is NULL, we return (0), as 
** this means that the reading has been done, and it is
** the EOF. If anything else is the case, then it means
** more is needed to be done. The length of the line is
** is found so that we can see what is at the end of the
** line. That way we can see what finally needs to be 
** done for the line. If a newline has been found, it 
** take us into a new_line_create function, otherwise
** it will take us into the end_line_create function.
*/

static int	ret_result(char **str, char **line, int ret, int fd)
{
	int	len;

	if (ret < 0)
		return (-1);
	else if (ret == 0 && str[fd] == NULL)
	{
		*line = NULL;
		return (0);
	}
	else
	{
		len = 0;
		while (str[fd][len] != '\n' && str[fd][len] != '\0')
			len++;
		if (str[fd][len] == '\n')
			return (new_line_create(&str[fd], line, len));
		else
			return (end_line_create(&str[fd], line));
	}
}

/*
** The ret_ret function returns the value of the
** variable ret. We need to create a temporary string
** in a while loop. It goes into the while loop and
** stays there if the reading is not finished, or if
** it has not encountered a new line, as read would 
** return 0 when it has finished reading. A temp string
** is created to combine the data of *str and the buff.
** This temporary string will replace the stored data
** each iteration so that we can keep track of how much
** is read and delete the previous stored data. The
** *str is freed at each iteration because the data has
** already been stored and we don't want any memory leaks.
** The loop continues until it has either finished reading
** or it has found  a new line. It will then return the
** value of ret respectively, into the previous function,
** which will then be fed into the ret_result function.
*/

static int	ret_ret(int fd, char *buff, char **str)
{
	char	*temp;
	int		ret;

	ret = read(fd, buff, BUFF_SIZE);
	while (ret > 0)
	{
		buff[ret] = '\0';
		if (str[fd])
		{
			temp = ft_strjoin(str[fd], buff);
			if (!temp)
				return (-1);
			free(str[fd]);
			str[fd] = temp;
		}
		else
			str[fd] = ft_strdup(buff);
		if (ft_strchr(str[fd], '\n'))
			return (ret);
		ret = read(fd, buff, BUFF_SIZE);
	}
	return (ret);
}

/*
** The get_next_line function returns a line read from
** a file descriptor. In this part of the function, 
** the static variable **str is being used so that when
** the next time get_next_line is called, it remembers 
** the previous call. First we check errors, if so, the
** function returns (-1), meaning an error has occured.
** We then need to determine the ret value. This is the 
** varibale used which holds the returning value of the
** read function. To get the ret value, we feed it into
** the function ret_ret. That will in turn give us the 
** ret value to feed into the the next function
** ret_result.
*/

int	get_next_line(const int fd, char **line)
{
	static char	*str[FD_SIZE];
	char		buff[BUFF_SIZE + 1];
	int			ret;

	if (fd >= 0 && line && BUFF_SIZE > 0 && fd < FD_SIZE)
	{
		ret = ret_ret(fd, buff, str);
		return (ret_result(str, line, ret, fd));
	}
	return (-1);
}


int		ft_seekstr(const char **a, const char *b)
{
	const char	*str;
	int			len;

	str = *a;
	while (*b != '\0')
		if (*str++ != *b++)
			return (0);
	len = (str - *a);
	*a = str;
	return (len);
}

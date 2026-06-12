int is_integer(char *str)
{
	int i = 0;

	if (!str)
		return (0);

	if (str[0] == '-' || str[0] == '+')
		i++;

	if (str[i] == '\0')
		return (0);

	for (; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}

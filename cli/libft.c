#include "cli.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_len;
	size_t	i;
	size_t	j;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	total_len = ft_strlen(s1) + ft_strlen(s2);
	ptr = (char *)malloc(total_len * sizeof(char) + 1);
	if (!ptr)
		return (NULL);
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		ptr[i++] = s2[j++];
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strnchr(const char *str, int len, int c)
{
	if (!str)
		return (NULL);
	while (len--)
	{
		if (*str == (char)c)
			return ((char *)str);
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return (NULL);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*ptr;

	ptr = dest;
	if (src < dest && src + n > dest)
	{
		src = src + n - 1;
		dest = dest + n - 1;
		while (n-- > 0)
			*(char *)dest-- = *(char *)src--;
	}
	else
		return (ft_memcpy(dest, src, n));
	return (ptr);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*ptr;

	if (!dest && !src)
		return (NULL);
	ptr = dest;
	while (n-- > 0)
		*(char *)dest++ = *(char *)src++;
	return (ptr);
}

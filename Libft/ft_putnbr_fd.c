/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 11:32:46 by usuario           #+#    #+#             */
/*   Updated: 2025/10/20 17:33:06 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;
	long	nb;

	nb = n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb *= -1;
	}
	if (nb >= 10)
	{
		ft_putnbr_fd(nb / 10, fd);
	}
	c = (nb % 10) + '0';
	write(fd, &c, 1);
}
//#include <stdio.h>
//#include <fcntl.h>   // para open()
//#include <unistd.h>  // para write() y close()
//
//int	main(void)
//{
//	int	fd;
//
//	printf("==== TESTS ft_putnbr_fd ====\n\n");
//
//	// 1️⃣ Número positivo pequeño
//	printf("Esperado: 42\nTu salida:   ");
//	ft_putnbr_fd(42, 1);
//	write(1, "\n\n", 2);
//
//	// 2️⃣ Número negativo pequeño
//	printf("Esperado: -42\nTu salida:   ");
//	ft_putnbr_fd(-42, 1);
//	write(1, "\n\n", 2);
//
//	// 3️⃣ Cero
//	printf("Esperado: 0\nTu salida:   ");
//	ft_putnbr_fd(0, 1);
//	write(1, "\n\n", 2);
//
//	// 4️⃣ Número positivo largo
//	printf("Esperado: 123456789\nTu salida:   ");
//	ft_putnbr_fd(123456789, 1);
//	write(1, "\n\n", 2);
//
//	// 5️⃣ Número negativo largo
//	printf("Esperado: -987654321\nTu salida:   ");
//	ft_putnbr_fd(-987654321, 1);
//	write(1, "\n\n", 2);
//
//	// 6️⃣ INT_MIN y INT_MAX
//	printf("Esperado: -2147483648\nTu salida:   ");
//	ft_putnbr_fd(-2147483648, 1);
//	write(1, "\n\n", 2);
//
//	printf("Esperado: 2147483647\nTu salida:   ");
//	ft_putnbr_fd(2147483647, 1);
//	write(1, "\n\n", 2);
//
//	// 7️⃣ Escribir en un archivo
//	fd = open("test_putnbr.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
//	if (fd == -1)
//		return (1);
//	ft_putnbr_fd(1234, fd);
//	write(fd, "\n", 1);
//	ft_putnbr_fd(-5678, fd);
//	write(fd, "\n", 1);
//	close(fd);
//	printf("Se escribieron números en test_putnbr.txt ✅\n\n");
//
//	// 8️⃣ Escribir en salida de error (fd = 2)
//	write(1, "Salida de error (stderr): ", 27);
//	ft_putnbr_fd(999, 2);
//	write(2, "\n", 1);
//
//	printf("\n==============================\n");
//	return (0);
//}

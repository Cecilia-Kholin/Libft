/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 11:32:46 by usuario           #+#    #+#             */
/*   Updated: 2025/10/20 16:46:00 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Existen 3 descriptores especiales que corresponden a los flujos de entrada, salida y error del
//programa. Puedes encontrarlos en las macros STDIN_FILENO, STDOUT_FILENO y STDERR_FILENO.
//STDIN_FILENO (0): Entrada estándar (generalmente el teclado).
//STDOUT_FILENO (1): Salida estándar (generalmente la pantalla).
//STDERR_FILENO (2): Salida de error estándar (también la pantalla).
#include "libft.h"

void ft_putchar_fd(char c, int fd)
{
    write(fd, &c, 1);
}
//
//#include <stdio.h>
//#include <fcntl.h>  // open()
//#include <unistd.h> // close()
//
//int	main(void)
//{
//	int	fd;
//
//	printf("==== TESTS ft_putchar_fd ====\n\n");
//
//	// 1 Escribir en la terminal (fd = 1)
//	ft_putchar_fd('A', 1);
//	ft_putchar_fd('\n', 1);
//
//	// 2 Escribir en la salida de error (fd = 2)
//	ft_putchar_fd('E', 2);
//	ft_putchar_fd('\n', 2);
//
//	// 3 Escribir en un archivo
//	fd = open("test_char.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
//    //Flag	Significado
//    //O_WRONLY	Abrir solo para escribir (no lectura).
//    //O_CREAT	Si el archivo no existe, créalo.
//    //O_TRUNC	Si el archivo ya existe, borra su contenido anterior (deja el archivo vacío).
//	if (fd == -1)
//		return (1);
//	ft_putchar_fd('F', fd);
//	ft_putchar_fd('A', fd);
//	ft_putchar_fd('N', fd);
//	ft_putchar_fd('N', fd);
//	ft_putchar_fd('Y', fd);
//	ft_putchar_fd('\n', fd);
//	close(fd);
//	printf("Se escribió 'FANNY' en test_char.txt ✅\n\n");
//
//	printf("==============================\n");
//	return (0);
//}

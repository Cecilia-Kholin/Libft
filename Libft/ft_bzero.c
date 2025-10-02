/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:28:32 by maricamp          #+#    #+#             */
/*   Updated: 2025/10/02 14:14:51 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//n → cuántos bytes quieres poner a cero.

//*: Este es el operador de desreferencia. 
//Accede al valor del dato que se encuentra en la dirección de memoria 
//resultante del paso anterior. En este caso, como se ha convertido a char*,
//el * obtiene el carácter almacenado en esa posición de memoria.
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		*((char*)s + i) = 0;
		i++;
	}
}
 #include <stdio.h> 
int main()
{
    printf("=== TESTS bzero ===\n");

    // 1) Cadena: borrar los 5 primeros bytes
    char str1[12] = "holaquetal";
    printf("1) Antes: \"%s\"\n", str1);
    bzero(str1, 5);   // pone 'h','o','l','a','q' -> todos a 0
    printf("1) Después: \"%s\"\n", str1);
    // Al poner '\0' en el medio, la cadena se corta

    // 2) Array de enteros
    int arr[5] = {1, 2, 3, 4, 5};
    printf("\n2) Antes: ");
    for (int i = 0; i < 5; i++) printf("%d ", arr[i]);
    printf("\n");
    bzero(arr, sizeof(arr)); // pone todos los bytes a 0
    printf("2) Después: ");
    for (int i = 0; i < 5; i++) printf("%d ", arr[i]);
    printf("\n");

    // 3) Struct inicializada con valores
    struct { int x; char y; double z; } st = {42, 'A', 3.14};
    printf("\n3) Antes: x=%d, y=%c, z=%f\n", st.x, st.y, st.z);
    bzero(&st, sizeof(st));  // reset total
    printf("3) Después: x=%d, y=%d, z=%f\n", st.x, st.y, st.z);
    // y se imprime como número porque ya no es un char válido

    // 4) Comparación bzero vs memset
    char s2[6] = "abcde";
    char s3[6] = "abcde";
    bzero(s2, 6);
    memset(s3, 0, 6);
    printf("\n4) bzero -> \"%s\"\n", s2);
    printf("4) memset -> \"%s\"\n", s3);

    return 0;
}

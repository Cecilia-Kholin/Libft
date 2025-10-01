/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricamp <maricamp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 11:14:54 by maricamp          #+#    #+#             */
/*   Updated: 2025/10/01 12:54:27 by maricamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//si n es menor que len de dest no copia nada, solo se agura que acabe en \0
//la longitud total que tendría la cadena resultante si hubiera cabido entera en el buffer
//#include <stdio.h> 
#include "libft.h"

size_t ft_strlcat(char *dst, const char *src, size_t n)
{
    size_t i = 0; 
    size_t len_dst;
    size_t len_src;
    size_t len_dst_initial;

    len_dst_initial = ft_strlen(dst); //apunta al \0 de la cadena original
    len_src = ft_strlen(src);
    len_dst = len_dst_initial;
    //Como no se copia nada, la cadena dst queda inalterada. Sigue siendo la misma que antes de la llamada.
    if (len_dst >= n)
    {
        // Retorna la longitud que *debería* tener la cadena si se hubiera concatenado
        return (n + len_src); // O (len_dst + len_src) si se asume que n es el tamaño real
    }
    while (len_dst < n - 1 && src[i] != '\0')
    {
        dst[len_dst++] = src[i++];
    }
    dst[len_dst] = '\0';
    return (len_dst_initial + len_src);
}
int main() {
    char src[] = "mundo";
    char dest[] = "hola";

    printf("src antes: %s\n", src);
    printf("dest antes: %s\n", dest);
    size_t ret = ft_strlcat(dest, src, 10);
    
    printf("src: %s\n", src);
    printf("dest: %s\n", dest);
    printf("ret: %zu\n", ret);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 12:52:08 by maricamp          #+#    #+#             */
/*   Updated: 2025/10/09 11:24:32 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//str[i] → accedes al carácter número i.
//&str[i] → obtienes un puntero a ese carácter.
//buscar la primera aparición de un carácter específico dentro de una cadena de texto
char *ft_strchr(const char *str, int c) //puedes leerlos (*str), recorrer la cadena, compararlos… pero no puedes hacer *str = 'x'
{
    size_t i;
    size_t str_len;

    i = 0;
    while(str[i])
    {
        if ((unsigned char)str[i] == c)
        {
            return ((char *)&str[i]);//devuelvo el puntero de donde esta c
            //el valor que entra es un const char, para poder usarlo se debe pasar a un puntero char* normal
        }
        i++;
    }
    if (c == '\0')
    {
        return ((char *)&str[i]);
    }
    return (NULL);
}
/* #include <stdio.h> 

int main(void)
{
    char    *resultado;
    const char    *str;

    str = "hola mundo";
    resultado = ft_strchr(str, '3');

    printf("Resultado: %s\n", resultado);
    return 0;
} */
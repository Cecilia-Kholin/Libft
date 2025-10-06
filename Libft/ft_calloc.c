/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 10:36:48 by maricamp          #+#    #+#             */
/*   Updated: 2025/10/06 15:04:40 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//gcc menser calloc
#include <stdio.h> 

#include "libft.h"

void *ft_calloc(size_t number, size_t size)
{
    void    *a;
    if (size != 0 && number > SIZE_MAX / size) //para que la multiplicacioin no se desborde
        return NULL;     
    //reserva memoria y lo pone a 0 number*size
    a = malloc(number * size); //para reservar los bytes totales del calloc
    //Devuelve un puntero al inicio del bloque (tipo void *)
    //void	*ft_memset(void *str, int c, size_t n)
    ft_memset(a, 0, number * size);
    return (a);
}

/* ---- helpers test ---- */
static int is_zeroed(const void *p, size_t n)
{
	const unsigned char *u = (const unsigned char *)p;
	for (size_t i = 0; i < n; i++)
		if (u[i] != 0) return 0;
	return 1;
}

static void print_ok(const char *name, int ok)
{
	printf("%s: %s\n", name, ok ? "OK" : "FAIL");
}

/* ---- main con pruebas rápidas ---- */
int main(void)
{
	int ok;

	/* 1) Vector de int → todo a 0 */
	{
		size_t n = 5;
		int *v = ft_calloc(n, sizeof *v);
		ok = (v != NULL) && is_zeroed(v, n * sizeof *v);
		print_ok("ints zeroed", ok);
		free(v);
	}

	/* 2) number*size se respeta (bug típico: usar 'number' en memset) */
	{
		size_t number = 5, size = 4; /* 20 bytes */
		unsigned char *u = ft_calloc(number, size);
		ok = (u != NULL) && is_zeroed(u, number * size);
		print_ok("number*size zeroed", ok);
		free(u);
	}

	/* 3) nmemb=0 y size=0 (cualquiera de los dos): estándar permite NULL o puntero liberable */
	{
		void *p1 = ft_calloc(0, sizeof(int));
		print_ok("nmemb=0 (NULL o puntero)", 1);
		free(p1); /* free(NULL) es no-op, y si no es NULL también debe ser liberable */

		void *p2 = ft_calloc(10, 0);
		print_ok("size=0 (NULL o puntero)", 1);
		free(p2);
	}

	/* 4) Overflow detectado → NULL */
	{
		size_t nmemb = SIZE_MAX / 16 + 1;
		void *p = ft_calloc(nmemb, 16);
		print_ok("overflow → NULL", p == NULL);
		free(p);
	}

	/* 5) Escribo después y compruebo que no crashea / mantiene datos */
	{
		size_t n = 64;
		unsigned char *u = ft_calloc(n, 1);
		ok = (u != NULL);
		if (ok) {
			for (size_t i = 0; i < n; i++) u[i] = (unsigned char)i;
			for (size_t i = 0; i < n; i++) if (u[i] != (unsigned char)i) { ok = 0; break; }
		}
		print_ok("write/read after calloc", ok);
		free(u);
	}

	return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 10:36:48 by maricamp          #+#    #+#             */
/*   Updated: 2025/10/06 15:42:31 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//crea una copia nueva de una cadena usando memoria dinámica.
/* Calcula la longitud de s (hasta '\0').
Reserva len + 1 bytes con malloc.
Copia los caracteres y añade el '\0' final.
Devuelve un puntero a la copia. Si falla la reserva → NULL. */
#include "libft.h"

char *ft_strdup(const char *string)
{
    size_t size;
    size_t i;
    char *copy;

    i = 0; 
    //calculamos la longitud
    size = ft_strlen(string);
    //reservamos esa cantidad para hacer la copia, + 1 para el \0
    copy = malloc(size + 1); //devuelve un puntero
    if (!copy)
		return (NULL);
    //hacemos la copia del string al return *copy
    while(i < size)
    {
        copy[i] = string[i];
        i++;
    }
    copy[i] = '\0';
    return (copy);
    
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>   // strlen, memcmp, (opcional) strdup


/* ===== infra de test ===== */
static int tests_run = 0, tests_fail = 0;

#define EXPECT_TRUE(cond, msg) do {                   \
    tests_run++;                                      \
    if (!(cond)) {                                    \
        tests_fail++;                                 \
        printf("❌ FAIL: %s (line %d)\n", msg, __LINE__); \
    }                                                 \
} while (0)

static void print_summary(void) {
    printf("\n==== SUMMARY ====\n");
    printf("Tests run : %d\n", tests_run);
    printf("Failures  : %d\n", tests_fail);
    printf("Result    : %s\n", tests_fail ? "❌ FAIL" : "✅ ALL PASS");
}

/* ===== casos de prueba ===== */
static void case_basic(const char *src) {
    char *dup = ft_strdup(src);
    EXPECT_TRUE(dup != NULL, "ft_strdup devuelve puntero no-NULL");
    if (!dup) return;

    size_t len = strlen(src);
    /* contenido idéntico + '\0' final */
    EXPECT_TRUE(strlen(dup) == len, "longitud igual a la del original");
    EXPECT_TRUE(memcmp(dup, src, len + 1) == 0, "contenido + '\\0' idénticos");

    /* puntero diferente */
    EXPECT_TRUE(dup != src, "puntero distinto al original");

    /* independencia: modificar copia no cambia original (usar fuente mutable) */
    if (len > 0) {
        char *sys = strdup(src); /* solo para comprobar referencia, opcional */
        dup[0] = (dup[0] >= 'a' && dup[0] <= 'z') ? (dup[0] - 'a' + 'A') : dup[0];
        if (sys) {
            EXPECT_TRUE(strcmp(sys, src) == 0, "original sigue igual (comparación referencia)");
            free(sys);
        }
    }

#ifdef COMPARE_SYSTEM_STRDUP
    /* comparación directa con strdup del sistema (opcional) */
    char *std = strdup(src);
    EXPECT_TRUE(std != NULL, "strdup del sistema no-NULL");
    if (std) {
        EXPECT_TRUE(strlen(std) == strlen(dup), "mismo strlen que strdup del sistema");
        EXPECT_TRUE(strcmp(std, dup) == 0, "mismo contenido que strdup del sistema");
        free(std);
    }
#endif

    free(dup);
}

static void test_empty(void) {
    case_basic("");
}

static void test_short(void) {
    case_basic("hola");
}

static void test_spaces(void) {
    case_basic("  con  espacios   ");
}

static void test_long(void) {
    const char *longstr =
        "viaje antes que destino — cadena más larga para comprobar copia correcta y '\\0'";
    case_basic(longstr);
}

static void test_mutable_source_independence(void) {
    /* Demuestra que al modificar la copia, el original (array local) no cambia */
    char src[] = "peras";
    char *dup = ft_strdup(src);
    EXPECT_TRUE(dup != NULL, "dup no-NULL en fuente mutable");
    if (!dup) return;

    dup[0] = 'P';
    EXPECT_TRUE(strcmp(src, "peras") == 0, "original mutable NO cambia");
    EXPECT_TRUE(strcmp(dup, "Peras") == 0, "copia modificada OK");

    free(dup);
}

int main(void) {
    test_empty();
    test_short();
    test_spaces();
    test_long();
    test_mutable_source_independence();

    print_summary();
    return tests_fail ? 1 : 0;
}


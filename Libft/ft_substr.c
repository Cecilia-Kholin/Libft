/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 10:36:48 by maricamp          #+#    #+#             */
/*   Updated: 2025/10/20 11:51:15 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_substr(char const *s, unsigned int start,size_t len)
{
    //espacio de memoria reservado
    size_t len_str;
    size_t total;
    size_t j;
    char *reservado;

    len_str = 0;
    j = 0;
    if (!s)
        return (NULL);
    while(s[len_str])
    {
        len_str++;
    }
    //Si start esta fuera del limite cadena vacia
    if ((size_t)start >= len_str)
    {   
        //guardar memoria para la cadena vacia
        reservado = malloc(1);
        if (!reservado) return NULL;
        reservado[0] = '\0';
        return(reservado);
    }
    total = len_str - (size_t)start;
    if (total > len)
		total = len;
    
    reservado = (char *)malloc(total + 1); //puntero al espacio de memoria y \0
    if (!reservado) return NULL;
    //poner el puntero donde diga start
    while(j < total)
    {
        reservado[j] = s[(size_t)start + j];
        j++;
    }
    reservado[j] = '\0';
    return(reservado);
}
//EJEMPLOS
/* ft_substr("hola mundo", 0, 4)   => "hola"
ft_substr("hola mundo", 5, 5)   => "mundo"
ft_substr("hola mundo", 5, 100) => "mundo"    
ft_substr("hola", 10, 3)        => ""      */     // start fuera => cadena vacía
/* Infra mínima de tests */
/* test_ft_substr.c */
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>   /* solo para strcmp en tests, tu ft_substr NO debe usarla */
//
//
///* infra mínima de tests */
//static int tests_run = 0, tests_fail = 0;
//#define EXPECT_TRUE(cond, msg) do {                             \
//    tests_run++;                                                \
//    if (!(cond)) {                                              \
//        tests_fail++;                                           \
//        printf("❌ FAIL: %s (line %d)\n", msg, __LINE__);        \
//    }                                                           \
//} while (0)
//
//static void check_eq_str(const char *got, const char *exp, const char *msg) {
//    if (!got && !exp) { EXPECT_TRUE(1, msg); return; }
//    if (!got || !exp)  { EXPECT_TRUE(0, msg); return; }
//    EXPECT_TRUE(strcmp(got, exp) == 0, msg);
//}
//
//static void summary(void) {
//    printf("\n==== SUMMARY ====\n");
//    printf("Tests run : %d\n", tests_run);
//    printf("Failures  : %d\n", tests_fail);
//    printf("Result    : %s\n", tests_fail ? "❌ FAIL" : "✅ ALL PASS");
//}
//
///* --------- casos ---------- */
//
//static void t_begin(void) {
//    const char *s = "hola mundo";
//    char *sub = ft_substr(s, 0, 4);   /* "hola" */
//    EXPECT_TRUE(sub != NULL, "alloc not NULL");
//    check_eq_str(sub, "hola", "substr(0,4) == \"hola\"");
//    free(sub);
//}
//
//static void t_middle_exact(void) {
//    const char *s = "hola mundo";
//    char *sub = ft_substr(s, 5, 5);   /* "mundo" */
//    EXPECT_TRUE(sub != NULL, "alloc not NULL");
//    check_eq_str(sub, "mundo", "substr(5,5) == \"mundo\"");
//    free(sub);
//}
//
//static void t_len_caps_to_tail(void) {
//    const char *s = "hola mundo";
//    char *sub = ft_substr(s, 6, 99);  /* desde 'u' hasta fin => "undo" */
//    EXPECT_TRUE(sub != NULL, "alloc not NULL");
//    check_eq_str(sub, "undo", "substr(6,99) == \"undo\"");
//    free(sub);
//}
//
//static void t_start_outside(void) {
//    const char *s = "hola";
//    char *sub = ft_substr(s, 10, 3);  /* start fuera => "" dinámica */
//    EXPECT_TRUE(sub != NULL, "alloc not NULL (empty)");
//    check_eq_str(sub, "", "substr(10,3) == \"\"");
//    free(sub);
//}
//
//static void t_len_zero(void) {
//    const char *s = "hola";
//    char *sub = ft_substr(s, 1, 0);   /* len=0 => "" */
//    EXPECT_TRUE(sub != NULL, "alloc not NULL (len=0)");
//    check_eq_str(sub, "", "substr(1,0) == \"\"");
//    free(sub);
//}
//
//static void t_empty_source(void) {
//    const char *s = "";
//    char *a = ft_substr(s, 0, 5);     /* "" */
//    char *b = ft_substr(s, 3, 1);     /* "" */
//    EXPECT_TRUE(a != NULL && b != NULL, "alloc not NULL (empty source)");
//    check_eq_str(a, "", "substr(\"\",0,5) == \"\"");
//    check_eq_str(b, "", "substr(\"\",3,1) == \"\"");
//    free(a); free(b);
//}
//
//static void t_border_exact_end(void) {
//    const char *s = "ABCDE";
//    char *sub = ft_substr(s, 2, 3);   /* "CDE" exacto hasta fin */
//    EXPECT_TRUE(sub != NULL, "alloc not NULL");
//    check_eq_str(sub, "CDE", "substr(2,3) == \"CDE\"");
//    free(sub);
//}
//
//static void t_internal_small_len(void) {
//    const char *s = "viaje antes que destino";
//    char *sub = ft_substr(s, 6, 5);   /* "antes" */
//    EXPECT_TRUE(sub != NULL, "alloc not NULL");
//    check_eq_str(sub, "antes", "substr(6,5) == \"antes\"");
//    free(sub);
//}
//
///* si tu implementación devuelve NULL cuando s == NULL */
//static void t_null_input_behavior(void) {
//    char *sub = ft_substr(NULL, 0, 3);
//    EXPECT_TRUE(sub == NULL, "ft_substr(NULL,...) == NULL");
//}
//
//int main(void) {
//    t_begin();
//    t_middle_exact();
//    t_len_caps_to_tail();
//    t_start_outside();
//    t_len_zero();
//    t_empty_source();
//    t_border_exact_end();
//    t_internal_small_len();
//    t_null_input_behavior();
//
//    summary();
//    return tests_fail ? 1 : 0;
//}

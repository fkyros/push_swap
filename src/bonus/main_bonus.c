/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:47:50 by gade-oli          #+#    #+#             */
/*   Updated: 2024/10/08 18:02:25 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

//idea:
	//leer numeros por argv
	//si input erroneo (no int, > o < que int, dupicados) -> "Error\n"
	//crear stack_a con numeros
	//ordenar numeros segun lo que lea por STDIN
	//si leo instruccion mal formada -> "Error\n"
	//si instrucciones validas y ordenan, y stack_b vacio -> "OK\n"
	//si no ordena o stack_b con cosas -> "KO\n"

int	main(int argc, char **argv)
{
	t_list		*stack_a;
	t_list		*stack_b;
	
	stack_a = parse_numbers(argc, argv);
	stack_b = NULL;
	//comenzar a leer opor STDIN 
	return (0);
}	

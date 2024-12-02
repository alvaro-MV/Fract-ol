/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvmoral <alvmoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:41:35 by alvmoral          #+#    #+#             */
/*   Updated: 2024/12/02 19:49:20 by alvmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTALS_H
# define FRACTALS_H

# include "fractol.h"

int	scape_mandelbrot(int i, int j, void *vfract);
int	scape_julia(int i, int j, void *vfract);
int	scape_burning_ship(int i, int j, void *vfract);
int	scape_lyapunov(int i, int j, void *vfract);

#endif

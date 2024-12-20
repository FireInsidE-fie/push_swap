/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:56:13 by estettle          #+#    #+#             */
/*   Updated: 2024/09/26 10:56:14 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_toupper()
 * returns the c character in uppercase
*/
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

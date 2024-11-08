/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:56:09 by estettle          #+#    #+#             */
/*   Updated: 2024/09/26 10:56:10 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_tolower()
 * returns the c character in lowercase
*/
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

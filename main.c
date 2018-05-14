/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 18:35:51 by rkrief            #+#    #+#             */
/*   Updated: 2018/05/14 18:40:39 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_parsing(char *str);

int main()
{
	char *str="#frjfhjkdfsfndfkv\n.name'dsfadf'\n#fsdlfdgfdds\n.comment'fdsfsdf'";

	ft_parsing(str);
	return (0);
}

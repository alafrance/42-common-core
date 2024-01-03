/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_bmp.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 09:50:44 by alafranc          #+#    #+#             */
/*   Updated: 2021/02/24 09:50:46 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_BMP_H
# define STRUCT_BMP_H

typedef struct			s_fileheader
{
	int					file_size;
	int					header_size;
	int					bytes_size;
	int					image_size;
	int					planes;
	int					bytes_number;
	char				header[54];
}						t_fileheader;

#endif

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alafranc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/17 14:19:53 by alafranc          #+#    #+#              #
#    Updated: 2021/01/05 16:32:43 by alafranc         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

FROM debian:buster

RUN apt-get update && apt-get install -y openssl && apt-get install -y sudo && apt-get install -y nginx && sudo apt install -y mariadb-server && sudo apt install -y php-fpm php-mysql

COPY srcs/ . 

EXPOSE 80 443

ENTRYPOINT ["bash", "script.sh"]

FROM alpine:3.12

COPY ./srcs/script.sh /script.sh


RUN apk -U upgrade && \
apk add --no-cache \
openrc mysql mysql-client && \
rm -f /var/cache/apk/*

RUN apk add telegraf --repository http://dl-3.alpinelinux.org/alpine/edge/community/ --allow-untrusted --no-cache

COPY srcs/telegraf.conf /etc/telegraf/telegraf.conf
COPY ./srcs/mariadb-server.cnf /etc/my.cnf.d/

EXPOSE 3306

ENTRYPOINT [ "sh", "script.sh"]
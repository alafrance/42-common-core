FROM alpine:3.12

RUN apk update && \
    apk add nginx openssl openrc wget && \
    apk add php7 php7-fpm php7-opcache php7-gd php7-mysqli php7-zlib php7-curl php7-mbstring php7-json php7-session

RUN apk add telegraf --repository http://dl-3.alpinelinux.org/alpine/edge/community/ --allow-untrusted --no-cache

COPY srcs/telegraf.conf /etc/telegraf/telegraf.conf
COPY srcs/ .

EXPOSE 5000

ENTRYPOINT ["sh", "script.sh"]
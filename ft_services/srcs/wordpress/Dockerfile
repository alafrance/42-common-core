FROM alpine:3.12

RUN apk update && \
    apk add nginx openssl openrc php7 php7-fpm php7-mysqli php7-mbstring php7-json php7-session php-phar curl wget && \
    curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
    chmod +x wp-cli.phar && \
    mv wp-cli.phar /usr/local/bin/wp

RUN apk add telegraf --repository http://dl-3.alpinelinux.org/alpine/edge/community/ --allow-untrusted --no-cache 

COPY srcs/telegraf.conf /etc/telegraf/telegraf.conf
COPY srcs/ .

EXPOSE 5050

ENTRYPOINT ["sh", "script.sh"]
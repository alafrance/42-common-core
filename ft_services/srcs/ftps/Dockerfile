FROM alpine:3.12

RUN apk update && apk add pure-ftpd --repository http://dl-3.alpinelinux.org/alpine/edge/testing/ --allow-untrusted --no-cache openssl && \
    apk add telegraf --repository http://dl-3.alpinelinux.org/alpine/edge/community/ --allow-untrusted --no-cache

COPY srcs/telegraf.conf /etc/telegraf/telegraf.conf
COPY srcs/ .

EXPOSE 21

ENTRYPOINT ["sh", "script.sh"]

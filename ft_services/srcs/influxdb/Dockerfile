FROM alpine:3.12

RUN apk update && apk add openrc --no-cache influxdb telegraf --repository http://dl-3.alpinelinux.org/alpine/edge/community/ --allow-untrusted --no-cache

COPY srcs/telegraf.conf /etc/telegraf/telegraf.conf

EXPOSE 8086

CMD (telegraf conf &) && influxd run -config /etc/influxdb.conf
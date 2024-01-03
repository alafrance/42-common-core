# Nginx
mv ./nginx.conf /etc/nginx/
mkdir /www
adduser -D -g 'www' www
chown -R www:www /var/lib/nginx
chown -R www:www /www
mv ./index.html /www

# SSL
openssl req -x509 -nodes -days 365 -subj "/C=FR/ST=FR/L=FR/O=42/CN=ft_services" -newkey rsa:2048 -keyout /etc/ssl/private/nginx-selfsigned.key -out /etc/ssl/certs/nginx-selfsigned.crt

# Starting
openrc sysinit
rc-service nginx start
telegraf conf

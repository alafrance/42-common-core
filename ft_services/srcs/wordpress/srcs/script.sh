apk add wget
wget http://wordpress.org/latest.tar.gz
tar -xzvf latest.tar.gz
rm latest.tar.gz
mv wordpress /usr/share/webapps
mv ./nginx.conf /etc/nginx/
mv wp-config.php /usr/share/webapps
adduser -D -g 'www' www
chown -R www:www /var/lib/nginx
chown -R www:www /www/.
openssl req -x509 -nodes -days 365 -subj "/C=FR/ST=FR/L=FR/O=42/CN=ft_services" -newkey rsa:2048 -keyout /etc/ssl/private/nginx-selfsigned.key -out /etc/ssl/certs/nginx-selfsigned.crt
sh user.sh

# Starting
openrc sysinit
rc-service nginx start
rc-service php-fpm7 restart
telegraf conf
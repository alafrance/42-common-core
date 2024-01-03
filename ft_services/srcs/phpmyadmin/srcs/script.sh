#install phpmyadmin
wget http://files.directadmin.com/services/all/phpMyAdmin/phpMyAdmin-5.0.4-all-languages.tar.gz
tar -xzvf phpMyAdmin-5.0.4-all-languages.tar.gz
rm phpMyAdmin-5.0.4-all-languages.tar.gz
mv phpMyAdmin-5.0.4-all-languages phpmyadmin

#Configure phpmyadmin
mkdir usr/share/webapps
chmod 777 phpmyadmin
cd /usr/share/webapps
chmod -R 777 /usr/share/webapps
mv /config.inc.php /phpmyadmin
mv /phpmyadmin /usr/share/webapps/phpmyadmin
ln -s /usr/share/webapps/phpmyadmin/ /var/www/localhost/htdocs/phpmyadmin ; \

#Configure nginx
mv /nginx.conf /etc/nginx/
adduser -D -g 'www' www
chown -R www:www /var/lib/nginx
chown -R www:www /www/.
openssl req -x509 -nodes -days 365 -subj "/C=FR/ST=FR/L=FR/O=42/CN=ft_services" -newkey rsa:2048 -keyout /etc/ssl/private/nginx-selfsigned.key -out /etc/ssl/certs/nginx-selfsigned.crt

# Starting
openrc sysinit
rc-service nginx start
rc-service php-fpm7 start

telegraf conf
#!/bin/bash

#SERVICE LAUNCH
service php7.3-fpm start
service nginx start

#SSL CERTIFICATE
sudo openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/nginx-selfsigned.key -out /etc/ssl/certs/nginx-selfsigned.crt
sudo openssl dhparam -out /etc/nginx/dhparam.pem 2048
sudo mv self-signed.conf /etc/nginx/snippets/
sudo mv ssl-params.conf /etc/nginx/snippets/
sudo cp /nginx_params/default /etc/nginx/sites-available/default

#MYSQL
service mysql start
sudo mysql_secure_installation
mysql -u root  < mysql.sql

#PUT WORDPRESS
sudo mv wordpress/ /var/www/html/

#PUT PphMyAdmin
sudo mv phpMyAdmin /var/www/html/

#DISPLAY LOGS
service nginx restart
tail -f /var/log/nginx/access.log /var/log/nginx/error.log

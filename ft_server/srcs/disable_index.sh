#!bin/bash

if cmp -s /nginx_params/default /etc/nginx/sites-available/default
then
	cp /nginx_params/indexoff /etc/nginx/sites-available/default
else
	cp /nginx_params/default /etc/nginx/sites-available/default
fi
service nginx restart

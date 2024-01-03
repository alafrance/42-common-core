# ft_server
I learn to create my first server with Docker

# For launch the server :
docker build -t ft_server .  
docker run -p 80:80 -p 443:443 -it --rm --name ft_server_ct ft_server

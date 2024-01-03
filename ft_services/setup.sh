function fill_template()
{
    sed "s/MINIKUBEIP/$IP_MINIKUBE/g" srcs/metallb/template_metallb.yaml > srcs/metallb/metallb.yaml
    sed "s/MINIKUBEIP/$IP_MINIKUBE/g" srcs/ftps/srcs/script_template.sh > srcs/ftps/srcs/script.sh
    sed "s/MINIKUBEIP/$IP_MINIKUBE/g" srcs/wordpress/srcs/user_template.sh > srcs/wordpress/srcs/user.sh

}

function setup_metallb()
{
    kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.5/manifests/namespace.yaml
    kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.5/manifests/metallb.yaml
    kubectl create secret generic -n metallb-system memberlist --from-literal=secretkey="$(openssl rand -base64 128)"
    kubectl apply -f ./srcs/metallb/metallb.yaml
    kubectl apply -f ./srcs/metallb/database_pvc.yaml
}

function setup()
{
    eval $(minikube docker-env)
    docker build -t my-$1 ./srcs/$1/
    kubectl apply -f ./srcs/$1/config.yaml
}

function launch()
{
    minikube delete
    minikube start --driver=virtualbox
    IP_MINIKUBE=$(minikube ip)
    fill_template
    setup_metallb
    setup influxdb
    setup mysql
    setup nginx
    setup ftps
    setup wordpress
    setup phpmyadmin
    setup grafana
    minikube dashboard
}

launch
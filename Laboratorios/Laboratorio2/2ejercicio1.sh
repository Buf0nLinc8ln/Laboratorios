#!/bin/bash

usuario=$1
grupo=$2
ruta=$3


> ar.log

ls -l $ruta # para pruebas

# Verifica que el script se ejecuta en root con el uso de "id -u"

if [ "$(id -u)" -ne 0 ]; then
    ls -l $ruta # para verificar
    echo "Error: Este script debe ejecutarse como root."
    exit 
fi

# se verifica que la ruta exista, sino se redirige mensaje a "ar.log"

if  [ ! -e "$ruta" ]; then
     echo "La ruta al archivo '$ruta' no existe." >> ar.log
     exit
fi



if getent group "$grupo"; then
    echo "El grupo '$grupo' ya existe." >> ar.log
else 
    addgroup "$grupo"
fi


if id "$usuario"; then
        echo "El usuario '$usuario' ya existe." >> ar.log
        usermod -m -G "$grupo" "$usuario"
else
    adduser $usuario
fi



chown $usuario:$grupo $ruta

chmod u+rwx,g=r,o= $ruta 

ls -l $ruta
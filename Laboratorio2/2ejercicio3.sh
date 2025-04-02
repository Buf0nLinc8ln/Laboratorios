#!/bin/bash

> ar.log

directorio="/home/lincoln/Desktop/scripts"

inotifywait -m -e modify,create,delete "$directorio" | while read path caso archivo
do

    if [[ "$archivo" != "ar.log" ]]; then
        case $caso in
            MODIFY)
                echo "$(date +%e/%m/%Y\(%H:%M\)): Se modifico el archivo '$archivo' en $path" >> ar.log
                ;;
            CREATE)
                echo "$(date +%e/%m/%Y\(%H:%M\)): Se creo el archivo '$archivo' en $path" >> ar.log
                ;;
            DELETE)
                echo "$(date +%e/%m/%Y\(%H:%M\)): Se elimino el archivo '$archivo' en $path" >> ar.log
                ;;
        esac
    fi
done


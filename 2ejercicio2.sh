#!/bin/bash

proceso=$1
# pid=$1 para pruebas
intentos=0 # se crea un limite de muestras

> ar.log #para pruebas

# funcion para obtener los segundos en tiempo real, se convierten los minutos a segundos para tener un margen de datos de una hora como mucho

segundos_time_real() {
    echo $(( (10#$(date +%M) * 60) + 10#$(date +%S) ))  # se usa 10# para convertir los numeros a base decimal y no tener problema con numeros que empiecen con 0.

}

# se inicia por asi decir el contantor de segundos

inicio=$(segundos_time_real)
while [ "$intentos" -lt 10 ];do # se condicona el while a un limite de intentos para que no sea infinito y asi graficar

    # se hace el calculo de los segundos transcurridos como dato para el eje x en la grafica
    # Con el uso de ps se extrae el uso de memoria y cpu, con "--no-headers" se elimina el emcabesado default de ps.
    # se hace el reporte en el archivo "ar.log"
    echo "$(($(segundos_time_real) - $inicio)) $(ps -C "$proceso" -o %cpu,%mem --no-headers)" >> ar.log 
    intentos=$((intentos + 1))
    sleep 2 # aqui se puede cambiar para asi no obtener datos constantes con respecto el tiempo

done


# 1. "cat > "grafica.gnuplot" <<EOF"; con el uso de "cat" se escribe en el archivo de configuracion de gnuplot "grafica.gnuplot". "<<EOF" marca el incio.
# 2. "set terminal jpeg" escoge el formato de salida de la imagen, en este caso es jpeg.
# 3. "set output "grafica.jpeg"" se guarda la imagen.
# 4. "set title "Uso de CPU y RAM"" se nombra el titulo de la grafica.
# 5. "set xlabel "Tiempo (s)"" se nombra el eje x.
# 6. "set ylabel "Uso CPU (%)"" y set y2label "Uso RAM (%)" nombran el eje y.
# 7. "set ytics nomirror y set y2tics" permite que los ejes de "y" CPU y RAM tengan escalas separadas.
# 8. "set grid" cuadricula la grafica.
# 9. "plot" se usa para extraer los datos guardados en columnas en "ar.log" y "axes x1y2" indica que esos datos son para que el segundo eje de "y".

cat > "grafica.gnuplot" <<EOF 
set terminal jpeg
set output "grafica.jpeg" 
set title "Uso de CPU y RAM"
set xlabel "Tiempo (s)"
set ylabel "Uso CPU (%)"
set y2label "Uso RAM (%)"
set ytics nomirror
set y2tics
set grid
plot "ar.log" using 1:2 title "CPU" with lines, \
     "ar.log" using 1:3 title "RAM" with lines axes x1y2
EOF # marca el final.


gnuplot "grafica.gnuplot" # se ejecuta gnuplot con el archivo de configuracion.
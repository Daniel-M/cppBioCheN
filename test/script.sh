g++ chemical.cpp -o chemical
./chemical > resultados.txt
awk '{print $1,$2}' resultados.txt > var1.txt
awk '{print $1,$3}' resultados.txt > var2.txt
awk '{print $1,$4}' resultados.txt > var3.txt
awk '{print $1,$5}' resultados.txt > var4.txt
awk '{print $1,$6}' resultados.txt > var5.txt
gnuplot -p -e "plot 'var1.txt' w lp,'var2.txt' w lp,'var3.txt' w lp,'var4.txt' w lp,'var5.txt' w lp"

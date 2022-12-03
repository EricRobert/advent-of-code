cd $1

echo "---" | cat tests - | while read args; read expected; read div; do
	./run $args | tee run.out
	result=$(cat run.out | tail -1)
	echo "$args" $(if [ "$result" = "$expected" ]; then echo "\e[1;32mOK\e[0m"; else echo "\e[1;31mshould be\e[0m $expected"; fi)
done

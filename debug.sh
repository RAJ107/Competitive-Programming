for((i=1; ;i++));
do
echo $i
./gen $i > int
diff -w <(./or < int) <(./br < int) || break
done

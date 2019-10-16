/* time cost: 0ms (100.00%) */
/* time complexity: O(n) */

# Read from the file file.txt and output the tenth line to stdout.

# cnt=0
# while read line && [ $cnt -le 10 ]; do
#   cnt=`expr $cnt + 1`
#   if [ $cnt -eq 10 ]; then
#     echo $line
#     exit 0
#   fi
# done < file.txt

sed -n '10p' file.txt
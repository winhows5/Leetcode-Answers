/* time cost: 4ms (56.95%) */
/* time complexity: O(n) */

# Read from the file words.txt and output the word frequency list to stdout.
cat words.txt | tr -s ' ' '\n' | sort -r | uniq -c | sort -r | awk '{ print $2, $1 }'
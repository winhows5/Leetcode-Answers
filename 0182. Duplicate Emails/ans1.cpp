/* time cost: 198ms (40.93%) */
/* time complexity: O(n) */
# Write your MySQL query statement below

# select distinct(p.Email) from Person p, Person q where p.Email = q.Email and p.Id != q.Id; 

select p.Email from Person p group by p.Email having count(p.Email) > 1;


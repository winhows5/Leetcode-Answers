/* time cost: 246ms (55.00%) */
/* time complexity: O(n) */
# Write your MySQL query statement below

# Write your MySQL query statement below
select Name as Customers from Customers c left join Orders o on c.Id = o.CustomerId 
where o.Id is null;
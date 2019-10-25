/* time cost: 658ms (76.09%) */
/* time complexity: O(n) */
# Write your MySQL query statement below

# Write your MySQL query statement below

select d.`Name` as `Department`, e.`Name` as `Employee`, e.`Salary` as `Salary` from 
`Department` d,
`Employee` e
where e.`DepartmentId` = d.`Id` 
and (select count(distinct(`Salary`)) from `Employee` where `Salary`>e.`Salary` and `DepartmentId`=d.`Id`) < 3;
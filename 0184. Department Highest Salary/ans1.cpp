/* time cost: 309ms (51.88%) */
/* time complexity: O(n) */
# Write your MySQL query statement below


select `Department`.`Name` as `Department`, `Employee`.`Name` as `Employee`, a.`MaxSal` as `Salary` from 
( select max(`Salary`) as `MaxSal`, `DepartmentId` from `Employee` group by `DepartmentId` ) a,
`Department`,
`Employee`
where a.`MaxSal` = `Employee`.`Salary` and a.`DepartmentId` = `Employee`.`DepartmentId` and a.`DepartmentId` = `Department`.`Id`;
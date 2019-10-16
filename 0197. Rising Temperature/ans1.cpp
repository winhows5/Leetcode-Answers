/* time cost: 419ms (14.92%) */
/* time complexity: O(n) */

# Write your MySQL query statement below

# select W.Id from Weather as W, Weather as A 
# where  DATE_SUB(W.RecordDate,INTERVAL 1 DAY)=A.RecordDate and W.Temperature>A.Temperature;

# select W.Id from Weather as W, Weather as A 
# where  TO_DAYS(W.RecordDate)=TO_DAYS(A.RecordDate)+1 and W.Temperature>A.Temperature;

select W.Id from Weather as W inner join Weather as A 
on DATE_SUB(W.RecordDate,INTERVAL 1 DAY)=A.RecordDate and W.Temperature>A.Temperature;
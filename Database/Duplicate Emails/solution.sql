/*
Write a SQL query to find all duplicate emails in a table named Person.
Create table If Not Exists Person (Id int, Email varchar(255))
Truncate table Person
insert into Person (Id, Email) values ('1', 'a@b.com')
insert into Person (Id, Email) values ('2', 'c@d.com')
insert into Person (Id, Email) values ('3', 'a@b.com')
+----+---------+
| Id | Email   |
+----+---------+
| 1  | a@b.com |
| 2  | c@d.com |
| 3  | a@b.com |
+----+---------+
For example, your query should return the following for the above table:

+---------+
| Email   |
+---------+
| a@b.com |
+---------+
Note: All emails are in lowercase.*/

# Write your MySQL query statement below
# SOLUTION 1

# SELECT Email
# FROM Person
# GROUP BY Email
# HAVING COUNT(EMail) > 1
 
# SOLUTION 2
SELECT Email 
FROM (
    SELECT Email, COUNT(Email) as number
    FROM Person
    GROUP BY Email    
) as STATISTIC
WHERE number > 1
;
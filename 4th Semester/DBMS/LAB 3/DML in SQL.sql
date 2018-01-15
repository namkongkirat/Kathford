CREATE DATABASE db_employee
USE db_employee

CREATE TABLE Employee(empid INT PRIMARY KEY, empname VARCHAR(30), post VARCHAR(15), salary FLOAT, deptno INT)

SELECT * FROM Employee

INSERT INTO Employee VALUES (1, 'Hari', 'Lecturer', 25000, 3)
INSERT INTO Employee VALUES (2, 'Ram', 'Receptionist', 24000, 3)
INSERT INTO Employee VALUES (3, 'Gita', 'Librarian', 15500, 2)
INSERT INTO Employee VALUES (4, 'Laxman', 'Lecturer', 20000, 2)
INSERT INTO Employee VALUES (5, 'Sita', 'Accountent', 23000, 1)
SELECT * FROM Employee

UPDATE Employee SET salary=5000 WHERE post='Lecturer'
SELECT * FROM Employee

SELECT empname, salary FROM Employee

DELETE FROM Employee WHERE post='Librarian'
SELECT * FROM Employee

SELECT * FROM Employee ORDER BY salary ASC

SELECT * FROM Employee ORDER BY salary DESC

SELECT DISTINCT deptno FROM Employee

UPDATE Employee SET salary=salary*1.25 WHERE post='Lecturer'

UPDATE Employee SET deptno=17 WHERE empname='Ram'

DELETE FROM Employee WHERE salary<20000

SELECT * FROM Employee WHERE empname LIKE 'R%'

SELECT * FROM Employee WHERE empname LIKE 'R%' or empname LIKE 'A%'

SELECT * FROM Employee WHERE empname LIKE 'R__'

SELECT * FROM Employee WHERE empname LIKE '%a_'

SELECT * FROM Employee WHERE empname LIKE '_[^a]%'



USE master

DROP DATABASE db_employee
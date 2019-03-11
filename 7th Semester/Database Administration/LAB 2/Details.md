# LAB 1

## Objective: To create users, objects to assign roles/privileges to users.

### 1. Create relation for the given schema:
    student(crn, name, email, mobile, parentname)
    department(deptid, dname, capacity)
    enroll(eid, crn, deptid,enrolldate)
    accounts(aid, crn, feepaid, totalfee, paydate)
### 2. Create views with following attributes
    i. name, mobile, email (student)
    ii. name, dname (student, department)
    iii. name, dname, enrolldata (student, department, enroll)
    iv. name, dname, feepaid (student, department, enroll, accounts)
### 3.Create users a, b, c, d

### 4. Grant users with following privilege.    
    a with select privilege
    b with insert privilege
    c with update preivilege
    d with delete preivilege

### 5. Cross verify the orivilege assigned.











# Lab 2

To create users, objects to assign reoles / privledges to users

## Task

1. Create relations for the given schema

```text
student (crn, name, email, mobile, studentname)
department (deptid, dname, capacity)
enroll (eid, crn, deptid, enrolldate)
account (aid, crn, feepaid, totalfee, paydate)
```

1. Create views with following attributes
   1. name, mobile, email (student)
   2. name, dname (student, deaprtment)
   3. name, dname, enrolldate (student, department, enroll)
   4. name, dname, feepaid (student, department, enroll, account)

2. Create users a, b, c, d

3. Grant users with following privledges

   - a with select privledge
   - b with insert privledge
   - c with update privledge
   - d with delete privledge

4. Cross verify the privleges assigned

## Notes

date format dd-mm-yyyy

## Outputs

```sql
create table student (
  crn number(5) primary key,
  sname varchar(25),
  email varchar(25),
  mobile varchar(15),
  studentname varchar(25)
);

create table department (
  deptid number(5) primary key,
  dname varchar(25) check (dname = upper(dname)),
  capacity number(2) check (capacity <= 48)
);

create table enroll (
  eid number(5) primary key,
  crn number(5),
  deptid number(5),
  enrolldate date,
  foreign key (crn) references student(crn),
  foreign key (deptid) references department(deptid)
);

create table account (
  aid number(5) primary key,
  crn number(5),
  feepaid number(10, 2),
  totalfee number(10, 2),
  paydate date,
  foreign key (crn) references student(crn)
);
```

```sql
create view view1 as
select sname as name, mobile, email
from student;

create view view2 as
select s.name as name, d.dname as dname
from student s, department d, enroll e
where s.crn = e.crn and d.deptid = e.deptid;

create view view3 as
select s.name as name, d.dname as dname, e.enrolldate as enrolldate
from student s, department d, enroll e
where s.crn = e.crn and d.deptid = e.deptid;

create view view4 as
select s.name as name, d.dname as dname, a.feepaid as feepaid
from student s, department d, enroll e, accounts a
where s.crn = e.crn and s.crn=a.crn and d.deptid = e.deptid;
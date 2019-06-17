# LAB 6

## TITLE: 
```Illustrate the storage oand retrieval of temporal data in Relational Database Management System```

## Queries
```sql
Create table std(
std_id number(3) primary key,
sname varchar(75),
age number(2)
);

Create table std_address(
stid number(3),
addr varchar(50),
vst date,
vet date,
foreign key(stid) references std(std_id)
);

Select s.std_id, s.sname, sa.addr from std s left join std_address sa on s.std_id = sa.stid and trunc(SYSDATE) between sa.vst and sa.vet;

```

# Lab 2
## Practise Database Views


## Task

1. Implement Ternary relationship and retrive data.
2. Insert multiple records using single statement.

teacher (id, name, contact)
book (id, title)
course (id, name)
teachers_books (course_id, teacher_id, book_id, desc)


### Syntax
```CREATE VIEW <viewname> AS <sql.select_statement>;```
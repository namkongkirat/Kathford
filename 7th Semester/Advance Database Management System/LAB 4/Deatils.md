# Lab 4
## Create User defined types.
## Illustrate mapping of unary relationship in relational database.
## List all employees and their manager name if any.

### Syntax
```CREATE TYPE person-type AS OBHECT
(
    idno NUMBER,
    name VARCHAR(100),
    phone VARHAR2(15),
    MAP MEMBER FUNCTION get_idno RETURN NUMBER
);```
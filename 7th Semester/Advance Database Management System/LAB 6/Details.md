# LAB 6
## Implement auto increment column using sequence and trigger.
### > Create sequence <seq_table_pk>;
### > Create before insert trigger:
        if new.pk_column is null then
            new.pk.column = seq_table_pk.nextval;
        end if;
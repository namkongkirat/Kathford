member('Dave').
member('Fred').
cannot(X,'waltz'):-member(X),can(X,'jive').
cannot(X,'jive'):-member(X),can(X,'waltz').
cannot(X,Y):-parentscannot(X,Y).
parentscannot('Fred','waltz').
can('Dave',Y):-cannot('Fred',Y).

fibo(X):-fibonacci(X,R),
         write("The "),
         write(X),
         write("th term is "),
         display(R).
fibonacci(1,1).
fibonacci(2,1).
fibonacci(X,F):-X>2,
                X1 is X-1,
                X2 is X-2,
                fibonacci(X1,F1),
                fibonacci(X2,F2),
                F is F1+F2.
display(F):-write(F).
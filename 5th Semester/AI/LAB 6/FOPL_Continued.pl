# has_missile("Iraq").
# sells_weapon("George","Iraq").
# country("Iraq").
# american("George").
# enemy_of_American(X):-hostile(X).
# enemy_of_America("Iraq").
# hostile(X):-country(X).
# criminal(X):-american(X), hostile(Y), sells_weapon(X,Y).



likesfood('Bhogendra',X):-food(X).
food('orange').
food('chicken').
eat(X,Y):-person(X),notkilledby(Y).


sellsweapon('George','Iraq').
country('Iraq').
american('George').
enemyofamerica(X):-hostile(X).
enemyofamerica('Iraq').
hostile(X):-country(X).
criminal(X):-american(X),hostile(Y),sellsweapon(X,Y).
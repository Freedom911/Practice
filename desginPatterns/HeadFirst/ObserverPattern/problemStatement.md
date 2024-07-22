## Observer Pattern
Observer pattern defines one to many relationship between objects where update in
one object is reflected in all dependent objects



### Classes
1. Subject class - It is a generic Class from which multiple subjects can inherit. Subject means publisher here.
2. Observer class - Generic class from which multiple observers inherit.
3. Concrete subject class - Concrete subject classes implementing functions of subject classes.
4. Concrete observer class - Implements update method inheritted from observer class.


### Case
There are National  customers who want to get subscribed to Iphone,PS5 and sony tv as whenever there
is a sale initiated from the online store they want to be notified.

1. Subject interface class containing common register,remove and notify.
2. List of Product classes Iphone,PS5 and Sony TV.
3. Observer Generic class containing update method.
4. National customer class inheriting from observer.

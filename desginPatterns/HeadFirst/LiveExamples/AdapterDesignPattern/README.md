We have DBConection parent class which PostgresDBConnectino Library inherits.
This class is used everywhere and used for executing query in our challan app

Now Anoop sir and Akshilesh sir along with me brainstorm and decide that all the query
we send for user details needs to be encrypted to get our security certificate

So I create an class EncryptedDB.h that is responibile for exeucting the query 
and returning the plain text from DB which is kept encrypted

Issue is we need to replace instance of DBConnection
as we have this
Execute(DBConnect *ptr,std::string query)
in our challan code
Now we make another function
Exeucte_ENC(EncryptedDBConnection *db,std::string query);


So adapter pattern comes to rescue it says
it converts the interface of a class(EncryptedDB.h) 
into another interface the clients expect(DBConnection.h).  Adapter lets 
classes work together that couldn’t otherwise because of 
incompatible interfaces

The solution can be done using composition i.e by keeping object of EncryptedDB in our interface
or we inherit from EncryptedDB and DBConnection


SO 
DBConnection is the TargetInterface

DBConnectionCompositionAdapter is the composition adapter that we make

Alternative is 
DBConnectionInheritanceAdapter is the inheritance adapter 

EncryptedDB is the Adaptee 


Adapter Pattern May appearn like decorator and their implementation look same especially the composition 
one but they have different roles

In Decorator our aim is to change the object behavior dynamically by decorating the object 
In Adapter we try to allow incompatible classes work together that normally cant

After Hearing my solution I was granted Good increment
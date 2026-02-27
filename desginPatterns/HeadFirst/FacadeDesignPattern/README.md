### Issue
Suppose we have made a cinema room in our paramount golf foreste 4 bhk with garden.
I have taken a room on top floor. and I would be using that room for cinema 
So I have setup hometheater, I have setup Philips Light, I have setup, 4k 95 inch tv,
I have setup room light, I have setup ac. Now I would watching  Walter Mitty in 4k
So for that I will first switch on hometheater, switch on tv, setup light color for philips ,
setup light color for room ,switch on ac and set temperature to 25 for ac.
Pheww thats a lot of setup I need to do. I may use command pattern for making a remote
and switch on and setup each device but that still is a lot of things to do
So we call a setup person and ask them to provide a remote that takes input the movie to watch,
and Start Movie for movie viewing and stop for movie stopping. thats it

### Facade Design Pattern to the rescue
So Facade Design Pattern provides a unified interface  to a set of interfaces in a subsystem
Facade design pattern is like a god class that keeps reference of all

While implementing Facade Design Pattern **Principle of Least Knowledge** should be used
which says that Talk to your immediate friends only



Point 1
Facade Design Pattern doesnt encapsulate the subclasses they merely provide the interface
The client still has the access for subsystems

for example in our main class we have

    TV tv;
    HomeTheater theater;
    PhilipsLight light;
    Facade obj(&tv,&theater,&light);

The Client has access to subsystems which are hometheater light and tv.


Point 2
There could be more than one facade and each facade may have add additioinal functionalties

ONe of the benifits of Facade allows to decouple client and subsystems. the Functionality may change
for our subsystems but client wont require it to know


The Difference between Adapter and Facade is not that adapter has only one subsystem and facade has many
the difference is their intent. Adapter can have more than one classes . like we can pass two objects in our constructor. The main intent is Adapter changes the interface into what the client expects Facade simply provides a unified interface


Point 3 Difference between Facade and Command
It may appear that Facde and COmmand look same but again their intent is same. Facde provides a unified interface which decopules from client. In command the request is encapsulated in an object thus allowing
client to parameterize different requests into similar type of object and perform undoable operation.


| **Aspect**          | **Command Pattern**                                    | **Facade Pattern**                                     |
|---------------------|--------------------------------------------------------|--------------------------------------------------------|
| **Primary Purpose**  | Encapsulates actions/requests as objects               | Simplifies interaction with complex subsystems         |
| **Focus**            | Actions/commands                                       | Simplifying interface to multiple subsystems           |
| **How it Works**     | Creates command objects that execute specific actions  | Wraps multiple subsystems with a simpler interface     |
| **Use Cases**        | Undo/redo functionality, queueing commands, parameterizing actions | Hiding complexity, reducing dependencies               |
| **Example**          | Turning lights,Fan,TV on/off with command objects             | Home theater system with lights, projector, sound system with functinality beyond on off |




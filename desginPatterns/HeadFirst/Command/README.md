## Command Design Pattern
Command Design Pattern basically encapsulates requests in such a manner that
both sender and receiver are decoupled.

Assume we  have a remote and we have multiple classes third party for devices like
1. Light
2. Fan
3. AC
4. Geyser

Now we want to create a mobile app and assign the buttons to operate these devices
We can directly couple the devices and add them to button
but say the button has two things only on and off. so 
on on Light or AC might work differentyl

so for each button we will be adding if else which basically diferentiates how the execute
if(light)
{
    switchOnLight();
}
else if(stero)
{
    switchOnStero();
    IncreaseVolume(10)
}

and kal ko new things comes then we have to edit code again and again. Needles to say O principle is violated

### Command to the rescue
Command Design pattern creates a class for each prodcut in such a manner that sender and receiver are decopuled
remote only calls command excute object and command internally calls the product methodds
Its  smooth.

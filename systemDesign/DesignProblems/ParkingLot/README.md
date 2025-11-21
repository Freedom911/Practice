## Design A Parking Lot

### Step 1 Gathering Requirements
1. Will it support single type of vehicle or there would be multiple - Multiple
2. Will it have single level or it will multi level parking - Multiple
3. Will it be flat fees or duration based - Can be both
4. What happens if all the slots are full - Maintain The queue
5. So a parking spot is specific for a vehicle type - Si

#### Functional Requirements
1. Parking Lot should assign parking space with a number on first come first serve manner
2. Parking Lot should maintain multiple types of Parking Spaces
3. Parking Lot should allow calculation based on duration or flat based
4. There would be multiple types of vehicles. say car,bike ,SUV
5. For Now we return the first space available

#### Non Functional Requirements
1. Application should be scalable to allow large parking spaces
2. Application should allow future enhancements


### Step 2 Identifying Entities
1. First Entity would be vehicle. There can be Car,Bike or SUV
2. We will have payment Entity that calculates money based on duration
3. Parking Space Entity would be there that includes parking id,ttpe of space,is occupied 
4. We have level Entity which includes multiple Parking Space Entities.
5. Then we will the Main Class (not the int main) Parking Lot which includes multiple levels.
   Its role would be to interact with the client and allocate a space. It will maintain the list of occupied vehicles
   along with Token Details.
6. Token Details will include vehicle number,In Time,Type of vehicle
7. Vehicle Enum will be there

### Step 3 Identiying Relationships
1. We have vehicleBase Class from which car,bike and suv are derived.It will have vehicle number
2. Concrete Vehicle Class is created by a factory class VehicleCreator.
3. We have PaymentStrategy from which flatPayment and Variable Payment. WE could have here weekend based additional fees or fine
   by using decorator . We keep it simple for now
4. Parking System class will have multiple Levels and each level will have multiple parking spaces with its id. Parking System will ask each level
   to return an empty Space
5. Parking System has multiple token details
6. ParkingSystem will be singleTon



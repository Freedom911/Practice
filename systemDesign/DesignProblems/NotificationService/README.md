Entities

1. We have NotificationTypeEnum message,email,push
2. We have Gateway that based on these type have send
  I mean there would be SMSGateway that sends text message
  Email will send that sends email and so on
3. Retry Decorator will retry messages derived from Gateway
4. Recipient will have user info and contact info
5. Notification will have recipient,type,message and id
6. Notification Gateway factory creates gateway based on type
7. Notification Service is the Facade class

Design Pattern Used
1. Factory
2. Decorator
3. Facade

#include "NotificationService.h"
#include "Notification.h"
#include "Recipient.h"


int main() 
{
    // 1. Setup the notification service
    NotificationService notificationService;

    // 2. Define recipients
    Recipient recipient1("user123","John", "john.doe@example.com", "9899989989", "pushToken123");

    // 3. Send various notifications using the Facade (NotificationService)

    // Scenario 1: Send a welcome email
    Notification welcomeEmail(recipient1,"Welcome to notification system",NotificationEnum::SMS,"Welcome!");

    notificationService.sendNotification(welcomeEmail);


    return 0;
}

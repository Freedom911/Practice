#pragma once
#include <string>
#include "NotificationEnum.h"
#include "Recipient.h"
/**
 * Facade class 
 * Which is the notification itself.User will create notification from main
 * and will use our service to send notification
 */
class Notification
{
    public:
        Notification(const Recipient &rec,std::string message,NotificationEnum type,std::string subject)
            :m_recipient{rec},m_message{message},m_type{type},m_subject{subject}
        {
            static int NotId = 0;
            m_id = "G-2025-" + std::to_string(NotId);
            NotId++;
        }
        Recipient GetRecipient()
        {
            return m_recipient;
        }
        std::string GetMessage()
        {
            return m_message;
        }
        NotificationEnum GetType()
        {
            return m_type;
        }
        std::string GetSubject()
        {
            return m_subject;
        }
        std::string Getid()
        {
            return m_id;
        }

    private:
        Recipient m_recipient;
        std::string m_message;
        NotificationEnum m_type;
        std::string m_subject;
        std::string m_id;


};

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Message {
protected:
    string text;
public:
    Message(const string& txt = "") : text(txt) {}
    
    void setText(const string& txt) { text = txt; }
    string getText() const { return text; }
    
    virtual string toString() const { return text; }
};

class SMS : public Message {
private:
    string recipientContactNo;
public:
    SMS(const string& txt, const string& contact) : Message(txt), recipientContactNo(contact) {}
    
    void setRecipient(const string& contact) { recipientContactNo = contact; }
    string getRecipient() const { return recipientContactNo; }
    
    string toString() const override {
        return "To: " + recipientContactNo + " - " + text;
    }
};

class Email : public Message {
private:
    string sender;
    string receiver;
    string subject;
public:
    Email(const string& txt, const string& sndr, const string& rcvr, const string& subj)
        : Message(txt), sender(sndr), receiver(rcvr), subject(subj) {}
    
    void setSender(const string& sndr) { sender = sndr; }
    void setReceiver(const string& rcvr) { receiver = rcvr; }
    void setSubject(const string& subj) { subject = subj; }
    
    string getSender() const { return sender; }
    string getReceiver() const { return receiver; }
    string getSubject() const { return subject; }
    
    string toString() const override {
        return "From: " + sender + "\nTo: " + receiver + "\nSubject: " + subject + "\nMessage: " + text;
    }
};

bool ContainsKeyword(const Message& messageObject, const string& keyword) {
    return messageObject.getText().find(keyword) != string::npos;
}

string EncodeMessage(const string& message) {
    string encoded = message;
    for (char& c : encoded) {
        if (isalpha(c)) {
            if (c == 'Z') c = 'A';
            else if (c == 'z') c = 'a';
            else c++;
        }
    }
    return encoded;
}

int main() {
    SMS sms("\nHello, how are you doing?", "+923443770000");
    Email email("Please get back to me asap", "k241004@nu.edu.pk","K240548@nu.edu.pk", "Immediate Response");
    
    cout << "SMS: " << sms.toString() << endl;
    cout << "\nEmail:\n" << email.toString() << endl;
    
    string keyword = "asap";
    cout << "\nKeyword Search ('asap') in Email: " << (ContainsKeyword(email, keyword) ? "Found" : "Not Found") << endl;
    
    string messageToEncode = "This is Java";
    cout << "\nOriginal Message: " << messageToEncode << endl;
    cout << "Encoded Message: " << EncodeMessage(messageToEncode) << endl;
    
    return 0;
}
